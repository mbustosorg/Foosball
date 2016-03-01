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
  pinMode(13, OUTPUT);
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
    else if(code[4] == 'x'){
      code[4] = customKey;
    }
    else{
      if(code[0] == '5'){
        lock.write(180);
        delay(15);
        lock.write(0);
      } else{
        lock.write(90);
        delay(15);
        lock.write(45);
      }
      lock.write(0);
    }
    analogWrite(13, 50);
    delay(50);
    analogWrite(13, 0);
  }
}
