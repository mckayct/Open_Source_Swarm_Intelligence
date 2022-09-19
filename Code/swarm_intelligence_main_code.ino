 /* Swarm Intelligence Code
  Rose-Hulman Institute of Technology
  Winter-Spring 2021-22

  By: Colton McKay
      school email: mckayct@rose-hulman.edu
      personal email: wcsm1999@yahoo.com

  Advisor: Dr. Wollowski

  Description:
  This code is the main driving code for my swarm robots (for more information on them see README).
  The code uses a painlessMesh Library to form a WIFI network using ESP-MESH protocals, this allows for dynamic network decay and growth
  The code also includes our algorithm for what the Robots must accomplish as well as some defined movement functions.
  My coding style is not "Rose-Hulman" standard, but I organize it into logical chunks for easier understanding. If future students need any help
  or would like to understand my work flow/process feel free to reach out to me via contact info above.

*/

// Import of Libraries
#include <basicMPU6050.h> 
#include <Adafruit_GPS.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Arduino.h>     // every sketch needs this
#include <TFLI2C.h>      // TFLuna-I2C Library v.0.2.0
#include <L298NX2.h>
#include "painlessMesh.h" //Used for making the WIFI Mesh Network


//**********************************************************
// #Defines go here

#define GPSSerial Serial1 // Define GPS Serial Connection
#define   MESH_PREFIX     "swarmIntelligence" // WIFI Network Name
#define   MESH_PASSWORD   "swarmsRCool" // WIFI Network Password
#define   MESH_PORT       5555 // TCP Port Network runs on, 5555 is default
#define GPSECHO false //Set to true to print Raw GPS Data to Serial. For Debugging only!
//  Pin definition
//Motor A Pins
const unsigned int EN_A = 3;
const unsigned int IN1_A = 5;
const unsigned int IN2_A = 6;
//Motor B Pins
const unsigned int IN1_B = 7;
const unsigned int IN2_B = 8;
const unsigned int EN_B = 9;
//Constants for Measuring Motion Time
unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 1000;  //the value is a number of milliseconds (1 second), scale as needed
const unsigned long timeConstInches = 10; // Constant variable in milliseconds that translate to roughly 1 inch of motion
const unsigned long timeConstDegree = 10; // Constant variable in milliseconds that translate to roughly 1deg of rotation motion
//Constants for LIDAR
int16_t tfDist;    // distance in inches (sensor reads in cm, I have converted)
int16_t  tfAddr = TFL_DEF_ADR;  // use this default I2C address or
//Servo for LIDAR
const int servoPin = 17;
int dutyCycle = 0;
const int PWMFreq = 50;                                //50hz
const int PWMChannel = 0;
const int PWMResolution = 12;                       //12 bits 0-4095

//***********************************************************************
// Declare Class objects Here

Scheduler userScheduler; // to control your personal task
painlessMesh  mesh; //Create a mesh
L298NX2 motors(EN_A, IN1_A, IN2_A, EN_B, IN1_B, IN2_B);// Initialize both motors
Adafruit_GPS GPS(&GPSSerial);//Define GPS Object
TFLI2C tflI2C;
basicMPU6050<> imu;


//**********************************************************************
// Declare Global Variables Here

void sendMessage() ; // Prototype so PlatformIO doesn't complain
//void updateLocalVariables();
//void updateGlobalVariables();
//void algorithm();
//void readData();
//void obstacleAvoidance();
////void gatherData();
//void randomStart();
//void movements();
//**********************************************************************
// Declare Tasks for Task Manager Here
//(WHEN, HOW OFTEN, TASK)
Task taskSendMessage( TASK_SECOND*1 ,1000, &sendMessage ); // Used to Ping to Network, Data

//Task taskRandomStart( -1 ,0, &randomStart);
//
//Task tastkUpdateGlobalVariables(-1, 0, &updateGlobalVariables );//Used to check and update Global Variables
//
//Task taskUpdateLocalVariables(-1, 0, &updateLocalVariables  );// Used to check and update Local Variables
//
//Task taskReadData(-1,TASK_FOREVER, &readData );// Used to check and update Local Variables
//
//Task taskAlgorithm(-1, 0, &algorithm );
//
//Task taskGatherData(TASK_SECOND*1 ,1000, &gatherData );
//
//Task taskobstacleAvoidance(-1, 0, &obstacleAvoidance );
//
//Task taskMovement(-1, 0, &movements );

  bool firstTime = false;


  //Global Variables
  float g_best[3];

  //Local Variables
  float l_best[3];
  float l_current[3];
  float movement[2];
  
  //Setup Arrays
  float gps[5];
  float imu_data[7];
  float lidar_sweep[100];
  float temp_sweep_min[1];

  //Parameters
  float dist_threshold = 100;





