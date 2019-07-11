# ESP8266Now
PoC IoT button for ServiceNow

This project will create an IoT button out of an ESP8266 board I had laying around. This button will trigger the creation of a new incident. Note: this particular board has built-in LCD which is absolutely not needed for this project.  

https://www.amazon.com/MakerFocus-ESP8266-Development-Display-Support/dp/B076JDVRLP/ref=sr_1_4?keywords=esp8266+lcd&qid=1562794279&s=gateway&sr=8-4

Like I said, it was laying around and was the first one I picked up.  You can get cheaper boards.

I'll use https://www.makeuseof.com/tag/wifi-connected-button-esp8266-tutorial/ as a starting point.  

Actually, maybe I'll make use of the LCD to give feedback....yeah, I think I'll do that.  Make it return the incident number or whatever.

I'm using the on-board PRG/FLASH button to keep it simple.

https://www.dropbox.com/s/gb85ydpxjefr60j/IMG_1810.MOV?dl=0

Can you guess what I was watching?

# The Config....

![The board](https://raw.githubusercontent.com/JasonVonKrueger/ESP8266Now/master/Resources/2019-07-11_08h41_18.png)

That's it.  No circuits to build.  You just need to have the board and set up your computer to program it.  I'm using the Arduino IDE amd there are tons of sites that show you how to do this so I'm not going to. Go here for starters:

https://www.makeuseof.com/tag/wifi-connected-button-esp8266-tutorial/

On the ServiceNow side, it's just a simple REST API that uses the GlideRecord class to create an incident. To make this work with minimal fuss, I did remove the requirement for authentication.  Don't tell ServiceNow.

![What not to do](https://raw.githubusercontent.com/JasonVonKrueger/ESP8266Now/master/Resources/2019-07-11_18h14_20.png)

# The Code

```c
#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

#ifndef STASSID
#define STASSID "AP_ID"
#define STAPSK  "super_secret"
#endif

const char* ssid     = STASSID;
const char* password = STAPSK;
const char* host = "dev72113.service-now.com";
const int httpsPort = 443;
const char fingerprint[] PROGMEM = "03 46 c1 6e 3b f2 de eb 07 c3 a1 65 84 fc 65 43 9d a1 9c f8";
const int buttonPin = 0;
int buttonState = 0; 
```
