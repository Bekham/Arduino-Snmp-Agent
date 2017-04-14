#ifndef SNMPTYPES_H
#define SNMPTYPES_H

/*
 *  SNMP PDU Error Statuses
 */
typedef enum SnmpPDUErrStat {
    NoError     = 0x00,   // No error occured
    TooBig      = 0x01,   // The response was too big to fit in once response
    NoSuchName  = 0x02,   // The OID in the request was not found. The OID doesn't exist
    BadValue    = 0x03,   // A data type in the request didn't match the data type in the SNMP agent
    ReadOnly    = 0x04,   // The SNMP manager tried to set a read-only value
    GenError    = 0x05,   // General error (errors that doesn't match any of the above)
} SnmpErrorStatus;

/*
 *  ASN.1 Data Types
 */
typedef enum Asn1Type {
    // Primitive Data Types
    Boolean      = 0x01,      
    Integer      = 0x02,
    BitString    = 0x03,
    OctetString  = 0x04,
    Null         = 0x05,
    ObjectID     = 0x06,
    IpAddress    = 0x40,
    Counter      = 0x41,
    Gauge        = 0x42,
    TimeTicks    = 0x43,
    Opaque       = 0x44,
    NsapAddress  = 0x45,

    // Complex Data Types
    Sequence       = 0x30,
    GetRequest     = 0xA0,
    GetNextRequest = 0xA1,
    GetResponse    = 0xA2,
    SetRequest     = 0xA3,
    Trap           = 0xA4,
} AsnType;

// Union used to encode 32 bit integer as byte string
typedef union uint32_u {
    uint32_t uint32;
    byte data[4];
};

#endif
