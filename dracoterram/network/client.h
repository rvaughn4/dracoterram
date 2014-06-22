
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

        protected:

        public:

        //ctor
            client( void );
        //dtor
            ~client( void );
        //run client
            virtual void run( void );

    };

};

#endif
