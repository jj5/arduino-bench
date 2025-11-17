const int SENSOR_PIN = 3;
const int LED_PIN = 13;
int sensor_value = 0;

void setup () {
  pinMode ( LED_PIN, OUTPUT );
  pinMode ( SENSOR_PIN, INPUT );
  Serial.begin ( 9600 );
  Serial.println( "Running..." );
}

void loop () {
  sensor_value = digitalRead( SENSOR_PIN );
  Serial.println( sensor_value );
  delay( 1000 );
}
