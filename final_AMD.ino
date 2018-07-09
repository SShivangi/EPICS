//LCD TESTING

#include<LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

int lcd_key=0;
int adc_key_in;
int pin = A0;
int num = 0;
int flag1 = 0;
int flag2 = 0;
int flag3 = 0;
int tp;
int a[5];
#define UP 1   //144
#define DOWN 2 //329
#define LEFT 3 //504
#define SELECT 4 //



//do a flag check for negative o/p in lcd 

void setup() {
  // put your setup code here, to run once:
  pinMode(pin, INPUT);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("AMD");
  delay(3000);
  lcd.clear();
  lcd.print("box no : " );
  delay(3000);
}


// limit the box number
// timer interface
// take input for each box
   void loop() 
{
  tp = analogRead(pin);
  if((tp > 50 && tp < 150) ) //up
  {
    flag1 = 1;
  }
  if(flag1 == 1 && !(tp > 50 && tp < 150) && num<4) //up counter
  {
    num = num+1;
    lcd.setCursor(0,1);
    lcd.print(num);
    
    tp = analogRead(pin); //select and store
    if((tp > 350 && tp < 550)){
     a[num-1] = num;
    }
    flag1 = 0;
  }
  if ((tp > 150 && tp < 350))//down
  {
    flag2 = 1;
  }
  if (flag2 == 1 && !(tp > 150 && tp < 350) && num>=2)//down counter
  {
    num = num -1;
    lcd.setCursor(0,1);
    lcd.print(num);
    flag2 =0;
  }

  tp = analogRead(pin);
    if((tp > 350 && tp < 550)){ 
      flag3 = 1;
    }
  if (flag3 == 1 && !(tp>350 && tp<550)){
     a[num-1] = num;
     lcd.setCursor(0,1);
     lcd.print("BOX SAVED");
     lcd.setCursor(9,1);
     lcd.print(a[5]);
    flag3 = 0;

    //number of times
   // delay time
   
  }
}
