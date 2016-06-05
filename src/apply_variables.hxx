namespace om636
{
	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T, class U, class V, int N> 
	void apply_variables( T & args, const U & vars, const V & map, int_to_type<N> )
	{
		using namespace std;
        
        stringstream( map.at( get<N - 1>(vars) ) ) >> get< tuple_size<T>::value - tuple_size<U>::value + N - 1 >(args);
		apply_variables(args, vars, map, int_to_type<N - 1>() );
	}

	/////////////////////////////////////////////////////////////////////////////////////////////
    template<class T, class U, class V> 
	void apply_variables( T & args, const U & vars, const V & map, int_to_type<0> )
	{}
}
