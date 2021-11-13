/**
 * Authors: Brianna Martinson and John Adkins
 * Project Completed on: July 13th, 2018
 * Department: Computing Department at ETSU
 * Summary: Programs an Arduino board to play notes via a buzzer by press of buttons
 */

#include "Notes.h" //Includes the Notes file
#define ACTIVATED LOW //Tells board to use low voltage

// The variables that represents the positive and negative ends of the buzzer
const int PIEZO = 11; // Positive side
const int LED = 13; // Negative side

// The variables that represent each button
const int BUTTON_C = 4;
const int BUTTON_D = 5;
const int BUTTON_E = 6;
const int BUTTON_F = 7;
const int BUTTON_G = 8;
const int BUTTON_A = 2;
const int BUTTON_B = 3;
const int BUTTON_SONG = 9;

void setup() //Sets up the values the board will use
{
  Serial.begin(9600); //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(LED, OUTPUT); //Tells the varible that it will be an output
  pinMode(BUTTON_C, INPUT); //Tells the varible that it will be an input
  digitalWrite(BUTTON_C,HIGH); //Sets the voltage the button will use
  pinMode(BUTTON_D, INPUT); //Tells the varibles that it will be an input
  digitalWrite(BUTTON_D,HIGH); //Sets the voltage the button will use
  pinMode(BUTTON_E, INPUT); //Tells the varible that it will be an input
  digitalWrite(BUTTON_E,HIGH); //Sets the voltage the button will use
  pinMode(BUTTON_F, INPUT); //Tells the varible that it will be an input
  digitalWrite(BUTTON_F,HIGH); //Sets the voltage the button will use
  pinMode(BUTTON_G, INPUT); //Tells the varible that it will be an input
  digitalWrite(BUTTON_G,HIGH); //Sets the voltage the button will use
  pinMode(BUTTON_A, INPUT); //Tells the varible that it will be an input
  digitalWrite(BUTTON_A,HIGH); //Sets the voltage the button will use
  pinMode(BUTTON_B, INPUT); //Tells the varible that it will be an input
  digitalWrite(BUTTON_B,HIGH); //Sets the voltage the button will use
  pinMode(BUTTON_SONG, INPUT); //Tells the varible that it will be an input
  digitalWrite(BUTTON_SONG,HIGH); //Sets the voltage the button will use
  
  digitalWrite(LED,LOW); //Sets the voltage the LED will use
}


// Different song
int melody[] = {
NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, -1, -1,
NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_D4, -1, -1, -1,
NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_D5,
NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_AS3, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_AS4, 
NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_G3, NOTE_G3, NOTE_AS3,


NOTE_AS4, NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4,  NOTE_C5, NOTE_AS4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_F4, -1, -1,
NOTE_DS4, NOTE_DS4, NOTE_F4, NOTE_D4, NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_F3, NOTE_AS3, NOTE_A3, NOTE_F3, 
NOTE_D4, NOTE_D4, NOTE_D4, NOTE_D5, NOTE_D5,
NOTE_G3, NOTE_AS3, NOTE_C4, NOTE_F3, NOTE_AS3, NOTE_G3, NOTE_AS4, NOTE_A4, NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_AS4, 

};

// Note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  
4.5, 2.25, 2.25, 4.5, 2.25, 2.25, 2.25, 2.25, 2.25, 4.5, 3, 9, 4.5, 
4.5, 2.25, 4.5, 2.25, 1.125, 2.25, 4.5, 
4.5, 2.25, 4.5, 2.25, 4.5, 2.25, 
4.5, 4.5, 4.5, 2.25, 4.5, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2, 
4.5, 4.5, 4.5, 2.25, 4.5, 4.5,

4.5, 2.25, 2.25, 4.5, 2.25, 2.25, 2.25, 2.25, 2.25, 4.5, 3, 9, 4.5, 
4.5, 2.25, 4.5, 4.5, 4.5, 4.5, 4.5, 4.5, 3, 3, 4.5, 
2.25, 4.5, 2.25, 4.5, 2.25, 
4.5, 4.5, 4.5, 4.5, 2.25, 4.5, 4.5, 2.25, 4.5, 2.25, 4.5, 2.25, 

};

// Notes for the mario theme
// -1 is a rest
int marioNotes[] = {
  NOTE_E4, NOTE_E4, -1, NOTE_E4, -1, NOTE_C4, NOTE_E4, -1, NOTE_G4, -1, NOTE_G3, -1,
  NOTE_C4, -1, NOTE_G3, -1, NOTE_E3, -1, NOTE_A3, NOTE_B3, NOTE_AS3, NOTE_A3, NOTE_G3, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_F4, NOTE_G4, 
  NOTE_E4, NOTE_C4, NOTE_D4, NOTE_B3,

  NOTE_C4, -1, NOTE_G3, -1, NOTE_E3, -1, NOTE_A3, NOTE_B3, NOTE_AS3, NOTE_A3, NOTE_G3, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_F4, NOTE_G4, 
  NOTE_E4, NOTE_C4, NOTE_D4, NOTE_B3,

  NOTE_G4, NOTE_FS4, NOTE_F4, NOTE_DS4, NOTE_E4, NOTE_GS3, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4,
  NOTE_F4, NOTE_DS4, NOTE_E4, NOTE_C5, -1 ,NOTE_C5, NOTE_C5, -1, NOTE_G4, NOTE_FS4, NOTE_F4, NOTE_DS4, NOTE_E4, NOTE_GS3, NOTE_A3, NOTE_C4,
  NOTE_A3, NOTE_C4, NOTE_D4, NOTE_DS4, -1, NOTE_D4, -1, NOTE_C4, -1,

  NOTE_G4, NOTE_FS4, NOTE_F4, NOTE_DS4, NOTE_E4, NOTE_GS3, NOTE_A3, NOTE_C4, NOTE_A3, NOTE_C4, NOTE_D4, NOTE_G4, NOTE_FS4, 
  NOTE_F4, NOTE_DS4, NOTE_E4, NOTE_C5, -1 ,NOTE_C5, NOTE_C5, -1, NOTE_G4, NOTE_FS4, NOTE_F4, NOTE_DS4, NOTE_E4, NOTE_GS3, NOTE_A3, NOTE_C4,
  NOTE_A3, NOTE_C4, NOTE_D4, NOTE_DS4, -1, NOTE_D4, -1, NOTE_C4

};

