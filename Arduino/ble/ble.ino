#include <SoftwareSerial.h>
SoftwareSerial serial(3,4);
int ledPin = 13;

void setup() {
  serial.begin(9600);
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);

}


void loop()
{
  
  String i;
  if (serial.available()){
      i=serial.readString();
      Serial.println("DATA RECEIVED:"+i);
      
    if(i=="on"){
      digitalWrite(ledPin,1);
      Serial.println("led on");
      serial.write("Has on");
    }else if(i=="off")
    {
      digitalWrite(ledPin,0);
      Serial.println("led off");
      serial.write("Has off");
    }else{
      serial.write("Hi there");
    }
  }
}
