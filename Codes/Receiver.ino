// Ok so this goes on the head. the UNO on the head will receive the radio signal. and then run the 8 vibration modules
#include <RH_ASK.h>
#include <SPI.h> // Required by RH_ASK

RH_ASK driver;

const int motorPin = 12; // 9 and 10 are used by Radiohead

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(motorPin, OUTPUT);

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
      // int rangeB = 255;
      // int rangeA = 128;
      int level = receivedChar - '1'; // index 0–8
      Serial.print("value :");
      // digitalWrite(10, HIGH);
      // int intensity = rangeA + (double)(rangeB - rangeA) * (((double)level * 10) / 100);
      // Serial.print(intensity);
      analogWrite(motorPin, 255);
      // Use delay as intensity
      int delayAmount = 0;
      if (level < 4)
        delayAmount = 40;
      else if (level < 7)
        delayAmount = 80;
      else
        delayAmount = 120;
      delay(delayAmount);
      analogWrite(motorPin, 0);
    }

    digitalWrite(LED_BUILTIN, LOW);
  }
}