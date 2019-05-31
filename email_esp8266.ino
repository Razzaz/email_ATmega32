#include <ESP8266WiFi.h>
const char* ssid = "redmi";           // Enter the SSID of your WiFi Network
const char* password = "1123581321";  // Enter the Password of your WiFi Network
char server[] = "mail.smtp2go.com";   // write SMTP server address

WiFiClient Client;

void setup() {
  delay(1000);
  Serial.begin(9600);
  Serial.println("");
  Serial.print("Connecting To: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Connected.");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  char inChar = 0;          
  char inData[6] = "";
  String variable = "";
  String variable1 = "";
  int index1 = 0;
 
  if (Serial.available() > 0) {
    while (Serial.available() > 0 && index1 < 6)
    {
      delay(100);
      inChar = Serial.read();
      inData[index1] = inChar;
      index1++;
      inData[index1] = '\0';
    }
    variable.toUpperCase();
    for (byte  i = 0 ; i < 6; i++) {
      variable.concat(String(inData[i]));
    }
    Serial.print("Variable = "); 
    Serial.println(variable);
    delay(20);
  }
   String  string = String(variable);
   if(variable == "SEN0"){
    sendEmail0();
    Serial.print("Mail sent to:"); Serial.println(" The recipient");
    Serial.println("");
   }
   else if(variable == "SEN1"){
    sendEmail1();
    Serial.print("Mail sent to:"); Serial.println(" The recipient");
    Serial.println("");
   }
   else if(variable == "SEN2"){
    sendEmail2();
    Serial.print("Mail sent to:"); Serial.println(" The recipient");
    Serial.println("");
   }
   else if(variable == "SEN3"){
    sendEmail3();
    Serial.print("Mail sent to:"); Serial.println(" The recipient");
    Serial.println("");
   }
}

byte sendEmail0()
{
  if (Client.connect(server, 2525) == 1)
  {
    Serial.println(F("connected to server"));
  } 
  else 
  {
    Serial.println(F("connection failed"));
    return 0;
  }
  if (!emailResp())
    return 0;
  Serial.println(F("Sending EHLO"));
  Client.println("EHLO www.example.com");
  if (!emailResp()) 
    return 0;
    
  Serial.println(F("Sending auth login"));
  Client.println("AUTH LOGIN");
  if (!emailResp()) 
    return 0;
  
  Serial.println(F("Sending User"));
  Client.println("a2hhaXJpXzE2MDFAeWFob28uY29t");
  
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending Password"));
  Client.println("WlhaaWJ6bHRjekowYlhVdw==");
  
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending From"));
  Client.println(F("MAIL From: ridhoadhadigani@gmail.com"));
  if (!emailResp())  
    return 0;
  Serial.println(F("Sending To"));
  Client.println(F("RCPT To: ridhoadhadigani@gmail.com"));
  
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending DATA"));
  Client.println(F("DATA"));
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending email"));
  Client.println(F("To: ridhoadhadigani@gmail.com")); 
  Client.println(F("From: studentsystem@gmail.com"));
  Client.println(F("Subject: CS50 Student System\r\n"));
  Client.println(F("Hello World! This is CS50!\n"));
  Client.println(F("Ridho attended class today\n"));
  Client.println(F("\n\nRegards CS50\n"));
  Client.println(F("Demanding, but definitely doable. Social, but educational. A focused topic, but broadly applicable skills. CS50 is the quintessential Harvard (and Yale!) course"));
  Client.println(F("."));
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending QUIT"));
  Client.println(F("QUIT"));
  if (!emailResp()) 
    return 0;
  Client.stop();
  Serial.println(F("disconnected"));
  return 1;
}

byte sendEmail1()
{
  if (Client.connect(server, 2525) == 1)
  {
    Serial.println(F("connected to server"));
  } 
  else 
  {
    Serial.println(F("connection failed"));
    return 0;
  }
  if (!emailResp())
    return 0;
  Serial.println(F("Sending EHLO"));
  Client.println("EHLO www.example.com");
  if (!emailResp()) 
    return 0;
    
  Serial.println(F("Sending auth login"));
  Client.println("AUTH LOGIN");
  if (!emailResp()) 
    return 0;
  
  Serial.println(F("Sending User"));
  Client.println("a2hhaXJpXzE2MDFAeWFob28uY29t");
  
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending Password"));
  Client.println("WlhaaWJ6bHRjekowYlhVdw==");
  
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending From"));
  Client.println(F("MAIL From: ridhoadhadigani@gmail.com"));
  if (!emailResp())  
    return 0;
  Serial.println(F("Sending To"));
  Client.println(F("RCPT To: ridhoadhadigani@gmail.com"));
  
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending DATA"));
  Client.println(F("DATA"));
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending email"));
  Client.println(F("To: ridhoadhadigani@gmail.com")); 
  Client.println(F("From: studentsystem@cs50.com"));
  Client.println(F("Subject: CS50 Student System\r\n"));
  Client.println(F("Hello World! This is CS50!\n"));
  Client.println(F("Khairi attended class today\n"));
  Client.println(F("\n\nRegards CS50\n"));
  Client.println(F("Demanding, but definitely doable. Social, but educational. A focused topic, but broadly applicable skills. CS50 is the quintessential Harvard (and Yale!) course"));
  Client.println(F("."));
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending QUIT"));
  Client.println(F("QUIT"));
  if (!emailResp()) 
    return 0;
  Client.stop();
  Serial.println(F("disconnected"));
  return 1;
}

