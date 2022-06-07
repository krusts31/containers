#include "vector.hpp"
#include <iostream>
#include <type_traits>
#include <string>
#include <chrono>
#include <unistd.h>
#include <vector>
 
class	test
{
	public:
		test(int x): _x(x)
		{}
		friend class test_2;
	private:
		int get_x() const
		{
			return (_x);
		}
		int _x;
};

class	test_2
{
	public:
		test_2(){};
		int	get_x(test &t)
		{
			return (t.get_x());
		}
};

template <class T>
void		func(void)
{
	if (std::is_same<T, std::string>::value)
		std::cout << "its a string" << std::endl;
	else
		std::cout << "not a string" << std::endl;

}

int main()
{
	/*
    using namespace std::chrono;
 
    uint64_t ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    std::cout << ms << " milliseconds since the Epoch\n";
 
    uint64_t Ms = duration_cast<microseconds>(system_clock::now().time_since_epoch()).count();
    std::cout << Ms << " milliseconds since the Epoch\n";
 
	std::vector<int>	vec(3, 3);
	std::vector<int>	vec_2(3, 3);
	std::vector<std::string>	vec_4(3, "bye");

	//std::vector<std::string>	vec_5{3};
	//std::vector<std::string>	vec_6{3};

	std::cout << vec[0] << " " << vec[1] << " " << vec[2] << std::endl;
	std::cout << vec_2[0] << " " << vec_2[1] << " " << vec_2[2] << std::endl;

	std::cout << vec_3[0] << " " << vec_3[1] << " " << vec_3[2] << std::endl;
	std::cout << vec_4[0] << " " << vec_4[1] << " " << vec_4[2] << std::endl;

	//std::cout << vec_5[0] << " " << vec_5[1] << " " << vec_5[2] << std::endl;
	//std::cout << vec_6[0] << " " << vec_6[1] << " " << vec_6[2] << std::endl;
	test 	lol(29);
	test_2	lol2;
	std::cout << lol2.get_x(lol) << std::endl;
	ft::vector<int>		vec1(20);
	std::vector<int>	vec2(3);

	std::cout << vec1.size() << std::endl;
	vec1 = vec2;
	std::cout << vec1.size() << std::endl;

	std::vector<int>	vec2(10, 4);

	for (std::vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++)
		std::cout << *iter << std::endl;
	std::cout << "capacity:" << vec2.capacity() << "size:" << vec2.size() << std::endl;
	vec2.reserve(50);
	for (std::vector<int>::iterator iter = vec2.begin(); iter != vec2.end(); iter++)
		std::cout << *iter << std::endl;
	std::cout << "capacity:" << vec2.capacity() << "size:" << vec2.size() << std::endl;
    return (0);
	*/
	ft::vector<int>	test(10, 100);
	ft::vector<int>::iterator	iter;
	//ft::vector<int>::const_iterator	c_iter;

	for (iter = test.begin(); iter != test.end(); iter++)
		std::cout << *iter << std::endl;
//	for (c_iter = test.begin(); c_iter != test.end(); c_iter++)
//		std::cout << *c_iter << std::endl;
}
