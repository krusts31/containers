#ifndef TEST_FUNC_HPP
# define TEST_FUNC_HPP
#include "vector.hpp"

#include <vector>
#include <stdlib.h>
#include <cstdarg>

template < class T >
bool	empty(std::vector<T> *std_vec, ft::vector<T> *ft_vec)
{
	assert(ft_vec->empty() == std_vec->empty());
	return (true);
}

template < class T >
bool	resize(std::vector<T> *std_vec, ft::vector<T> *ft_vec, unsigned int size, T val)
{
	ft_vec->resize(size, val);
	std_vec->resize(size, val);

	typename std::vector<T>::iterator std_iter = std_vec->begin();
	for (typename ft::vector<T>::iterator ft_iter = ft_vec->begin(); ft_iter != ft_vec->end(); ft_iter++)
	{
		if (*ft_iter != *std_iter)
		{
			std::cout << "ft_iter: "<< *ft_iter << " std_iter:: " << *std_iter <<  " " << ft_vec->size() << " " << std_vec->size() << std::endl;
			return (false);
		}
		std_iter++;
	}
	return (true);
}

template < class T >
bool	begin(std::vector<T> *std_vec, ft::vector<T> *ft_vec)
{
	typename std::vector<T>::iterator	std_iterator = std_vec->begin();
	typename ft::vector<T>::iterator		ft_iterator = ft_vec->begin();

	//if the vectors are empty then there is segault when derefrescing a iterator
	if (!ft_vec->size() && !std_vec->size())
		return (true);
	assert(*ft_iterator == *std_iterator);
	return (true);
}

template < class T >
bool	end(std::vector<T> *std_vec, ft::vector<T> *ft_vec)
{
	typename std::vector<T>::iterator		std_iterator = std_vec->end();
	typename ft::vector<T>::iterator		ft_iterator = ft_vec->end();

	if (ft_vec->size() && std_vec->size())
		return (true);
	std_iterator--;
	ft_iterator--;
	if (*ft_iterator == *std_iterator)
		return (true);
	return (false);
}

bool	is_fill_constructor_working(void)
{
	ft::vector<int>		to_copie(4);

	return (false);
}

template < class T >
bool	get_allocator(std::vector<T> *std_vec, ft::vector<T> *ft_vec)
{
	assert(ft_vec->get_allocator() == std_vec->get_allocator());
	return (true);
}

template < class T >
bool	capacity(std::vector<T> *std_vec, ft::vector<T> *ft_vec)
{
	assert(ft_vec->capacity() == std_vec->capacity());
	return (true);
}

template < class T >
bool	size(std::vector<T> *std_vec, ft::vector<T> *ft_vec)
{
	assert(ft_vec->size() == std_vec->size());
	return (true);
}

template < class T >
bool	assign_operator(ft::vector<T> *ft_vec_2, ft::vector<T> *ft_vec)
{
	*ft_vec = *ft_vec_2;

	//set up iterators
	assert(ft_vec->size() == ft_vec_2->size());
	assert(ft_vec->capacity() == ft_vec_2->capacity());
	return (true);
}

/*
template < class T >
bool	accses_operator(std::vector<T> *std_vec, ft::vector<T> *ft_vec)
{
	//ft_vec[] == std_vec[]
	return (true);
}
*/

template < class T >
bool	reserve(std::vector<T> *std_vec, ft::vector<T> *ft_vec)
{
	for (int i = 0; i < 10; i++)
	{
		ft_vec->reserve(i);
		std_vec->reserve(i);
		assert(ft_vec->capacity() == std_vec->capacity());
		assert(ft_vec->size() == std_vec->size());
	}
	return (true);
}

#endif
