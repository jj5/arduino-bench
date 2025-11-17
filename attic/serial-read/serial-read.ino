
enum state { OFF, ON, FLASH };

enum state state = OFF;

int blink_pin = 13;

void setup() {
  pinMode( blink_pin, OUTPUT );
  Serial.begin( 9600 );
}

void loop() {
  if ( Serial.available() > 0 ) { read_command(); }
  switch ( state ) {
    case ON :
      digitalWrite( blink_pin, HIGH );
      break;
    case OFF :
      digitalWrite( blink_pin, LOW );
      break;
    case FLASH :
      int pin = digitalRead( blink_pin );
      digitalWrite( blink_pin, !pin );
      delay( 500 );
      digitalWrite( blink_pin, pin );
      delay( 500 );
      break;
  }
}

void read_command() {
  char c = Serial.read();
  switch ( c ) {
    case 'a' :
      state = ON;
      break;
    case 's' :
      state = OFF;
      break;
  }
}
