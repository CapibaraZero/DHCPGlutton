# DHCPGlutton

An ESP32 program to start a DHCP starvation attack via Wi-Fi.

# How it works?

Start by connecting to a WiFi network then, in the loop, you can randomize MAC address and reconnect to the network, triggering DHCP request. Since it's WiFi we can't spoof packet MAC address(it would be ignored by AP) and we need to spoof entire WiFi MAC then reconnect, for this reason the execution is slow. 

For usage, check example folder.

## Current limits

- A bit slow(a /24 network can take up to 15 minutes to finish ip in pool. More client are connected to the network, less time ESP will finish DHCP pool)
- Sometimes RNG generate same MAC address(this cause waste of time)