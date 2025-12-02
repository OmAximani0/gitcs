int relay = 8;

void setup() {
    pinMode(relay, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(relay, HIGH);
    delay(1000);
    Serial.println("Relay is ON");

    digitalWrite(relay, LOW);
    delay(1000);
    Serial.println("Relay is OFF");
}
