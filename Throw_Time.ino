void throwTime() {

  for (int i = 0; i < numberOfGrids*2; i++) {
    Serial.print (i);
    if (i <= numberOfGrids-1) {
      digitalWrite(grid1[i], HIGH);
      Serial.print (" : Grid 1");
    }
    if (i >= numberOfGrids) {
      digitalWrite(grid2[i-5], HIGH);
      Serial.print (" : Grid 2");
    }
    for (int j = 0; j < numberOfPinsPerColor; j ++) {
      if (j == k) digitalWrite (dinGreen, 1);
      else digitalWrite (dinGreen, 0);
      if (j == k) digitalWrite (dinBlue, 1);
      else digitalWrite (dinBlue, 0);
      if (j == k) digitalWrite (dinRed, 1);
      else digitalWrite (dinRed, 0);
      if (j == k) digitalWrite (dinBlue, 1);
      else digitalWrite (dinBlue, 0);
      digitalWrite (clk, HIGH);
      delay(10);
      digitalWrite (clk, LOW);
     
    if (i <= numberOfGrids) {
      digitalWrite(grid1[i], LOW);
      Serial.println (" -- G1 off");
    }
      if (i >= numberOfGrids) { 
      digitalWrite(grid2[i-numberOfGrids], LOW);
      Serial.println (" -- G2 off");
  
      }
    }
    }
  digitalWrite(clk, LOW);
  digitalWrite(load, HIGH);
  delay(10);
  digitalWrite(load, LOW);
  delay(100);

  k = k + 1;
  if (k > numberOfPinsPerColor - 1) k = 0;
}





//
//  for (int j = numberOfPinsPerColor * 2; j >= 0; j--) {
//    digitalWrite(dinGreen, dinBluePixels[j]);
//    digitalWrite(dinBlue, dinBluePixels[j]);
//    digitalWrite(dinRed, dinBluePixels[j]);
//    digitalWrite(clk, HIGH);
//    delay(10);
//    digitalWrite(clk, LOW);
//    delay(10);
//  }
