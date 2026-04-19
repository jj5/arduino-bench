
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

// 2025-11-24 jj5 - our HW-038 water sensor is attached to this pin:
const int SENSOR_PIN = A0;

// 2025-11-24 jj5 - this is how many counts we wait after we've seen a new WaterLevel before we update our display
const uint64_t WAIT = 5;

enum WaterLevel {
  Empty,
  Low,
  Medium,
  High,
};

struct LevelInfo {
  WaterLevel level;
  // 2025-11-24 jj5 - this is how many times we've seen this level continuously...
  uint64_t count;
};

LevelInfo current_level{ WaterLevel::Empty, 0 };

void set_pins( int red, int yellow, int green ) {
  digitalWrite( LED_PIN_R, red );
  digitalWrite( LED_PIN_Y, yellow );
  digitalWrite( LED_PIN_G, green );
}

void set_level( WaterLevel level, int value ) {

  if ( current_level.level != level ) { current_level = { level, 0 }; }

  current_level.count++;

#ifndef DEBUG
  if ( current_level.count != WAIT ) { return; }
#endif

  lcd.setCursor( 0, 0 );
  lcd.print( "Value: " );
  lcd.print( value );
  lcd.print( "    " );
  lcd.setCursor( 0, 1 );
  lcd.print(  "Level: " );

  switch ( current_level.level ) {
    case WaterLevel::Empty :
      lcd.print( "No water " );
      set_pins( LOW, LOW, LOW );
      break;
    case WaterLevel::Low :
      lcd.print( "Low      " );
      set_pins( HIGH, LOW, LOW );
      break;
    case WaterLevel::Medium :
      lcd.print( "Medium   " );
      set_pins( LOW, HIGH, LOW );
      break;
    case WaterLevel::High :
      lcd.print( "High     " );
      set_pins( LOW, LOW, HIGH );
      break;
  }

#ifdef DEBUG
  delay( 1000 );
#endif

}

void setup() {

  Serial.begin( 115200 );
  while ( ! Serial );
  Serial.println( "Serial initialized." );

  pinMode( LED_PIN_R, OUTPUT );
  pinMode( LED_PIN_Y, OUTPUT );
  pinMode( LED_PIN_G, OUTPUT );

  set_pins( HIGH, HIGH, HIGH );
  
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor( 4, 1 );
  lcd.print( " In The Lab" );
  lcd.setCursor( 4, 2 );
  lcd.print( "With Jay Jay!" );
  
  delay( 5000 );
  
  lcd.clear();

}

void loop() {
  // 2025-11-24 jj5 - get a reading from our water sensor
  int value = analogRead( SENSOR_PIN );

#ifdef DEBUG
  Serial.println( value );
#endif

  if ( value < 400 ) {
    set_level( WaterLevel::High, value );
  }
  else if ( value < 500 ) {
    set_level( WaterLevel::Medium, value );
  }
  else if ( value < 900 ) {
    set_level( WaterLevel::Low, value );
  }
  else {
    set_level( WaterLevel::Empty, value );
  }
}