byte sendEmail2()
{
  if (Client.connect(server, 2525) == 1)
  {
    Serial.println(F("connected to server"));
  } 
  else 
  {
    Serial.println(F("connection failed"));
    return 0;
  }
  if (!emailResp())
    return 0;
  Serial.println(F("Sending EHLO"));
  Client.println("EHLO www.example.com");
  if (!emailResp()) 
    return 0;
    
  Serial.println(F("Sending auth login"));
  Client.println("AUTH LOGIN");
  if (!emailResp()) 
    return 0;
  
  Serial.println(F("Sending User"));
  Client.println("a2hhaXJpXzE2MDFAeWFob28uY29t");
  
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending Password"));
  Client.println("WlhaaWJ6bHRjekowYlhVdw==");
  
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending From"));
  Client.println(F("MAIL From: ridhoadhadigani@gmail.com"));
  if (!emailResp())  
    return 0;
  Serial.println(F("Sending To"));
  Client.println(F("RCPT To: ridhoadhadigani@gmail.com"));
  
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending DATA"));
  Client.println(F("DATA"));
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending email"));
  Client.println(F("To: ridhoadhadigani@gmail.com")); 
  Client.println(F("From: studentsystem@cs50.com"));
  Client.println(F("Subject: CS50 Student System\r\n"));
  Client.println(F("Hello World! This is CS50!\n"));
  Client.println(F("Yudhistira attended class today\n"));
  Client.println(F("\n\nRegards CS50\n"));
  Client.println(F("Demanding, but definitely doable. Social, but educational. A focused topic, but broadly applicable skills. CS50 is the quintessential Harvard (and Yale!) course"));
  Client.println(F("."));
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending QUIT"));
  Client.println(F("QUIT"));
  if (!emailResp()) 
    return 0;
  Client.stop();
  Serial.println(F("disconnected"));
  return 1;
}

byte sendEmail3()
{
  if (Client.connect(server, 2525) == 1)
  {
    Serial.println(F("connected to server"));
  } 
  else 
  {
    Serial.println(F("connection failed"));
    return 0;
  }
  if (!emailResp())
    return 0;
  Serial.println(F("Sending EHLO"));
  Client.println("EHLO www.example.com");
  if (!emailResp()) 
    return 0;
    
  Serial.println(F("Sending auth login"));
  Client.println("AUTH LOGIN");
  if (!emailResp()) 
    return 0;
  
  Serial.println(F("Sending User"));
  Client.println("a2hhaXJpXzE2MDFAeWFob28uY29t");
  
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending Password"));
  Client.println("WlhaaWJ6bHRjekowYlhVdw==");
  
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending From"));
  Client.println(F("MAIL From: ridhoadhadigani@gmail.com"));
  if (!emailResp())  
    return 0;
  Serial.println(F("Sending To"));
  Client.println(F("RCPT To: ridhoadhadigani@gmail.com"));
  
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending DATA"));
  Client.println(F("DATA"));
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending email"));
  Client.println(F("To: ridhoadhadigani@gmail.com")); 
  Client.println(F("From: studentsystem@cs50.com"));
  Client.println(F("Subject: CS50 Student System\r\n"));
  Client.println(F("Hello World! This is CS50!\n"));
  Client.println(F("Surya attended class today\n"));
  Client.println(F("\n\nRegards CS50\n"));
  Client.println(F("Demanding, but definitely doable. Social, but educational. A focused topic, but broadly applicable skills. CS50 is the quintessential Harvard (and Yale!) course"));
  Client.println(F("."));
  if (!emailResp()) 
    return 0;
  Serial.println(F("Sending QUIT"));
  Client.println(F("QUIT"));
  if (!emailResp()) 
    return 0;
  Client.stop();
  Serial.println(F("disconnected"));
  return 1;
}

byte emailResp()
{
  byte responseCode;
  byte readByte;
  int loopCount = 0;

  while (!Client.available()) 
  {
    delay(1);
    loopCount++;
    // Wait for 20 seconds and if nothing is received, stop.
    if (loopCount > 20000) 
    {
      Client.stop();
      Serial.println(F("\r\nTimeout"));
      return 0;
    }
  }

  responseCode = Client.peek();
  while (Client.available())
  {
    readByte = Client.read();
    Serial.write(readByte);
  }

  if (responseCode >= '4')
  {
    return 0;
  }
  return 1;
}
