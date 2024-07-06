#include <SoftwareSerial.h>

#define LED 13

unsigned long int time=0;

void setup() {
  // Open serial communications and wait for port to open:
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.begin(9600);
}

void loop() 
{ 
  if((millis()-time)>1000)
  {
    time = millis();
    Serial.println("D*1*2*3*4*");
  }
  
  if (Serial.available()) 
  {
    String rx = Serial.readString();
    rx.replace("\n","");
    if(rx.equalsIgnoreCase("1"))
    {
      digitalWrite(LED, HIGH);
      Serial.println("LED ON");
    }
    else if(rx.equalsIgnoreCase("0"))
    {
      Serial.println("LED OFF");
      digitalWrite(LED,LOW);
    }
  }

}
