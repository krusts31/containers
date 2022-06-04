#ifndef TEST_FUNC_HPP
# define TEST_FUNC_HPP
#include "vector.hpp"

#include <vector>
#include <stdlib.h>
#include <cstdarg>

template < class T >
bool	empty(std::vector<T> *std_vec, ft::vector<T> *ft_vec)
{
	if (ft_vec->empty() != std_vec->empty())
		return (false);
	return (true);
}

bool	is_fill_constructor_working(void)
{
	ft::vector<int>		to_copie(4);

	return (false);
}

template < class T >
bool	capacity(std::vector<T> *std_vec, ft::vector<T> *ft_vec)
{
	if (ft_vec->capacity() != std_vec->capacity())
		return (false);
	return (true);
}
#endif
