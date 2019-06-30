void getTime() {
  if (Serial.available()) {
    time_t t = processSyncMessage();
    if (t != 0) {
      Teensy3Clock.set(t); // set the RTC
      setTime(t);
    }
  }
  delay(1000);
}
time_t getTeensy3Time()
{
  return Teensy3Clock.get();
}
unsigned long processSyncMessage() {
}
