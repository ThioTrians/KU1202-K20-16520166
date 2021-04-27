#include <LiquidCrystal.h>
#include <math.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
const int pingPin = A1;
long timeDiff, distance;
int shift;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("PING Sensor");
}

void loop()
{
  distance = getDistanceFromPINGSensor();
  lcd.setCursor(0, 1);
  lcd.print("Jarak : ");

  lcd.setCursor(8, 1);
  lcd.print("      ");
  lcd.setCursor(8, 1);
  if (distance != 336) {
    shift = getShift(distance);
    lcd.print(distance);
    lcd.setCursor(8 + shift, 1);
    lcd.print("cm");
  } else {
    lcd.print("N/A");
  }
}

long getDistanceFromPINGSensor() {
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  timeDiff = pulseIn(pingPin, HIGH);
  distance = timeDiff / 58;
  return distance;
}

int getShift(long distance) {
  int i = 1;
  while (distance >= pow(10, i - 1)) {
    i++;
  }
  return i;
}