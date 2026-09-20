# arduino-dht22-temp-humidity-monitor

Proyek sederhana monitoring suhu dan kelembapan udara secara real-time menggunakan mikrokontroler **Arduino Uno R3**, sensor presisi **DHT22 (AM2302)**, dan display **LCD 16x2 dengan modul I2C**. Proyek ini dibuat sebagai dokumentasi jurnal belajar IoT Hari ke-1.

---

## 📋 Fitur Utama
* **Pembacaan Presisi**: Membaca data suhu (°C) dan kelembapan udara (%) secara kontinyu menggunakan sensor DHT22.
* **Tampilan Ringkas**: Menampilkan data temperatur dan kelembapan langsung pada layar LCD 16x2 I2C.
* **Indikator Status**: LED Hijau menyala sebagai penanda sistem beroperasi dan pembacaan sensor berhasil.
* **Debugging Serial**: Mengirimkan log data temperatur & kelembapan ke Serial Monitor Arduino IDE.

---

## 🛠️ Daftar Komponen & Spesifikasi

| Komponen | Spesifikasi / Keterangan | Jumlah |
| :--- | :--- | :---: |
| **Arduino Uno R3** | Mikrokontroler ATmega328P (Logic Level 5V) | 1 |
| **Sensor DHT22 / AM2302** | Sensor Suhu (-40°C - 80°C) & Kelembapan (0-100% RH) | 1 |
| **Display LCD 16x2** | Modul Backpack I2C PCF8574 (Alamat `0x27` / `0x3F`) | 1 |
| **LED Hijau** | Indikator pembacaan aktif (5mm) | 1 |
| **Resistor 330Ω** | Pembatas arus LED | 1 |
| **Breadboard & Jumper** | Breadboard 830P + Kabel Jumper Male-to-Male / Female-to-Male | Secukupnya |

---

## 🔌 Skema Wiring / Sambungan Kabel

### 1. Modul LCD 16x2 I2C -> Arduino Uno R3
* **VCC** → Pin **5V**
* **GND** → Pin **GND**
* **SDA** → Pin Analog **A4** (atau pin SDA dedicated)
* **SCL** → Pin Analog **A5** (atau pin SCL dedicated)

### 2. Sensor DHT22 -> Arduino Uno R3
* **VCC / VDD** → Pin **5V**
* **DATA** → Pin Digital **D2**
* **GND** → Pin **GND**
*(Catatan: Jika menggunakan sensor DHT22 mentah 4-pin tanpa board breakout, pasangkan resistor pull-up 10kΩ antara pin VCC dan pin DATA).*

### 3. Indikator LED Hijau -> Arduino Uno R3
* **Anoda (+ / Kaki Panjang)** → Resistor 330Ω → Pin Digital **D8**
* **Katoda (- / Kaki Pendek)** → Pin **GND**

---

## 💻 Prasyarat Software & Library
Sebelum mengunggah kode program, pastikan kamu telah menginstal:
1. **Arduino IDE** (versi 1.8.x atau 2.x)
2. **DHT sensor library** oleh *Adafruit* (via Library Manager)
3. **LiquidCrystal_I2C** oleh *Frank de Brabander / Marco Schwartz* (via Library Manager)

---

## 🚀 Cara Penggunaan
1. **Clone Repository ini**:
   ```bash
   git clone https://github.com/username/arduino-dht22-temp-humidity-monitor.git
   ```
2. Rangkai seluruh komponen sesuai skema wiring di atas.
3. Buka file `src/main.ino` di Arduino IDE.
4. Hubungkan Arduino Uno ke PC/Laptop dengan kabel USB.
5. Pilih Board **Arduino Uno** dan atur **Port COM** yang sesuai pada menu `Tools`.
6. Klik **Upload**.
7. *Troubleshooting*: Jika teks pada LCD tidak muncul, putar trimpot/potensiometer biru di bagian belakang modul I2C LCD untuk menyesuaikan kontras layar.

---

## 📄 Lisensi
Proyek ini bersifat open-source dan dilisensikan di bawah [MIT License](LICENSE).
