#ifndef SNMPVARBIND_H
#define SNMPVARBIND_H

#define VARBIND_OID_STRING_MAX 32

#include "AsnObject.h"

/*
 *  A varbind is an Object Identifier (OID) and
 *  its corresponding value, for example:
 *  OID:   1.3.6.1.2.1.1.3.0 (DISMAN-EVENT-MIB::sysUpTimeInstance)
 *  Value: 25598200
 */
class Varbind {
    public:
        uint8_t type;
        uint8_t length;
        AsnObject oid;
        AsnObject value;

        // Get the OID instance value as a char array
        void GetOID(char *oid_string) {
            memset(oid_string, 0, sizeof(oid_string));

            strcpy(oid_string, "1.3");

            uint16_t oid_number;
            uint8_t oid_number_index = 1;

            while (oid_number_index < length-4) {
                uint8_t oid_octet;
                uint8_t oid_bitman;
                oid_number = 0;
                do {
                    oid_octet = oid.value[oid_number_index++];
                    oid_number = (oid_number << 7) + (oid_octet & ~0x80);
                } while ((oid_octet & 0x80) != 0);

                char oid_number_str[VARBIND_OID_STRING_MAX];
                utoa(oid_number, oid_number_str, 10);

                strcat(oid_string, ".");
                strcat(oid_string, oid_number_str);
            }
        };
};

#endif
