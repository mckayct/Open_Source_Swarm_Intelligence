
# Open Source Swarm Intelligence
<p align="center">
Purpose: Low-Cost Open Source Swarm Capable Robots for Academic Research
</p>
<p align="center">
  <img src="https://img.shields.io/badge/adafruit-000000?style=for-the-badge&logo=adafruit&logoColor=white" alt="Adafruit" width="100"/>
  <img src="https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white" alt="Arduino" width="100"/>
  <img src="https://img.shields.io/badge/espressif-E7352C?style=for-the-badge&logo=espressif&logoColor=white" alt="Arduino" width="110"/> 
</p>


## Brief Description:

This repositiory is for the code, paper and files for swarm intelligence research I conducted at Rose-Hulman Institute of Technology under Dr. Michael Wollowski. The end goal of the research was to produce swarm capable robots for academia, that have a wide range of usability at a low-cost. The robots are originally from Kevin Thomas (user tristomietitoredeituit) on Thingiverse [SMARs](https://www.thingiverse.com/thing:2662828), and I modified a housing for them as well as combined some other features.

The final product uses a Mesh Network for communication, and is programmable in Arduino code. I have included all the CAD/STL files, as well as code for people to use. If you use these robots please feel free to share with me what you make! The best way for the swarm intelligence field to grow, is to allow more people to interact with the field.

## Table of Contents

- [Robot Overview](#robot-overview)
- [Photographs of the Robots](#photographs-of-the-robots)
- [Installation](#installation)
- [BOM](#bill-of-materials)
- [Ideas For Future](#ideas-for-future)
- [Credits](#credits)
- [License](#license)
- [Support Me](#support-me)
## Robot Overview

<p align="center">
<img src="https://github.com/mckayct/Open_Source_Swarm_Intelligence/blob/dd1bf942ce23ad5b1e470ddc3e182947b6546575/Photos/SMARs.png" alt="SMARS" width="400"/>
</p>

The robotic platform uses a modified 3D printable open source “Screwless/Screwed Modular Assemblable Robotic System” (SMARs) originally designed by Kevin Thomas and modified by Zwald Damien. Kevin Thomas’s page details a plethora of helpful guides as well as his own outline of a teaching schedule for teaching a class with the SMARs robots visualized in Figure 2; however, this course is mainly aimed at high school level students or early undergraduate introductory courses. The SMARs platform is easily produced with a 3D printer and can be modified or expanded upon so long as the creator’s original CC BY-NC-SA 4.0 license is upheld.

<p align="center">
<img src="https://github.com/mckayct/Open_Source_Swarm_Intelligence/blob/dd1bf942ce23ad5b1e470ddc3e182947b6546575/Photos/Board.png" alt="SMARS" width="400"/>
</p>

For the brain of our robot, we used the FeatherS2 by Unexpected Maker Figure(3). The ESP32-S2 microcontroller was chosen for its ability to be programmed in Arduino code, Circuit Python, or Micro Python and their built-in Wi-Fi communication. This specific ESP32-S2-based board utilizes the Adafruit Feather layout, which allows it to be compatible with Adafruit’s Wing addons. Interchanging Wing modules or stacking them allows new sensors to be added to the robot with ease via a UART connection. 

<p align="center">
<img src="https://github.com/mckayct/Open_Source_Swarm_Intelligence/blob/8463e33c7f02dc853dbc1ddd00699f9d659b8d04/Photos/Sensors.jpg" alt="SMARS" width="400"/>
</p>
 
In addition, the board has a built-in STEMMA QT connector that allows additional sensors to be connected to the board via I2C connection protocol so long as their I2C addresses are unique. For power, a JST PH LiPo connector allows the use of a 3.7V one-cell LiPo battery which is capable of powering the robot for 6+ hours.  Mobility is provided by a mini dual-channel L298N motor driver, controlling two N20 mini-DC motors with built-in gearboxes. These low-cost motors come in many gear reduction combinations that can allow for faster acceleration or more torque depending on what the buyer is desiring.

## Photographs of the Robots

<p align="center">
  <img src="https://github.com/mckayct/Open_Source_Swarm_Intelligence/blob/9db047a9917501220417a4b8927add208d241941/Photos/PXL_20220516_110912480.jpg" alt="ISO" width="400"/>
  <img src="https://github.com/mckayct/Open_Source_Swarm_Intelligence/blob/c9dec4ec9c30a73c01cc55c6404b23e2a7087d69/Photos/PXL_20220516_110931297.jpg" alt="BOTTOM" width="600"/> 
</p>

## Installation

To get the robots working you will need a computer with the Arduino IDE or Circuit Python[^first] setup. The provided code is for Arduino, but these microcontrollers are capable of being coded in either. Users are then encouraged to look through the example code provided, and modify it to their needs.

[^first]: Note at the time of writing, Circuit Python for the ESP32S2 does not support Mesh Networking, so Arduino Coding is preferred right now.

## Bill of Materials

Items are listed below. Users can use links attached or search on other websites for better deals. Sensors can also be changed depending on what the user's end goal is

| Item | Description | Quantity of Component per Robot | Price on Link[^2] | Link  |
| :----: | :-------: |  :---------------: | :---: | :---: |
| Microcontroller           | Main control board for Robot                                           | 1 | $24.95 |[Adafruit](https://www.adafruit.com/product/4769) |
| Motor Controller          | Controller for N20 Motors                                              | 1 | $13.02 |[Amazon](https://www.amazon.com/Channel-Positive-Inversion-Adjustment-Stepper/dp/B09Y4LKV52/ref=sr_1_23?crid=3B0N4G2SE1MID&keywords=l298n+mini&qid=1653160730&s=industrial&sprefix=l298n+mini%2Cindustrial%2C73&sr=1-23) |
| N20 Motors                | N20 Motors with straight gearbox                                       | 2 | $9.49 | [Ebay](https://www.ebay.com/itm/313865598591?hash=item4913d8f67f:g:mnIAAOSwYWFiAJZR)|
| MPU-6050                  | 6-D.O.F. Inertial Measuring Unit                                       | 1 | $6.95 | [Adafruit](https://www.adafruit.com/product/3886)|
| Adafruit GPS Featherwing  | Feather Sized GPS Module                                               | 1 | $24.95 |[Adafruit](https://www.adafruit.com/product/3133) |
| TFLuna Point LiDAR        | Singular Point LiDAR                                                   | 1 | $26.99 |[Amazon](https://www.amazon.com/RCmall-Single-Point-Compatible-Obstacle-Avoidance/dp/B09SZ5H21B/ref=sr_1_4?crid=2VQZGB1LF6GC&keywords=tfluna+lidar&qid=1653160551&s=industrial&sprefix=tfluna+lidar%2Cindustrial%2C71&sr=1-4) |
| 9g Servo                  | 180 Degree Rotational Servo                                            | 1 | $20.99 |[Amazon](https://www.amazon.com/Smraza-Helicopter-Airplane-Control-Arduino/dp/B07L2SF3R4/ref=sr_1_2_sspa?keywords=9g+servo&qid=1653160479&sr=8-2-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUEzRlcwU0MzV0pGN09UJmVuY3J5cHRlZElkPUExMDQ3OTU2MTFKTElVQjg2MFdPUSZlbmNyeXB0ZWRBZElkPUEwMzI1MTA5MUFXNEtIUFJQUlZZMSZ3aWRnZXROYW1lPXNwX2F0ZiZhY3Rpb249Y2xpY2tSZWRpcmVjdCZkb05vdExvZ0NsaWNrPXRydWU=) |
| LiPo Battery              | 2500 mAh Battery                                                       | 1 | $14.95 |[Adafruit](https://www.adafruit.com/product/328) |
| Tiny Breadboards          | Minature Breadboard for cabling                                        | 2 |  $6.49 |[Amazon](https://www.amazon.com/HiLetgo-SYB-170-Breadboard-Colorful-Plates/dp/B071KCZZ4K/ref=sr_1_2_sspa?crid=2GNW8NY876FU8&keywords=tiny+breadboard&qid=1653160375&s=industrial&sprefix=tiny+breadboards%2Cindustrial%2C78&sr=1-2-spons&psc=1&spLa=ZW5jcnlwdGVkUXVhbGlmaWVyPUFSS0Y3SklRUDJXSzImZW5jcnlwdGVkSWQ9QTA0NzY2OTg3QjA0TFlMQUpNVEomZW5jcnlwdGVkQWRJZD1BMTAxODU2NjFEQzlMTVNGNkJUTFUmd2lkZ2V0TmFtZT1zcF9hdGYmYWN0aW9uPWNsaWNrUmVkaXJlY3QmZG9Ob3RMb2dDbGljaz10cnVl) |
| Dupont Wires              | For easy connection between components                                 | 1 | $6.98 | [Amazon](https://www.amazon.com/Elegoo-EL-CP-004-Multicolored-Breadboard-arduino/dp/B01EV70C78/ref=asc_df_B01EV70C78/?tag=hyprod-20&linkCode=df0&hvadid=222785939698&hvpos=&hvnetw=g&hvrand=3286274990828402662&hvpone=&hvptwo=&hvqmt=&hvdev=c&hvdvcmdl=&hvlocint=&hvlocphy=9016683&hvtargid=pla-362913641420&psc=1 )|
| 3D printed material       | 3D printed components listed in CAD File                               | 1 | ~$10 | |


[^2]: Does not mean price per robot, nor price per component. Simply price per the link given.

## Ideas for Future

While the current robot was satisfactory for an introduction to Swarm Intelligence, I would eventually like to make them into a more final product including
* Academic Schedule for a Class Based Upon Swarm Intelligence
* Change the drive train to Tank Tread Systems (original SMARs plan)
* Creat New Algorithms for the Swarm
* Look for ways to reduce price

If you create something with this project, please reachout and share it with me!

---
## Credits

### For their Support During my Research
* Dr. Michael Wollowski
  - https://www.rose-hulman.edu/academics/faculty/wollowski-michael-wollowsk.html
  - https://www.rose-hulman.edu/~wollowsk/
* Dr. David Fisher
  - https://www.rose-hulman.edu/academics/faculty/fisher-david-fisherds.html
  - https://wordpress.rose-hulman.edu/fisherds/
* Dr. Carlotta Berry
  - https://www.rose-hulman.edu/academics/faculty/berry-carlotta-berry123.html
  - https://wordpress.rose-hulman.edu/berry123/

### For Tutorials or Foundations to my Research
* Kevin Thomas - SMARs Robot Design
  - https://www.smarsfan.com/
* Unexpected Maker
  - https://feathers2.io/
* Pat Langley
  - https://doi.org/10.1609/aimag.v42i4.15089
* Wikipedia
  - https://en.wikipedia.org/wiki/Swarm_intelligence
* Random Nerd Tutorials
  - https://randomnerdtutorials.com/esp-mesh-esp32-esp8266-painlessmesh/
* Wyss Institute
  - https://wyss.harvard.edu/technology/programmable-robot-swarms/

## License
<p align="center">
<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">
 <img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a>

<br />
This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.
</p>

## Support Me
<div align="Center">
 You ABSOLUTELY DO NOT have to, but if you would like to...
 </div>
<p align="center"> 
<a href="https://www.buymeacoffee.com/mckayct" target="_blank"><img src="https://www.buymeacoffee.com/assets/img/custom_images/orange_img.png" alt="Buy Me A Coffee" style="height: 41px !important;width: 174px !important;box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;-webkit-box-shadow: 0px 3px 2px 0px rgba(190, 190, 190, 0.5) !important;" ></a>
 
 </p>
<p align ="center">
<img src="https://media4.giphy.com/media/tlGD7PDy1w8fK/giphy.gif?cid=ecf05e476ngi7lzc9ly19rv2zvck6tynnifp0oxq8g142gc8&rid=giphy.gif&ct=g" width="200" height="200" />
</p>
