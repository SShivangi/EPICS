//pin init
int ledPin = 13;
int hallsensorPin = 3 ;
int buzzerPin = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(hallsensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(5000); // this is the time the buzzer waits before starting- for now I have set it 5 sec
  digitalWrite(hallsensorPin, HIGH); // does not turn the hallsensor input low and follows the prior code for high input - ledPin = High, BuzzerPin = high
  
  if (digitalRead(hallsensorPin) == HIGH)
  {
    digitalWrite(buzzerPin, HIGH);
    delay(3000);
    digitalWrite(ledPin, HIGH);
  }
  else
  if (digitalRead(hallsensorPin) == LOW)
  //else
  {
    digitalWrite(buzzerPin, HIGH);
    delay(3000);
    digitalWrite(ledPin, LOW);
  }
  delay(3000);
  digitalWrite(hallsensorPin , LOW);
  digitalWrite(ledPin,LOW);
  digitalWrite(buzzerPin, LOW);
  delay(5000);

  //delay(1000);
}
