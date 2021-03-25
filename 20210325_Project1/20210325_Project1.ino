//Stałe
const int buttonPin = A2;  //Przycisk
const int ledPin = 13;     //Dioda
//Zmienne
int buttonPushCounter = 0; //Ilosc przycisniec
int buttonState = 0;       //Aktualny stan przycisku
int lastButtonState = 0;   //Poprzedni stan przycisku

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(ledPin, HIGH);
}

void loop() {
  buttonState = analogRead(buttonPin);
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter++;
      Serial.print("Licznik: ");
      Serial.println(buttonPushCounter);
    }
    delay(5);
  }
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(ledPin, LOW);
  }
  else {
    digitalWrite(ledPin, HIGH);
  }
  lastButtonState = buttonState;
}
