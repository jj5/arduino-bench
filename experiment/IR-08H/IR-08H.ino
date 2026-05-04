
#define LED 13
#define SIG 7
#define ENABLE 6

void setup() {
  Serial.begin( 115200 );
  pinMode( LED, OUTPUT );
  pinMode( ENABLE, OUTPUT );
  pinMode( SIG, INPUT );
}

int last;

void loop() {

  digitalWrite( ENABLE, LOW );
  int signal = digitalRead( SIG );

  if ( signal != last ) {
    Serial.println( signal );
    digitalWrite( LED, signal );
  }

  last = signal;

  /*
  digitalWrite( 13, LOW );
  delay( 500 );
  digitalWrite( 13, HIGH );
  delay( 500 );
  */
}
