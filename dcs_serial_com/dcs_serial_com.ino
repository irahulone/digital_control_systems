/*
  Moving Average Filter. 
  
  Example to implement a real time moving average filter, using a potentiometer
  as an input to the system.  
  

  Connections:

  Connect the output of a potentiometer to pin A0.  
  
  -------------------------------------------------------------------------------
  
  This example code is in the public domain.

  modified 9 Feb 2018
  by Manoj Sharma
  
  @irahulone 

  -------------------------------------------------------------------------------
  
*/

int input = 0;
int input2 = 0;
int light_intensity = 0;

void setup() 
{
  Serial.begin(9600); // To open the serial port at 9600bps
  
  pinMode(9, OUTPUT); // bulb
  pinMode(13, OUTPUT);
}

void loop() 
{
  if(Serial.available()) // cleck for any incoming serial data
  {
    input = Serial.parseInt(); // read a valid char, and convert it to integer
    input2 = Serial.parseInt();
    
    Serial.print(input); Serial.print("  "); Serial.print(input2);
    Serial.println();
  }

  analogWrite(9,input);
  digitalWrite(13,input2);

}


