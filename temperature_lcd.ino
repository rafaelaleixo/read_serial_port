/*
  Temperature Sensor
  Reading temperature with LM35 sensor.
  
  Coded by: arduinoprojects101.com
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

//declare variables
float tempC;
float tempF;
int tempPin = 1;

int ThermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc, Tf;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
int led = 3;


void setup(){
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.print("Temp1=");
  lcd.setCursor(0, 1);
  lcd.print("Temp2=");
  pinMode(5,OUTPUT);
  analogWrite(5,40);    
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop(){
  tempC = analogRead(tempPin);           //read the value from the sensor
  tempF = (5.0 * tempC * 100.0)/1024.0;  //convert the analog data to temperature
//  tempF = ((tempC*9)/5) + 32;            //convert celcius to farenheit

//  Vo = analogRead(ThermistorPin);
//  R2 = R1 * (1023.0 / (float)Vo - 1.0);
//  logR2 = log(R2);
//  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
//  tempC = T - 273.15;
//  tempF = (tempC * 9.0)/ 5.0 + 32.0; 


if (tempC >= 50.0){
  digitalWrite(led, HIGH);    
}
else{
  digitalWrite(led, LOW);
}

  // print result to lcd display
  lcd.setCursor(6, 0);
  lcd.print(tempC,1);
//  lcd.print("'C");

  lcd.setCursor(6, 1);
  lcd.print(tempF,1);
//  lcd.print("'F");

  Serial.println(tempC);

  // sleep...
  delay(1000);
}
