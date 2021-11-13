/* How to use the HC-SR04 Ultrasonic Sensor with Arduino 
   Dev: Michalis Vasilakis // Date: 23/7/2015 // www.ardumotive.com */

//Libraries
#include "Ultrasonic.h"
#include <Servo.h>

//Define pins ultrasonic(trig,echo)
Ultrasonic ultrasonic(A0,A1);

//Variables
int distance;
int servoPin = 3;
Servo Servo1;
const int buzzer = 4;

// The variables that represent each LED
int LED_B = 8;
int LED_Y = 9;
int LED_R = 10;

void setup() {
  Serial.begin(9600);
  Servo1.attach(servoPin);
  pinMode(LED_B, OUTPUT); //Tells the varible that it will be an output
  pinMode(LED_Y, OUTPUT); //Tells the varible that it will be an output
  pinMode(LED_R, OUTPUT); //Tells the varible that it will be an output
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  distance = ultrasonic.Ranging(INC); //Use 'CM' for centimeters or 'INC' for inches
  //Print distance...
  Serial.print("Object found at: ");
  Serial.print(distance);
  Serial.println("in");
  //every .5 sec. 
  delay(500);
  if (distance < 10)
  {
    digitalWrite(LED_R, LOW);    // turn on LED1
    digitalWrite(LED_Y, LOW);    // turn on LED1
    digitalWrite(LED_B, HIGH);    // turn on LED1
    Servo1.write(0); 
    tone(buzzer, 1000);
    delay(500);
  }
  else if(distance < 50)
  {
    digitalWrite(LED_R, LOW);    // turn on LED1
    digitalWrite(LED_B, LOW);    // turn on LED1
    digitalWrite(LED_Y, HIGH);    // turn on LED1
    Servo1.write(90);
    tone(buzzer, 500);
    delay(500);
  }
  else
  {
    digitalWrite(LED_B, LOW);    // turn on LED1
    digitalWrite(LED_Y, LOW);    // turn on LED1
    digitalWrite(LED_R, HIGH);    // turn on LED1
    Servo1.write(180);
    tone(buzzer, 200);
    delay(500);
  } 
  noTone(buzzer);
}
