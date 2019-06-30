#include <TimeLib.h>

//Switch + System Setups//
const int stateOnePin = 6; //toggle display to xxx function
const int throwTimePin = 5; //toggle display to Throw Time Function
const int momTimeButPin = 7; //reset RTC if momTimeState HIGH

//VFD TEENSY PIN Assignments //
const int clk = 37;
const int load = 38;
const int blank = 36;
const int dinBlue = 39;
const int dinRed = 35;
const int dinGreen = 34;

//Array Vals
const int numberOfTUBES = 2;
const int numberOfColors = 3;
const int numberOfPinsPerColor = 7;
const int numberOfGrids = 5;
const int numberOfVerticalPins = (numberOfColors * numberOfPinsPerColor);  //21 vertical

//populate grid pins into two arrays for unique control
int grid1[numberOfGrids] = { 25, 24, 23, 22, 21 }; //VFD1:G1=25
int grid2[numberOfGrids] = {18, 17, 16, 15, 14 };
//one grid array for sequential addressing


//arrays containing empty arrays for vertical population
int dinBluePixels[numberOfPinsPerColor];
int dinGreenPixels[numberOfPinsPerColor];
int dinRedPixels[numberOfPinsPerColor];

int k = 0;


void setup() {
  //SYSTEM
  Serial.begin(115200);
  pinMode(stateOnePin, INPUT);
  pinMode(throwTimePin, INPUT);
  pinMode(momTimeButPin, INPUT);

  //RTC
  setSyncProvider(getTeensy3Time);
  while (!Serial);
  delay(100);
  if (timeStatus() != timeSet) {
    Serial.println("Unable to sync with the RTC");
  } else {
    Serial.println("RTC has set the system time");
  }

  //MAX 6921 Chip
  pinMode (dinBlue, OUTPUT);
  pinMode (dinRed, OUTPUT);
  pinMode (dinGreen, OUTPUT);
  pinMode(clk, OUTPUT);
  pinMode(load, OUTPUT);
  pinMode(blank, OUTPUT);

  ///TOGGLE MAX 6921 IC //
  digitalWrite(blank, HIGH);
  delay(500);
  digitalWrite(blank, LOW);
  digitalWrite(clk, LOW);
  digitalWrite(load, LOW);
  digitalWrite(dinBlue, LOW);
  digitalWrite(dinRed, LOW);
  digitalWrite(dinGreen, LOW);
  
   //Turn All Grids ON
  int grids[numberOfGrids * numberOfTUBES] = { 25, 24, 23, 22, 21, 18, 17, 16, 15, 14  };
  for (int i = 0; i < numberOfGrids * 2; i ++) {
    pinMode(grids[i], OUTPUT);
    digitalWrite (grids[i], HIGH);
  }
}
void loop() {
  systemRun();
}
