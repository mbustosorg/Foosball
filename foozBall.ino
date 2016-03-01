#include <Servo.h>

#include <Keypad.h>

char code[] = {'x', 'x', 'x', 'x', 'x'};

Servo lock;
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {7, 0, 1, 3}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {2, 4, 5, 6}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 

void setup(){
  lock.attach(8);
  lock.write(0);
  pinMode(13, OUTPUT);
}

void blink(int delayLength) {
    analogWrite(13, 50);
    delay(delayLength);
    analogWrite(13, 0);
}

void loop(){
  char customKey = customKeypad.getKey();
  
  if (customKey){
    if(code[0] == 'x'){
      code[0] = customKey;
    }
    else if(code[1] == 'x'){
      code[1] = customKey;
    }
    else if(code[2] == 'x'){
      code[2] = customKey;
   }
    else if(code[3] == 'x'){
      code[3] = customKey;
    }
    else{
      code[4] = customKey;
      if(code[0] == '5' && code[1] == '8' && code[2] == '0' && code[3] == '9' && code[4] == '*'){
        lock.write(180);
        delay(1000);
        lock.write(0);
      } else{
        lock.write(90);
        delay(1000);
        lock.write(45);
        delay(1000);
        lock.write(0);
      }
      code[0] = 'x'; code[1] = 'x'; code[2] = 'x'; code[3] = 'x'; code[4] = 'x';
    }
    blink(50);
  }
}
