#include<LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
int led = 13;                
int sensor = 8;              // the pin that the sensor is atteched to          
int val = 0;                 // variable to store the sensor status (value)

const int Sensor = A0; 
byte degree_symbol[8] = 
              {
                0b00111,
                0b00101,
                0b00111,
                0b00000,
                0b00000,
                0b00000,
                0b00000,
                0b00000
              };
void setup()
{
  pinMode(Sensor, INPUT);
  lcd.begin(16,2);
  lcd.createChar(1, degree_symbol);
  lcd.setCursor(0,0);
  lcd.print("    Digital    ");
  lcd.setCursor(0,1);
  lcd.print("  Thermometer   ");
  delay(4000);
  lcd.clear();
   pinMode(led, OUTPUT);     
  pinMode(sensor, INPUT);    
  Serial.begin(9600);        
}
void loop()
{
  
     float temp_reading=analogRead(Sensor);
     float temperature=temp_reading*(5.0/1023.0)*100;
     delay(10); 
  
    lcd.clear();
    lcd.setCursor(0,0);
    

 val = digitalRead(sensor);   // read sensor value
  if (val == LOW) {           // check if the sensor is HIGH
    digitalWrite(led, LOW);   // turn LED ON
    delay(500);                // delay 500 milliseconds 
  }
    else {
      Serial.println("Motion detected!"); 
      lcd.print("Temperature in C");
    lcd.setCursor(4,1);
    lcd.print(temperature);
    lcd.write(1);
    lcd.print("C");
    digitalWrite(led, HIGH);
    delay(1000);

    }
  } 

  
   
