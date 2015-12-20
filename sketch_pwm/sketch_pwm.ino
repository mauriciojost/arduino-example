int ledPin = 13;
int analogPin0 = A0;
int value = 0;
void setup() {
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
  TCCR2B = _BV(CS22);
  OCR2A = 180;
  OCR2B = 50;
}

void loop() {
  value = (value + 1) % 255;
  int i = 0;
  for (i = 0; i< 10000; i++) {
    analogWrite(ledPin, value);
    analogWrite(analogPin0, value);
  }
  Serial.print(value, HEX);
  Serial.print("\n");
}
