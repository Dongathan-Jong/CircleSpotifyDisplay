#include <SpotifyEsp32.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01A.h>
#include <SPI.h>

#define TFT_CS 5
#define TFT_DC 2
#define TFT_RST 4
#define TFT_MOSI 8
#define TFT_SCLK 10

const char* SSID = "NETGEAR80";
const char* PASSWORD = "tinybanana043";

const char* CLIENT_ID = "";
const char* CLIENT_SECRET = "";
const char* REFRESH_TOKEN = "";

Spotify sp(CLIENT_ID, CLIENT_SECRET);
Adafruit_GC9A01A tft(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);


void setup() {
  Serial.begin(115200);
  delay(500);

  sp.begin();
  while(!sp.is_auth())
  {
    sp.handle_client();
  }
  Serial.println("Auth");
  tft.begin();
  tft.setRotation(0);
  tft.fillScreen(GC9A01A_BLACK);
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
  tft.drawCircle(120, 120, 50, GC9A01A_RED);
}