//**********************************************************************
// Primary Functions - SETUP (runs 1 time) and LOOP (runs Infinite times)
void setup() {
  Serial.begin(115200);
//  startMillis = millis();
  //mesh.setDebugMsgTypes( ERROR | MESH_STATUS | CONNECTION | SYNC | COMMUNICATION | GENERAL | MSG_TYPES | REMOTE ); // all types on
  //MESH FUNCTION
  mesh.setDebugMsgTypes( ERROR | STARTUP );  // set before init() so that you can see startup messages
  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT );
  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);
  mesh.onChangedConnections(&changedConnectionCallback);
  mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);

  //GPS
//  GPS.begin(9600);
//  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);  // uncomment this line to turn on RMC (recommended minimum) and GGA (fix data) including altitude
//  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_1HZ); // 1 Hz update rate
  // For the parsing code to work nicely and have time to sort thru the data, and
  // print it out we don't suggest using anything higher than 1 Hz

  //MPU
  // Set registers - Always required
//  imu.setup();
  // Initial calibration of gyro
//  imu.setBias();

  //Servos
//  Wire.begin();
  
  //TASK SCHEDULER
  userScheduler.addTask( taskSendMessage );
//  userScheduler.addTask(taskGatherData);
//  taskGatherData.enable();
  taskSendMessage.enable();

//  ledcSetup(PWMChannel, PWMFreq, PWMResolution);
//  ledcAttachPin(servoPin, PWMChannel);
//  ledcWrite(PWMChannel, dutyCycle);
//  
  
}

void loop() {
  mesh.update();   // it will run the user scheduler as well
}

//____________________________________________________________________________________________________________________________________________________________________________
//**********************************************************************
//**********************************************************************
// Custom Functions - These will be divided into different categories

//**********************************************************************
// Painless Mesh Main Functions
void sendMessage() {
  String msg = "BASE_STATION:";
  msg += gatherData();
  mesh.sendBroadcast( msg );
  taskSendMessage.setInterval( random( TASK_SECOND * 1, TASK_SECOND * 5 ));
}

// Needed for painless library
void receivedCallback( uint32_t from, String &msg ) {
  Serial.printf("%u msg=%s\n", from, msg.c_str());
}

void newConnectionCallback(uint32_t nodeId) {
  Serial.printf("New Connection, nodeId = %u\n", nodeId);
}

void changedConnectionCallback() {
  Serial.printf("Changed connections\n");
}

void nodeTimeAdjustedCallback(int32_t offset) {
  Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(), offset);
}


//**********************************************************************
// Robot Motion Main Functions

void forward(double inches) {
//  currentMillis = millis();
  while ((currentMillis - startMillis) != (timeConstInches * inches)) {
    motors.forward();
  }
  motors.stop();

}

void turn(double degree, char dir) {
//  currentMillis = millis();
  while ((currentMillis - startMillis) != (timeConstDegree * degree)) {
    if (dir == 'L') {
      motors.forwardA();
      motors.backwardB();
    } else {
      motors.backwardA();
      motors.forwardB();
    }
  }
  motors.stop();
}

void reverse(double inches) {
  currentMillis = millis();
  while ((currentMillis - startMillis) != (timeConstInches * inches)) {
    motors.backward();
  }
  motors.stop();
}

//**********************************************************************
// GPS Data Main Functions
void GPSData() {
//  currentMillis = millis();
  char c = GPS.read();    // read data from the GPS in the 'main loop'
  if (GPSECHO)
    if (c) Serial.print(c);  // if you want to debug, this is a good time to do it!
  // approximately every 2 seconds or so, print out the current stats
  if (currentMillis - startMillis > period * 2) {
    if (GPS.fix) {
      gps[0] = GPS.latitude;
      gps[1] = GPS.longitude;
      gps[2] = GPS.altitude;
      gps[3] = GPS.angle;
      gps[4] = GPS.satellites;
    }
  }
}

