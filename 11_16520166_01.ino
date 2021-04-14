const int pingPin = 7; // pin Arduino yang akan membaca output sensor

void setup() {
Serial.begin(9600); //memulai port serial
}

void loop() {
  long duration, cm; // Delay a little bit to improve simulation performance
  
  pinMode (pingPin, OUTPUT);  // atur pin sebagai output
  digitalWrite (pingPin, LOW); //beri sinyal awal LOW
  delayMicroseconds(2); //jeda 2 mikrosekon
  digitalWrite (pingPin, HIGH); //trigger sensor dengan sinyal HIGH
  delayMicroseconds (5); // trigger sensor selama 5 mikrosekon
  digitalWrite (pingPin, LOW); // beri sinyal low
  
  pinMode (pingPin, INPUT); // atur pin sebagai input
  duration = pulseIn (pingPin, HIGH); // sinyal HIGH untuk dapat durasi (dalam mikrosekon)
  cm = microsecondsToCentimeters (duration); // konversi mikro ke centi
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
}

long microsecondsToCentimeters (long microseconds) {
  // kecepatan suara 340 m/s atau 29 mikrosekon/cm
  // dibagi dua untuk mencari jatak sensor-objek
  return microseconds / 29 / 2;
}