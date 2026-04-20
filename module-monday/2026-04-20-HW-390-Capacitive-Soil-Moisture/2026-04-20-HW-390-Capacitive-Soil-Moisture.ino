// 2025-11-24 jj5 - this is LiquidCrystal I2C v1.1.2 by Frank de Brabander
// 2025-11-24 jj5 - SEE: https://github.com/johnrickman/LiquidCrystal_I2C
#include <LiquidCrystal_I2C.h>

// 2025-12-01 jj5 - do not define this constant for production builds...
//#define DEBUG

// 2025-11-24 jj5 - initialize the LCD screen with I2C address 0x27, 20 columns, and 4 rows
LiquidCrystal_I2C lcd( 0x27, 20, 4 );

const int LED_PIN_R = 5; // Red
const int LED_PIN_Y = 4; // Yellow
const int LED_PIN_G = 3; // Green

const int PIN = A0;

void set_pins( int red, int yellow, int green ) {
  digitalWrite( LED_PIN_R, red );
  digitalWrite( LED_PIN_Y, yellow );
  digitalWrite( LED_PIN_G, green );
}

void setup() {
  Serial.begin(115200);
  pinMode( PIN, INPUT );
  set_pins( HIGH, HIGH, HIGH );
}

void loop() {
  int level = analogRead( PIN );
  Serial.println( level );
  delay( 1000 );
}
