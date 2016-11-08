#include<SoftwareSerial.h>
#include<TinyGPS++.h>

SoftwareSerial gsm(3,4);
SoftwareSerial gps_ss(10,11);
TinyGPSPlus gps;

int flag =0;

String message1 = "";

char number[13];
int flag1 = 0, var1;
String check, sub;
int first_index;

void setup() {
gsm.begin(9600);
Serial.begin(9600);
gsm.println("AT");
}

void loop()
{
  while(flag1==0)
  {
    check="";
    sub = "";
  if(gsm.available()>0)
  {
    check = gsm.readString();
    Serial.print(check);
    var1 = check.indexOf("+CLIP");
    if(var1>0)
    {
     first_index = check.indexOf('"');
     Serial.println(first_index);
     sub = check.substring(first_index+1,first_index+14);
    }
    Serial.println(sub);
    if(sub == "+919176858568")
    {
    flag1 = 1;
    gsm.println("ATH");
    gsm.end();
    gps_ss.begin(9600);
    break;
    }
   }
  }

    switch(flag1)
    {
      case 0: break;
      case 1: 
              {
                while(flag==0)
                {
                  while(gps_ss.available()>0) 
                    if(gps.encode(gps_ss.read()))
                    {
                      createSMS();
                      flag=1; 
                      break;
                    }
                }
                flag=0;
                break;
              }
      default: break;
    }

}

void createSMS()
{ 
  
  if(gps.location.isUpdated())
  {
    message1 = "http://maps.google.com/maps?q=loc:";
    message1 += String(gps.location.lat(),6);
    message1 += ",";
    message1 += String(gps.location.lng(),6);
    Serial.println(message1);
  }
  else
  {
    message1 = "Location Not Avaliable";
  }
   sendSMS();
}

void sendSMS()
{
  gps_ss.end();
  gsm.begin(9600);
  delay(1000);
  gsm.println("AT+CMGF=1");
  delay(1000);
  gsm.println("AT+CMGS=\"+919176858568\"");
  delay(1000);
  gsm.print(message1);
  delay(100);
  gsm.write(0x1A);
  gsm.write(0x0D);
  gsm.write(0x0A);
  flag1=0;
}

