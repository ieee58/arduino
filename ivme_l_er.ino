#include <Adafruit_MLX90614.h>

#include <math.h>
#include <Wire.h>
#include <helper_3dmath.h>
#include <MPU6050.h>
#include <I2Cdev.h>
#include <Wire.h>




MPU6050 ivme_sensor; // sensörümüze ivme_sensor adını verdik
int16_t ax, ay, az; //ivme tanımlama
int16_t gx, gy, gz; //gyro tanımlama
 
void setup() {
Wire.begin();
Serial.begin(9600);
Serial.println("I2C cihazlar baslatiliyor...");
ivme_sensor.initialize();
Serial.println("Test cihazi baglantilari...");
Serial.println(ivme_sensor.testConnection() ? "MPU6050 baglanti basarili" : "MPU6050 baglanti basarisiz");
}
 
void loop() {
ivme_sensor.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); // ivme ve gyro değerlerini okuma

//açısal ivmeleri ve gyro değerlerini serial ekrana yazdıralım
Serial.print(ax); Serial.print("\t");
Serial.print(ay); Serial.print("\t");
Serial.print(az); Serial.print("\t");
Serial.print(gx); Serial.print("\t");
Serial.print(gy); Serial.print("\t");
Serial.print(gz); Serial.println("\t");

delay(500); //değerlerin değişimini daha net görmek için yarım saniye beklesin
}
