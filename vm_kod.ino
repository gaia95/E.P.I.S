#include <LiquidCrystal.h> 
#include <Ultrasonic.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Defining connections

// Declarations and initialization 

  const int TP = 9; // Trigger pin connection to arduino 
  const int EP = 10; // Echo pin
  int distance; // mesarue distance, time it takes for a ping to hit object 
 
void setup() {
  
  Serial.begin(9600); // arduino and firmware communication
  lcd.begin(16,2); // start set up of lcd
  
  pinMode(13, OUTPUT); // giving current outwards
  pinMode(TP, OUTPUT); 
  pinMode(EP, INPUT); 

}

void loop() {
  
lcd.setCursor(10,1);
lcd.print("cm");

// Measuring distance with sound waves

  digitalWrite(TP, LOW);
  delayMicroseconds(10);
  digitalWrite(TP, HIGH); 
  delayMicroseconds(10);
  digitalWrite(TP, LOW);
  distance = pulseIn(EP,HIGH); 
  delay(25);


if (distance > 5830 && distance < 17500 ) 
{ 

    Serial.println("Good Levels");
    lcd.setCursor(0,0);
    lcd.print("Good Levels");
    delay(3000);
    lcd.clear();

    Serial.println(distance);
    lcd.setCursor(0,0); // where on lcd it will show up
    lcd.print(distance);

}

if (distance > 17500 ){

  digitalWrite(LED_BUILTIN, HIGH); // Turn on LED, highest volt
  delay(250); // small delay
  digitalWrite(LED_BUILTIN, LOW); // Turn off LED, lowest volt
  delay(250);

  lcd.setCursor(0,0);
  Serial.println("!WARNING!"); lcd.print("!WARNING!");
  delay(750);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print(distance);

}

if (distance < 5830) // if distance < 100 cm 
{

  digitalWrite(LED_BUILTIN, HIGH); 
  delay(250); 
  digitalWrite(LED_BUILTIN, LOW); 
  delay(250);

  lcd.setCursor(0,0); // row , column

  Serial.println("!WARNING!"); lcd.print("!WARNING!");
  delay(750);
  lcd.clear();

// printing distance on lcd 
  Serial.println(distance);
  lcd.setCursor(0,1); // where on lcd it will show up
  lcd.print(distance);
 
 }
}