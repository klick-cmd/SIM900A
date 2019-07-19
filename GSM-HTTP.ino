include <SoftwareSerial.h>
SoftwareSerial gprsSerial(2, 3);

void setup()
{
  gprsSerial.begin(9600);
  Serial.begin(9600);

  Serial.println("Config SIM900...");
  delay(2000);
  Serial.println("Done!...");
  gprsSerial.flush();
  Serial.flush();

  

  // attach or detach from GPRS service 
  gprsSerial.println("AT+CGATT?");
  delay(100);
  toSerial();


  // bearer settings
  gprsSerial.println("AT+SAPBR=3,1,\"CONTYPE\",\"GPRS\"");
  delay(2000);
  toSerial();

  // bearer settings
  gprsSerial.println("AT+SAPBR=3,1,\"APN\",\"internet\"");
  delay(2000);
  toSerial();

  // bearer settings
  gprsSerial.println("AT+SAPBR=1,1");
  delay(2000);
  toSerial();

  gprsSerial.println("AT+SAPBR=2,1");
  delay(2000);
  toSerial();
}


void loop()
{
   // initialize http service
   gprsSerial.println("AT+HTTPINIT");
   delay(2000); 
   toSerial();

   gprsSerial.println("AT+HTTPPARA=\"CID\",1");
   delay(2000); 
   toSerial();


   // set http param value
   gprsSerial.println("AT+HTTPPARA=\"URL\",\"192.xxx.x.xxx/insert.php?temp=2015\"");  
   delay(2000);
   toSerial();

   

   // set http action type 0 = GET, 1 = POST, 2 = HEAD
   gprsSerial.println("AT+HTTPACTION=0");
   delay(6000);
   toSerial();

   // read server response
   gprsSerial.println("AT+HTTPREAD"); 
   delay(1000);
   toSerial();

   gprsSerial.println("");
   gprsSerial.println("AT+HTTPTERM");
   toSerial();
   delay(300);

   gprsSerial.println("");
   delay(10000);
}

void toSerial()
{
  while(gprsSerial.available()!=0)
  {
    Serial.write(gprsSerial.read());
  }
}
