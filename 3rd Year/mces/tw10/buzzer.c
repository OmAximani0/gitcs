int buzzer = 9;

void setup() {
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(buzzer, HIGH);
    Serial.println("Buzzer is ON");
    delay(1000);
    digitalWrite(buzzer, LOW);
    Serial.println("Buzzer is OFF");
    delay(1000);
}
