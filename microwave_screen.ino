#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int secunds = 0;
int minutes = 0;
int button_1 = 10;
int button_2 = 9;
int buttonState_1 = 0;
int buttonState_2 = 0;
int led = 8;
int cont = 0;
int visual = 0;
int visual_2 = 0;

void setup() {
  pinMode(button_1,INPUT);
  pinMode(button_2,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}
void loop() {
  buttonState_1 = digitalRead(button_1);
  buttonState_2 = digitalRead(button_2);
  minutes = int(secunds/60);
  
  if (buttonState_1 == HIGH){
    secunds +=30;
    visual+=30;
    delay(300);
    if (visual > 30){
      visual = 0;  
    }
  } 
  else if (buttonState_2 == HIGH){ 
    cont+=1;
    delay(500);
  }
  else if (cont == 1){
    if (visual == 0 && minutes > 0){
      visual=59;
    } 
    else if (minutes >=0){
      if (visual!=0){
        secunds-=1;
        visual -=1;
        visual_2 -=1;
        delay(500);
      }
      else if (visual == 0){
        digitalWrite(led,HIGH);
      }
    }
  }
  else if (cont == 2){
    minutes = 0;
    visual = 0;
    cont = 0;
    digitalWrite(led,LOW);
  }
  
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(minutes);
  lcd.print(":");
  if(visual < 10){
    lcd.print("0");
  }
  lcd.print(visual);

  Serial.println(visual);
}
