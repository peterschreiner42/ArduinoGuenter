
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

bool ErsteEingabeKorrekt;
bool AnsageOneAbgespielt;
char Taste;
Keypad Tastenfeld = Keypad(makeKeymap(hexaKeys), rowPins, colPins,ROWS,COLS);

// the setup function runs once when you press reset or power the board
void setup()
{
  Serial.begin(9600);
  counter = 0;

  ErsteEingabeKorrekt = false;
  AnsageOneAbgespielt = false;
}

// the loop function runs over and over again forever
void loop() 
{
  if(!ErsteEingabeKorrekt)
    ErsteEingabeKorrekt = PartOne();

  if(ErsteEingabeKorrekt && !AnsageOneAbgespielt) // wird somit nur einmal ausgeführt wenn Erster Part erfolgreich war.
    PartTwo()

  if(ErsteEingabeKorrekt)
    PartThree();
}

bool PartThree()
{
// Timer starten

}

bool PartTwo()
{

  // Ansage EINMAL ausführen
  AnsageOneAbgespielt = true;
}

bool PartOne()
{
  Taste = Tastenfeld.getKey();
  if(Taste)
  {
    Serial.print(Taste);
    eingabe[counter] = (char)Taste;
    if(counter>4) 
    {
        counter =0;
        return Auswertung(eingabe);
    }
  
    counter++;
  }
  return false;
}

bool Auswertung(char ein[])
{
  if(ein[0]=1 & ein[2]=1 &ein[3]=3)
    return true;
  else 
    return false;
}
