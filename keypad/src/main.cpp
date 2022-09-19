#include <Arduino.h>
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
const int ROW_NUM=4;
const int COLUMN_NUM=4;

char keys[ROW_NUM][COLUMN_NUM] = {
  {'1','2','3', 'A'},
  {'4','5','6', 'B'},
  {'7','8','9', 'C'},
  {'*','0','#', 'D'}
};

byte pin_rows[ROW_NUM]={2,3,4,5};
byte pin_column[COLUMN_NUM] = {6,7,8,9};

Keypad keypad= Keypad (makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

void setup() {
  lcd.init();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
}

void loop() {
  char key=keypad.getKey();

  if(key){
    lcd.clear();
    Serial.println(key);
    lcd.write(key);
  }
}
