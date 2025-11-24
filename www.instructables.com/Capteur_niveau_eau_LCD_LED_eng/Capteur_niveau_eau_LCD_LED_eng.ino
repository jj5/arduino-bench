// 2025-11-24 jj5 - SEE: https://www.instructables.com/Testing-Water-Level-Sensor-Arduino-UNO-Water-Level/

#include <LiquidCrystal_I2C.h>  // Including the LiquidCrystal_I2C library

LiquidCrystal_I2C lcd(0x27, 16, 2);  // Initializing the LCD screen with I2C address, 16 columns, and 2 rows
const int ledPinR = 5;  // Pin for the first LED (Red)
const int ledPinY = 4;  // Pin for the second LED (Yellow)
const int ledPinG = 3;  // Pin for the third LED (Green)

void setup() {
  pinMode(ledPinR, OUTPUT);  // Configuring the pin as an output
  pinMode(ledPinY, OUTPUT);  // Configuring the pin as an output
  pinMode(ledPinG, OUTPUT);  // Configuring the pin as an output
  
  digitalWrite(ledPinR, LOW);  // Initializing the state as low (LED off)
  digitalWrite(ledPinY, LOW);  // Initializing the state as low (LED off)
  digitalWrite(ledPinG, LOW);  // Initializing the state as low (LED off)
  
  lcd.init();  // Initializing the LCD screen
  lcd.backlight();  // Turning on the LCD backlight
  
  lcd.setCursor(0, 0);  // Setting the cursor position to column 0, row 0
  lcd.print("School Sur Seine!");  // Displaying the text "School Sur Seine!"
  
  lcd.setCursor(7, 1);  // Setting the cursor position to column 7, row 1
  lcd.print(":)");  // Displaying the symbol ":)"
  
  delay(5000);  // Waiting for 5 seconds
  
  lcd.clear();  // Clearing the LCD screen
}

void loop() {
  int value = analogRead(A0);  // Reading the analog value from pin A0
  lcd.setCursor(0, 0);  // Setting the cursor position to column 0, row 0
  lcd.print("Value :");  // Displaying the text "Value :"
  lcd.print(value);  // Displaying the read value
  lcd.print("    ");  // Displaying empty spaces to clear previous characters
  lcd.setCursor(0, 1);  // Setting the cursor position to column 0, row 1
  lcd.print("Level :");  // Displaying the text "Level :"
  
  if (value < 10) {
    lcd.print("No water ");  // Displaying the text "No water"
    
    digitalWrite(ledPinR, LOW);  // Turning off the Red LED
    digitalWrite(ledPinY, LOW);  // Turning off the Yellow LED
    digitalWrite(ledPinG, LOW);  // Turning off the Green LED
  } else if (value >= 100 && value < 630) {
    lcd.print("Low     ");  // Displaying the text "Low"
    
    digitalWrite(ledPinR, HIGH);  // Turning on the Red LED
    digitalWrite(ledPinY, LOW);  // Turning off the Yellow LED
    digitalWrite(ledPinG, LOW);  // Turning off the Green LED
  } else if (value >= 630 && value < 670) {
    lcd.print("Medium  ");  // Displaying the text "Medium"
    
    digitalWrite(ledPinY, HIGH);  // Turning on the Yellow LED
    digitalWrite(ledPinR, LOW);  // Turning off the Red LED
    digitalWrite(ledPinG, LOW);  // Turning off the Green LED
  } else if (value >= 670) {

    lcd.print("High    ");  // Displaying the text "High"
    
    digitalWrite(ledPinG, HIGH);  // Turning on the Green LED
    digitalWrite(ledPinR, LOW);  // Turning off the Red LED
    digitalWrite(ledPinY, LOW);  // Turning off the Yellow LED
  }
}
