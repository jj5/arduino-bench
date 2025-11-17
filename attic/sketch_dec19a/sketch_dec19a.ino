
void setup()
{
  pinMode(8, OUTPUT);
  digitalWrite(8, HIGH);
    
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);  
}
