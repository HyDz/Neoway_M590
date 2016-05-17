/*

This example send an sms to a defined number each time the Arduino boot

*/

#include <M590.h> 

char phonenumber[] = "\"06xxxxxxxx\""; // phone number the sms will be send.
char smscontent[] = "M590 GSM Module Test by HyDz"

void setup(){
 // initialize both serial ports:
 Serial.begin(9600); // Arduino - USB Serial
 Serial2.begin(115200); // Arduino - M590 Serial // My module come with a 115200 baudrate it can be 9600 or other.
 delay(5000);  // give time to log on to network.
 sendSMS(phonenumber, smscontent);
 }
 
 void loop(){
 }
 
 
