/**
 * Authors: Brianna Martinson
 * Project Completed on: July 11th, 2018
 * Department: Computing Department at ETSU
 * Summary: A simple program to sequentially turn on and turn off 3 LEDs
 */

// The variables that represent each LED
int LED1 = 13;
int LED2 = 12;
int LED3 = 11;

void setup() //Sets up the values the board will use
{
   pinMode(LED1, OUTPUT); //Tells the varible that it will be an output
   pinMode(LED2, OUTPUT); //Tells the varible that it will be an output
   pinMode(LED3, OUTPUT); //Tells the varible that it will be an output
}


void loop() //Loops the following code while the board has power
{
  digitalWrite(LED1, HIGH);    // turn on LED1 
  delay(200);                  // wait for 200ms
  digitalWrite(LED2, HIGH);    // turn on LED2
  delay(200);                  // wait for 200ms       
  digitalWrite(LED3, HIGH);    // turn on LED3 
  delay(200);                  // wait for 200ms
  digitalWrite(LED1, LOW);     // turn off LED1
  delay(300);                  // wait for 300ms
  digitalWrite(LED2, LOW);     // turn off LED2
  delay(300);                  // wait for 300ms
  digitalWrite(LED3, LOW);     // turn off LED3
  delay(300);                  // wait for 300ms before running program all over again
}
