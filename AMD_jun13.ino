#include<LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

#define ledPin 13
#define solenoidPin 11
#define buzzerPin 10
#define keyPin 2

int adc_key_in = 0;
int pin = A0; // analog input pin
int tp = 0;
int flag = 0;
int num = 0;
int f1 = 0;
int f2 = 0;
int f3 = 0;
int f4 = 0;
int editFlag = 1;
int dayCount = 0;
int delay1 =0 ;
int delay2 = 0;
int delay3 = 0;
int delay4 = 0;

int Press(void){
  while(f4 == 0){ //f4 turns 1 on select button press
        tp = analogRead(keyPin);
        if (tp > 50 && tp < 150){
            f1 = 1;
        }
        if (f1 == 1 && !(tp >50 && tp < 150)){
          num = num+1;
          lcd.setCursor(1,0);
          lcd.print(num);
          f1 = 0;
        }

        if (tp > 150 && tp < 350){
          f2 = 1;
        }

        if (f2 == 1 && !(tp >150 && tp< 350)){
          num = num -1;
          lcd.setCursor(1,0);
          lcd.print(num);
          f2 = 0;
        }

        if (tp > 350 && tp < 550){
          f3 = 1;
        }

        if (f3 == 1 && !(tp > 350 && tp < 550)){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Selected");
          f4 = 1;
        }
   }

    return(num);
}

void setup() {
  // put your setup code here, to run once:

  pinMode(keyPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(solenoidPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  /*
   * counter/timer keeps counting
   * when timer value == set value, cause an interrupt
   * interrupt leads to execution of isr - which has - 
   *            1. led flashing of the compartment 
   *            2. solenoid actuates of the compartment
   *            3. buzzer rings
   * how to decide the which compartment to work on? 
   *            giving the compartment no while programming. 
   *            so, the value is to be stored in an array. 
   */

   //enter data block
   while(editFlag = 1){
       lcd.begin(16,2);
       lcd.setCursor(0,0);
       lcd.print("Enter no of days: ");
       dayCount = Press(); // should write the correct value on the screen
                   // and the num value is stored in x
      
       delay(2000);
       lcd.clear();
      
       lcd.setCursor(0,0);
       lcd.print("Enter delay 1: ");
       delay1 = Press();
      
       delay(2000);
       lcd.clear();
      
       lcd.setCursor(0,0);
       lcd.print("Enter delay 2: ");
       delay2 = Press();
      
       delay(2000);
       lcd.clear();
      
       lcd.setCursor(0,0);
       lcd.print("Enter delay 3: ");
       delay3 = Press();
      
       delay(2000);
       lcd.clear();
      
       lcd.setCursor(0,0);
       lcd.print("Enter delay 4: ");
       delay4 = Press();

       editFlag = 0;
    }

    while(editFlag == 0){

      /*
       * actuation code
       * 
       * here attach a timer interrupt - when timer count compare is true, 
       * call the isr. 
       * 
       * isr should contain code on actuation. 
       * 
       * question --- how to raise an interrupt for timer compare? 
       */
    }
    
  
}
   
