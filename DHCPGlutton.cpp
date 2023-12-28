/*
 * This file is part of the Capibara zero (https://github.com/CapibaraZero/fw or https://capibarazero.github.io/).
 * Copyright (c) 2023 Andrea Canale.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
 
#include "DHCPGlutton.hpp"
#include <WiFi.h>
#include "esp_wifi.h"

/* Randomize 6 bytes */
void DHCPGlutton::generate_random_mac()
{
    randomSeed(millis());   // Try to generate true-random number(sometimes it fails)
    /* (Pseudo)Randomly fill mac_address */
    random_mac_address[0] = random(0, 255);
    random_mac_address[1] = random(0, 255);
    random_mac_address[2] = random(0, 255);
    random_mac_address[3] = random(0, 255);
    random_mac_address[4] = random(0, 255);
    random_mac_address[5] = random(0, 255);
}

DHCPGlutton::DHCPGlutton()
{
    WiFi.macAddress(original_mac_address); // Save original MAC to restore it
}

DHCPGlutton::~DHCPGlutton()
{
    esp_wifi_set_mac(WIFI_IF_STA, &original_mac_address[0]); // Restore MAC on destroy
}

void DHCPGlutton::random_mac_address_spoof()
{
    generate_random_mac();                                 // Generate random MAC
    esp_wifi_set_mac(WIFI_IF_STA, &random_mac_address[0]); // Change MAC
}

void DHCPGlutton::send_dhcp_request()
{
    WiFi.reconnect(); // Reconnect to AP to trigger DHCP again
    while (WiFi.status() != WL_CONNECTED)
        ; // Wait until new connection
}