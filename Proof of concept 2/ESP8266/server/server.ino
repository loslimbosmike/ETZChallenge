#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define startChar (';')
#define endChar ('#')
#define buffLeng 32

const char *ssid = "ESP8266_LED_Strip_AP";
const char *pwd = "NaomiLove2011";

ESP8266WebServer server(80);

char *page = "<!DOCTYPE html><html><head><meta name=\"viewport\"content=\"width=device-width,initial-scale=1\"><link rel=\"icon\" href=\"data:,\"><style>html {font-family: Helvetica;display: inline-block;margin: 0pxauto;text-align: center;}.button {background-color: #195B6A;border: none;color: white;padding: 16px40px;text-decoration: none;font-size: 30px;margin: 2px;cursor: pointer;}</style></head><body><h1>Control LED strip</h1><p>Love</p><p><a href=\"/Love\"><button class=\"button\">Toggle Love</button></a></p><p>Everything is good</p><p><a href=\"/Good\"><button class=\"button\">Toggle Good</button></a></p><p>Wink</p><p><a href=\"/Wink\"><button class=\"button\">Toggle Wink</button></a></p><p>Sleep</p><p><a href=\"/Sleep\"><button class=\"button\">Toggle Sleep</button></a></p><p>Morning</p><p><a href=\"/Morning\"><button class=\"button\">Toggle Morning</button></a></p><p>Paw</p><p><a href=\"/Paw\"><button class=\"button\">Toggle Paw</button></a></p><p>Candle light</p><p><a href=\"/Candlelight\"><button class=\"button\">Toggle Candle light</button></a></p></body></html>";
char cmd;

void setup()
{
    Serial.begin(9600);
    delay(10);
    Serial.println("\n");

    WiFi.softAP(ssid, pwd);

    Serial.print("Access Point >>");
    Serial.print(ssid);
    IPAddress IP = WiFi.softAPIP();
    Serial.print("AP IP address: ");
    Serial.println(IP);

    server.on("/", HTTP_GET, handleRoot);
    server.on("/Love", HTTP_GET, handleLove);
    server.on("/Good", HTTP_GET, handleGood);
    server.on("/Wink", HTTP_GET, handleWink);
    server.on("/Sleep", HTTP_GET, handleSleep);
    server.on("/Morning", HTTP_GET, handleMorning);
    server.on("/Paw", HTTP_GET, handlePaw);
    server.on("/Candlelight", HTTP_GET, handleCandlelight);
    server.onNotFound(handleNotFound);

    server.begin();
}

void loop()
{
    server.handleClient();
}

void handleRoot()
{
    server.send(200, "text/html", page);
}
void handleLove()
{
    cmd = 0;
    toggleLED(cmd);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleGood()
{
    cmd = 1;
    toggleLED(cmd);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleWink()
{
    cmd = 2;
    toggleLED(cmd);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleSleep()
{
    cmd = 3;
    toggleLED(cmd);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleMorning()
{
    cmd = 4;
    toggleLED(cmd);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handlePaw()
{
    cmd = 5;
    toggleLED(cmd);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleCandlelight()
{
    cmd = 6;
    toggleLED(cmd);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleNotFound()
{
    server.send(404, "text/plain", "404: Not found");
}
void toggleLED(int seq)
{
    Serial.write(seq);
}
