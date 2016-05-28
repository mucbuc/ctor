#include <iostream>
#include <string>
#include <tuple>
#include <map>

#include <lib/ctor/src/builder.h>

#include "test.h"

using namespace om636;

struct complex
{
    complex() = default;
    complex(int i) : m_first( i ), m_second() {}
    complex(int i, double j)  : m_first( i ), m_second(j) {}

    int m_first;
    double m_second; 
};


int main(int argc, char * argv[])
{
    using namespace std;
    
    typedef map< string, string> map_type;
    typedef std::unique_ptr<complex> ptr;
    
    map_type map;
    map[ "one" ] = "1";
    map[ "half" ] = ".5";
    
    basic_builder< complex, map_type > builder( map );

    ptr first( builder.build() ); 
    ASSERT( first.get() );


    ptr second( builder.build< tuple<int> >( "one" ) ); 
    ASSERT( second.get() && second->m_first == 1 );

    ptr third( builder.build< tuple<int, double> >( "one", "half" ) ); 
    ASSERT( third.get() && third->m_second == 0.5 );
    
	return 0; 
}