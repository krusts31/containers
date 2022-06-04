#include "vector.hpp"

#include <vector>

template < class T >
bool	test_1(int n)
{
	ft::vector<T>			ft_vec;
	std::vector<T>			std_vec;

	while (n)
	{
		if (ft_vec.empty() != std_vec.empty())
			return (false);
		n--;
	}
	return (true);
}

bool	is_fill_constructor_working(void)
{
	ft::vector<int>		to_copie(4);

	return (false);
}

template < class T >
bool	test_2(int n)
{
	ft::vector<T>		ft_vec(4);
	std::vector<T>		std_vec(4);

	while (n)
	{
		if (ft_vec.capacity() != std_vec.capacity())
			return (false);
		n--;
	}
	return (true);
}

bool	test_time(void)
{
	
	return (true);
}
