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
using namespace om636;

void test_example_with_multipe_arguments()
{
    auto builder( ctor< tuple<double, int, string> >
        ::defaultedWith( double(41.3), int(2), string("who?") )
        .overridenBy( "index", "name" ) 
        // right hand side arguments are referenced before left hand side arguments. 
        // "index" <=> int(2), "name" <=> "who?" 
    );
    
    auto product( builder.build( 
        { { "index", "3" }, { "name", "part231" } } 
    ) );

    ASSERT( get<0>(product) == 41.3 );
    ASSERT( get<1>(product) == 3 );
    ASSERT( get<2>(product) == "part231" );
}

void test_example_with_signgle_argument()
{
    auto builder( ctor< tuple<double> >
        ::defaultedWith( double(2.1234) )
        .overridenBy("value") 
    );

    auto product( builder.build( { { "value", "5.4321" } } ) );

    ASSERT( get<0>(product) == 5.4321 );
}

void test_ctor_with_two_variables()
{
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
    typedef map<string, string> map_type;
    
    auto b( ctor< std::tuple<double>, map_type >::defaultedWith( double(2.1234) ) );
    auto product( b.build() );
    
    ASSERT( get<0>(product) == 2.1234 );
    
    FOOTER;
}

void default_ctor_test()
{
    
    typedef int product_type;
    typedef map<string, string> map_type;
    
    auto b( ctor< product_type, map_type >::defaultedWith( int( 0 ) ) );
    b.build();

    FOOTER;
}
struct aggregate
{
    aggregate(int first, double second)
    : m_first( first )
    , m_second( second )
    {
        ++ctor_counter;
    }
    
    aggregate(const aggregate & c)
    : m_first( c.m_first )
    , m_second( c.m_second )
    {
        ++ctor_counter;
    }
    
    aggregate(aggregate && c)
    : m_first( c.m_first )
    , m_second( c.m_second )
    {
        ++ctor_counter;
    }
    
    ~aggregate()
    {}
    
    int m_first;
    double m_second;
    
    static unsigned ctor_counter;
};

unsigned aggregate::ctor_counter( 0 );

void test_2_args_with_2_vars()
{
    typedef aggregate product_type;
    typedef map<string, string> map_type;
    
    auto a( ctor< product_type, map_type >
           ::defaultedWith( int(0), double(0) )
           .overridenBy( "index", "radius" ) );
    
    aggregate c( a.build( { { "index", "8" }, { "radius", "200.3" } } ) );

    ASSERT( c.m_first == 8 )(c.m_first);
    ASSERT( c.m_second && c.m_second == 200.3 )( c.m_second );
    ASSERT( aggregate::ctor_counter == 1 );
    FOOTER;
}

int main(int argc, const char * argv[]) {
    
    test_default_ctor();
    test_2_args_with_2_vars();
    default_ctor_test();
    test_ctor_with_variable();
    test_ctor_with_two_variables();
    test_example_with_signgle_argument();
    test_example_with_multipe_arguments();
    
    return 0;
}
