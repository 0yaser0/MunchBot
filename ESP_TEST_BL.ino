#include <BluetoothSerial.h>
BluetoothSerial SerialBT;

// Motor del bab
 
int enA = 4;
int in1 = 15;
int in2 = 2;

void Up() {
  digitalWrite(in1, 1);
  digitalWrite(in2, 0);
  analogWrite(enA, 200);
}

void Down() {
  digitalWrite(in1, 0);
  digitalWrite(in2, 1);
  analogWrite(enA, 200);
}
void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_MunchBot");
  Serial.println("The device started, now you can pair it with bluetooth!");

  // Set all the motor control pins to outputs
 
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}


void loop() {
  if (SerialBT.available()) {
    char incomingChar = SerialBT.read();
    if (incomingChar == '1') {
      Down();
      delay(800);
      Up();
      delay(800);
    }
  }
}
