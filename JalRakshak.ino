#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER_PIN 8

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    Serial.println("Sensor reading error");
    digitalWrite(BUZZER_PIN, LOW);
  } else {
    float distance = duration * 0.0343 / 2;
    Serial.print("Water distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance <= 5) {
      digitalWrite(BUZZER_PIN, HIGH);
      Serial.println("WARNING: Tank is almost full!");
    } else {
      digitalWrite(BUZZER_PIN, LOW);
    }
  }
  delay(1000);
}
