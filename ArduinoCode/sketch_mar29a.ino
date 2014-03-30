int LeftPin = 24;      // LED connected to digital pin 9
int RightPin = 26;
int UpPin = 30;
int DownPin =28 ;
int A_Pin= 40;
int B_Pin= 38;
int X_Pin = 42;
int Y_Pin = 44;
int HomePin= 32;
int SelectPin=36 ;
int StartPin= 34;

int DS_Voltage = INPUT; //92 corresponds to 1.81V
void setup()
{
  pinMode(LeftPin, DS_Voltage);  // analogRead values go from 0 to 1023, pinMode values from 0 to 255
  pinMode(RightPin, DS_Voltage);
  pinMode(UpPin, DS_Voltage);
  pinMode(DownPin, DS_Voltage);
  pinMode(A_Pin, DS_Voltage);
  pinMode(B_Pin, DS_Voltage);
  pinMode(X_Pin, DS_Voltage);
  pinMode(Y_Pin, DS_Voltage);
  pinMode(HomePin, DS_Voltage);
  pinMode(SelectPin, DS_Voltage);
  pinMode(StartPin, DS_Voltage); 
}

int Move(int button,int numsteps){
   for (int thisPin = 1; thisPin <= numsteps; thisPin++)  {
    pinMode(button,OUTPUT);
    digitalWrite(button, LOW);
    delay(100);
    pinMode(button,INPUT);
    delay(250);
  }  
}

void loop()

{
  Move(RightPin,1);
  Move(LeftPin,1);
  Move(DownPin,2);
  Move(UpPin,2);

  
  
} 
