
/******Pin Mapping**********************************
***************************************************/
//Pin map stucture to location of pins
enum pinMap  {
  LEFT_PIN = 24,      // LED connected to digital pin 9
  RIGHT_PIN = 26,
  UP_PIN = 30,
  DOWN_PIN =28,
  A_PIN = 40,
  B_PIN = 38,
  X_PIN = 42,
  Y_PIN = 44,
  HOME_PIN = 32,
  SELECT_PIN = 36,
  START_PIN = 34,
};
  
//Set global INPUT voltage constant
const int DS_VOLTAGE = INPUT; //92 corresponds to 1.81V

/******Setup method****************************
Description: standard arduino method for initial setup
Sets the serial ports and standard pin voltage
***************************************************/
//setup method: 
void setup()
{
  // set standard baud rate
  Serial.begin(9600); 

    // sanity check, print ready back through serial
  Serial.println("Ready"); 
 
  //Setting pins to default to input voltage
  //to trick the 3DS into thinking everthing
  //is normal (simulate voltage present)
  //Note: analogRead values go from 0 to 1023, pinMode values from 0 to 255 
  pinMode(LEFT_PIN, DS_VOLTAGE);  
  pinMode(RIGHT_PIN, DS_VOLTAGE);
  pinMode(UP_PIN, DS_VOLTAGE);
  pinMode(DOWN_PIN, DS_VOLTAGE);
  pinMode(B_PIN, DS_VOLTAGE);
  pinMode(X_PIN, DS_VOLTAGE);
  pinMode(Y_PIN, DS_VOLTAGE);
  pinMode(HOME_PIN, DS_VOLTAGE);
  pinMode(SELECT_PIN, DS_VOLTAGE);
  pinMode(START_PIN, DS_VOLTAGE);
}

/******buttonPress method****************************
Description: buttonPress takes a button location 
and sends a button press simulation signal to the nintendoDS
@Param a_nButton: pin number of button to press
@Patam a_uNuPresses: number of presses of button
***************************************************/
boolean buttonPress (unsigned int a_unButton, unsigned char a_ucNumPresses) {

  for (int iii = 1; iii <= a_ucNumPresses; iii++)  {
    //set specific pin to output voltage
    pinMode(a_unButton,OUTPUT);
    
    //write pin low to simulate pressing
    digitalWrite(a_unButton, LOW);
    delay(100);

    //reset pin back to input voltage
    pinMode(a_unButton,INPUT);   
    delay(250);
  } 
  return true;
}

/******validButtonPush method****************************
Description: takes in push command and calls press if valie
and sends press simulation to the nintendoDS
@Param a_cButton: pin number of button to press
@Patam a_numberPresses: number of presses of button
***************************************************///Description: isValidButon check if the command is a
//@Param a_nButton: pin numa_nButtonber of button to press
unsigned int ifValidButtonPush (char a_cButton) {
  //defaul it will press button
  boolean bPressStatus = true;
  
  switch (a_cButton){
      case 'L':
            buttonPress( LEFT_PIN,1);
      break;
        
      case 'R':
            buttonPress(RIGHT_PIN,1);
      break;

      case 'U':
            buttonPress( UP_PIN,1);
      break;
      
      case 'D':
            buttonPress( DOWN_PIN,1);
      break;

      case 'A':
            buttonPress(A_PIN ,1);
      break;
      
      case 'B':
            buttonPress(B_PIN ,1);
      break;
      
      case 'X':
            buttonPress(X_PIN ,1);
      break;

      case 'Y':
              buttonPress(Y_PIN ,1);
      break;
      
      case 'H':
            buttonPress( HOME_PIN,1);
      break;
      
      case 'E':
            buttonPress( SELECT_PIN,1);
      break;
      
      case 'S':
            buttonPress( START_PIN,1);
      break;
      default:
            bPressStatus = false;
      break;
    }
  return bPressStatus;
}

//Program's main loop
//Loop scanning for commands. Read commands,
//verify if they are buttons and simulation pressing on DS
void loop()
{
    //variable to store command from IRC
    char cInputCommand = ' ';

    // Ensure serial is not busy (checks if data has been sent before reading again)
    if(Serial.available()){ 
      
      // read the incoming data
      cInputCommand = Serial.read(); 
      
      //send command to push button
      ifValidButtonPush (cInputCommand);

      //TODO: Is this even necessary?
      //send the command back in a new line so that it is not all one long line
      Serial.println(cInputCommand); 
    }
    delay(100); // delay for 1/10 of a second
}
