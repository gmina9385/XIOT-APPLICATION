#include <elapsedMillis.h>

elapsedMillis timeElapsed; /*used for checking the time elapsed to take the readings of the temperature sensor*/
int sw =2; /*defining the pin of the switch*/
int led =4;  /*defining the pin of the led*/
bool led_state= false; /* false for OFF & true for ON -- intially the led is OFF*/
int sw_read; /*variable to read the switch*/
int sw_state=0;  /*state of the switch-- 0: not pressed & 1: pressed--initially not pressed*/
int temp; /*variable to contain the value of the temperature*/
int tempPin=0; /*naming pin 0 of analog input side for the temperature readings */
int three_sec=3000; /*declare a variable for the 3 sec rate*/

void Print_SM();/*function to print the state of the lead and switch on serial monitor*/
void readTemp();

void setup()
{
  Serial.begin(9600);
  pinMode (sw, INPUT);
  pinMode (led, OUTPUT);
}

void loop() 
{
  sw_read=digitalRead(sw);
  if(sw_read!=sw_state)   /*if the state of the switch is inverted. It will print and */
  {
    sw_state=sw_read; /* The state of the switch is updated*/
    Print_SM();       /*print on the serial monitor*/
    led_state= !led_state;
    digitalWrite(led,led_state);
  }

  /*taking the temperture sensor readings every three seconds   */
  readTemp();
    
}

void Print_SM()
{
  Serial.print("pressed");
  if(led_state)
  {
    Serial.print("ON");
  }
  else
  {
    Serial.print("OFF");
  }
}

void readTemp()
{
  if (timeElapsed > three_sec) 
  {       
    temp = (5.0 * analogRead(tempPin) * 100.0) / 1024; // equation which is taken from the datasheet of LM35 Temperature Sensor -- temp has the reading of the temperature
    timeElapsed = 0;       // reset the counter to 0 so the counting starts over
  }
   
}

