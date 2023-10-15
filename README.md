# 恋に落ちて
This application is an application exclusively for M5Dial. 
The motif is the famous Japanese phrase "Fall in love."

# Build
- I recommend using PlatformIO on VS Code to build and upload because it's convenient and excellent.

# Workaround
- if you encounter SPI pin number error, you can fix it as a followings.
  - open pins_arduino.h
    - \.platformio\packages\framework-arduinoespressif32\variants\m5stack_stamp_s3\pins_arduino.h
  - insert the following codes

```diff
static const uint8_t TXD2 = 1;
static const uint8_t RXD2 = 2;

+static const uint8_t SCK = 4;
+static const uint8_t MISO = 5;
+static const uint8_t MOSI = 6;
+static const uint8_t SS = 7;

static const uint8_t SDA = 13;
static const uint8_t SCL = 15;
```
 
# Instructions
- Power ON M5Dial
- Push BtnA to reset application.
- Turn M5Dial clockwise slowly.
- with looking at the display.

# Commentary
The song "恋に落ちて" can be translated into English as "Falling in Love." 
This song typically revolves around the theme of romance, 
specifically the moment when two individuals deeply in love surrender to their feelings and "fall in love."

Through its lyrics and melody, 
the song often celebrates the magic and allure of love, 
highlighting the wonder and excitement of falling in love. 

It praises how enchanting and almost spellbinding the experience of love can be and how special and joyful that moment is.

This song explores the richness of love, the emotions it evokes, and the happiness it brings, 
often resonating with many people. When expressed in English, similar themes and emotions are conveyed through the lyrics and melody.

