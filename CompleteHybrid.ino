/* 
 Code made to make my custom controller communicate with Unity 5.5  

 The idea of the code is that we sent nummers for every button to unity 
 and unity breaks these nummers in things it can work with

 For example:
 Button 1 is send like 1.0 or 1.1
 .0 means button 1 is off
 .1 means button 1 is on
 ect. for all other buttons but then with 2,3,4,5 before the .0 or .1

 The sliders do exactly the same but withh the variantion that they are not bools
 they have 3 variables. so 6.1,6.2 & 6.3
 
 Code made by:
 Tim van den Boomen & Sexy Jorim

 Used tutorial: 
 http://www.alanzucconi.com/2015/10/07/how-to-integrate-arduino-with-unity/
 */

#include <SoftwareSerial.h>
#include <SerialCommand.h>
SerialCommand sCmd;

int Slider1;
int Svar1;
int Slider2;
int Svar2;

int Button1;
int lastButton1;
int Button2;
int lastButton2;
int Button3;
int lastButton3;
int Button4;
int lastButton4;
int Button5;
int lastButton5;
 
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT); 
  pinMode(1, INPUT_PULLUP); 
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  Serial.begin (9600);
  while (!Serial);

  // Sliders geven random getallen aan, hiermee tellen ze hopelijk vanaf 0
  //Slider1 = 0;
  //Slider2 = 0;

  sCmd.addCommand("PING", pingHandler);
  sCmd.addCommand("ECHO", echoHandler);
}

void loop() {  
  if(Serial.available() > 0)
  sCmd.readSerial();
  
  Slider1 = analogRead(A0);
  //Serial.print("Slider1: ");
  //Serial.println(Slider1);
  //Serial.println(Svar1);

  if(Slider1 < 390){
    Svar1 = 1;
  } else if(Slider1 <450) {
    Svar1 = 2;
  } else if(Slider1 <600) {
    Svar1 = 3;
  }

  Slider2 = analogRead(A1);
  //Serial.print("Slider2: ");
  //Serial.println(Slider2);
  //Serial.println(Svar1);

  if(Slider2 < 390){
    Svar2 = 1;
  } else if(Slider2 <450) {
    Svar2 = 2;
  } else if(Slider2 <600) {
    Svar2 = 3;
  }

//HIT BUTTON
  int currentButton1 = digitalRead(1);
  if(currentButton1 != lastButton1){
    //Serial.println(lastButton1);
    String output2 = "2." + String(lastButton1);
    Serial.println(output2);
  }
  lastButton1 = currentButton1;

//KLEUR BUTTON 1
  int currentButton2 = digitalRead(2);
  if(currentButton2 != lastButton2){
    //Serial.println(lastButton2);
    String output3 = "3." + String(lastButton2);
    Serial.println(output3);
  }
  lastButton2 = currentButton2;

  //KLEUR BUTTON 2
  int currentButton3 = digitalRead(3);
  if(currentButton3 != lastButton3){
    //Serial.println(lastButton3);
    String output4 = "4." + String(lastButton3);
    Serial.println(output4);
  }
  lastButton3 = currentButton3;

  //KLEUR 3 BUTTON
  int currentButton4 = digitalRead(4);
  if(currentButton4 != lastButton4){
    //Serial.println(lastButton4);
    String output5 = "5." + String(lastButton4);
    Serial.println(output5);
  }
  lastButton4 = currentButton4;

  //DROP BUTTON
  int currentButton5 = digitalRead(5);
  if(currentButton5 != lastButton5){
    //Serial.println(lastButton5);
    String output6 = "6." + String(lastButton5);
    Serial.println(output6);
  }
  lastButton5 = currentButton5;
}

void echoHandler () {
  char *arg;
  arg = sCmd.next();
  if (arg != NULL)
    Serial.println(arg);
  else
    Serial.println("nothing to echo");
}

//If unity says 'PING' this data will be sent
void pingHandler ()
{ 
  String output = "0." + String(Svar1);
  String output1 = "1." + String(Svar2);

  Serial.println(output);
  Serial.println(output1);
}





