#include "SoftwareSerial.h"
#include <LiquidCrystal_I2C.h>

SoftwareSerial mySerial(3, 2);
LiquidCrystal_I2C lcd(0x27, 16, 2);

#define blue 2
#define green 3
#define red 4

unsigned int f;
unsigned int g;
unsigned int h;

void setup() {
  pinMode(blue, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);
  mySerial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("  Welcome To");
  lcd.setCursor(0, 1);
  lcd.print("Sign to Speech");
  delay(3000);
  lcd.clear();
}

void loop() {
  f = analogRead(1); 
  g = analogRead(2); 
  h = analogRead(3); 

  if (f <= 722 && g <= 670) { 
    twoFingerAction("Give Me Coffee", "Plz Give Me", "    Coffee   ", blue, green);
  } 
  else if (g <= 670 && h <= 675) { 
    twoFingerAction("Give Me Snacks", "Plz Give Me", "    Snacks   ", green, red);
  } 
  else if (f <= 722 && h <= 675) { 
    twoFingerAction("Plz Give Me Milk", "Plz Give Me", "     Milk    ", blue, red);
  } 
  

  else if (f <= 722) { 
    singleFingerAction("Plz Give Me Water", "  Plz Give Me", "     Water   ", blue);
  } 
  else if (g <= 670) { 
    singleFingerAction("Plz Give Me Food", "  Plz Give Me", "     Food   ", green);
  } 
  else if (h <= 675) { 
    singleFingerAction("EMERGENCY EMERGENCY", "EMERGENCY EMERGENCY", "EMERGENCY", red);
  } 
  
  delay(200);
}

void singleFingerAction(String msg, String line1, String line2, int led) {

  digitalWrite(blue, LOW);
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);


  digitalWrite(led, HIGH);
  

  mySerial.println(msg);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" If Anything");
  lcd.setCursor(0, 1);
  lcd.print("  You Want ");
}

void twoFingerAction(String msg, String line1, String line2, int led1, int led2) {
  
  digitalWrite(blue, LOW);
  digitalWrite(green, LOW);
  digitalWrite(red, LOW);

  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  

  mySerial.println(msg);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line1);
  lcd.setCursor(0, 1);
  lcd.print(line2);
  delay(3000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" If Anything");
  lcd.setCursor(0, 1);
  lcd.print("  You Want ");
}
