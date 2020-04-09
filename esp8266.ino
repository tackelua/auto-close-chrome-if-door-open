#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char *ssid = "your-wifi-ssid";
const char *password = "your-wifi-password";

const char *host = "server-ip";
const uint16_t port = 3000;

const uint8_t input = 5;

void setup()
{
    Serial.begin(74880);
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    pinMode(input, INPUT_PULLUP);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(200);
        Serial.print(".");
    }

    Serial.println("\r\nWiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void loop()
{
    static bool wasDoorOpen = digitalRead(input);
    bool isDoorOpen = digitalRead(input);
    if (!wasDoorOpen && isDoorOpen)
    {
        gg();
    }
    wasDoorOpen = isDoorOpen;
    delay(1);
}

void gg()
{
    HTTPClient http;
    http.begin("http://192.168.1.9:3000/20gg");
    int httpCode = http.GET();

    if (httpCode == 200)
    {
        Serial.println("GG");
    }
    else
    {
        Serial.println("Game over");
    }

    http.end();
}