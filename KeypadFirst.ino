
#include <Keypad.h>

const byte COLS = 4;
const byte ROWS = 4;

char hexaKeys[ROWS][COLS]={
{'D','#','0','*'},
{'C','9','8','7'},
{'B','6','5','4'},
{'A','3','2','1'}
};



byte colPins[COLS] = {2,3,4,5};
byte rowPins[ROWS] = {6,7,8,9};
char eingabe[4];
int counter = 0;

char Taste;
Keypad Tastenfeld = Keypad(makeKeymap(hexaKeys), rowPins, colPins,ROWS,COLS);

// the setup function runs once when you press reset or power the board
void setup()
{
  Serial.begin(9600);
  counter = 0;
}

// the loop function runs over and over again forever
void loop() 
{
  Taste = Tastenfeld.getKey();
  if(Taste)
  {
    Serial.print(Taste);
    eingabe[counter] = (char)Taste;
    if(counter>4) 
    {
    Auswertung(eingabe);
    }
  
    counter++;
  }
}

void Auswertung(char ein[])
{
  char value = (char)ein[0]; 
  Serial.print(ein[0]);
  Serial.print(ein[1]);
  Serial.print(ein[2]);
  Serial.print(ein[3]);

  counter = 0;
}
