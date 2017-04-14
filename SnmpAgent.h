#ifndef SNMPAGENT_H
#define SNMPAGENT_H

#define COMMUNITY_MAX_LENGTH    8
#define UDP_PACKET_MAX_LENGTH   64

#define DEFAULT_SNMP_PORT     161
#define DEFAULT_SNMP_VERSION  0 // SnmpAgent only support SNMP version 1

#include "Arduino.h"
#include "Udp.h"
#include "SnmpMessage.h"
#include "SnmpPDU.h"
#include "SnmpTypes.h"

// DofiLoop Private MIB = 1.3.6.1.4.1.49701

const char sysDescr_oid[] PROGMEM       = "1.3.6.1.2.1.1.1.0";    // read-only OctetString
const char sysUpTime_oid[] PROGMEM      = "1.3.6.1.2.1.1.3.0";    // read-only OctetString
const char sysContact_oid[] PROGMEM     = "1.3.6.1.2.1.1.4.0";    // read-only OctetString
const char sysName_oid[] PROGMEM        = "1.3.6.1.2.1.1.5.0";    // read-only OctetString
const char sysLocation_oid[] PROGMEM    = "1.3.6.1.2.1.1.6.0";    // read-only OctetString

const char usrValue_oid[] PROGMEM       = "1.3.6.1.4.1.49701.1.1.0";

class SNMPAgent {
    public:
        void begin();
        void listen();

        bool SetCommunity(char *value PROGMEM);

        void SetContact(char *value PROGMEM) { sysContact_value = value; };
        void SetDescription(char *value PROGMEM) { sysDescr_value = value; };
        void SetLocation(char *value PROGMEM) { sysLocation_value = value; };
        void SetSystemName(char *value PROGMEM) { sysName_value = value; };

        char *value1;
        
    private:
        char      community[COMMUNITY_MAX_LENGTH];
        uint16_t  port;

        unsigned char packetBuffer[UDP_PACKET_MAX_LENGTH];

        // SNMP System Values
        char      *sysDescr_value PROGMEM;
        char      *sysContact_value PROGMEM;
        char      *sysName_value PROGMEM;
        char      *sysLocation_value PROGMEM;

        bool      ParseSnmpPacket(int packetSize);
        bool      IsAuthenticated();
        bool      ParsePDU();
        bool      ProcessPDU();
        bool      SendResponse();
};

#endif
