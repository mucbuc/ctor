# ctor
constructor helper

## objective
- specify type and value of constructor arguments
- customize constructor arguments

## quick ref
- `defaultedWith` specify constructor argument types and values
- `overridenBy` associate constructor arguments with values at time of construction

## example
```
	using namespace std;
	using namespace om636;

    auto b( ctor< tuple<double>, map_type >
    	::defaultedWith( double(2.1234) )
    	.overridenBy("value") 
    );
    auto product( b.build( { { "value", "5.4321" } } ) );

	ASSERT( get<0>(product) == 5.4321 );
```

