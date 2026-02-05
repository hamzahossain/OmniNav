// Ok so this goes on the head. the UNO on the head will receive the radio signal. and then run the 8 vibration modules
#include <RH_ASK.h>
#include <SPI.h> 

RH_ASK driver;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600); // Open Serial Monitor at 9600 baud

  if (!driver.init()) {
    Serial.println("RadioHead ASK init failed. Check wiring!");
  } else {
    Serial.println("Receiver ready.");
  }
}

void loop() {
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) {
    // Blink LED when a message is received
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);

    Serial.print("[");
    Serial.print(millis()); // milliseconds since reset
    Serial.print(" ms] Received: ");

    for (uint8_t i = 0; i < buflen; i++) {
      Serial.print((char)buf[i]);
    }

    Serial.println();
  }
}
