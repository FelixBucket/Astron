#pragma once
#include <stdint.h>

// Defined types
typedef uint64_t channel_t;
typedef uint32_t doid_t;
typedef uint32_t zone_t;

#define CHANNEL_MAX ((channel_t)(-1))
#define DOID_MAX ((doid_t)(-1))
#define ZONE_MAX ((zone_t)(-1))
#define ZONE_BITS (sizeof(zone_t)*8)

// Channel constants
#define INVALID_CHANNEL 0
#define CONTROL_MESSAGE 1
#define BCHAN_CLIENTS 10
#define BCHAN_STATESERVERS 12
#define BCHAN_DBSERVERS 13
#define PARENT_PREFIX ((channel_t)(1) << ZONE_BITS)

// Location macros
#define LOCATION2CHANNEL(p, z) ((channel_t)(p) << ZONE_BITS|(channel_t)(z))
#define PARENT2CHILDREN(p) (PARENT_PREFIX|(channel_t)(p))

// DO ID Constants
#define INVALID_DO_ID 0
#define INVALID_ZONE 0

// Message Booleans
#define SUCCESS 1
#define FAILURE 0

// Reserve message-type 0
#define RESERVED_MSG_TYPE 0

// Control range
#define CONTROL_MSGTYPE_MIN         9000
#define CONTROL_MSGTYPE_MAX         9999
// Control message-type constants
#define CONTROL_ADD_CHANNEL         9000
#define CONTROL_REMOVE_CHANNEL      9001
#define CONTROL_ADD_RANGE           9002
#define CONTROL_REMOVE_RANGE        9003
#define CONTROL_ADD_POST_REMOVE     9010
#define CONTROL_CLEAR_POST_REMOVE   9011
#define CONTROL_SET_CON_NAME        9012
#define CONTROL_SET_CON_URL         9013

// Client Agent range
#define CLIENTAGENT_MSGTYPE_MIN 1000
#define CLIENTAGENT_MSGTYPE_MAX 1999
// Client Agent control message-type constants
#define CLIENTAGENT_SET_STATE                   1000
#define CLIENTAGENT_SET_CLIENT_ID               1001
#define CLIENTAGENT_SEND_DATAGRAM               1002
#define CLIENTAGENT_EJECT                       1004
#define CLIENTAGENT_DROP                        1005
#define CLIENTAGENT_DECLARE_OBJECT              1010
#define CLIENTAGENT_UNDECLARE_OBJECT            1011
#define CLIENTAGENT_ADD_SESSION_OBJECT          1012
#define CLIENTAGENT_REMOVE_SESSION_OBJECT       1013
#define CLIENTAGENT_SET_FIELDS_SENDABLE         1014
#define CLIENTAGENT_OPEN_CHANNEL                1100
#define CLIENTAGENT_CLOSE_CHANNEL               1101
#define CLIENTAGENT_ADD_POST_REMOVE             1110
#define CLIENTAGENT_CLEAR_POST_REMOVES          1111
#define CLIENTAGENT_ADD_INTEREST                1200
#define CLIENTAGENT_ADD_INTEREST_MULTIPLE       1201
#define CLIENTAGENT_REMOVE_INTEREST             1203

