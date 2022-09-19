/*
On ESP32 generates a sweeping pulse of 1mS to 2mS at 50hz
*/

const int servoPin = 17;

int dutyCycle = 0;

const int PWMFreq = 50;                                //50hz
const int PWMChannel = 0;
const int PWMResolution = 12;                       //12 bits 0-4095
 
void setup()
{
  ledcSetup(PWMChannel, PWMFreq, PWMResolution);
  ledcAttachPin(servoPin, PWMChannel);
  ledcWrite(PWMChannel, dutyCycle);
}

void loop()
{
    ledcWrite(PWMChannel, 200);                     //approx 1ms
    delay(2000);

    ledcWrite(PWMChannel, 400);                     //approx 2mS
    delay(2000);
}
