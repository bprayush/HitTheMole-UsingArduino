

int leds = 2; //use 2-6
int buttons = 7; //use 7-11
int init_delay = 500;
int n = 5;
int wrongInput = 12;
int rightInput = 13;
int ledChange;


void setup()
{
  pinMode(A0, INPUT);
  randomSeed(analogRead(A0));
  for (int i = leds; i < (leds + n); i++)
  {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }

  for (int i = buttons; i < (buttons + n); i++)
  {
    pinMode(i, INPUT);
    digitalWrite(i, HIGH);
  }


  pinMode(12, OUTPUT);  
  pinMode(13,OUTPUT);  // LED
  digitalWrite(12, HIGH);
  digitalWrite(13, HIGH);
 
// enable interrupt for pin...
  pciSetup(7);
  pciSetup(8);
  pciSetup(9);
  pciSetup(10);
  pciSetup(11);
  Serial.begin(9600);
}

void loop()
{

  //Serial.println(digitalRead(7));
  ledChange = random(2, 7);
  digitalWrite(ledChange, LOW);
  delay(init_delay);
  digitalWrite(ledChange, HIGH);

}

void pciSetup(byte pin)
{
    *digitalPinToPCMSK(pin) |= bit (digitalPinToPCMSKbit(pin));  // enable pin
    PCIFR  |= bit (digitalPinToPCICRbit(pin)); // clear any outstanding interrupt
    PCICR  |= bit (digitalPinToPCICRbit(pin)); // enable interrupt for the group
}
  
ISR (PCINT0_vect) // handle pin change interrupt for D8 to D13 here
 {    
     //showInputs();
     checkInput();
     Serial.print("LED number: ");
     Serial.println(ledChange);
 }
 
ISR (PCINT2_vect) // handle pin change interrupt for D0 to D7 here
 {
     //showInputs();
     checkInput();
     Serial.print("LED number: ");
     Serial.println(ledChange);
 }  

void checkInput()
{
  
  if(!digitalRead(buttons) && ledChange == 2)
  {
    Serial.println("--------------------------------");
    Serial.println("Inside 2");
    Serial.println(digitalRead(buttons));
    Serial.println("--------------------------------");
    
    digitalWrite(rightInput, LOW);
    delay(400);
    digitalWrite(rightInput, HIGH);
    delay(400);

    init_delay -= 30;
    if (init_delay <= 150)
      init_delay = 150;

    
  }
  else if(!digitalRead(buttons+1) && ledChange == 3)
  {
    Serial.println("--------------------------------");
    Serial.println("Inside 3");
    Serial.println(digitalRead(buttons+1));
    Serial.println("--------------------------------");
    
    digitalWrite(rightInput, LOW);
    delay(400);
    digitalWrite(rightInput, HIGH);
    delay(400);

    init_delay -= 50;
    if (init_delay <= 150)
      init_delay = 150;

  }
  else if(!digitalRead(buttons+2) && ledChange == 4)
  {
    Serial.println("--------------------------------");
    Serial.println("Inside 4");
    Serial.println(digitalRead(buttons+2));
    Serial.println("--------------------------------");
    
    digitalWrite(rightInput, LOW);
    delay(400);
    digitalWrite(rightInput, HIGH);
    delay(400);

    init_delay -= 50;
    if (init_delay <= 150)
      init_delay = 150;

  }
  else if(!digitalRead(buttons+3) && ledChange == 5)
  {
    Serial.println("--------------------------------");
    Serial.println("Inside 5");
    Serial.println(digitalRead(buttons+3));
    Serial.println("--------------------------------");
    
    digitalWrite(rightInput, LOW);
    delay(400);
    digitalWrite(rightInput, HIGH);
    delay(400);

    init_delay -= 50;
    if (init_delay <= 150)
      init_delay = 150;

  }
  else if(!digitalRead(buttons+4) && ledChange == 6)
  {
    Serial.println("--------------------------------");
    Serial.println("Inside 6");
    Serial.println(digitalRead(buttons+4));
    Serial.println("--------------------------------");
    
    digitalWrite(rightInput, LOW);
    delay(400);
    digitalWrite(rightInput, HIGH);
    delay(400);

    init_delay -= 50;
    if (init_delay <= 150)
      init_delay = 150;

  }
  else
  {
    init_delay = 1000;
    digitalWrite(wrongInput, LOW);
    delay(500);
    digitalWrite(wrongInput, HIGH);
  }

  Serial.print("Delay: ");
  Serial.println(init_delay);
  
}


void showInputs()
{
  Serial.print("Pin 7: ");
  Serial.println(digitalRead(7)); 

   Serial.print("Pin 8: ");
  Serial.println(digitalRead(8));  

  Serial.print("Pin 9: ");
  Serial.println(digitalRead(9));  

  Serial.print("Pin 10: ");
  Serial.println(digitalRead(10));  

  Serial.print("Pin 11: ");
  Serial.println(digitalRead(11));  
}

