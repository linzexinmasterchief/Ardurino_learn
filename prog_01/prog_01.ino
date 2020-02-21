#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();
int x;
String text;

String input;

void setup() {
  Serial.begin(9600);
  x = 0;
  text = "Hello,COA202";
  input = "";
  lcd.begin(text.length(), 1);
  lcd.setCursor(0, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear();
  x += 1;
  if (x > text.length()) {
    x = 0;
  }
  lcd.print(text.substring(x));
  Serial.println(text.substring(x));

  input = String(Serial.readString());
  input = input.substring(0, input.length() - 1);
  if (input != "") {
    text = input;
  }
  
//  delay(5);
}
