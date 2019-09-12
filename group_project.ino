/* 
#0-20 degrees celsius    Too cold
#20-25 degrees celsius   Goldilocks temp
#25-50 degrees celsius   Too hot
*/
//Libraries
#include <DHT.h>

//Constants

#define DHTPIN 2     // what pin we're connected to

#define DHTTYPE DHT22   // DHT 22  (AM2302)

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino

//Variables
float temp; //Stores temperature value


// constants won't change. Used here to set a pin number:
const int ledPin =  LED_BUILTIN;// the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED

// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)


void setup()

{

    Serial.begin(9600);

    dht.begin();

    // set the digital pin as output:
    pinMode(ledPin, OUTPUT);

}



void loop()

{

    //Read data and store it to variable of temp

    temp = dht.readTemperature();

    

    //Print temp values to serial monitor
    Serial.print(" Temp: ");

    Serial.print(temp);

    Serial.println(" Celsius");

 unsigned long currentMillis = millis();
    
  if (currentMillis - previousMillis >= interval)
  {
    // save the last time you blinked the LED
    previousMillis = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if ( 20 > temp and temp > 25  )
    {
      ledState = HIGH;
    } else
    {
      ledState = LOW;
    }
  } 

  
    delay(1000*60); //Delay 1 minutes.   
}
