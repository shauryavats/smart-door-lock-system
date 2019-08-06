#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
int trigPin = 9;
int echoPin = 10;
long duration;
int distance;
int lockPin=11;
void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(lockPin,OUTPUT);
  lcd.begin(16, 2);
Serial.begin(9600);
}
void loop() {
 lcd.setCursor(0, 1);
 lcd.print("Access denied!");
digitalWrite(lockPin,LOW); 
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance= duration*0.034/2;
Serial.print("Distance: ");
Serial.println(distance);
if(distance<=30){
digitalWrite(lockPin,HIGH);
lcd.print("Access Granted ;)");
lcd.print(millis() / 5000);
Serial.println("Unlocked");
delay(5000);
digitalWrite(lockPin,LOW);
 lcd.print("Access denied!");
Serial.println("LOCKED");
}
  while(Serial.available()){
  char a=Serial.read();
if(Serial.read()=='alohmora'){
digitalWrite(lockPin,HIGH);
lcd.print("Access Granted ;)");
lcd.print(millis() / 5000);
delay(5000);
digitalWrite(lockPin,LOW);
 lcd.print("Access denied!");

}
}
}
