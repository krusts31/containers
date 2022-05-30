#include <string>
#include "vector.hpp"
#include "test_class.hpp"

int	main()
{
	ft::vector<int>				test_int;
	ft::vector<std::string>		test_str;
	ft::vector<float>			test_float;
	ft::vector<char>			test_char;
	ft::vector<test_class>		test_vc;

	system("leaks a.out");
	return (0);
}
