int IR1 = 2;
int IR2 = 3;
int LED1 = 5;
int LED2 = 6;
int LDR = A3;
int LDRValue;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(LDR, INPUT);
  
  LDRValue = 0;
  
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}

void loop() {

  LDRValue = analogRead(LDR);
  Serial.print("sensor = ");
  Serial.print(LDRValue);
  delay (500);

  if (LDRValue >= 100)
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    Serial.println("It's Bright Outside; Lights status: OFF");
  }
  if ((LDRValue < 100) && (digitalRead(IR1) == HIGH)) 
    {
      digitalWrite(LED1, HIGH);
      Serial.println("It's Dark Outside; LED1 Lights status: ON");
      delay(2000);
    }
  
  if ((LDRValue < 100) && (digitalRead(IR2) == HIGH)) 
    {
      digitalWrite(LED2, HIGH);
      Serial.println("It's Dark Outside; LED2 Lights status: ON");
      delay(2000);
    }  
}
