
 const int sensor=A0;
 int sensor_state;
 const int trigPinr = 7;
  const int echoPinr = 6; 
  long durationr;
  int distancer;
 void setup()
{
   pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(trigPinr, OUTPUT); 
  pinMode(echoPinr, INPUT);
  pinMode(A0,INPUT);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(trigPinr, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPinr, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinr, LOW);
  durationr = pulseIn(echoPinr, HIGH);
  distancer= durationr*0.034/2;
  Serial.print("Distancer: ");
  Serial.println(distancer);

   if( distancer <10) //IF ONLY CENTER DETECTED
     {
     digitalWrite (9,HIGH);
     }
     else if( distancer >11) //IF ONLY CENTER DETECTED
     {
     digitalWrite (9,LOW);
     }

  sensor_state=digitalRead(sensor);
 if(  sensor_state == LOW)
{
  Serial.println("GATE OPEN");

digitalWrite(8,HIGH);             
}
 
 else if(  sensor_state==HIGH)
{
  Serial.println("GATE CLOSE");

digitalWrite(8,LOW);
 
}

}
