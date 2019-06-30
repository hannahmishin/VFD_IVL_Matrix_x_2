void systemRun() {

  long lastDebounceTime = 0;
  long debounceDelay = 50;

  int stateOneState;
  int lastStateOneState;
  int throwTimeState;
  int lastThrowTimeState;
  int momTimeState;
  int lastMomTimeState;
  boolean displayStateOne = false;
  boolean doTimeSetNow = false;
  boolean displayThrowTime = false;
  boolean displayStateThree = false;

  //State One Set
  int stateOneRead = digitalRead (stateOnePin);
  int throwTimeRead = digitalRead (throwTimePin);
  int momTimeRead = digitalRead(momTimeButPin);

  //State One
  if (stateOneRead != lastStateOneState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    stateOneState = stateOneRead;
  }
  if (stateOneState == HIGH) {
    displayStateOne = true;
    displayThrowTime = false;
    doTimeSetNow = false;
  }
  lastStateOneState = stateOneState;

  //Throw Time State
  if (throwTimeRead != lastThrowTimeState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    throwTimeState = throwTimeRead;
  }
  if (throwTimeState == HIGH) {
    displayThrowTime = true;
    displayStateOne = false;
    doTimeSetNow = false;
  }
  lastThrowTimeState = throwTimeState;

  ///Get Time
  if (momTimeRead != lastMomTimeState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    momTimeState = momTimeRead;
  }
  if (momTimeState == HIGH) {
    doTimeSetNow = true;
    displayStateOne = false;
    displayThrowTime = false;
  }
  lastMomTimeState = momTimeState;

  if (displayStateOne == false && displayThrowTime  == false &&  doTimeSetNow  == false) {
    displayStateThree = true;
  }

  ///change display
  if (displayStateOne == true) {
    Serial.println ("displayStateOne");
  }
  if (displayThrowTime  == true) {
    throwTime();
    Serial.println ("displayThrowTime");
  }
  if (doTimeSetNow  == true) {
    getTime();
    Serial.println ("doTimeSetNow");
  }
  if (displayStateThree  == true) {
    Serial.println ("displayStateThree");
  }
}
