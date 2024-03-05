#include <SoftwareSerial.h>
#include <ArduinoJson.h> // WARNING: ArduinoJson5 here. Latest ArduinoJson6 has a different syntax.

// Creating a software serial to communicate between Arduino and NodeMCU
// Here pin 10 is TX and pin 11 is RX
SoftwareSerial espSerial(10, 11);

void setup()
{
  // Starting the serial both in 115200 baud. (Both baud rate has to be same)
  Serial.begin(115200);
  espSerial.begin(115200);
}

void loop()
{
  // Just creating some random values
  float h = 50.88;
  float t = 15.33;
  
  // Creating a JsonBuffer with size of 1000 and assigning the json object to a variable
  // This syntax is a bit different in ArduinoJson6 
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject& data = jsonBuffer.createObject();

  // Adding data to the json object
  data["hum"] = h;
  data["temp"] = t;

  // Sending the data to NodeMCU
  data.printTo(espSerial);
  
  jsonBuffer.clear();  
  delay(2000);
}
