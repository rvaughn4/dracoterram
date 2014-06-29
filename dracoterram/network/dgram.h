
 #ifndef dt_dgram_h
 #define dt_dgram_h

#include "../dracoterram.h"

    #pragma pack( 1 )
    struct dgram
    {
        uint32_t s_id;
        uint8_t s_idkey;
        uint16_t p_id;
        uint16_t m_id;
    };
    #pragma pack()


 #endif
