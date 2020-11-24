const uint8_t led0 = 2; // unsigned integer (8 bits)  (0 to 255) // BIT 0
const uint8_t led1 = 4; // unsigned integer (8 bits)  (0 to 255) // BIT1
const uint8_t led2 = 5; // unsigned integer (8 bits)  (0 to 255) // BIT 2
const uint8_t led3 = 7; // unsigned integer (8 bits)  (0 to 255) // BIT 3
int value;
void setup() {
  Serial.begin(9600);
  

DDRD |= ((1<<led0 | 1<<led1)| (1<<led2 | 1<<led3)); // setting all led pins as output
}

void loop() {
  Serial.println("Please enter a integer between 0 and 15");
  while (Serial.available()==0){
    // do nothing
  }
  value = Serial.parseInt();
  Serial.println (value);

  /////////////////////////////////////////////////
  if(value==0){
  // BIT 0
PORTD = B00000000;
  }
  else if(value ==1){
// 1
PORTD = B00000000; // clearing all the bits to set new bits 
PORTD|=(1<<led0);
  }
  else if(value ==2){
//2
PORTD = B00000000;
PORTD|=(1<<led1);
  }
  else if (value ==3){
//3
PORTD = B00000000;
PORTD|=(1<<led0|1<<led1);
  }
  else if (value ==4){
//4
PORTD = B00000000;
PORTD|=(1<<led2);
  }
  else if (value ==5){
//5
PORTD = B00000000;
PORTD|=(1<<led0|1<<led2);
  }
  else if (value==6){
//6
PORTD = B00000000;
PORTD|=(1<<led1|1<<led2);
}
else if (value ==7){
//7
PORTD = B00000000;
PORTD|=(1<<led0|1<<led1|1<<led2);
}
else if (value ==8){
//8
PORTD = B00000000;
PORTD|=(1<<led3);
}
else if (value ==9){
//9
PORTD = B00000000;
PORTD|=(1<<led0|1<<led3);
}
else if (value ==10){
//10
PORTD = B00000000;
PORTD|=(1<<led1|1<<led3);
}
else if (value == 11){
 PORTD = B00000000;
PORTD|=(1<<led0|1<<led1|1<<led3);
}
else if (value == 12){
  PORTD = B00000000;
  PORTD|=(1<<led3|1<<led2);
}

else if (value == 13){
  PORTD = B00000000;
  PORTD |=(1<<led3|1<<led2|1<<led0);
}
else if (value == 14){
  PORTD = B00000000;
  PORTD |=(1<<led3|1<<led2|1<<led1);
  
}
else if (value == 15){
  PORTD = B00000000;
  PORTD |=((1<<led3|1<<led2)|(1<<led1|1<<led0));
}
else Serial.println("Invalid input");

}
