const int relayPin = 2;  // choose a pin for the relay

void setup() {
  pinMode(relayPin, OUTPUT);  // set the relay pin as an output
}

void loop() {
  // turn the relay on at 6 PM (18:00 hours)
  if (hour() >= 18 && minute() == 0) {
    digitalWrite(relayPin, HIGH);  // turn the relay on (and the street light)
  }

  // turn the relay off at 6 AM (06:00 hours)
  if (hour() == 6 && minute() == 0) {
    digitalWrite(relayPin, LOW);  // turn the relay off (and the street light)
  }

  delay(1000);  // wait for 1 second before checking again
}

// function to get the current hour
int hour() {
  return (millis() / 3600000) % 24;
}

// function to get the current minute
int minute() {
  return (millis() / 60000) % 60;
}


