/*
   FSM assignment
*/

#include <Arduino.h>
#include <Wire.h>

enum Count {zero, one, two, three, four, five, six, seven, downSeven, downSix, downFive, downFour, downThree, downTwo, downOne, downZero};

Count countPlace = zero;

int pushed = 0;

void setup() {
  Serial.begin(9600);
}

bool checkReverse(){
    pushed = Serial.read();
    if(pushed>-1){
      return false;
   }
   else{
    return true;
   }
}

Count nextCount(Count count){
  switch (count) {
    case zero: 
    Serial.println("0: 000");
      if(checkReverse()){              
        count = one;
        }
         else{
          count = downOne;
          Serial.println("Reverse");
        }
          break;
      
    case one: 
    Serial.println("1: 001");
      if(checkReverse()){              
        count = two;
        }
         else{
          count = downTwo;
          Serial.println("Reverse");
        }
          break;
      
    case two: 
    Serial.println("2: 010");
      if(checkReverse()){              
        count = three;
        }
         else{
          count = downThree;
          Serial.println("Reverse");          
        }
          break;

    case three: 
    Serial.println("3: 011");
      if(checkReverse()){              
        count = four;
        }
         else{
          count = downFour;
          Serial.println("Reverse");
        }
          break;
          
    case four: 
    Serial.println("4: 100");
      if(checkReverse()){              
        count = five;
        }
         else{
          count = downFive;
          Serial.println("Reverse");       
        }
          break;

    case five: 
    Serial.println("5: 101");
      if(checkReverse()){              
        count = six;
        }
         else{
          count = downSix;
          Serial.println("Reverse");        
        }
          break;

    case six: 
    Serial.println("6: 110");
      if(checkReverse()){              
        count = seven;
        }
         else{
          count = downSeven;
          Serial.println("Reverse");        
        }
          break;
          
    case seven: 
    Serial.println("7: 111");
      if(checkReverse()){              
        count = zero;
        }
         else{
          count = downZero;        
          Serial.println("Reverse");
        }
          break;

    case downSeven: 
    Serial.println("7: 111");
      if(checkReverse()){              
        count = downSix;
        }
         else{
          count = six;
          Serial.println("Reverse");
        }
          break;
          
    case downSix: 
    Serial.println("6: 110");
      if(checkReverse()){              
        count = downFive;
        }
         else{
          count = five;
          Serial.println("Reverse");
        }
          break;
          
    case downFive: 
    Serial.println("5: 101");
      if(checkReverse()){              
        count = downFour;
        }
         else{
          count = four;
          Serial.println("Reverse");
        }
          break;

    case downFour: 
    Serial.println("4: 100");
      if(checkReverse()){              
        count = downThree;
        }
         else{
          count = three;
          Serial.println("Reverse");
        }
          break;
          
    case downThree: 
    Serial.println("3: 011");
      if(checkReverse()){              
        count = downTwo;
        }
         else{
          count = two;
          Serial.println("Reverse");
        }
          break;

    case downTwo: 
    Serial.println("2: 010");
      if(checkReverse()){              
        count = downOne;
        }
         else{
          count = one;
          Serial.println("Reverse");
        }
          break;

    case downOne: 
    Serial.println("1: 001");
      if(checkReverse()){              
        count = downZero;
        }
         else{
          count = zero;
          Serial.println("Reverse");
        }
          break;

    case downZero: 
    Serial.println("0: 000");
      if(checkReverse()){              
        count = downSeven;
        }
         else{
          count = seven;
          Serial.println("Reverse");
        }
          break;
      }
   return count;
}

void loop() {
  countPlace = nextCount(countPlace);
  delay(500);
}
