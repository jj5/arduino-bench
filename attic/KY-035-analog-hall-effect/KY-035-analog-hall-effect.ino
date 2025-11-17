const int SENSOR_PIN = A5; // select the input pin
const int LED_PIN = 13; // select the pin for the LED
int sensor_value = 0; // variable to store the value coming from the sensor

void setup () {
  pinMode ( LED_PIN, OUTPUT );
  Serial.begin ( 9600 );
  Serial.println( "Running..." );
}

void loop () {
  sensor_value = analogRead( SENSOR_PIN );
  Serial.println( sensor_value );
  digitalWrite( LED_PIN, HIGH );
  delay( sensor_value );
  digitalWrite( LED_PIN, LOW );
  delay( sensor_value );
}
