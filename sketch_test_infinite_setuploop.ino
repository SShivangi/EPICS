#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

int n = 1;
int key_press = 1;
void setup() {
  lcd.setCursor(0,0);
  lcd.print("Enter Set Up");
  delay(2000);
  while(n==1){
    if(key_press == 1){
      n = 0;
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("N = 0 now");
    }
  }
}

void loop() {
  lcd.setCursor(1,1);
  lcd.print("Hi");
}
