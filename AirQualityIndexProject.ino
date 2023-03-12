#include <LiquidCrystal.h>
const int rs=12, en=11, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

int buz = 8;
int led = 9;
const int aqsensor = A0;
int threshold = 175;

void setup() {
 pinMode(buz,OUTPUT);
 pinMode(led,OUTPUT);
pinMode(aqsensor,INPUT);

Serial.begin(9600);

lcd.clear();
lcd.begin(16,2);



}

void loop() {
 int ppm = analogRead(aqsensor);
 
 Serial.print("Air Quality: ");
 Serial.println(ppm);

lcd.setCursor(0,0);
lcd.print("Air Quality: ");
lcd.print(ppm);

if(ppm > threshold)
{
  lcd.setCursor(1,1);
  lcd.print("AQ Level HIGH");
  tone(led,1000,200);
  digitalWrite(buz,HIGH);
 

}
else {
digitalWrite(led,LOW);
digitalWrite(buz,LOW);
lcd.setCursor(1,1);
lcd.print("AQ Level Good");
}
delay(500);
}

