#include <LiquidCrystal.h>  // include the library code:

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int analogInPin = A0;

int sensorValue = 0;  // Value read from the pot
int outputValue = 0;  // Value displayed on LCD
float  voltaj;
void setup()
{
  Serial.begin(9600); // Rate of data transmission
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.clear();
}

void loop()
{
  sensorValue = analogRead(analogInPin);  // Reading Potentiometer
  outputValue = map(sensorValue, 0, 1023, 0, 100); // 1024 degeri 100 degere yerleştiriyor
  voltaj=(0.047)*outputValue;//5v=100 orantısından bulunuyor 
  lcd.setCursor(0,0); // Sets the cursor to col 0 and row 0
  lcd.print("VOLTAJ: "); // Prints Dimming % to LCD
  lcd.print(voltaj); // Prints formatted dimming value to LCD
  delay(1000);
}
