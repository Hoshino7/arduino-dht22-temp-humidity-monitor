#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Definisi Pin
#define DHTPIN 2         // Pin DATA DHT22 ke Digital Pin 2 Arduino [1]
#define DHTTYPE DHT22    // Menggunakan jenis sensor DHT22 [1]
#define LED_PIN 8        // Pin Anoda LED Hijau ke Digital Pin 8 Arduino

// Inisialisasi Sensor & LCD (Alamat I2C umum 0x27 atau 0x3F) [2, 3]
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  Serial.begin(9600);
  
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Matikan LED saat booting
  
  dht.begin();
  
  lcd.init();
  lcd.backlight();
  
  // Pesan Selamat Datang
  lcd.setCursor(0, 0);
  lcd.print("  Project H-1  ");
  lcd.setCursor(0, 1);
  lcd.print(" Monitoring IoT ");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Membaca suhu (Celsius) dan kelembapan (%) [1, 4]
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Cek apakah pembacaan sensor gagal
  if (isnan(temp) || isnan(hum)) {
    lcd.setCursor(0, 0);
    lcd.print("Error Read DHT! ");
    digitalWrite(LED_PIN, LOW);
    return;
  }

  // Tampilkan Suhu di Baris Pertama LCD
  lcd.setCursor(0, 0);
  lcd.print("Suhu  : ");
  lcd.print(temp, 1);
  lcd.print((char)223); // Karakter derajat (°)
  lcd.print("C  ");

  // Tampilkan Kelembapan di Baris Kedua LCD
  lcd.setCursor(0, 1);
  lcd.print("Lembap: ");
  lcd.print(hum, 1);
  lcd.print("%  ");

  // Nyalakan LED Hijau sebagai tanda pembacaan berhasil
  digitalWrite(LED_PIN, HIGH);

  // Print juga ke Serial Monitor untuk debugging
  Serial.print("Suhu: ");
  Serial.print(temp);
  Serial.print(" *C | Kelembapan: ");
  Serial.print(hum);
  Serial.println(" %");

  // Jedat waktu pembacaan (DHT22 memerlukan interval ~2 detik) [5, 6]
  delay(2000); 
}