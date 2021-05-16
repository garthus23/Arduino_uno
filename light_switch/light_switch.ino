int ledPin = 5;
int buttonpin = 9;
int light = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonpin, INPUT_PULLUP);  
}

void loop() {
  if (digitalRead(buttonpin) == LOW && light == 0)
  {
        digitalWrite(ledPin, HIGH);
        light = 1;
        delay(500);
  }
  else if (digitalRead(buttonpin) == LOW && light == 1)
  {
        digitalWrite(ledPin, LOW);
        light = 0;
        delay(500);
  }
}
