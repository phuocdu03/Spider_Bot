#include "BluetoothSerial.h" //Thư viện cho Bluetooth ESP32

BluetoothSerial SerialBT;

const int ledPin = 2;
char c, temp;
void setup(){
  SerialBT.begin("ESP32-Bluetooth");//Tên Bluetooth ESP32, có thể thiết lập tên khác
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  if (SerialBT.available()){//sau khi có sự thay đổi (nhấn nút) / truyền gửi Bluetooth
    c = SerialBT.read(); //Đọc data từ APP
    switch (c) {
      case 'U':
        Serial.println("UP");
        Serial.println(c);
        digitalWrite(ledPin, HIGH);
        break;
      case 'D':
        Serial.println("DOWN");
        Serial.println(c);
        digitalWrite(ledPin, LOW);
        break;
      case 'L':
        Serial.println("LEFT");
        Serial.println(c);
        digitalWrite(ledPin, HIGH);
        break;
      case 'R':
        Serial.println("RIGHT");
        Serial.println(c);
        digitalWrite(ledPin, LOW);
        break;
      case '1'://Chào tay trái
        Serial.println("SHAKELEFT");
        Serial.println(c);
        digitalWrite(ledPin, HIGH);
        break;
      case '2'://Chào tay phải
        Serial.println("SHAKERIGHT");
        Serial.println(c);
        digitalWrite(ledPin, LOW);
        break;
      case '3'://SIT
        Serial.println("SIT");
        Serial.println(c);
        digitalWrite(ledPin, HIGH);
        break;
      case '4'://STAND
        Serial.println("STAND");
        Serial.println(c);
        digitalWrite(ledPin, LOW);
        break;
      default: 
        Serial.println("NO");
        Serial.println(c);
    }
  }else{
    switch(c){
      case 'u':
        Serial.println("UP");
        Serial.println(c);
        digitalWrite(ledPin, HIGH);
        delay(1000);
        break;
      case 'd':
        Serial.println("DOWN");
        Serial.println(c);
        digitalWrite(ledPin, LOW);
        break;
      case 'l':
        Serial.println("LEFT");
        Serial.println(c);
        digitalWrite(ledPin, HIGH);
      case 'r':
        Serial.println("RIGHT");
        Serial.println(c);
        digitalWrite(ledPin, LOW);
        break;
      default:
        Serial.println("NO");
        Serial.println(c);
        delay(1000);}
  }
}