
/*
 * WiFlyHQ Example httpclient.ino
 *
 * This sketch implements a simple Web client that connects to a 
 * web server, sends a GET, and then sends the result to the 
 * Serial monitor.
 *
 * This sketch is released to the public domain.
 *
 */

#include <WiFlyHQ.h>

#include <SoftwareSerial.h>
SoftwareSerial debugSerial(8,9);

//#include <AltSoftSerial.h>
//AltSoftSerial wifiSerial(8,9);

WiFly wifly;

/* Change these to match your WiFi network */
const char mySSID[] = "GuestNet";
const char myPassword[] = "21208thave";

const char site[] = "192.168.14.139";

void terminal();

void setup()
{
    char buf[32];

    /*Serial.println("Starting");*/
    /*Serial.print("Free memory: ");*/
    /*Serial.println(wifly.getFreeMemory(),DEC);*/

    Serial.begin(9600);
    debugSerial.begin(9600);
    wifly.begin(&Serial, &debugSerial);

    /* Join wifi network if not already associated */
    if (!wifly.isAssociated()) {
        /* Setup the WiFly to connect to a wifi network */
        wifly.setSSID(mySSID);
        wifly.setPassphrase(myPassword);
        wifly.enableDHCP();

        wifly.join();
    } else {
        /*Serial.println("Already joined network");*/
    }

    //terminal();

    /*Serial.print("MAC: ");*/
    /*Serial.println(wifly.getMAC(buf, sizeof(buf)));*/
    /*Serial.print("IP: ");*/
    /*Serial.println(wifly.getIP(buf, sizeof(buf)));*/
    /*Serial.print("Netmask: ");*/
    /*Serial.println(wifly.getNetmask(buf, sizeof(buf)));*/
    /*Serial.print("Gateway: ");*/
    /*Serial.println(wifly.getGateway(buf, sizeof(buf)));*/

    wifly.setDeviceID("Wifly-WebClient");
    /*Serial.print("DeviceID: ");*/
    /*Serial.println(wifly.getDeviceID(buf, sizeof(buf)));*/

    if (wifly.isConnected()) {
        /*Serial.println("Old connection active. Closing");*/
        wifly.close();
    }

    if (wifly.open(site, 80)) {
        /*Serial.print("Connected to ");*/
        /*Serial.println(site);*/

        /* Send the request */
        wifly.println("GET / HTTP/1.0");
        wifly.println();
    } else {
        /*Serial.println("Failed to connect");*/
    }
}

void loop()
{
    /*if (wifly.available() > 0) {*/
    /*    char ch = wifly.read();*/
    /*    Serial.write(ch);*/
    /*    if (ch == '\n') {*/
    /*        [> add a carriage return <] */
    /*        Serial.write('\r');*/
    /*    }*/
    /*}*/

    /*if (Serial.available() > 0) {*/
    /*    wifly.write(Serial.read());*/
    /*}*/
}

/* Connect the WiFly serial to the serial monitor. */
void terminal()
{
    /*while (1) {*/
    /*    if (wifly.available() > 0) {*/
    /*        Serial.write(wifly.read());*/
    /*    }*/


    /*    if (Serial.available() > 0) {*/
    /*        wifly.write(Serial.read());*/
    /*    }*/
    /*}*/
}
