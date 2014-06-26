
#include "../dracoterram.h"

namespace dracoterram
{

        //ctor
            session::session( uint32_t id, uint8_t idkey )
            {
                this->id = id;
                this->idkey = idkey;
            }

        //dtor
            session::~session( void )
            {

            }

        //run client
            void session::run( void )
            {

            }

        //returns id
            uint32_t session::getId( void )
            {
                return this->id;
            }

        //returns id key
            uint8_t session::getIdKey( void )
            {
                return this->idkey;
            }

        //returns ping
            uint32_t session::getPing( void )
            {
                return this->ping;
            }

        //sets ping
            void session::setPing( uint32_t p )
            {
                this->ping = p;
            }

        //returns last ping time
            uint64_t session::getPingTime( void )
            {
                return this->lastPing;
            }

        //sets last ping time
            void session::setPingTime( uint64_t t )
            {
                this->lastPing = t;
            }

        //returns true if connected
            bool session::isConnected( void )
            {
                return 1;
            }



};
