
#include <Keypad.h>  
#include <Servo.h>
#define ROW_NUM    4  
#define COLUMN_NUM 4  
#define SERVO_PIN  A0 
Servo servo; // servo motor
char keys[ROW_NUM][COLUMN_NUM] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte pin_rows[ROW_NUM] = {9, 8, 7, 6}; 
byte pin_column[COLUMN_NUM] = {5, 4, 3, 2}; 
Keypad keypad = Keypad( makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM );
const String password_1 = "555"; 
const String password_2 = "123";   
const String password_3 = "ABCD";
const String password_4 = "111";
String input_password;
int angle = 0; // the current angle of servo motor
unsigned long lastTime;
void setup() {
  Serial.begin(115200);
   
  pinMode( 10, OUTPUT);
  pinMode( 13, OUTPUT);
  input_password.reserve(32); 
  servo.attach(SERVO_PIN);
  servo.write(0); 
  lastTime = millis();
}
void loop() {

  char key = keypad.getKey();
  if (key) {
    Serial.println(key);
    if (key == '*') {
      input_password = ""; // reset the input password
    } else if (key == '#') {
      if (input_password == password_1 || input_password == password_2 || input_password == password_3 || input_password == password_4) {
        Serial.println("The password is correct, rotating Servo Motor to 90°");
        angle = 90;
        servo.write(angle);
        lastTime = millis();
      } else {
        Serial.println("The password is incorrect, try again");
        digitalWrite( 10, HIGH);
        delay(2000);
         digitalWrite( 10, LOW);
         delay(1000);
      }

      input_password = ""; // reset the input password
    } else {
      input_password += key; // append new character to input password string
    }
  }

  if (angle == 90 && (millis() - lastTime) > 5000) 
  {
    angle = 0;
    servo.write(angle);
    Serial.println("Rotating Servo Motor to 0°");
  }
 
 
}
