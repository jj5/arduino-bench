
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
  String command = Serial.readString();
  command.trim();
  command.toLowerCase();
  Serial.print( "Command: " );
  Serial.println( command );
  if ( command == "on" ) {
    state = ON;
  }
  else if ( command == "off" ) {
    state = OFF;
  }
  else if ( command == "flash" ) {
    state = FLASH;
  }
  else {
    Serial.println( "Unknown command." );
  }
}
