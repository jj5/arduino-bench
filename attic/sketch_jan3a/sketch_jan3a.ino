int led_pin=13;

void setup() {

pinMode(led_pin,OUTPUT);

}

void loop()

{

digitalWrite(led_pin,HIGH);
delay(2000);

digitalWrite(led_pin,LOW);

delay(200);

}

/*Sketch uses 692 bytes (8%) of program storage space. Maximum is 8192 bytes.
Global variables use 9 bytes (1%) of dynamic memory, leaving 503 bytes for local variables. Maximum is 512 bytes.
avrdude: Yikes!  Invalid device signature.
         Double check connections and try again, or use -F to override
         this check.

Failed programming: uploading error: exit status 1*/
