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

void test_example()
{
    using namespace std;
    using namespace om636;

    auto b( ctor< tuple<double> >
        ::defaultedWith( double(2.1234) )
        .overridenBy("value") 
    );
    auto product( b.build( { { "value", "5.4321" } } ) );

    ASSERT( get<0>(product) == 5.4321 );
}

void test_ctor_with_two_variables()
{
    using namespace std;
    using namespace om636;
    typedef map<string, string> map_type;
    
    auto b( ctor< tuple<double, string>, map_type >
        ::defaultedWith( double(2.1234), string("hello") )
        .overridenBy("greeting") );
    auto product( b.build( { { "greeting", "hey" } } ) );
    
    ASSERT( get<1>(product) == "hey" );
    
    FOOTER;
}

void test_ctor_with_variable()
{
    using namespace std;
    using namespace om636;
    typedef map<string, string> map_type;
    
    auto b( ctor< std::tuple<double>, map_type >
        ::defaultedWith( double(2.1234) )
        .overridenBy("value") );
    auto product( b.build( { { "value", "5.4321" } } ) );
    
    ASSERT( get<0>(product) == 5.4321 );
    
    FOOTER;
}

void test_default_ctor()
{
    using namespace std;
    using namespace om636;
    typedef map<string, string> map_type;
    
    auto b( ctor< std::tuple<double>, map_type >::defaultedWith( double(2.1234) ) );
    auto product( b.build() );
    
    ASSERT( get<0>(product) == 2.1234 );
    
    FOOTER;
}

void default_ctor_test()
{
    using namespace std;
    using namespace om636;
   
    typedef int product_type;
    typedef map<string, string> map_type;
    
    auto b( ctor< product_type, map_type >::defaultedWith( int( 0 ) ) );
    b.build();

    FOOTER;
}
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

void test_2_args_with_2_vars()
{
    using namespace std;
    using namespace om636;
    typedef agregate product_type;
    typedef map<string, string> map_type;
    
    auto a( ctor< product_type, map_type >
           ::defaultedWith( int(0), double(0) )
           .overridenBy( "index", "radius" ) );
    
    agregate c( a.build( { { "index", "8" }, { "radius", "200.3" } } ) );

    ASSERT( c.m_first == 8 )(c.m_first);
    ASSERT( c.m_second && c.m_second == 200.3 )( c.m_second );
    ASSERT( agregate::ctor_counter == 1 );
    FOOTER;
}

int main(int argc, const char * argv[]) {
    
    test_default_ctor();
    test_2_args_with_2_vars();
    default_ctor_test();
    test_ctor_with_variable();
    test_ctor_with_two_variables();
    test_example();
    
    return 0;
}
