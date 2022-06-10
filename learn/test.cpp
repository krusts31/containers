#include <vector>
#include <iostream>
#include <string>

int	main()
{
	std::vector<int> v;
	std::vector<char> vc;
	std::vector<std::string> vcs;

	std::cout << v.max_size() << std::endl;
	std::cout << vc.max_size() << std::endl;
	std::cout << vcs.max_size() << std::endl;
}
