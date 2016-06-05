# ctor
builder 

example
```
ctor< product_type, map_type, int, double > a( make_tuple(0, 0), "index", "radius" );

map_type table;
table["index"] = "8";
table["radius"] = "200.3";

product_type c( a.build( table ) );
```

