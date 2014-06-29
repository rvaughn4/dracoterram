
#ifndef dt_packet_h
#define dt_packet_h

#include "../../dracoterram.h"

namespace dracoterram
{

    class packet
    {

        private:

        //packet id
            uint16_t id, m_id;
        //buffer
            char buff[ 256 ];
            uint8_t buffSize;


        protected:

        public:

        //ctor
            packet( uint16_t id, uint16_t m_id );
        //ctor
            packet( void );
        //dtor
            ~packet( void );
        //returns id
            uint16_t getId( void );
        //returns message id
            uint16_t getMessageId( void );
        //returns buffer size
            uint8_t getBufferSize( void );
        //returns bufer
            char *getBuffer( void );
        //resizes buffer
            bool resizeBuffer( uint8_t sz );
        //returns data size
            uint8_t getDataSize( void );
        //resizes data
            bool resizeData( uint8_t sz );
        //returns data
            char *getData( void );
    };

};

#endif
