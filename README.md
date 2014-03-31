Twitch Plays Hardware
=========

**v0.0** Built at [Hack Into The BemyApp Factory](http://public.bemyapp.com/thefactory/)     
Won best use of Arduino platform :)     

For the hackathon we created a method to control a Nintendo3Ds via Internet Relay Chat.  The code was written Hackathon Style and was a fork of clone of the program Twitch channel "Twitch Plays Pokemon" uses and abstracts it in such a way we can control hardware.

This is both an opensourced hardware and softare hackathon and we are providing everything you need to get started.  A big part of learning is trying to figure things out and understand how they work.  If you are having trouble, try the [twitch plays pokemon project](https://github.com/sunshinekitty5/TwitchPlaysPokemon) using an emulator.  Once you can play Pokemon through the emulator, then you can move on to using a DS.

#### Please see the hackster.io [project page](http://www.hackster.io/392/twitchplayshardware "Project Page") for full documention including how to hack that 3DS and set up hardware!  ### 

## Software Documentation ##

The softare implemention is a fork of TwitchPlaysPokemon clone and provides implmentations for both use for windows applications like an emulator, as well as to write to arduino via serial.  The current implemention uses arduino, but similar methods can be used for other hardware devices.

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
- **Pyserial 2.7 Windows ** [ 32 Bit](https://pypi.python.org/packages/any/p/pyserial/pyserial-2.7.win32_py3k.exe#md5=c6fb580ae7763671297794b8a1d91c9e)
- Install the [Arduino IDE](http://arduino.cc/en/Main/Software "here")
- Create a [twitch.tv](http://twitch.tv) account




### How to use ###
- Install all the required prerequisites
- Follow the instruction and set up using Emulator [here](https://github.com/sunshinekitty5/TwitchPlaysPokemon)
- Check out this [video](https://www.youtube.com/watch?v=LvBU9SJ8sfE&feature=youtu.be) if you are having issues.  The twitch chat authentication can be found [here](http://twitchapps.com/tmi/)
- Configure the hardware as outlined in the Hackster.io [page](http://www.hackster.io/392/twitchplayshardware)
- Download the arduino located in /ArduinoCode/ and load onto arduino using IDE.  Please ensure you set the correct board, serial port and that the pins are the correct number
- Confirm that you are write to the Arduino via the serial terminal on the Arduino IDE.  Arduino should return the command you send.
- Ensure you close the arduino IDE once you upload the code.  Python can not talk to the arduino if the port is busy (being used by the arduino IDE)
- Inside /TwitchPythonBot/ run Launch.py using your favourite python intrepreter.  Follow the same steps you followed when using  the Emulator [here](https://github.com/sunshinekitty5/TwitchPlaysPokemon) except set Notepad as the program instead of VisualGameBoyAdvance
- For the sake of flexibility, the file in /game/ will open and is set at notepad as default.
- If you set things up right, the Python script should sniff the steam and send the commands to Arduino

To get people to play via stream just type the comands in the chat:
 
    A:    		a
	B:			b
	X:			x
	Y:			y
	Up:         up
	Right: 		right
	Down: 		down
	Left: 		left


### My Channel ###

- My channel will be available [**here**](http://www.twitch.tv/twitchplayshardware"Twitch Plays 
- At the hackathon there was about a 30 second lag at the hackathon.
- Derek, my partner at the hackathon owns the DS and possibly will post in the future, stay tuned.

