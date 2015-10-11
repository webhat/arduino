/*
  AnalogReadSerialToBlink
  Reads an analog input on pin 0, prints the result to the serial monitor and blink pin 13 LED.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
    pinMode(13, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0) + 1;
  // print out the value you read:
  Serial.println(sensorValue);
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(sensorValue);
  digitalWrite(13, LOW);
  delay(sensorValue);
//  delay(1);        // delay in between reads for stability
}
