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


const int window_size = 100;  // define the window size.

const int refPosPin = A0;     // input pin 

int refPosAr[window_size];


float ref = 0;

void setup() 
{
  Serial.begin(9600);
}


void loop() 
{
  
  int p = sizeof(refPosAr)/sizeof(int);  // compute window size
  refPosAr[p] = analogRead(refPosPin);

  float a = 0;
  for(int i = 1; i <= p; i++)
  {
    a += refPosAr[i];
  }
  a = a/p;
  ref = a;
  
  for(int i = 2; i <= p; i++)
  {
    refPosAr[i-1] = refPosAr[i];
  }
  

  Serial.println(ref);
  
}




