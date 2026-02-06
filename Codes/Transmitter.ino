#include <RH_ASK.h>
#include <SPI.h>        // Required by RH_ASK
#include <Keypad.h>     // Keypad library

// --- RF Driver ---
RH_ASK driver;

// --- Keypad Setup ---
const byte ROWS = 4; // 4 rows
const byte COLS = 4; // 4 columns

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; // adjust to your wiring
byte colPins[COLS] = {5, 4, 3, 2}; // adjust to your wiring

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  if (!driver.init()) {
    Serial.println("RF init FAIL");
  } else {
    Serial.println("Transmitter Ready");
  }
}

void loop() {
  // Check keypad input
  char key = keypad.getKey();
  if (key) {
    // Build message (single char string)
    char msg[2];
    msg[0] = key;
    msg[1] = '\0';

    Serial.print("Sending key: ");
    Serial.println(msg);

    digitalWrite(LED_BUILTIN, HIGH);

    driver.send((uint8_t *)msg, strlen(msg));
    driver.waitPacketSent();

    digitalWrite(LED_BUILTIN, LOW);
  }

  // You can also add periodic ping here if needed
}
