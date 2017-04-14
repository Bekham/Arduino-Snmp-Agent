#include "SnmpAgent.h"
#include <UIPEthernet.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <SimpleTimer.h>

SNMPAgent SnmpAgent;
OneWire oneWire(2);
DallasTemperature sensors(&oneWire);

static byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xEF};
char temperature[6];
uint32_t lastMillis = 0;

void setup() {

  // put your setup code here, to run once:
  Serial.begin(115200);

  sensors.begin();

  Ethernet.begin(mac);
  
  Serial.print("SNMP Agent IP: "); Serial.println(Ethernet.localIP());

  SnmpAgent.begin();
  SnmpAgent.SetCommunity(PSTR("public"));
  SnmpAgent.SetContact(PSTR("vader@deathstar.com"));
  SnmpAgent.SetDescription(PSTR("Force Sensor"));
  SnmpAgent.SetLocation(PSTR("Death Star"));
  SnmpAgent.SetSystemName(PSTR("arduino"));
  SnmpAgent.SetValue(1, temperature);
  SnmpAgent.value1 = temperature;
}

void loop() {
  // put your main code here, to run repeatedly:
  SnmpAgent.listen();

  // Update the temperature variable every 10 seconds
  if (millis() - lastMillis > 10000) {
    sensors.requestTemperatures(); // Send the command to get temperatures
    dtostrf(sensors.getTempCByIndex(0), 1, 1, temperature);
    lastMillis = millis();
  }
}
