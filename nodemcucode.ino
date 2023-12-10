#include <Servo.h>
#define BLYNK_PRINT Serial






#define BLYNK_TEMPLATE_ID "TMPL6q5u5M100"
#define BLYNK_TEMPLATE_NAME "servoo"
#define BLYNK_AUTH_TOKEN "16ZF1JtIPfIRJNBsWoNlImZr8qNlV4g0"

#include <ESP8266WiFi.h>

#include <BlynkSimpleEsp8266_SSL.h>



// You should get Auth Token in the Blynk App.

// Go to the Project Settings (nut icon).

char auth[] = "16ZF1JtIPfIRJNBsWoNlImZr8qNlV4g0";



// Your WiFi credentials.

// Set password to "" for open networks.

char ssid[] = "Arifinnn";

char pass[] = "Alihasan36";
int M1PWM = D6; //GPIO12

Servo servo1;
Servo servo2;
BLYNK_WRITE(V1)
{



  int pinValue1 = param.asInt(); // assigning incoming value from pin V1 to a variable



  analogWrite(M1PWM,pinValue1);



  Blynk.virtualWrite(V1, pinValue1);



  Serial.print("V1 Slider value is: ");



  Serial.println(pinValue1);



}



BLYNK_WRITE(V2){

  servo1.write(param.asInt());

}



BLYNK_WRITE(V3){

  servo2.write(param.asInt());

}
BLYNK_WRITE(V4){
if (Serial.available () >0) {
char data=Serial. read ();
Serial.println (data) ;
}


void setup()

{

  // Debug console

  Serial.begin(9600);

  servo1.attach(D3);

  servo2.attach(D4);

  pinMode (M1PWM,OUTPUT);



  Blynk.begin(auth, ssid, pass);

}



void loop()

{

  Blynk.run();

}
