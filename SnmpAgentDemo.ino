#include "SnmpAgent.h"
#include <UIPEthernet.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SimpleTimer.h>

static byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEF};

const char sysContact[] PROGMEM = "vader@deathstar.com";
const char sysDescription[] PROGMEM = "Force Sensor";
const char sysLocation[] PROGMEM = "Death Star";
const char sysName[] PROGMEM = "arduino";
const char community[] PROGMEM = "public";  // Read-Only & Read-Write Community String Combined
char temperature[6];

SNMPAgent SnmpAgent;
OneWire oneWire(2);
DallasTemperature sensors(&oneWire);
uint32_t lastMillis = 0;

void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);

  sensors.begin();

  Ethernet.begin(mac);
  
  Serial.print("localIP: "); Serial.println(Ethernet.localIP());

  SnmpAgent.begin();
  SnmpAgent.SetCommunity(community);
  SnmpAgent.SetContact(sysContact);
  SnmpAgent.SetDescription(sysDescription);
  SnmpAgent.SetLocation(sysLocation);
  SnmpAgent.SetSystemName(sysName);
  SnmpAgent.value1 = temperature;
}

void loop() {
  // put your main code here, to run repeatedly:
  SnmpAgent.listen();

  // Update the temperature variable every 10 seconds
  if (millis() - lastMillis > 10000) {
    sensors.requestTemperatures(); // Send the command to get temperatures
    dtostrf(sensors.getTempCByIndex(0), 1, 2, temperature);
    lastMillis = millis();
  }
}
