

////////////////////////// read the value /////////////////////////////////////////////

int valAr[20];  // Specify the window size here

void readValue()
{
  int p = sizeof(valAr)/sizeof(int);  // window size

  // shift all the values to the left
  for(int i = 2; i <= p; i++)
  {
    valAr[i-1] = valAr[i];
  }
  // assign the newest value to the end
  valAr[p] = analogRead(analogPin);

  // compute the mean
  float a = 0;
  for(int i = 1; i <= p; i++)
  {
    a += valAr[i];
  }
  a = a/p;
  val = a;
}

/////////////////////////// compute derivative and integrals ////////////////
void computeDer_and_Int()
{
  unsigned long currentMillis1 = millis();
  if (currentMillis1 - previousMillis1 >= T) 
  {
    previousMillis1 = currentMillis1;
    oldVal = val;
  }
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 2*T) 
  {
    previousMillis = currentMillis; 
    //val = analogRead(analogPin);
    readValue();
    valDer = (val - oldVal)*(1);
  }
  valDer = lpf(valDer);
}

////////////////////////// low pass filter /////////////////////////////////
int lpfAr[20];

float lpf(float input)
{
  int p = sizeof(lpfAr)/sizeof(int);  // window size
  lpfAr[p] = input;
  float a = 0;  
  for(int i = 1; i <= p; i++)
  a += lpfAr[i];
  a = a/p;
  for(int i = 2; i <= p; i++)
  lpfAr[i-1] = lpfAr[i];
  return a;
}
