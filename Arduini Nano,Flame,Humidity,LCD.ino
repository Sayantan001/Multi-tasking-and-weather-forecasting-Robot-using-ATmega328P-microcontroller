#include <dht.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

dht DHT;

#define DHT11_PIN 7
#define flame_sensor 8
#define flame_sensor1 10
#define buzzer 9
int flame_detected;
int flame_detected1;

void setup(){
  lcd.begin(16, 2);
   Serial.begin(9600);
   pinMode(buzzer, OUTPUT);



  pinMode(flame_sensor, INPUT);
  pinMode(flame_sensor1, INPUT);

}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Humidity: ");
  lcd.print(DHT.humidity);
  lcd.print("%");
  
  flame_detected = digitalRead(flame_sensor);
 flame_detected1 = digitalRead(flame_sensor1);  

  if ((flame_detected == 1)||(flame_detected1 == 1))

  {

digitalWrite(buzzer, HIGH);}
else

  {

    Serial.println("No flame detected. stay cool");

    digitalWrite(buzzer, LOW);



  }


}