#include <vector>
#include <iostream>
#include <string>

int	main()
{
	std::vector<int> v(40);

	v.resize(20, -23);
	for (std::vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
		std::cout << *iter << std::endl;
}
