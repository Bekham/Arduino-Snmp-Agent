#ifndef SNMPVARBINDLIST_H
#define SNMPVARBINDLIST_H

#define SNMP_VARBIND_LIST_MAX 1

#include "SnmpTypes.h"
#include "Varbind.h"

/*
 *  A varbind list is a list of one or more varbind
 *  objects that matches the SNMP Request or Response
 */
class VarbindList {
    public:
        uint8_t type;
        uint8_t length;
        Varbind list[SNMP_VARBIND_LIST_MAX];

        VarbindList() {
            for (uint8_t i=0; i<SNMP_VARBIND_LIST_MAX; i++)
                list[i].type = Null;  
        };
};

#endif