// State Server range
#define STATESERVER_MSGTYPE_MIN 2000
#define STATESERVER_MSGTYPE_MAX 2999
// State Server control message-type constants
#define STATESERVER_CREATE_OBJECT_WITH_REQUIRED         2000
#define STATESERVER_CREATE_OBJECT_WITH_REQUIRED_OTHER   2001
#define STATESERVER_DELETE_AI_OBJECTS                   2009
// State Server object message-type constants
#define STATESERVER_OBJECT_GET_FIELD            2010
#define STATESERVER_OBJECT_GET_FIELD_RESP       2011
#define STATESERVER_OBJECT_GET_FIELDS           2012
#define STATESERVER_OBJECT_GET_FIELDS_RESP      2013
#define STATESERVER_OBJECT_GET_ALL              2014
#define STATESERVER_OBJECT_GET_ALL_RESP         2015
#define STATESERVER_OBJECT_SET_FIELD            2020
#define STATESERVER_OBJECT_SET_FIELDS           2021
#define STATESERVER_OBJECT_DELETE_FIELD_RAM     2030
#define STATESERVER_OBJECT_DELETE_FIELDS_RAM    2031
#define STATESERVER_OBJECT_DELETE_RAM           2032
// State Server visibility message-type constants
#define STATESERVER_OBJECT_SET_LOCATION                         2040
#define STATESERVER_OBJECT_CHANGING_LOCATION                    2041
#define STATESERVER_OBJECT_ENTER_LOCATION_WITH_REQUIRED         2042
#define STATESERVER_OBJECT_ENTER_LOCATION_WITH_REQUIRED_OTHER   2043
#define STATESERVER_OBJECT_GET_LOCATION                         2044
#define STATESERVER_OBJECT_GET_LOCATION_RESP                    2045
#define STATESERVER_OBJECT_SET_AI                               2050
#define STATESERVER_OBJECT_CHANGING_AI                          2051
#define STATESERVER_OBJECT_ENTER_AI_WITH_REQUIRED               2052
#define STATESERVER_OBJECT_ENTER_AI_WITH_REQUIRED_OTHER         2053
#define STATESERVER_OBJECT_GET_AI                               2054
#define STATESERVER_OBJECT_GET_AI_RESP                          2055
#define STATESERVER_OBJECT_SET_OWNER                            2060
#define STATESERVER_OBJECT_CHANGING_OWNER                       2061
#define STATESERVER_OBJECT_ENTER_OWNER_WITH_REQUIRED            2062
#define STATESERVER_OBJECT_ENTER_OWNER_WITH_REQUIRED_OTHER      2063
#define STATESERVER_OBJECT_GET_OWNER                            2064
#define STATESERVER_OBJECT_GET_OWNER_RESP                       2065
// State Server parent methods message-type constants
#define STATESERVER_OBJECT_GET_ZONE_OBJECTS     2100
#define STATESERVER_OBJECT_GET_ZONES_OBJECTS    2102
#define STATESERVER_OBJECT_GET_CHILDREN         2104
#define STATESERVER_OBJECT_GET_ZONE_COUNT       2110
#define STATESERVER_OBJECT_GET_ZONE_COUNT_RESP  2111
#define STATESERVER_OBJECT_GET_ZONES_COUNT      2112
#define STATESERVER_OBJECT_GET_ZONES_COUNT_RESP 2113
#define STATESERVER_OBJECT_GET_CHILD_COUNT      2114
#define STATESERVER_OBJECT_GET_CHILD_COUNT_RESP 2115
#define STATESERVER_OBJECT_DELETE_ZONE          2120
#define STATESERVER_OBJECT_DELETE_ZONES         2122
#define STATESERVER_OBJECT_DELETE_CHILDREN      2124
// DBSS object message-type constants
#define DBSS_OBJECT_ACTIVATE_WITH_DEFAULTS       2200
#define DBSS_OBJECT_ACTIVATE_WITH_DEFAULTS_OTHER 2201
#define DBSS_OBJECT_DELETE_FIELD_RAM             2230
#define DBSS_OBJECT_DELETE_FIELDS_RAM            2231
#define DBSS_OBJECT_DELETE_DISK                  2232

// Database Server range
#define DBSERVER_MSGTYPE_MIN 3000
#define DBSERVER_MSGTYPE_MAX 3999
// Database Server message-type constants
#define DBSERVER_CREATE_OBJECT                      3000
#define DBSERVER_CREATE_OBJECT_RESP                 3001
#define DBSERVER_OBJECT_GET_FIELD                   3010
#define DBSERVER_OBJECT_GET_FIELD_RESP              3011
#define DBSERVER_OBJECT_GET_FIELDS                  3012
#define DBSERVER_OBJECT_GET_FIELDS_RESP             3013
#define DBSERVER_OBJECT_GET_ALL                     3014
#define DBSERVER_OBJECT_GET_ALL_RESP                3015
#define DBSERVER_OBJECT_SET_FIELD                   3020
#define DBSERVER_OBJECT_SET_FIELDS                  3021
#define DBSERVER_OBJECT_SET_FIELD_IF_EQUALS         3022
#define DBSERVER_OBJECT_SET_FIELD_IF_EQUALS_RESP    3023
#define DBSERVER_OBJECT_SET_FIELDS_IF_EQUALS        3024
#define DBSERVER_OBJECT_SET_FIELDS_IF_EQUALS_RESP   3025
#define DBSERVER_OBJECT_SET_FIELD_IF_EMPTY          3026
#define DBSERVER_OBJECT_SET_FIELD_IF_EMPTY_RESP     3027
#define DBSERVER_OBJECT_DELETE_FIELD                3030
#define DBSERVER_OBJECT_DELETE_FIELDS               3031
#define DBSERVER_OBJECT_DELETE                      3032
