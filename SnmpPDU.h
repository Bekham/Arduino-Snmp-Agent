#ifndef SNMPPDU_H
#define SNMPPDU_H

#include "VarbindList.h"

/*
 *  An SNMP PDU (Protocol Data Unit) describes the type of
 *  SNMP packet in use.
 */
class SnmpPDU {
    public:
        uint32_t request_id;
        uint8_t error;
        uint8_t error_index;
        VarbindList varbind_list;

        SnmpPDU() {
            request_id = 0; error = 0; error_index = 0;
        };
};

#endif
