#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

#define SERVICE_UUID "7d016a09-ee69-4a7f-95bd-31e9d7e27387"

const int enA = 4;
const int in1 = 2;
const int in2 = 15;

void Up() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  analogWrite(enA, 200);
  Serial.println("Up");
}

void Down() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  analogWrite(enA, 200);
  Serial.println("Down");
}

void Stop() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  Serial.println("Stop");
}

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_MunchBot");
  Serial.println("The device started, now you can pair it with Bluetooth!");

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop() {
  if (SerialBT.available()) {
    char incomingChar = SerialBT.read();
    if (incomingChar == 'A') {
      Serial.print("Received: ");
      Serial.println(incomingChar);
      dropFood();
    } else {
      Serial.print("Incoming Char not A: ");
      Serial.println(incomingChar);
    }
  }
}

void dropFood() {
  Down();
  delay(650);
  Up();
  delay(650);
  Stop();
}
