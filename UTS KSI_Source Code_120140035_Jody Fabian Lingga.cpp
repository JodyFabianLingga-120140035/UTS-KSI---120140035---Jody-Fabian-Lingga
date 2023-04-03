#include <MQ2.h>
 
#define Fire_digital 7
#define mq2Pin 8
#define buzzer 2
#define ledR 4
#define ledY 12
int lpg;
 
MQ2 mq2(mq2Pin);
 
void setup() {
 Serial.begin(9600);
 mq2.begin();
 pinMode(Fire_digital, INPUT);
 pinMode(mq2Pin, INPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(ledR, OUTPUT);
 Serial.println("MQ2 warming up!");
	delay(20000);
 Serial.println("MQ2 Ready!");
}
 
void loop() {
 int firesensorDigital = digitalRead(Fire_digital);
 lpg = digitalRead(mq2Pin);
 
if (firesensorDigital == LOW ){
 Serial.println("Ada Api!");
 tone(buzzer, 1000, 1000);
 digitalWrite(ledR, HIGH);
}
else if(lpg == LOW){
 Serial.println("Ada GAS / ASAP!");
 tone(buzzer, 500, 1000);
 digitalWrite(ledY, HIGH);
 delay(1000);
 noTone(buzzer);
}
else{
 Serial.println("Tidak ada Gas/Asap/Api!");
 noTone(buzzer);
 digitalWrite(ledR, LOW);
 digitalWrite(ledY, LOW);
}
delay(100);
}
