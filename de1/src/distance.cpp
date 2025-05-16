#include <distance.h>

void initDistance() {
    pinMode(TRIG, OUTPUT); // Sets the trigPin as an Output
    pinMode(ECHO, INPUT); // Sets the echoPin as an Input
}

int getDistance() {
    // Clears the trigPin
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(ECHO, HIGH);
  
  // Calculate the distance
  float distanceCm = duration * SOUND_SPEED/2;
  return (int)distanceCm;
}