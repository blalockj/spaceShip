/*
BreatherBox one servo


Head Topper
top = 0
bottom = 180 
hand plugs to pin 2
1M resistor


*/
//indicator LED
int top = 13;


//CapSensing setup

int capTopClip = 1024;  //max point that we are still reading cap values
int capBottomClip = 0;  //min point that we are reading cap values
int smooth = 2;


#include <CapacitiveSensor.h>
CapacitiveSensor cs_4_2 = CapacitiveSensor(4,2);
int sum; //for smoothing values



//reset button
int reSet = 12;

void setup(){
  Serial.begin(9600);

  pinMode(top, OUTPUT);
  pinMode(reSet, INPUT);
}

void loop() 
{ 
  int capTopClip = analogRead(0); 
  digitalWrite(reSet, LOW);
  //cap sensing
  long start = millis();
  long total1 =  cs_4_2.capacitiveSensor(30);  
  sum = (sum - (sum / smooth)) + ((total1) / smooth);  //smooth cap data
  
  
  int total2 = constrain(sum, 0, capTopClip);  //clips values, tighter means more movement


 
  
  if (sum >= capTopClip){
    digitalWrite(top, HIGH);
  }
  if (sum >= 2000){
    digitalWrite(reSet, HIGH);
  }
  else{}
 
  Serial.print("clip: ");
  Serial.print(capTopClip);  
  Serial.print("Capacit:  ");
  Serial.print(sum);
  Serial.print("\t");
  Serial.print("\n");
  
  
  delay(15);
  
}
 

