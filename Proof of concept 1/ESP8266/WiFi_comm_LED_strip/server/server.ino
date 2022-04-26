#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

#define ENDCHAR '#'

const char *ssid = "HomeSweetHome";
const char *password = "Mike2016Naomi";

ESP8266WebServer server(80);

char *page = "<!DOCTYPE html> <html><head><meta name =\"viewport\"content=\"width=device-width,initial-scale=1\"><link rel=\"icon\" href=\"data:,\"><style>html{font-family:Helvetica;display:inline-block;margin:0pxauto;text-align:center;}.button{background-color:#195B6A;border:none;color:white;padding:16px40px;text-decoration:none;font-size:30px;margin:2px;cursor:pointer;}</style></head><body><h1>Control LED strip</h1><p>Wave</p><p><a href =\"/Wave\"><button class=\"button\">Toggle wave</button></a></p><p>Flash</p><p><a href =\"/Flash\"><button class=\"button\">Toggle Flash</button></a></p><p>Red</p><p><a href =\"/Red\"><button class=\"button\">Toggle Red</button></a></p><p>Green</p><p><a href =\"/Green\"><button class=\"button\">Toggle Green</button></a></p><p>Blue</p><p><a href =\"/Blue\"><button class=\"button\">Toggle Blue</button></a></p><p>Even</p><p><a href =\"/Even\"><button class=\"button\">Toggle Even</button></a></p><p>Odd</p><p><a href =\"/Odd\"><button class=\"button\">Toggle Odd</button></a></p><p>None</p><p><a href =\"/None\"><button class=\"button\">Toggle None</button></a></p></body></html> ";
char cmd;

void setup()
{
    Serial.begin(115200);

    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", HTTP_GET, handleRoot);
    server.on("/Wave", HTTP_GET, handleWave);
    server.on("/Flash", HTTP_GET, handleFlash);
    server.on("/Red", HTTP_GET, handleRed);
    server.on("/Green", HTTP_GET, handleGreen);
    server.on("/Blue", HTTP_GET, handleBlue);
    server.on("/Even", HTTP_GET, handleEven);
    server.on("/Odd", HTTP_GET, handleOdd);
    server.on("/None", HTTP_GET, handleNone);
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
void handleWave()
{
    cmd = 0;
    toggleLED(cmd);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleFlash()
{
    cmd = 1;
    toggleLED(cmd);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleRed()
{
    cmd = 2;
    toggleLED(cmd);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleGreen()
{
    cmd = 3;
    toggleLED(cmd);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleBlue()
{
    cmd = 4;
    toggleLED(cmd);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleEven()
{
    cmd = 5;
    toggleLED(cmd);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleOdd()
{
    cmd = 6;
    toggleLED(cmd);
    server.sendHeader("Location", "/");
    server.send(303);
}
void handleNone()
{
    cmd = 7;
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
