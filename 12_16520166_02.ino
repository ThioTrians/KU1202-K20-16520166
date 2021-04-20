#include <Servo.h>
Servo servo_0;  //deklarasi servo yang dipakai
const int servoPin = 7; // pin arduino yg connect ke servo 0
const int ledPin =2; // pin led yg terhubung
int pos = 0; // variabel penyimpan nilai posisi(derajat)

void setup()
{
  pinMode(ledPin, OUTPUT); //pin sebagai output
  servo_0.attach(servoPin); //lokasi servo dipasang
  servo_0.write(pos); // inisialisasi posisi awal servo 0
}

void loop()
{
  digitalWrite(2, HIGH);
  for (pos = 0; pos <= 90; pos += 1){
    servo_0.write(pos);
    delay(15);
  }
  delay(2000);
  
  digitalWrite(2, LOW);
  for (pos = 90; pos >= 0; pos -+ 1) {
    servo_0.write(pos);
    delay(15);
  }
  delay(2000);
}
  