#include <RH_ASK.h>
#include <SPI.h> // Required even if not used directly

RH_ASK driver;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(9600); // Open Serial Monitor at 9600 baud

  if (!driver.init()) {
    Serial.print("FAIL");
    // If init fails, check wiring
    // Default TX pin is 12
  } else Serial.println("Transmitter Ready");
}

void loop() {
  const char *msg = "a";
  Serial.print("Sending [");
  Serial.print(millis());
  Serial.println(" ms]");
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  
  Serial.print("SENT [");
  Serial.print(millis());
  Serial.println(" ms]");

  delay(200);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(2000-200); // Send every 5 seconds
}