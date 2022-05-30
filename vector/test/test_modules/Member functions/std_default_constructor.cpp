#include <vector>
#include <string>
#include "test_class.hpp"

int	main()
{
	std::vector<int>			test_int;
	std::vector<std::string>	test_str;
	std::vector<float>			test_float;
	std::vector<char>			test_char;
	std::vector<test_class>		test_vc;

	system("leaks a.out");
	return (0);
}
