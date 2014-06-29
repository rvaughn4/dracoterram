
#include "../../dracoterram.h"

namespace dracoterram
{

        //ctor
            packet::packet( uint16_t id, uint16_t m_id )
            {
                this->id = id;
                this->m_id = m_id;
                this->buffSize = sizeof( dgram );
            }

        //ctor
            packet::packet( void )
            {
                this->buffSize = sizeof( dgram );
            }

        //dtor
            packet::~packet( void )
            {
            }

        //returns id
            uint16_t packet::getId( void )
            {
                return this->id;
            }

        //returns message id
            uint16_t packet::getMessageId( void )
            {
                return this->m_id;
            }

        //returns buffer size
            uint8_t packet::getBufferSize( void )
            {
                return this->buffSize;
            }

        //returns bufer
            char *packet::getBuffer( void )
            {
                return this->buff;
            }

        //resizes buffer
            bool packet::resizeBuffer( uint8_t sz )
            {
                if( sz < sizeof( dgram ) )
                    return 0;
                this->buffSize = sz;
                return 1;
            }

        //returns data size
            uint8_t packet::getDataSize( void )
            {
                return this->buffSize - sizeof( dgram );
            }

        //resizes data
            bool packet::resizeData( uint8_t sz )
            {
                uint8_t s = sz + sizeof( dgram );
                if( s < sz )
                    return 0;
                return this->resizeBuffer( s );
            }

        //returns data
            char *packet::getData( void )
            {
                return this->buff + sizeof( dgram );
            }


};
