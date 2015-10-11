/*
  AnalogReadSerialToBlinkMilli
  Reads an analog input on pin 0, prints the result to the serial monitor and the pin 13 LED.
  loop() uses a statemachine as in [1] to make concurrent processes possible.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.

 1. https://learn.adafruit.com/multi-tasking-the-arduino-part-1?view=all
 */

int ledState = HIGH;
int ledPin = 13;
unsigned long previousMillis;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  unsigned long currentMillis = millis();
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0) + 1;
  // print out the value you read:
  Serial.println(sensorValue);
  if ((ledState == HIGH) && (currentMillis - previousMillis >= sensorValue)) {
    ledState = LOW;  // Turn it off
    previousMillis = currentMillis;  // Remember the time
    digitalWrite(ledPin, ledState);  // Update the actual LED
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= sensorValue))  {
    ledState = HIGH;  // turn it on
    previousMillis = currentMillis;   // Remember the time
    digitalWrite(ledPin, ledState);   // Update the actual LED
  }//  delay(1);        // delay in between reads for stability
}
