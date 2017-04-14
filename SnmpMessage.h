#ifndef SNMPMESSAGE_H
#define SNMPMESSAGE_H

#include "AsnObject.h"

/*
 *  An SNMP Message is a complete representation of the packet that
 *  will be sent or recieved via UDP/IP.
 */
class SnmpMessage {
    public:
        uint8_t type;   // ASN_TYPE
        uint8_t length;
        AsnObject version;
        AsnObject community;
        AsnObject pdu;
    
        // Print the entire SNMP Message in hex format
        void dump()
        {
            Serial.print(F("Version = "));
            Serial.println(version.value[0], DEC);

            Serial.print(F("Community = '"));
            for (uint8_t i=0; i<community.length; i++)
                Serial.print((char)community.value[i]);
            Serial.println("'");

            Serial.print(F("PDU = '"));
            for (int i=0; i<pdu.length; i++) {
                Serial.print(pdu.value[i], HEX);
                Serial.print(" ");
            }
            Serial.println("'");

        }
};

#endif
