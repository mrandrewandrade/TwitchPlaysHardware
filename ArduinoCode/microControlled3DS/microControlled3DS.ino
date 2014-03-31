//microController3DS.ino
//Simple that takes commands from serial and write to pins
//Used to controlled a Nintendo3DS using twitch.tv stream IRC
//Copyright (C) 2014 : Andrew Andrade
// This program is free software; you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation; either version 3 of the License, or
//(at your option) any later version.

//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//GNU General Public License for more details.
/******Pin Mapping**********************************
***************************************************/
// Pin map stucture to location of pins
// LED connected to digital pin 9
// TODO: Change these pin numbers to match hardware
#define LEFT_PIN   24      
#define RIGHT_PIN  26
#define UP_PIN     30
#define DOWN_PIN   28
#define A_PIN      40
#define B_PIN      38
#define X_PIN      42
#define Y_PIN      44
#define HOME_PIN   32
#define SELECT_PIN 36
#define START_PIN  34
  

/******Setup method****************************
Description: standard arduino method for initial setup
Sets the serial ports and standard pin voltage
***************************************************/
// setup method: 
void setup()
{
  // set standard baud rate
  Serial.begin(9600); 

    // sanity check, print ready back through serial
  Serial.println("Ready"); 
 
  // Setting pins to INPUT spoof a 100 MOhm resistor
  pinMode(LEFT_PIN, INPUT);  
  pinMode(RIGHT_PIN, INPUT);
  pinMode(UP_PIN, INPUT);
  pinMode(DOWN_PIN, INPUT);
  pinMode(B_PIN, INPUT);
  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
  pinMode(HOME_PIN, INPUT);
  pinMode(SELECT_PIN, INPUT);
  pinMode(START_PIN, INPUT);
}

/******buttonPress method****************************
Description: buttonPress takes a button location 
and sends a button press simulation signal to the nintendoDS
@Param a_unButton: pin number of button to press
@Param a_ucNuPresses: number of presses of button
***************************************************/
boolean buttonPress (unsigned int a_unButton, unsigned char a_ucNumPresses) {

  for (int iii = 1; iii <= a_ucNumPresses; iii++)  {
    // set specific pin to output voltage
    pinMode(a_unButton, OUTPUT);
    
    // write pin low to simulate pressing
    digitalWrite(a_unButton, LOW);
    delay(100);

    // reset pin back to input voltage
    pinMode(a_unButton, INPUT);   
    delay(250);
  } 
  return true;
}

/******validButtonPush method****************************
Description: takes in push command and calls press if valid
and sends press simulation to the nintendoDS
@Param a_cButton: pin number of button to press
***************************************************/
// TODO: Implement - @Param a_numberPresses: number of presses of button
unsigned int ifValidButtonPush (char a_cButton) {
  // Sucess status of button press
  boolean bPressStatus = true;
  
  switch (a_cButton){
      case 'L':
            buttonPress(LEFT_PIN, 1);
      break;
        
      case 'R':
            buttonPress(RIGHT_PIN, 1);
      break;

      case 'U':
            buttonPress(UP_PIN, 1);
      break;
      
      case 'D':
            buttonPress(DOWN_PIN, 1);
      break;

      case 'A':
            buttonPress(A_PIN, 1);
      break;
      
      case 'B':
            buttonPress(B_PIN, 1);
      break;
      
      case 'X':
            buttonPress(X_PIN, 1);
      break;

      case 'Y':
            buttonPress(Y_PIN, 1);
      break;
      
      case 'H':
            buttonPress(HOME_PIN, 1);
      break;
      
      case 'E':
            buttonPress(SELECT_PIN, 1);
      break;
      
      case 'S':
            buttonPress(START_PIN, 1);
      break;
      default:
            bPressStatus = false;
      break;
    }
  return bPressStatus;
}

// Program's main loop
// Loop scanning for commands. Read commands,
// verify if they are buttons and simulation pressing on DS
void loop()
{
    // Variable to store command from IRC
    char cInputCommand = ' ';

    // Ensure serial is not busy (checks if data has been sent before reading again)
    if(Serial.available()){ 
      
      // Read the incoming data
      cInputCommand = Serial.read(); 
      
      // Send command to push button
      ifValidButtonPush(cInputCommand);

      // TODO: Is this even necessary?
      // send the command back in a new line so that it is not all one long line
      Serial.println(cInputCommand); 
    }
    delay(100); // delay for 1/10 of a second
}
