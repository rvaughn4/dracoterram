
#ifndef dt_client_h
#define dt_client_h

#include "../dracoterram.h"

namespace dracoterram
{

    class client
    {

        private:

        //socket
            int s4, s6;
        //session id (is offset in vector)
            uint32_t id;
        //session id-key (is unique, prevents accidental reuse of session)
            uint8_t idkey;
        //last sucessful ping time
            uint64_t lastPing;
        //ping
            uint32_t ping;

        protected:

        public:

        //ctor
            client( void );
        //dtor
            ~client( void );
        //run client
            virtual void run( void );
        //returns id
            uint32_t getId( void );
        //returns id key
            uint8_t getIdKey( void );
        //returns ping
            uint32_t getPing( void );
        //sets ping
            void setPing( uint32_t p );
        //returns last ping time
            uint64_t getPingTime( void );
        //sets last ping time
            void setPingTime( uint64_t t );
        //returns true if connected
            bool isConnected( void );

    };

};

#endif
