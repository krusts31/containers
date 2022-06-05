/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 18:13:07 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/05 23:17:53 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "mini_tests.hpp"
#include "mini_test.hpp"
#include "vector.hpp"

#include <time.h>

#include <string.h>
#include <string>

#include <type_traits>

//vector has 3
//ft::vector<T>	(args).function(args_2) == std::vector(args).function(args)
//now can the args be of T waht about args_2 of T?
//template < class T, class args_1, class args_2 > int, int, srt
//template < class T, class args_1, class args_2 > int, iter, iter 
//the unit mini_tester has to mini_test some things like leaks
//the unit thet has to mini_test the functoins 

enum constructor{def, fill, fill_2, range, copy};

template < class T>
void	mini_test_func_2(int size, bool (*f)(ft::vector<T> *, ft::vector<T> *),
		std::string name,
		int constructor)
{
	ft::vector<T>		*ft_vec;
	ft::vector<T>		*ft_vec2;

	while (size != -1)
	{
		if (constructor == def)
		{
			ft_vec = new ft::vector<T>;
			ft_vec2 = new ft::vector<T>;
		}
		else if (constructor == fill)
		{
			ft_vec = new ft::vector<T>(size);
			ft_vec2 = new ft::vector<T>(size + 20);
		}
		else if (constructor == fill_2)
		{
			ft_vec = new ft::vector<T>(size, T());
			ft_vec2 = new ft::vector<T>(size + 20, T());
		}
		else
		{
			return ;
			ft_vec = new ft::vector<T>;
			ft_vec2 = new ft::vector<T>;
		}
		mini_test::mini_test<T>(name, f, ft_vec, ft_vec2, constructor);
		delete ft_vec;
		delete ft_vec2;
		size--;
		if (def == constructor)
			return ;
	}
}

template < class T>
void	mini_test_func(int size, bool (*f)(std::vector<T> *, ft::vector<T> *),
		std::string name,
		int constructor)
{
	ft::vector<T>		*ft_vec;
	std::vector<T>		*std_vec;

	while (size != -1)
	{
		if (constructor == def)
		{
			ft_vec = new ft::vector<T>;
			std_vec = new std::vector<T>;
		}
		else if (constructor == fill)
		{
			ft_vec = new ft::vector<T>(size);
			std_vec = new std::vector<T>(size);
		}
		else if (constructor == fill_2)
		{
			ft_vec = new ft::vector<T>(size, T());
			std_vec = new std::vector<T>(size, T());
		}
		else
		{
			return ;
			ft_vec = new ft::vector<T>;
			std_vec = new std::vector<T>;
		}
		mini_test::mini_test<T>(name, f, ft_vec, std_vec, constructor);
		delete ft_vec;
		delete std_vec;
		size--;
		if (def == constructor)
			return ;
	}
}

int main()
{
	srand(time(0));
	using namespace mini_test;

	enum constructor{def, fill, fill_2, range, copy};
	int	size = 2;

	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		mini_test_func<int>(size, capacity, "capacity()", CONSTRUCTOR);
		mini_test_func<float>(size, capacity, "capacity()", CONSTRUCTOR);
		mini_test_func<double>(size, capacity, "capacity()", CONSTRUCTOR);
		mini_test_func<std::string>(size, capacity, "capacity()", CONSTRUCTOR);
		mini_test_func<char>(size, capacity, "capacity()", CONSTRUCTOR);
		mini_test_func<char *>(size, capacity, "capacity()", CONSTRUCTOR);
		mini_test_func<char **>(size, capacity, "capacity()", CONSTRUCTOR);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif

	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		mini_test_func<int>(size, empty, "empty()", CONSTRUCTOR);
		mini_test_func<float>(size, empty, "empty()", CONSTRUCTOR);
		mini_test_func<double>(size, empty, "empty()", CONSTRUCTOR);
		mini_test_func<std::string>(size, empty, "empty()", CONSTRUCTOR);
		mini_test_func<char>(size, empty, "empty()", CONSTRUCTOR);
		mini_test_func<char *>(size, empty, "empty()", CONSTRUCTOR);
		mini_test_func<char **>(size, empty, "empty()", CONSTRUCTOR);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif

	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		mini_test_func<int>(size, get_allocator, "get_allocator()", CONSTRUCTOR);
		mini_test_func<float>(size, get_allocator, "get_allocator()", CONSTRUCTOR);
		mini_test_func<double>(size, get_allocator, "get_allocator()", CONSTRUCTOR);
		mini_test_func<std::string>(size, get_allocator, "get_allocator()", CONSTRUCTOR);
		mini_test_func<char>(size, get_allocator, "get_allocator()", CONSTRUCTOR);
		mini_test_func<char *>(size, get_allocator, "get_allocator()", CONSTRUCTOR);
		mini_test_func<char **>(size, get_allocator, "get_allocator()", CONSTRUCTOR);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif

	/*
	mini_test_func<int>(size, accses_operator, "[]()");
	mini_test_func<float>(size, accses_operator, "[]()");
	mini_test_func<double>(size, accses_operator, "[]()");
	mini_test_func<std::string>(size, accses_operator, "[]()");
	mini_test_func<char>(size, accses_operator, "[]()");
	mini_test_func<char *>(size, accses_operator, "[]()");
	mini_test_func<char **>(size, accses_operator, "[]()");

#ifdef LEAKS
	system("leaks a.out");
#endif
*/

	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		mini_test_func_2<int>(size, assign_operator, "=(ft::vector)", CONSTRUCTOR);
		mini_test_func_2<float>(size, assign_operator, "=(ft::vector)", CONSTRUCTOR);
		mini_test_func_2<double>(size, assign_operator, "=(ft::vector)", CONSTRUCTOR);
		mini_test_func_2<std::string>(size, assign_operator, "=(ft::vector)", CONSTRUCTOR);
		mini_test_func_2<char>(size, assign_operator, "=(ft::vector)", CONSTRUCTOR);
		mini_test_func_2<char *>(size, assign_operator, "=(ft::vector)", CONSTRUCTOR);
		mini_test_func_2<char **>(size, assign_operator, "=(ft::vector)", CONSTRUCTOR);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif
	std::cout << GREEN << "PASSED: "<< g_passed <<  RED << " FAILED: " << g_failed << RESET << std::endl;
	return (0);
}
