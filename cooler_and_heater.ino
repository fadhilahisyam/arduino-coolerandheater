#include <LiquidCrystal_I2C.h>

// C++ code
//
const int tmpPin = A0;
const int heaterPin = 6;
const int coolerPin = 2;
const int ledPin1 = 3;
const int ledPin2 = 4;
const int ledPin3 = 5;
LiquidCrystal_I2C lcd(32, 16, 2);
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(tmpPin, INPUT);
  pinMode(heaterPin, OUTPUT);
  pinMode(coolerPin, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop()
{
  int temp = analogRead(tmpPin);
  int suhu = (temp/8);
  Serial.println(temp);
  lcd.setCursor(0, 0);
  lcd.print("Suhu: ");
  lcd.print(suhu);
  lcd.print("C");
  
  if (suhu <= 20){
    loTemp();
    lcd.setCursor(0, 1);
    lcd.print("Suhu Dingin");
  }
  else if (suhu >= 20 && suhu <= 30){
    normTemp();
    lcd.setCursor(0, 1);
    lcd.print("Suhu Normal");
  }
  else if (suhu >= 30){
    hiTemp();
    lcd.setCursor(0, 1);
    lcd.print("Suhu Panas ");
  }
  delay(100);
}
void hiTemp()
{
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(coolerPin, HIGH);
  digitalWrite(heaterPin, LOW);
}
void normTemp()
{
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, LOW);
  digitalWrite(coolerPin, LOW);
  digitalWrite(heaterPin, LOW);
}
void loTemp()
{
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin3, LOW);
  digitalWrite(coolerPin, LOW);
  digitalWrite(heaterPin, HIGH);
}