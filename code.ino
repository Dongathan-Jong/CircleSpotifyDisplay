#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01A.h>
#include <SPI.h>

#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

Adafruit_GC9A01A tft(TFT_CS, TFT_DC, TFT_RST);

int ballX = 120;
int ballY = 120;
int ballRadius = 10;
int speedX = 2;
int speedY = 3;
uint16_t ballColor = GC9A01A_RED;
uint16_t bgColor = GC9A01A_BLACK;

void setup() {
  Serial.begin(115200);
  delay(500);
  
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(bgColor);
}

void loop() {
  tft.fillCircle(ballX, ballY, ballRadius, bgColor);

  ballX += speedX;
  ballY += speedY;

  if (ballX - ballRadius <= 0 || ballX + ballRadius >= tft.width()) {
    speedX = -speedX;
  }
  if (ballY - ballRadius <= 0 || ballY + ballRadius >= tft.height()) {
    speedY = -speedY;
  }

  tft.fillCircle(ballX, ballY, ballRadius, ballColor);

  delay(10); 
}
