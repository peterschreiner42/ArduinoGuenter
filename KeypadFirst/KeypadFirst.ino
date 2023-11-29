
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
int eingabe[3] = {0,0,0};
int counter = 0;

bool ErsteEingabeKorrekt;
bool AnsageOneAbgespielt;

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
    PartTwo();

  if(ErsteEingabeKorrekt)
    PartThree();
}

bool PartThree()
{
// Timer starten

}

bool PartTwo()
{
  Serial.print("Part2");
  // Ansage EINMAL ausführen
  AnsageOneAbgespielt = true;
}

int CCgetId()
{
  int input_password = 0;

 Serial.println("CCgetId");
  while (true) // Repeat forever
  {
    char key = Tastenfeld.getKey();

    // If it's a digit, add it to the 'pasword'
    if (key >= '0' && key <= '9')
    {
      input_password *= 10;
      input_password += key - '0';
    }

    // If it's the 'enter' key, return the value
    if (key == '#')
      return input_password;

  } // End: while (true)
}

bool PartOne()
{
  Serial.println("Part1");
  int pwdInput = CCgetId();

  Serial.println(pwdInput);
  if(pwdInput == 110)
  {
    Serial.print("true");
    return true;
  }
  Serial.print("false");
  return false;  
}

