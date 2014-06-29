
#include "../dracoterram.h"

namespace dracoterram
{

        //ctor
            client::client( void )
            {

                struct sockaddr_in a4;
                struct sockaddr_in6 a6;
                char buff[ 1024 ];
                int r;

                this->id = 0;

                this->s4 = socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );
                this->s6 = socket( AF_INET6, SOCK_DGRAM, IPPROTO_UDP );

                memset( &a4, 0, sizeof( a4 ) );
                a4.sin_family = AF_INET;
                a4.sin_port = htons( 9001 );
                a4.sin_addr.s_addr = htonl( INADDR_ANY );

                memset( &a6, 0, sizeof( a6 ) );
                a6.sin6_family = AF_INET6;
                a6.sin6_port = htons( 9001 );
                a6.sin6_addr = in6addr_any;

                if( this->s4 > 0 )
                {
                    r = bind( this->s4, (sockaddr *)&a4, sizeof( a4 ) );
                    if( 0 )//r < 0 )
                    {
                        close( this->s4 );
                        this->s4 = 0;
                    }
                    else
                    {
                memset( &a4, 0, sizeof( a4 ) );
                a4.sin_family = AF_INET;
                a4.sin_port = htons( 9000 );
                a4.sin_addr.s_addr = inet_addr( "127.0.0.1" );
                *( (int *)buff ) = 1;
                        sendto( this->s4, buff, sizeof( int ), 0, (sockaddr *)&a4, sizeof( a4 ) );
                    }
                }
                if( this->s6 > 0 )
                {
                    if( bind( this->s6, (sockaddr *)&a6, sizeof( a6 ) ) < 0 )
                    {
                        close( this->s6 );
                        this->s6 = 0;
                    }
                }

            }

        //dtor
            client::~client( void )
            {
                close( this->s6 );
                close( this->s4 );
            }

        //run client
            void client::run( void )
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
                if( r < 1 )
                    return;

                if( FD_ISSET( this->s4, &f ) )
                {
                    struct sockaddr_in a4;
                    z = sizeof( a4 );
                    r = recvfrom( this->s4, buff, sizeof( buff ), 0, (sockaddr *)&a4, &z );
                    if( r > 0 )
                    {
                        *( (int *)buff ) = *( (int *)buff ) + 1;
                        sendto( this->s4, buff, r, 0, (sockaddr *)&a4, sizeof( a4 ) );
                        r = *( (int *)buff );
                        std::cout << r << "\r\n";
                    }
                }

                if( FD_ISSET( this->s6, &f ) )
                {
                    struct sockaddr_in6 a6;
                    z = sizeof( a6 );
                    r = recvfrom( this->s6, buff, sizeof( buff ), 0, (sockaddr *)&a6, &z );
                    if( r > 0 )
                    {
                    *( (int *)buff ) = *( (int *)buff ) + 1;
                        sendto( this->s6, buff, r, 0, (sockaddr *)&a6, sizeof( a6 ) );
                        std::cout << r << "\r\n";
                    }

                }

            }

        //returns id
            uint32_t client::getId( void )
            {
                return this->id;
            }

        //returns id key
            uint8_t client::getIdKey( void )
            {
                return this->idkey;
            }

        //returns ping
            uint32_t client::getPing( void )
            {
                return this->ping;
            }

        //sets ping
            void client::setPing( uint32_t p )
            {
                this->ping = p;
            }

        //returns last ping time
            uint64_t client::getPingTime( void )
            {
                return this->lastPing;
            }

        //sets last ping time
            void client::setPingTime( uint64_t t )
            {
                this->lastPing = t;
            }

        //returns true if connected
            bool client::isConnected( void )
            {
                return 0;
            }

};
