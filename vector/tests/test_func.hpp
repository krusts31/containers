#include "vector.hpp"

#include <vector>
#include <stdlib.h>

template < class T >
bool	empty(int n, int iter)
{
	int	random_integer;
	ft::vector<T>	*ft_vec = new ft::vector<T>(n);
	std::vector<T>	*std_vec = new std::vector<T>(n);

	while (iter)
	{
		random_integer = ((rand()%100)+1) * n;
		//std::cout << random_integer << std::endl;
		ft_vec = new ft::vector<T>(random_integer);
		std_vec = new std::vector<T>(random_integer);
		if (ft_vec->empty() != std_vec->empty())
		{
			std::cout << "capacity failed with " << n << std::endl;
			return (false);
		}
		delete ft_vec;
		delete std_vec;
		iter--;
	}
	ft_vec = new ft::vector<T>(0);
	std_vec = new std::vector<T>(0);
	if (ft_vec->empty() != std_vec->empty())
	{
		std::cout << "capacity failed with 0" << std::endl;
		return (false);
	}
	delete ft_vec;
	delete std_vec;
	return (true);
}

bool	is_fill_constructor_working(void)
{
	ft::vector<int>		to_copie(4);

	return (false);
}

template < class T >
bool	capcity(int n, int iter)
{
	int	random_integer;
	ft::vector<T>	*ft_vec = new ft::vector<T>(n);
	std::vector<T>	*std_vec = new std::vector<T>(n);

	while (iter)
	{
		random_integer = ((rand()%100)+1) * n;
		//std::cout << random_integer << std::endl;
		ft_vec = new ft::vector<T>(random_integer);
		std_vec = new std::vector<T>(random_integer);
		if (ft_vec->capacity() != std_vec->capacity())
		{
			std::cout << "capacity failed with " << n << std::endl;
			return (false);
		}
		delete ft_vec;
		delete std_vec;
		iter--;
	}
	ft_vec = new ft::vector<T>(0);
	std_vec = new std::vector<T>(0);
	if (ft_vec->capacity() != std_vec->capacity())
	{
		std::cout << "capacity failed with 0" << std::endl;
		return (false);
	}
	delete ft_vec;
	delete std_vec;
	return (true);
}
