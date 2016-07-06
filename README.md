# ctor
construction helper

## objective
- specify type and value of constructor arguments
- provide dynamic way to customize these arguments

## quick ref
- `defaultedWith` specify constructor argument types and values
- `overridenBy` associate constructor arguments with values at time of construction

## example with single argument
```
    auto builder( ctor< tuple<double> >
        ::defaultedWith( double(2.1234) )
        .overridenBy("value") 
    );

    auto product( builder.build( { { "value", "5.4321" } } ) );

    ASSERT( get<0>(product) == 5.4321 );

```

## example with multiple arguments
```
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
```