//**********************************************************************
// IMU Main Functions

String IMUData() {
  String temp;
  // Update gyro calibration 
//  imu.updateBias();
//  imu.setup();
  if(firstTime == false){
    imu.setup();
    imu.setBias();
    firstTime = true;
  }else{
  imu.updateBias();
//  imu_data[0]= imu.ax();
//  imu_data[1]= imu.ay();
//  imu_data[2]= imu.az();
//  imu_data[3]= imu.gx();
//  imu_data[4]= imu.gy();
//  imu_data[5]= imu.gz();
//  imu_data[6]= imu.temp();
    temp +="x: ";
    temp +=String(imu.ax(),3);
    return temp;
  }
}

//**********************************************************************
// LIDAR Main Functions

//void LIDARScanData() {
//  if ( tflI2C.getData(tfDist, tfAddr)) // If read okay...
//  {
//    Serial.print("Dist: ");
//    Serial.println(tfDist);          // print the data...
//  }
//  else tflI2C.printStatus();           // else, print error.
//}

void LiDARSweep(){
  if ( tflI2C.getData(tfDist, tfAddr)){ // If read okay...
    ledcWrite(PWMChannel, 200);                     //approx 1ms
    for(int i = 0; i<100;i++){
      lidar_sweep[i] = tfDist;
    }
  }
  else tflI2C.printStatus();           // else, print error. 
}


//**********************************************************************
// Particle Swarm Optimization Tasks

String gatherData(){
  String values = IMUData();
//  GPSData();
//  LiDARSweep();
  return values;
}

//void obstacleAvoidance(){
//  LiDARSweep();
//  float temp_sweep_min = lidar_sweep[0];
//  for(int i = 0; i<sizeof(lidar_sweep);i++){
//    if(lidar_sweep[i]<temp_sweep_min){
//      temp_sweep_min = lidar_sweep[i];
//    }
//  }
//  if(temp_sweep_min < dist_threshold){
//    reverse(2);
//    turn(45, 'R');
//    forward(2);
//  }
//
//}
//
//void randomStart(){
//  forward(random(1,5));
//  turn(random(1,90),'L');
//  forward(random(1,5));
//  taskGatherData.enableDelayed(1000);
//}
//
//void updateLocalVariables(){
//  l_current[0] = gps[0];
//  l_current[1] = gps[1];
//  l_current[2] = gps[2];
//  taskReadData.enableDelayed(1000);
//}
//
//void updateGlobalVariables(){
//}
//
//void movements(){
//  float dist = sq(pow(movement[0],2)+pow(movement[1],2));
//  char where[1];
//  
//  if(movement[0] > 0){
//    where[0] = 'L';
//  }else{
//    where[0] = 'R';
//  }
//  if(movement[1] > 0){
//    where[1] = 'D';
//  }else{
//    where[1] = 'U';
//  }
//
//
//  if(where[0] == 'L' & where[1] == 'D'){
//    turn(135,'L');
//    forward(dist);
//  }if(where[0] == 'L' & where[1] == 'U'){
//    turn(45,'L');
//    forward(dist);
//  }
//
//  if(where[0] == 'R' & where[1] == 'D'){
//    turn(135,'R');
//    forward(dist);
//  }if(where[0] == 'R' & where[1] == 'U'){
//    turn(45,'R');
//    forward(dist);
//  }
////    taskGatherData.enableDelayed(1000);
//}
//
//void algorithm(){
//  //Check if we are at better than global
//  if(l_best[0] > g_best[0] & l_best[1] > g_best[1]){
//    g_best[0] = l_best[0];
//    g_best[1] = l_best[1];
//  }
//  //Check each dimension
//  //X
//  if(l_current[0]>l_best[0]){
//    movement[0] = (l_current[0]-l_best[0]);
//  }
//  if(l_current[0]<l_best[0]){
//    movement[0] = (l_current[0]-l_best[0]);
//  }
//  //Y
//  if(l_current[1]>l_best[1]){
//    movement[1] = (l_current[1]-l_best[1]);
//  }
//  if(l_current[1]<l_best[1]){
//    movement[1] = (l_current[1]-l_best[1]);
//  }
//  taskMovement.enableDelayed(1000);
//}
//void readData(){
//  taskAlgorithm.enableDelayed(1000);
//}
