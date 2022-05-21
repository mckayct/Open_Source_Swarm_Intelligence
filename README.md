
# Open Source Swarm Intelligence
Purpose: Low-Cost Open Source Swarm Capable Robots for Academic Research

## Brief Description:

This repositiory is for the code, paper and files for swarm intelligence research I conducted at Rose-Hulman Institute of Technology under Dr. Michael Wollowski. The end goal of the research was to produce swarm capable robots for academia, that have a wide range of usability at a low-cost. The robots are originally from Kevin Thomas (user tristomietitoredeituit) on Thingiverse (https://www.thingiverse.com/thing:2662828 "SMARs Link"), and I modified a housing for them as well as combined some other features.

The final product uses a Mesh Network for communication, and is programmable in Arduino code. I have included all the CAD/STL files, as well as code for people to use. If you use these robots please feel free to share with me what you make! The best way for the swarm intelligence field to grow, is to allow more people to interact with the field.

## Table of Contents

- [Robot Overview](#robot overview)
- [Photographs of the Robots](#photographs of the robots)
- [Installation](#installation)
- [BOM](#BOM)
- [Usage](#usage)
- [Credits](#credits)
- [License](#license)
## Robot Overview

The robotic platform uses a modified 3D printable open source “Screwless/Screwed Modular Assemblable Robotic System” (SMARs) originally designed by Kevin Thomas and modified by Zwald Damien. Kevin Thomas’s page details a plethora of helpful guides as well as his own outline of a teaching schedule for teaching a class with the SMARs robots visualized in Figure 2; however, this course is mainly aimed at high school level students or early undergraduate introductory courses. The SMARs platform is easily produced with a 3D printer and can be modified or expanded upon so long as the creator’s original CC BY-NC-SA 4.0 license is upheld.


For the brain of our robot, we used the FeatherS2 by Unexpected Maker Figure(3). The ESP32-S2 microcontroller was chosen for its ability to be programmed in Arduino code, Circuit Python, or Micro Python and their built-in Wi-Fi communication. This specific ESP32-S2-based board utilizes the Adafruit Feather layout, which allows it to be compatible with Adafruit’s Wing addons. Interchanging Wing modules or stacking them allows new sensors to be added to the robot with ease via a UART connection. 
 
In addition, the board has a built-in STEMMA QT connector that allows additional sensors to be connected to the board via I2C connection protocol so long as their I2C addresses are unique. For power, a JST PH LiPo connector allows the use of a 3.7V one-cell LiPo battery which is capable of powering the robot for 6+ hours.  Mobility is provided by a mini dual-channel L298N motor driver, controlling two N20 mini-DC motors with built-in gearboxes. These low-cost motors come in many gear reduction combinations that can allow for faster acceleration or more torque depending on what the buyer is desiring.

## Photographs of the Robots

![ISO View of Robot](https://github.com/mckayct/Open_Source_Swarm_Intelligence/blob/9db047a9917501220417a4b8927add208d241941/Photos/PXL_20220516_110912480.jpg "Swarm Robot ISO View")
![Bottom View of Robot](https://github.com/mckayct/Open_Source_Swarm_Intelligence/blob/c9dec4ec9c30a73c01cc55c6404b23e2a7087d69/Photos/PXL_20220516_110931297.jpg "Swarm Robot ISO View")

## Installation

To get the robots working you will need a computer with the Arduino IDE or Circuit Python[^first] setup. The provided code is for Arduino, but these microcontrollers are capable of being coded in either. Users are then encouraged to look through the example code provided, and modify it to their needs.

[^first]: Footnote Note at the time of writing, Circuit Python for the ESP32S2 does not support Mesh Networking, so Arduino Coding is preferred right now.

## BOM


## Usage

Provide instructions and examples for use. Include screenshots as needed.

To add a screenshot, create an `assets/images` folder in your repository and upload your screenshot to it. Then, using the relative filepath, add it to your README using the following syntax:

    ```md
    ![alt text](assets/images/screenshot.png)
    ```

## Credits

List your collaborators, if any, with links to their GitHub profiles.

If you used any third-party assets that require attribution, list the creators with links to their primary web presence in this section.

If you followed tutorials, include links to those here as well.

## License

The last section of a high-quality README file is the license. This lets other developers know what they can and cannot do with your project. If you need help choosing a license, refer to [https://choosealicense.com/](https://choosealicense.com/).

---

🏆 The previous sections are the bare minimum, and your project will ultimately determine the content of this document. You might also want to consider adding the following sections.

## Badges

![badmath](https://img.shields.io/github/languages/top/lernantino/badmath)

Badges aren't necessary, per se, but they demonstrate street cred. Badges let other developers know that you know what you're doing. Check out the badges hosted by [shields.io](https://shields.io/). You may not understand what they all represent now, but you will in time.

## Features

If your project has a lot of features, list them here.

## How to Contribute

If you created an application or package and would like other developers to contribute it, you can include guidelines for how to do so. The [Contributor Covenant](https://www.contributor-covenant.org/) is an industry standard, but you can always write your own if you'd prefer.

## Tests

Go the extra mile and write tests for your application. Then provide examples on how to run them here.
