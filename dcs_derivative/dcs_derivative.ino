/*
  Derivative (or difference in discrete domain). 
  
  Computes the derivative of a given quantity.  
  

  Connections:

  Connect the output of a potentiometer to pin analog pin A0.  
  
  -------------------------------------------------------------------------------
  
  This example code is in the public domain.

  modified 9 Feb 2018
  by Manoj Sharma
  
  @irahulone 

  -------------------------------------------------------------------------------
 
*/

const int analogPin = A0; // Wiper pin to this pin

float val    = 0;   // analog value 
float valDer = 0;   // derivative of analog value
float oldVal = 0;

float x1, x2;   // pos and velocity as states

const int T = 50; // sampling time in ms

unsigned long previousMillis = 0;   // time stamp 
unsigned long previousMillis1 = 0;  // time stamp

void setup() 
{
  Serial.begin(9600); 
}
void loop() 
{
  long int mil = millis();
  readValue();  // moving average filter
  //val = analogRead(analogPin);

  computeDer_and_Int();  

  x1 = val;
  x2 = valDer;
  
  Serial.print(x1); Serial.print(",");
  Serial.print(x2); //Serial.print(", ");
  Serial.println();
}



