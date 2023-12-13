#ifndef DHCPGLUTTON_H
#define DHCPGLUTTON_H

#include <stdint.h>
#include <Arduino.h>

class DHCPGlutton
{
private:
    void generate_random_mac();
    uint8_t random_mac_address[6] = { 0 };
    uint8_t original_mac_address[6] = { 0 };
public:
    DHCPGlutton(/* args */);
    ~DHCPGlutton();
    void random_mac_address_spoof();
    void send_dhcp_request();
};

#endif
