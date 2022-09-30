#include <ctype.h>
#define LED_PIN 11
const int buzzer = 8;

static char charToMorseCode[26][5] = {
  ".-", "-...", "-.-.", "-..",".","..-.",
  "--.", "....","..",".---","-.-", ".-..","--","-.",
  "---", ".--.","--.-",".-.","...", "-","..-"," ...-",
  ".--", "-..-","-.--","--.."
  };

void setup() {

  pinMode(buzzer, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
 
}


void execute(char* code){

  while(*code !='\0'){
      beep(*code);
      code++;
      delay(100);
  }
  
}


void beep(char c){

  switch(c){

    case '.' :
    {
      tone(buzzer,300);
      analogWrite(LED_PIN, 255);
      delay(155);
      noTone(buzzer);
      analogWrite(LED_PIN, 0);
      delay(150);
    }; break;
    case '-' :
    {
      tone(buzzer,300);
      analogWrite(LED_PIN, 255);
      delay(540);
      noTone(buzzer);
      analogWrite(LED_PIN, 0);
      delay(100);
    }; break; 
    
    default :
    {
      analogWrite(LED_PIN, 0);
      delay(3000);
    }; break; 
    
    }
  
}

void decode(char* msg){
  char c;
  while(*msg != '\0'){
      c = toupper(*msg);
      execute(charToMorseCode[c - 'A']);
      msg++;

      delay(1000);
    }
  
  
}

void loop() {
  
  char text[25] = "IGOR VOLI ANU";

  decode(text);

}