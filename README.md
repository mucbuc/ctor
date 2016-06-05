# ctor
builder 

components: 

template<typename T, typename U> 
class abstract_builder
{
	typedef T product_type;
	typedef U map_type; 

	virtual ~abstract_builder() = default; 
	virtual product_type build(const map_type &) = 0; 
};

template<typename T, typename U, typename V ..., int N> 
builder_impl
: public abstract_builder< T, U > 
{
	typedef abstract_builder< T, U > base_type; 
	using typename base_type::product_type; 
	using typename base_type::map_type; 
	typedef std::tuple<V ...> arguments_type;
	enum { variables_count = N };
	typedef array< string, variables_count > variables_type;

	builder_impl( arguments_type args, )

	product_type build(const map_type &) override 
	{
		return create<product_type>( m_args ); 
	}

	arguments_type m_args; 
	variables_type m_vars;
};

template<class T, class U, class ... V> 
struct builder 
{
	arguments_type

	template<typename ... W> 
	builder( arguments_type args, W ... vars) 
	{
		using namespace std;
		static_assert( sizeof ... ( V ) >= sizeof ... ( W ) );

		m_impl = new builder_impl< ctor_arguments, variables >( args, vars ); 
	}

	abstract_builder m_impl; 
};

simplifictions: 
	it seems like the "variables" template could just be a int 

