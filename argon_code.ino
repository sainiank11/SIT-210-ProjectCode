// This #include statement was automatically added by the Particle IDE.
#include <Grove_Temperature_And_Humidity_Sensor.h>
#include <string.h>

//specifies the port which is being used 
int port = D3;
const pin_t MY_LED = D5;

//initialises the DHT library sequence
DHT dht(port);
String temp;

void setup() 
{
    dht.begin();
    pinMode(port, INPUT);
    pinMode(MY_LED, OUTPUT);
    Particle.variable("temp", temp);
}

void loop() 
{   
    //gets temperature recording from the sensor in celcius and stores it in temp as a string
    temp = String(dht.getTempCelcius());
    Particle.publish("temp", temp, PRIVATE);
    
    int compare = dht.getTempCelcius();
    
    if (compare > 15)
    {
        digitalWrite(MY_LED, HIGH);
    } 
    else{
        digitalWrite(MY_LED, LOW);
    }
    
    
    delay(3s);
}
