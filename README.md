# Twitch Plays Hardware #

**v0.0** Built at Hack Into The BemyApp Factory
Won best use of Arduino platform :)  We used Jeremy's Bloom's book as a reference, find is here:

For the hackathon we created a method to control a Nintendo3Ds via Internet Relay Chat.  Warning the code was written quick at and was a fork of clone of the program Twitch channel "Twitch Plays Pokemon" uses and abstracts it in such a way we can control hardware.

This is both an opensourced hardware and softare hackathon:

## Please see the Hackster.io (http://www.hackster.io/392/twitchplayshardware "Project Page") for full documention including how to hack that 3DS!  ## 

The softare implemention is a fork of TwitchPlaysPokemon clone and provide implmentations for both use for windows applications like an emulator, as well as to write to arduino via serial.  The current implemention uses arduino, but similar methods can be used for other hardware devices.

The currently hardware and network stack is the following:

Nintendo 3DS  <--Digital Write--  Arduino  <--SerialWrite--  Python on PC  <--IRC--  twitch.tv viewers

The Nintendo 3DS is streamed via webcam to the computer running Python.

#### Key notes, please read: ####
- The python code is NOT written by me.  I only added the serial code implementation.
- The python script and the Arduino can not connect to the arduino at the same time.  Please ensure you close the python script before trying to use the ide.
- COM port must be manually configured in the python code.  You can use the arduino IDE to find the correct COM port, and modify the python script to connect to the correct port.


## Built for Windows, written in Python 3 32 BITv##

### Prerequisists: ###

Please note, this uses the PyWin32 and PySerial which requires the 32 bit version of Python 3.  This will not work on any operating system other than windows.

- **Python 3.3.4** [32 bit](http://www.python.org/ftp/python/3.3.4/python-3.3.4.msi "32 bit")
- **PyWin32**  [32 bit](http://sourceforge.net/projects/pywin32/files/pywin32/Build%20218/pywin32-218.win32-py3.3.exe/download "32 bit")
- *If you have any dll related issues make sure you're using the right version!*
- **Pyserial 2.7 windows 32 ** https://pypi.python.org/packages/any/p/pyserial/pyserial-2.7.win32_py3k.exe#md5=c6fb580ae7763671297794b8a1d91c9e
- Install the Arduino IDE (http://arduino.cc/en/Main/Software "here")
- Create a twitch.tv account


To get people to play via stream just type the comands in the chat:
 
	A:			a
	B:			b
	X:			x
	Y:			y
	Up: 		up
	Right: 		right
	Down: 		down
	Left: 		left


### How to use ###
-Configure the hardware as outlined in the Hackster.io page: 



- Remove the text document from the game folder.  Any file in this folder will auto open when the python script is opened.
- Double click on Launch.py
- The bot will walk you through first-time configuration


### My Channel ###

- My channel will be available [**here**](http://www.twitch.tv/twitchplayshardware"Twitch Plays 
- There is about a 30 second lag at the hackathon.  The wireless internet is terrible here.
- Derek, my partner at the hackathon owns the DS and possibly will post in the future.
