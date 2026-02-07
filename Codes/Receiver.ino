// Ok so this goes on the head. the UNO on the head will receive the radio signal. and then run the 8 vibration modules
#include <RH_ASK.h>
#include <SPI.h> // Required by RH_ASK

RH_ASK driver;

const int motorPin = 12; // 9 and 10 are used by Radiohead

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);

  if (!driver.init())
  {
    Serial.println("RadioHead ASK init failed. Check wiring!");
  }
  else
  {
    Serial.println("Receiver ready.");
  }
}

void loop()
{
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen))
  {
    digitalWrite(LED_BUILTIN, HIGH);

    // Print timestamp + received char
    Serial.print("[");
    Serial.print(millis());
    Serial.print(" ms] Received: ");
    Serial.println((char)buf[0]);
    for (uint8_t i = 0; i < buflen; i++)
    {
      Serial.print((char)buf[i]);
    }
    char receivedChar = (char)buf[0];
    if (receivedChar >= '1' && receivedChar <= '9')
    {

      Serial.println("numero");
      int level = receivedChar - '1';
      Serial.print("value :");

      analogWrite(motorPin, 255);

      // Use delay as intensity
      int delayAmount = 0;
      if (level < 4)
        delayAmount = 30;
      else if (level < 7)
        delayAmount = 80;
      else
        delayAmount = 130;

      delay(delayAmount);
      int lightPin = 0;
      if (level == 1)
        lightPin = 2;
      else if (level == 3)
        lightPin = 7;
      else if (level == 5)
        lightPin = 5;
      else if (level == 7)
        lightPin = 4;
      if (lightPin)
      {
        digitalWrite(lightPin, HIGH);
        delay(200);
        digitalWrite(lightPin, LOW);
      }
      analogWrite(motorPin, 0);
    }

    digitalWrite(LED_BUILTIN, LOW);
  }
}