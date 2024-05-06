Overview
========
This is a HSQ-8801 Project from Brutalist Instruments.

SDK version
===========
- Version: 2.15.000

Toolchain supported
===================
- IAR embedded Workbench  9.40.1
- Keil MDK  5.38.1
- GCC ARM Embedded  12.2
- MCUXpresso  11.8.0

Hardware requirements
=====================
- Mini/micro USB cable
- EVKB-IMXRT1050 board
- Personal Computer


# HOW TO SETUP THIS REPO
=========================
You'll need two environment variables set in your system:
- NXPSDK_PATH, This should be your path to your SDK that you installed when setting up VS Code.
	For example, mine is in c:\\Files\\repos\\NXPSDK
- ARMGCC_PATH, This should be the path to your Arm-GNU install by NXP. 
	For example, mine is in C:/Users/UserName/.mcuxpressotools/arm-gnu-toolchain-12.3.rel1-mingw-w64-i686-arm-none-eabi

[this guide will be helpful](https://www.howtogeek.com/668503/how-to-set-environment-variables-in-bash-on-linux/) for creating the variables. it is recommended to use nano as the text editor, rather than gedit.

If you're unsure of your files are located, clone an example project, and check mcuxpresso-tools.json in the .vscode folder. 

The other thing you'll need to setup is your \_\_repo\_\_ folder.
This needs 3 links symbolic links in it, two three folders in the NXP SDK. 
There are instructions in the repo folder on how to set this up.


# HOW TO COMMIT TO THIS REPO
=====================
There are 3 branches that you will be concerned with. 
- main
- dev
- your feature branch

(internal contribution)
When working on a feature, Please branch off of dev, and PR into dev when your feature is complete. 

(external contribution)
Please fork this repository, and PR back into dev when your feature is complete. 

Main is resolved for the most stable, tested version of FW. 