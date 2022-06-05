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
bool	get_allocator(std::vector<T> *std_vec, ft::vector<T> *ft_vec)
{
	if (ft_vec->get_allocator() != std_vec->get_allocator())
		return (false);
	return (true);
}

template < class T >
bool	capacity(std::vector<T> *std_vec, ft::vector<T> *ft_vec)
{
	if (ft_vec->capacity() != std_vec->capacity())
		return (false);
	return (true);
}

template < class T >
bool	assign_operator(ft::vector<T> *std_vec, ft::vector<T> *ft_vec)
{
	*ft_vec = *std_vec;

	//need to make iterators work so that I could test weather or not all the values have been copied
	if (ft_vec->size() != std_vec->size())
		return (false);
	if (ft_vec->capacity() != std_vec->capacity())
		return (false);
	return (true);
}

/*
 * before setting up this I need to make the fill constructor
template < class T >
bool	accses_operator(std::vector<T> *std_vec, ft::vector<T> *ft_vec)
{
	//ft_vec[] == std_vec[]
	return (true);
}
*/
#endif
