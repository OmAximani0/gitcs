int light_pin = 5;

void setup() {
    pinMode(light_pin, INPUT);
    Serial.begin(9600);
}

void loop() {
    int light_data = digitalRead(light_pin);

    if (light_data == 1)
        Serial.println("Light not detected!");        
    else
        Serial.println("Light Detected!");        
    delay(1000);
}
