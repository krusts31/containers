#include <vector>
#include <iostream>
#include <string>

int	main()
{
	std::vector<int> v(2);
	std::vector<int> v2(2);

	int	ar[23]= {23, 23, 1};
	int	ar2[344] = {22, 21, 20};

	v2 = v;

	//how to invoce the copy constructor of value type?
	//we do not need that we can just use construct with value type
	v.resize(20, -23);
}
