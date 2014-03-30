//Pin map stucture to location of pins
struct PINMAP  {
  const int LEFT_PIN = 24;      // LED connected to digital pin 9
  const int RIGHT_PIN = 26;
  const int UP_PIN 30;
  const int DOWN_PIN =28 ;
  const int A_PIN = 40;
  const int B_PIN = 38;
  const int X_PIN = 42;
  const int Y_PIN = 44;
  const int HOME_PIN = 32;
  const int SELECT_IN = 36;
  const int START_PIN = 34;
};

//Set global INPUT voltage constant
const int DS_VOLTAGE = INPUT; //92 corresponds to 1.81V

//setup method: standard arduino method for
//initial setup
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
  pinMode(LEFT_PIN DS_VOLTAGE);  
  pinMode(RIGHT_PIN, DS_VOLTAGE);
  pinMode(UP_PIN, DS_VOLTAGE);
  pinMode(DOWN_PIN, DS_VOLTAGE);
  pinMode(B_PIN DS_VOLTAGE);
  pinMode(X_PIN, DS_VOLTAGE);
  pinMode(Y_PIN, DS_VOLTAGE);
  pinMode(HOME_PIN, DS_VOLTAGE);
  pinMode(SELECT_PIN, DS_VOLTAGE);
  pinMode(START_PIN, DS_VOLTAGE);

}

//buttonPress method
//Description: buttonPress takes a button location and sends
//press simulation to the nintendoDS
//@Param a_button: pin number of button to press
//@Patam a_numberPresses: number of presses of button
int buttonPress (int a_button, int a_numPresses) {

  for (int iii = 1; iii <= a_numPresses; iii++)  {
    
    //set specific pin to output voltage
    pinMode(a_button,OUTPUT);
    
    //write pin low to simulate pressing
    digitalWrite(a_button, LOW);
    delay(100);

    //reset pin back to input voltage
    pinMode(a_button,INPUT);   
    delay(250);

  } 
}

//buttonPress method
//Description: isValidButon check if the command is a
//valid button and returns true
//@Param a_button: pin number of button to press
//@Patam a_numberPresses: number of presses of button
boolean isValidButton (char a_button) {
  
  boolean bStatus = false;
  //TODO: add the other cases
  if (a_button== LEFT_PIN ) {
    bStatus = true;
  }

  return bStatus;
}


//Program's main loop
//Loop scanning for commands. Read commands,
//verify if they are buttons and simulation pressing on DS
void loop()
{
    //variable to store command from IRC
    char inCommand = ' ';

    // Ensure serial is not busy (checks if data has been sent before reading again)
    if(Serial.available()){ 
      
      // read the incoming data
      inCommand = Serial.read(); 
      
      //check if command is valid
      if (isValidButton(inCommand) ) {
        buttonPress(inCommand,1);
      }

      //TODO: Is this even necessary?
      //send the command back in a new line so that it is not all one long line
      Serial.println(inByte); 
    }

    delay(100); // delay for 1/10 of a second
}

