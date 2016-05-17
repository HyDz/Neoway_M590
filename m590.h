/*

Neoway_M590 by HyDz

Control M590 GSM module from Neoway 

Based on a tehniq3 work you can see here https://github.com/tehniq3/M590_GPRS

*/

#include <String.h> // To convert char to *char with Arduino Due

char inchar;
char insms[7]={0}; // 7 is the number of characters that the readSMS() function will return you can up this number


void floatTochar(float toconvert){
sprintf(convertedfloat, "%f", toconvert);
 }

void duplexCOM(){
while(Serial2.available()) Serial.write(Serial2.read());
while(Serial.available()) Serial2.write(Serial.read());
}

void sendSMS(char *number,char *content){

char atcmgs[]="AT+CMGS=";
char numcommand[37];
char cr[] = "\r";

strcpy(numcommand,atcmgs);
strcat(numcommand,number);
strcat(numcommand,cr);

  
    Serial2.print("\r");
  delay(1000); 
 Serial2.print("AT+CSCS=\"GSM\"\r"); // set GSM charset
  delay(1000);
  Serial2.print("AT+CMGF=1\r");  // set SMS mode to text
  delay(1000);
  Serial2.print(numcommand);
  delay(1000);
  Serial2.print(content);   //The text of the message to be sent
  delay(1000);
  Serial2.write(0x1A);  // command for send sms, code for CTRL-Z
  delay(1000); 
  }
  
  void readSMS(){
  byte index = 0;
  if(Serial2.available() >0)
    {
      for (int i=0; i <= 5; i++){
      inchar = Serial2.read();
      insms[index] = inchar;
      index++;
      insms[index] = '\0';
      }
      return;
      }
  }

void clearSMS(){

Serial2.print("AT+CMGF=1\r");  // set SMS mode to text
delay(1000);

Serial2.print("AT+CSCS=\"GSM\"");
Serial2.print("\r");
delay(1000);

Serial2.print("AT+CMGF=1\r");  // set SMS mode to text
delay(1000);

  // blurt out contents of new SMS upon receipt to the GSM shield's serial out
Serial2.print("AT+CNMI=2,2,0,0,0\r"); 
delay(1000);

Serial2.println("AT+CMGD=1,4"); // delete all SMS
delay(1000);  
  }
  
  
