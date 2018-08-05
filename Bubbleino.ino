#include <Servo.h>  
 
class Flasher
{
  // Class Member Variables
  // These are initialized at startup
  int ledPin;      // the number of the LED pin
  long OnTime;     // milliseconds of on-time
  long OffTime;    // milliseconds of off-time
 
  // These maintain the current state
  int ledState;                 // ledState used to set the LED
  unsigned long previousMillis;   // will store last time LED was updated
 
  // Constructor - creates a Flasher 
  // and initializes the member variables and state
  public:
  Flasher(int pin, long on, long off)
  {
  ledPin = pin;
  pinMode(ledPin, OUTPUT);     
    
  OnTime = on;
  OffTime = off;
  
  ledState = LOW; 
  previousMillis = 0;
  }
  
  void Update()
  {
    // check to see if it's time to change the state of the LED
    unsigned long currentMillis = millis();
     
    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      ledState = LOW;  // Turn it off
      previousMillis = currentMillis;  // Remember the time
      digitalWrite(ledPin, ledState);  // Update the actual LED
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      ledState = HIGH;  // turn it on
      previousMillis = currentMillis;   // Remember the time
      digitalWrite(ledPin, ledState);   // Update the actual LED
    }
  }
};


class Buuble
{
  Servo servo;             // the servo
  int mypos;              // current servo position 
  int myState;  //
  int  updateInterval;      // interval between updates
  
  public:
  Buuble(int interval)
  {
    updateInterval = interval;
    myState = LOW;
  }
  
  void Attach(int mypin)
  {
    servo.attach(mypin);
  }
  
  void Detach()
  {
    servo.detach();
  }
  
  void Update()
  {
    if( (myState == HIGH) )
    {
      myState = LOW;  // Turn it off
      servo.write(00);
      delay(4000);
    }
    else if ( (myState == LOW) )
    {
      myState = HIGH;  // turn it on
      servo.write(180);
      delay(2000);

    }
    Serial.println(myState);
    delay(1000) ;

  }
  void blow()
  {
      myState = LOW;  // Turn it off
      servo.write(00);
      delay(1000);  
  }
  void water()
  {
      myState = HIGH;  // turn it on
      servo.write(180);
      delay(1000);

  }
};


Buuble este(1);
Flasher led3(13, 1000, 1200);

int long mytime,lastUpdate; 

void setup() 
{ 
  Serial.begin(9600);
  este.Attach(10);
} 
void loop() 
{
  long updateInterval = 30000;
  Serial.print("time in microsec: ");
  Serial.println(millis());
  
  if( (millis() - lastUpdate) > updateInterval)
  {
    unsigned long currentMillis = millis();
    int x = random(1,4);
    for (int i=0; i<x ;i++){
      este.blow();
      este.water();
    }
    
    lastUpdate = millis();  
  }
    led3.Update();
  
  
} 
