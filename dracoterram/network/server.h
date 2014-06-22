
#ifndef dt_server_h
#define dt_server_h

#include "../dracoterram.h"

namespace dracoterram
{

    class session;

    class server
    {

        private:

        //connected sessions
            std::vector<session *> clients;
        //socket
            int s4, s6;

        protected:

        //delete all sessions
            void deleteSessions( void );
        //generate new session
            virtual session *genSession( void );
        //run all sessions
            void runSessions( void );

        public:

        //ctor
            server( void );
        //dtor
            ~server( void );
        //run server
            virtual void run( void );

    };

};

#endif
