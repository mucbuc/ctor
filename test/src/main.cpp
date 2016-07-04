//
//  main.cpp
//  teseter
//
//  Created by Mark Busenitz on 6/3/16.
//  Copyright © 2016 Mark Busenitz. All rights reserved.
//

#include <iostream>
#include <tuple>
#include <array>
#include <map>

#include <lib/ctor/src/interface.h>

#include "test.h"

using namespace std;

struct agregate
{
    agregate(int first, double second)
    : m_first( first )
    , m_second( second )
    {
        ++ctor_counter;
    }
    
    agregate(const agregate & c)
    : m_first( c.m_first )
    , m_second( c.m_second )
    {
        ++ctor_counter;
    }
    
    agregate(agregate && c)
    : m_first( c.m_first )
    , m_second( c.m_second )
    {
        ++ctor_counter;
    }
    
    ~agregate()
    {}
    
    int m_first;
    double m_second;
    
    static unsigned ctor_counter;
};

unsigned agregate::ctor_counter( 0 );

void default_ctor_test();
void test_2_args_with_2_vars();

int main(int argc, const char * argv[]) {
    test_2_args_with_2_vars();
    default_ctor_test();

    return 0;
}

void default_ctor_test()
{
    using namespace std;
    using namespace om636;
   
    typedef int product_type;
    typedef map<string, string> map_type;
      
    map_type table;
    auto b( ctor< product_type, map_type >::defaultedWith( int( 0 ) ) );
    b.build(table);

    FOOTER;
}

void test_2_args_with_2_vars()
{
    using namespace std;
    using namespace om636;
    typedef agregate product_type;
    typedef map<string, string> map_type;
    
    auto a( ctor< product_type, map_type >
           ::defaultedWith( int(0), double(0) )
           .overridenBy( "index", "radius" ) );
    
    map_type table;
    table["index"] = "8";
    table["radius"] = "200.3";
    
    agregate c( a.build( table ) );

    ASSERT( c.m_first == 8 )(c.m_first);
    ASSERT( c.m_second && c.m_second == 200.3 )( c.m_second );
    ASSERT( agregate::ctor_counter == 1 );
    FOOTER;
}
