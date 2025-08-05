#include <SpotifyEsp32.h>
#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01A.h>
#include <SPI.h>

#define TFT_CS 5
#define TFT_DC 2
#define TFT_RST 4
#define TFT_MOSI 8
#define TFT_SCLK 10

const char* SSID = "";
const char* PASSWORD = "";

const char* CLIENT_ID = "";
const char* CLIENT_SECRET = "";
const char* REFRESH_TOKEN = "";

Spotify sp(CLIENT_ID, CLIENT_SECRET, REFRESH_TOKEN);
Adafruit_GC9A01A tft(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);


void setup() 
{
  Serial.begin(115200);
  delay(500);
  tft.
  wifiConnect();

  sp.begin();
  while(!sp.is_auth())
  {
    sp.handle_client();
  }
  Serial.println("Auth");
  response r = sp.get_current();

  tft.endSession();
  tft.begin();
  tft.setCursor(0,0);
  sp.authenticate();
  tft.setTextSize(1.5);
  tft.setRotation(3);
  tft.fillScreen(GC9A01A_BLACK);
  tft.setTextColor(GC9A01A_GREEN);
}

void loop() 
{
  for(int i = 120; i > 115; i--)
  {
    tft.drawCircle(120,120, i,GC9A01A_GREEN);
  }
  delay(5000);
  print_response(sp.currently_playing());
}

void getInfo()
{
  double counter = 0.0;
  sp.startUp();
  if(sp.currently_playing() == true)
  {
    Serial.println("playing right now!");
    counter+= 0.1;
  }
  else if(chain == 0)
  {
    sp.print();
  }
  Serial.println("done!");

  for(int i = 0; i < width; i++)
  {
    Serial.print("Ping: ");
    Serial.println(i);
    for(int j = 0; j < height; j++)
    {
      Serial.out.println("okay");
    }
  }
  
}

void wifiConnect()
{
  WiFi.begin(SSID, PASSWORD);
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected To Wifi.");
}

 