// Numbers with a .0 at the end are the durations for the rests
int marioDurations[] = {

4, 4, 4.0, 4, 4.0, 4, 4, 4.0, 2, 4.0, 2, 4.0,
4, 4, 4, 4, 4, 4, 4, 4, 8, 4, 3.5, 3.5, 3.5, 4, 4, 4, 
4, 4, 4, 4, 

4, 4, 4, 4, 4, 4, 4, 4, 8, 4, 3.5, 3.5, 3.5, 4, 4, 4, 
4, 4, 4, 4, 

4, 8, 4, 8, 4, 8, 4, 4, 4, 4, 4, 4, 8, 
4, 8, 4, 4, 12.0, 8, 8, 8.0, 4, 8, 4, 8, 4, 8, 4, 4,
4, 4, 4, 8, 4.0, 4, 4.0, 4, 2.0,

4, 8, 4, 8, 4, 8, 4, 4, 4, 4, 4, 4, 8, 
4, 8, 4, 4, 12.0, 8, 8, 8.0, 4, 8, 4, 8, 4, 8, 4, 4,
4, 4, 4, 8, 4.0, 4, 4.0, 4

};


void loop() //Loops the following code while the board has power
{
   while(digitalRead(BUTTON_C) == ACTIVATED) //When you press the button you labeled C, do the following
  {
    tone(PIEZO,NOTE_C4); // Tells the buzzer to play a C note in the fourth octave
    digitalWrite(LED,HIGH); // Lights up the LED on the board so you know the board recieved the input
  }
  while(digitalRead(BUTTON_D) == ACTIVATED) //When you press the button you labeled D, do the following
  {
    tone(PIEZO,NOTE_D4); // Tells the buzzer to play a D note in the fourth octave
    digitalWrite(LED,HIGH); // Lights up the LED on the board so you know the board recieved the input
  }

  while(digitalRead(BUTTON_E) == ACTIVATED) //When you press the button you labeled E, do the following
  {
    tone(PIEZO,NOTE_E4); // Tells the buzzer to play a E note in the fourth octave
    digitalWrite(LED,HIGH); // Lights up the LED on the board so you know the board recieved the input
  }

  while(digitalRead(BUTTON_F) == ACTIVATED) //When you press the button you labeled F, do the following
  {
    tone(PIEZO,NOTE_F4); // Tells the buzzer to play a F note in the fourth octave
    digitalWrite(LED,HIGH); // Lights up the LED on the board so you know the board recieved the input
  }
    
  while(digitalRead(BUTTON_G) == ACTIVATED) //When you press the button you labeled G, do the following
  {
    tone(PIEZO,NOTE_G4); // Tells the buzzer to play a G note in the fourth octave
    digitalWrite(LED,HIGH); // Lights up the LED on the board so you know the board recieved the input
  }

  while(digitalRead(BUTTON_A) == ACTIVATED) //When you press the button you labeled A, do the following
  {
    tone(PIEZO,NOTE_A3); // Tells the buzzer to play a A note in the third octave
    digitalWrite(LED,HIGH); // Lights up the LED on the board so you know the board recieved the input
  }

  while(digitalRead(BUTTON_B) == ACTIVATED) //When you press the button you labeled B, do the following
  {
    tone(PIEZO,NOTE_B3); // Tells the buzzer to play a B note in the third octave
    digitalWrite(LED,HIGH); // Lights up the LED on the board so you know the board recieved the input
  }

  if(digitalRead(BUTTON_SONG) == ACTIVATED) //Plays a song when you press the button you labed SONG
  {
    for (int thisNote=0; thisNote < 129; thisNote++) //Loops through the array of notes
    {
      int noteDuration = 600 / marioDurations[thisNote]; //The variable that uses the array that contains how long to play a note
      tone(PIEZO, marioNotes[thisNote]); //Tells the buzzer to play the current note in the array
      digitalWrite(LED,HIGH); // Lights up the LED on the board so you know the board recieved the input
      int pauseBetweenNotes = noteDuration * 1.50; //The variable used to identify the amount of time to pause the program
      delay(pauseBetweenNotes); //Pauses the program for the amount of time (in milliseconds) 
      noTone(11); // Stops the current note so it can play the next note
    }
   
  } 

  noTone(PIEZO); // Stops the buzzer's sound
  digitalWrite(LED,LOW); // Turns off the LED on the board so you know the board is done with the last recieved input

}
