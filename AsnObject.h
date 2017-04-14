#ifndef ASNOBJECT_H
#define ASNOBJECT_H

#define ASN_VALUE_MAX_SIZE    32

#include "SnmpTypes.h"

/*
 *  An ASN.1 Object which is used to describe for example
 *  SNMP Version, SNMP Community, Request ID, Error,
 *  Error Index, Object Identifier and Value
 */
class AsnObject {
    public:
        uint8_t type;
        uint8_t length;
        byte value[ASN_VALUE_MAX_SIZE];

        AsnObject() { type = Null; length = 0; memset(value, 0, ASN_VALUE_MAX_SIZE); };
};

#endif
