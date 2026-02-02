// C++ code
//
#include <Adafruit_LiquidCrystal.h>

const int triggerPin = 7;
const int echoPin = 6;

float distance = 0;
float duration = 0;

Adafruit_LiquidCrystal lcd_1(0);

void setup()
{
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
    
  lcd_1.begin(16, 2);
  lcd_1.print("Distance:");
}

void loop()
{
  lcd_1.setCursor(0, 1);
  lcd_1.print(distance);
  lcd_1.print("   ");
  lcd_1.setBacklight(1);
  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(250);
  digitalWrite(triggerPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.0344) / 2;
}
