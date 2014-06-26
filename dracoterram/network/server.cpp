
#include "../dracoterram.h"

namespace dracoterram
{

        //ctor
            server::server( void )
            {

                struct sockaddr_in a4;
                struct sockaddr_in6 a6;
                int r;

                this->s4 = socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );
                this->s6 = socket( AF_INET6, SOCK_DGRAM, IPPROTO_UDP );

                memset( &a4, 0, sizeof( a4 ) );
                a4.sin_family = AF_INET;
                a4.sin_port = htons( 9000 );
                a4.sin_addr.s_addr = INADDR_ANY;

                memset( &a6, 0, sizeof( a6 ) );
                a6.sin6_family = AF_INET6;
                a6.sin6_port = htons( 9000 );
                a6.sin6_addr = in6addr_any;

                if( this->s4 > 0 )
                {
                    r = bind( this->s4, (sockaddr *)&a4, sizeof( a4 ) );
                    if( r < 0 )
                    {
                        server::printError();

//                        close( this->s4 );
  //                      this->s4 = 0;
                    }
                }
                if( this->s6 > 0 )
                {
                    if( bind( this->s6, (sockaddr *)&a6, sizeof( a6 ) ) < 0 )
                    {
                        server::printError();
                        close( this->s6 );
                        this->s6 = 0;
                    }
                }

            }

        //dtor
            server::~server( void )
            {
                close( this->s6 );
                close( this->s4 );
            }

        //run server
            void server::run( void )
            {
                fd_set f;
                struct timeval t;
                int r;
                unsigned int z;
                char buff[ 1024 ];

                t.tv_sec = 0;
                t.tv_usec = 0;

                FD_ZERO( &f );
                if( this->s4 > 0 )
                    FD_SET( this->s4, &f );
                if( this->s6 > 0 )
                    FD_SET( this->s6, &f );

                r = this->s4;
                if( r < this->s6 )
                    r = this->s6;
                if( r <= 0 )
                    return;

                r = select( r + 1, &f, 0, 0, &t );
                if( r < 0 )
                    server::printError();
                if( r < 1 )
                    return;

                if( FD_ISSET( this->s4, &f ) )
                {
                    struct sockaddr_in a4;
                    z = sizeof( a4 );
                    r = recvfrom( this->s4, buff, sizeof( buff ), 0, (sockaddr *)&a4, &z );
                    if( r > 0 )
                    {
                        sendto( this->s4, buff, r, 0, (sockaddr *)&a4, sizeof( a4 ) );
                    }
                }

                if( FD_ISSET( this->s6, &f ) )
                {
                    struct sockaddr_in6 a6;
                    z = sizeof( a6 );
                    r = recvfrom( this->s6, buff, sizeof( buff ), 0, (sockaddr *)&a6, &z );
                    if( r > 0 )
                    {
                        sendto( this->s6, buff, r, 0, (sockaddr *)&a6, sizeof( a6 ) );
                    }

                }

            }

        //delete all sessions
            void server::deleteSessions( void )
            {

            }

        //generate new session
            session *server::genSession( void )
            {
                return 0;
            }

        //run all sessions
            void server::runSessions( void )
            {

            }

        //print error
            void server::printError( void )
            {
                int er = errno;
                std::cerr << "\r\n" << strerror( er ) << "\r\n";
            }


};

