#include <Servo.h>. 
const int trigPin = 8;
const int echoPin = 9;
const int led = 4;
long timetaken;
int objectdistance;
int pos = 0;
Servo servo1; 
void setup() {
  pinMode(led, OUTPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  servo1.attach(7); 
  digitalWrite(led, HIGH); 
}
void loop() {

  
  for(pos = 0; pos < 180; pos++) 
  {                                  
    servo1.write(pos);              
    delay(50);
     objectdistance = distance();
     if (10<objectdistance<15)
     {
  digitalWrite(led, LOW);    
  delay(1000); 
 digitalWrite(led, HIGH);
                
     
  }else if ( 0<objectdistance<10)
  
  {
    servo1.write(pos);              
    delay(5000);
    for(pos = 0; pos < 5; pos++) {
    digitalWrite(led, LOW);    
  delay(100); 
 digitalWrite(led, HIGH);
 
  }
  Serial.print(pos);
 Serial.print("here something");
  
  }
  else continue;
  }
  for(pos = 180; pos>=1; pos-=1)     
  {                               
    servo1.write(pos);              
    delay(40);   
    objectdistance= distance();
    if (10<objectdistance<15)
     {
  digitalWrite(led, LOW);    
  delay(1000); 
 digitalWrite(led, HIGH);
                
     
  }else if ( 0<objectdistance<10)
  
  {
    servo1.write(pos);              
    delay(5000);
    for(pos = 0; pos < 5; pos += 1) {
    digitalWrite(led, LOW);    
  delay(100); 
 digitalWrite(led, HIGH);
    }
     Serial.print(pos);
 Serial.print("here something");
 Serial.print(objectdistance);
    Serial.print("cm");

  }
  
   else continue;
       
    Serial.print(objectdistance);
    Serial.print("cm");
    Serial.print(",");
     
  
}


}
int distance(){ digitalWrite(trigPin, LOW); 
  delayMicroseconds(5);
   digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
   
   timetaken = pulseIn(echoPin, HIGH); 
 int objectdistanced = (timetaken*0.034/2);

     return objectdistance;

}
