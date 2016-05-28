namespace om636
{
    template<class T, class U>
    basic_builder<T, U>::basic_builder(const map_type & map)
    : m_map( map )
    {}
    
    template<class T, class U>
    auto basic_builder<T, U>::build() const -> product_type *
    {
        return new product_type; 
    }

    template<class T, class U>
    template<class V>
    auto basic_builder<T, U>::build(string_type first) const -> product_type *
    {
        using namespace std;
        
        V arguments;

        stringstream( m_map.at(first) ) >> get<0>(arguments);

        return new product_type( get<0>(arguments) ); 
    }

    template<class T, class U>
    template<class V>
    auto basic_builder<T, U>::build(string_type first, string_type second) const -> product_type *
    {
        using namespace std;
        
        V arguments; 

        stringstream( m_map.at(first) ) >> get<0>(arguments);
        stringstream( m_map.at(second) ) >> get<1>(arguments);

        return new product_type( get<0>(arguments), get<1>(arguments) ); 
    }

    template<class T, class U>
    template<class V>
    auto basic_builder<T, U>::build(string_type first, string_type second, string_type third) const -> product_type *
    {
        using namespace std;
        
        V arguments; 

        stringstream( m_map.at(first) ) >> get<0>(arguments);
        stringstream( m_map.at(second) ) >> get<1>(arguments);
        stringstream( m_map.at(third) ) >> get<2>(arguments);

        return new product_type( get<0>(arguments), get<1>(arguments), get<2>(arguments) );  
    }

    template<class T, class U>
    template<class V> 
    auto basic_builder<T, U>::build(string_type first, string_type second, string_type third, string_type fourth) const -> product_type *
    {
        using namespace std;
        
        V arguments; 

        stringstream( m_map.at(first) ) >> get<0>(arguments);
        stringstream( m_map.at(second) ) >> get<1>(arguments);
        stringstream( m_map.at(third) ) >> get<2>(arguments);
        stringstream( m_map.at(fourth) ) >> get<3>(arguments);

        return new product_type( get<0>(arguments), get<1>(arguments), get<2>(arguments), get<3>(arguments) );  
    }

    template<class T, class U>
    template<class V> 
    auto basic_builder<T, U>::build(string_type first, string_type second, string_type third, string_type fourth, string_type fifth) const -> product_type *
    {
        using namespace std;
        
        V arguments; 

        stringstream( m_map.at(first) ) >> get<0>(arguments);
        stringstream( m_map.at(second) ) >> get<1>(arguments);
        stringstream( m_map.at(third) ) >> get<2>(arguments);
        stringstream( m_map.at(fourth) ) >> get<3>(arguments);
        stringstream( m_map.at(fifth) ) >> get<4>(arguments);

        return new product_type( get<0>(arguments), get<1>(arguments), get<2>(arguments), get<3>(arguments), get<4>(arguments) );  
    }
}