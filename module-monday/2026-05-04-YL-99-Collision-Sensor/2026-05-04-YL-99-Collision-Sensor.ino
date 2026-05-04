
#define LED 13
#define SIG 7

void setup() {
  Serial.begin( 115200 );
  pinMode( LED, OUTPUT );
  pinMode( SIG, INPUT );
}

void loop() {
  int signal = digitalRead( SIG );
  digitalWrite( LED, signal );
}
