#include <iostream>

#include "dracoterram/dracoterram.h"

using namespace std;

int main()
{

    dracoterram::server *s;
    dracoterram::client *c;

    s = new dracoterram::server();
    c = new dracoterram::client();

    while( 1 )
    {

        s->run();
        c->run();

        struct timespec t;
        t.tv_sec = 0;
        t.tv_nsec = 10 * 10000;
        nanosleep( &t, 0 );

    }

    return 0;
}
