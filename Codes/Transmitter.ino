// this is the main UNO. this is what detects and sends the signal.
#include <RH_ASK.h>
#include <SPI.h> 

RH_ASK driver;

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);

  if (!driver.init()) {
    // lol?
    // Default TX pin is 12
  }
}

void loop() {
  const char *msg = "ping";
  digitalWrite(LED_BUILTIN, HIGH); 
  driver.send((uint8_t *)msg, strlen(msg));
  driver.waitPacketSent();
  delay(200);                     
  digitalWrite(LED_BUILTIN, LOW);  
  delay(5000); // Send every 5 seconds
}
