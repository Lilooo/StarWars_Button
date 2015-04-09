/*
 Melody Star Wars
 with LilyPad Arduino Protosnap
 */
 
#include "pitches.h"

int speakerPin = 7;
int buttonPin = A5;
int leds[] = {5,6,A2,A4,A3};
int i = 0;

int music[19][3] = {
  {NOTE_F4, 200, 200},  
  {NOTE_F4, 200, 200},
  {NOTE_F4, 200, 200},
  {NOTE_AS4, 1200, 1200},
  {NOTE_F5, 600, 600},
  {NOTE_DS5, 200, 200},
  {NOTE_D5, 200, 200},
  {NOTE_C5, 200, 200},
  {NOTE_AS5, 1200, 1200},
  {NOTE_F5, 600, 600},
  {NOTE_DS5, 200, 200},
  {NOTE_D5, 200, 200},
  {NOTE_C5, 200, 200},
  {NOTE_AS5, 1200, 1200},
  {NOTE_F5, 600, 600},
  {NOTE_DS5, 200, 200},
  {NOTE_D5, 200, 200},
  {NOTE_DS5, 200, 200},
  {NOTE_C5, 900, 1200}
  };
  
void play_tone() {
      tone(speakerPin, music[i][0], music[i][1]);
      delay(music[i][2]);
      i++;      
      noTone(7);
}

void reset_led() {
  digitalWrite(leds[0], LOW);
  digitalWrite(leds[1], LOW);
  digitalWrite(leds[2], LOW);
  digitalWrite(leds[3], LOW);
  digitalWrite(leds[4], LOW);
}

void setup() {
  Serial.begin(9600);
  for (int i = 0; i <= 4; i++) {
     // Serial.println(leds[i]);
     pinMode(leds[i], OUTPUT);
  }
  pinMode(speakerPin, OUTPUT);
  pinMode(buttonPin, INPUT); 
  digitalWrite(buttonPin, HIGH);
}

void loop() {
  if(digitalRead(buttonPin) == 0)
   {
     int y = 0;
     for (int i = 0; i < 19; i++)
     {
       if (music[i] != 0)
       {
         // Serial.println(leds[y]);
         digitalWrite(leds[y], HIGH);
         y++;
         if (y > 4)
           y = 0;
       }
       play_tone();
       reset_led();
     }
     i = 0;
   } else {
     digitalWrite(speakerPin, LOW);
   }
 }
