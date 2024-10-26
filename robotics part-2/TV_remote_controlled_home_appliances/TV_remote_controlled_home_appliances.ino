#include <IRremote.h>

#define IR_RECEIVE_PIN 3

#define IR_BUTTON_1 12
#define IR_BUTTON_2 24
#define IR_BUTTON_3 94
#define IR_BUTTON_POWER 69
#define r1 10
int relay1 = LOW;
#define r2 11
int relay2 = LOW;
#define r3 12
int relay3 = LOW;

void setup() {
  Serial.begin(115200);
  IrReceiver.begin(IR_RECEIVE_PIN);
   pinMode(r1, OUTPUT); 
    pinMode(r2, OUTPUT);
    pinMode(r3, OUTPUT);  
}

void loop() {
  if (IrReceiver.decode()) {
    IrReceiver.resume();
    int command = IrReceiver.decodedIRData.command;
    switch (command) {
      case IR_BUTTON_1: {
        Serial.println("Pressed on button 1");
         relay1 = ~ relay1;
            digitalWrite(r1,relay1);
            delay(250);
        break;
      }
      case IR_BUTTON_2: {
        Serial.println("Pressed on button 2");
         relay2 = ~ relay2;
            digitalWrite(r2,relay2);
            delay(250);
        break;
      }
      case IR_BUTTON_3: {
        Serial.println("Pressed on button 3");
         relay3 = ~ relay3;
            digitalWrite(r3,relay3);
            delay(250);
        break;
      }
      case IR_BUTTON_POWER: {
        Serial.println("Pressed on power");
        digitalWrite(r1,0);
            digitalWrite(r2,0);  //all off
            digitalWrite(r3,0);
            delay(250);
        break;
      }
      default: {
        Serial.println("Button not recognized");
      }
    }
  }
}
