int LED = 7;
int flame_sensor = 4;
int flame_detected;
void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(flame_sensor, INPUT);
}
void loop()
{
  flame_detected = digitalRead(flame_sensor);
  if (flame_detected == 1)
  {
    Serial.println("Flame detected...! take action immediately.");
    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);
  }
  else
  {
    Serial.println("No flame detected. stay cool");
    digitalWrite(LED, LOW);
  }
  delay(1000);
}
