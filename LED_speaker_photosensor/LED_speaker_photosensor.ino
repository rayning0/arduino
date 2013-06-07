/* Modified code from Chp. 1 of "Arduino Cookbook" by Michael Margolis
   Connected photosensor, speaker, and potentiometer to Arduino and breadboard
   Based on light intensity on photosensor, LED will change blink rate
   and speaker will change frequency. 
   
   More light means LED blinks faster and speaker makes higher frequency sound
*/

const int outputPin = 9; // speaker pin
const int ledPin = 13; // LED connected to digital pin 13 
const int sensorPin = 0; // connect photosensor to analog input 0 
const int sminDuration = 1; // 1 ms on, 1 ms off (500 Hz) - higher pitch
const int smaxDuration = 10; // 10 ms on, 10 ms off (50 Hz)
const int lminDuration = 10; // min duration for LED
const int lmaxDuration = 300;

void setup() { 
  pinMode(outputPin, OUTPUT); // enable output on the speaker pin 
  pinMode(ledPin, OUTPUT); // output on LED pin
  Serial.begin(9600); 
} 

void loop() { 
  int sensorReading = analogRead(sensorPin); // read photosensor input 
  int lrate = map(sensorReading, 200, 800, lminDuration, lmaxDuration);
  lrate = constrain(lrate, lminDuration, lmaxDuration);
  int srate = map(sensorReading, 200, 800, sminDuration, smaxDuration);
  srate = constrain(srate, sminDuration, smaxDuration);
  
  Serial.print("lrate = ");
  Serial.println(lrate);
  Serial.print("srate = ");
  Serial.println(srate);
  
  digitalWrite(ledPin, HIGH); // turn LED on
  delay(lrate); // wait time dependent on light on photosensor
  digitalWrite(ledPin, LOW); // turn LED off
  delay(lrate);
  digitalWrite( outputPin, HIGH); // turn the speaker on 
  delay(srate); // wait time dependent on photosensor 
  digitalWrite( outputPin, LOW); // turn the speaker off 
  delay(srate);
}

