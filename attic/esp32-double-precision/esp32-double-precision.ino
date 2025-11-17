
// Number of digits in 7-seg display.
#define NUM_SEGS 8


void setup() {
  // put your setup code here, to run once:
  Serial.begin( 115200 );
}

//volatile double value = 0.0;
volatile double value = 0.0;

void loop() {

  value += (double)0.1;
  value += (double)0.1;
  value += (double)0.1;
  value -= 0.3;

  value =  90000000;
  value += 90000000;

  Serial.println( convertToString( value ) );

  sleep( 1 );

}

// Convert the number passed to a String. Maximize the display digits.
String convertToString(double total) {
  char result[30];
  String value;
  int decimals = NUM_SEGS + 2;
  
  // See if result that is too big can be shortened. Get the value with
  //  extra decimal places.
  dtostrf (total, NUM_SEGS, decimals, result);
  value = String(result);
  value.trim();

  // Remove trailing zeros from the value if there is a decimal place.
  bool hasdecimal = false;
  if (value.indexOf('.') != -1) {
    hasdecimal = true;
    value = removeTrailingZeros(value);
  } 

  // Check for still too big.
  if (hasdecimal) {
    if (value.length()-1 > NUM_SEGS) {
      // Still too big. See if decimal places can be reduced.
      int decimalpos = value.indexOf('.');
      if (decimalpos > 0) {
        // At least one whole number so reduce decimals.
        int decimals = NUM_SEGS - decimalpos;
        if (decimals >= 2) {
          dtostrf (total, NUM_SEGS, decimals, result);
          String test = String(result);
          test = removeTrailingZeros(test);
          if (test.charAt(test.length()-1) != '.') {
            // There are still numbers in the fraction so OK.
            value = String(result);
            value.trim();
          } else {
            // Just a whole number so remove the decimal.
            test.remove(test.length()-1);
            value = test;
          }
        }
      } 
    }
  }
  return value;
}

// Remove the trailing zeros from the string passed.
String removeTrailingZeros(String value) {
  bool skipZero = true;
  for (int i = value.length()-1; i >= 0; i--) {
    char digit = value.charAt(i);
    if (digit == '0'  && skipZero) {
      value.remove(i);
      continue;
    } else {
      break;
    }
  }
  return value;
}
