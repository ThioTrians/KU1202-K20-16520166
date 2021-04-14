int sensePin = A0;  // pin arduino yang akan membaca output sensor
int sensorInput;  // variabel untuk menyimpan nilai output sensor
double temp; // variabel untuk menyimpan nilai suhu (celcius)

void setup()
{
  Serial.begin(9600); // memulai port serial
}

void loop()
{
  sensorInput = analogRead (sensePin); // baca sensor analog
  temp = (double)sensorInput / 1024; //hitung persentase dari pembacaan input
  temp = temp * 5;   // dikali dengan 5V untuk dapat nilai tegangan
  temp = temp - 0.5;   // dikurangi dengan offset
  temp = temp * 100;   // konversi menjadi derajat celsius
  
  Serial.print("Suhu: ");
  Serial.print(temp);
  Serial.print(" Celsius");
}