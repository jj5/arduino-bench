
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
