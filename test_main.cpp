/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 18:13:07 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/16 23:45:41 by alkrusts      ########   odam.nl         */
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

std::string gen_random(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;
}

enum constructor{def, fill, fill_2, range, copy};

template < class T>
void	mini_test_func_2(int size_of_vec,
		bool (*f)(ft::vector<T> *, ft::vector<T> *),
		std::string name,
		int constructor)
{
	ft::vector<T>		*ft_vec;
	ft::vector<T>		*ft_vec2;

	while (size_of_vec != -1)
	{
		if (constructor == def)
		{
			ft_vec = new ft::vector<T>;
			ft_vec2 = new ft::vector<T>;
			mini_test::mini_test<T>(name, f, ft_vec, ft_vec2, constructor, size_of_vec, T(), T());
		}
		else if (constructor == fill)
		{
			ft_vec = new ft::vector<T>(size_of_vec);
			ft_vec2 = new ft::vector<T>(size_of_vec + 20);
			mini_test::mini_test<T>(name, f, ft_vec, ft_vec2, constructor, size_of_vec, T(), T());
		}
		else if (constructor == fill_2)
		{
			ft_vec = new ft::vector<T>(size_of_vec, T());
			ft_vec2 = new ft::vector<T>(size_of_vec + 20, T());
			mini_test::mini_test<T>(name, f, ft_vec, ft_vec2, constructor, size_of_vec, T(), T());
		}
		else
		{
			return ;
			ft_vec = new ft::vector<T>;
			ft_vec2 = new ft::vector<T>;
			mini_test::mini_test<T>(name, f, ft_vec, ft_vec2, constructor, size_of_vec, T(), T());
		}
		delete ft_vec;
		delete ft_vec2;
		size_of_vec--;
		if (def == constructor)
			return ;
	}
}

//how to test function that take argumetns?
//well you need to pass the to the mini_test_func_3 
//this and then or add a nother loop to the existing loop
template < class T>
void	mini_test_func_3(int size_of_vec,
		bool (*f)(std::vector<T> *, ft::vector<T> *, unsigned int, T),
		std::string name,
		int constructor,
		unsigned int arg_1,
		T arg_2)
{
	ft::vector<T>		*ft_vec;
	std::vector<T>		*std_vec;
	int					iterations = 10;

	while (iterations)
	{
		while (size_of_vec != -1)
		{
			if (constructor == def)
			{
				ft_vec = new ft::vector<T>;
				std_vec = new std::vector<T>;
				mini_test::mini_test<T>(name, f, ft_vec, std_vec, constructor, size_of_vec, T(), T(), arg_1, arg_2);
			}
			else if (constructor == fill)
			{
				ft_vec = new ft::vector<T>(size_of_vec);
				std_vec = new std::vector<T>(size_of_vec);
				mini_test::mini_test<T>(name, f, ft_vec, std_vec, constructor, size_of_vec, T(), T(), arg_1, arg_2);
			}
			else if (constructor == fill_2)
			{
				ft_vec = new ft::vector<T>(size_of_vec, T());
				std_vec = new std::vector<T>(size_of_vec, T());
				mini_test::mini_test<T>(name, f, ft_vec, std_vec, constructor, size_of_vec, T(), T(), arg_1, arg_2);
			}
			else
			{
				return ;
				ft_vec = new ft::vector<T>;
				std_vec = new std::vector<T>;
				mini_test::mini_test<T>(name, f, ft_vec, std_vec, constructor, size_of_vec, T(), T(), arg_1, arg_2);
			}
			delete ft_vec;
			delete std_vec;
			size_of_vec--;
			if (def == constructor)
				return ;
		}
		iterations--;
	}
}

template < class T>
void	mini_test_func(int size_of_vec, bool (*f)(std::vector<T> *, ft::vector<T> *),
		std::string name,
		int constructor)
{
	ft::vector<T>		*ft_vec;
	std::vector<T>		*std_vec;

	while (size_of_vec != -1)
	{
		if (constructor == def)
		{
			ft_vec = new ft::vector<T>;
			std_vec = new std::vector<T>;
			mini_test::mini_test<T>(name, f, ft_vec, std_vec, constructor, size_of_vec, T(), T());
		}
		else if (constructor == fill)
		{
			ft_vec = new ft::vector<T>(size_of_vec);
			std_vec = new std::vector<T>(size_of_vec);
			mini_test::mini_test<T>(name, f, ft_vec, std_vec, constructor, size_of_vec, T(), T());
		}
		else if (constructor == fill_2)
		{
			ft_vec = new ft::vector<T>(size_of_vec, T());
			std_vec = new std::vector<T>(size_of_vec, T());
			mini_test::mini_test<T>(name, f, ft_vec, std_vec, constructor, size_of_vec, T(), T());
		}
		else
		{
			return ;
			ft_vec = new ft::vector<T>;
			std_vec = new std::vector<T>;
			mini_test::mini_test<T>(name, f, ft_vec, std_vec, constructor, size_of_vec, T(), T());
		}
		delete ft_vec;
		delete std_vec;
		size_of_vec--;
		if (def == constructor)
			return ;
	}
}

int main()
{
	srand(time(0));
	using namespace mini_test;

	enum constructor{def, fill, fill_2, range, copy};
	int	size_of_vec = 4;

	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		mini_test_func<int>(size_of_vec, capacity, "capacity()", CONSTRUCTOR);
		mini_test_func<float>(size_of_vec, capacity, "capacity()", CONSTRUCTOR);
		mini_test_func<double>(size_of_vec, capacity, "capacity()", CONSTRUCTOR);
		mini_test_func<std::string>(size_of_vec, capacity, "capacity()", CONSTRUCTOR);
		mini_test_func<char>(size_of_vec, capacity, "capacity()", CONSTRUCTOR);
		mini_test_func<char *>(size_of_vec, capacity, "capacity()", CONSTRUCTOR);
		mini_test_func<char **>(size_of_vec, capacity, "capacity()", CONSTRUCTOR);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif

	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		mini_test_func<int>(size_of_vec, empty, "empty()", CONSTRUCTOR);
		mini_test_func<float>(size_of_vec, empty, "empty()", CONSTRUCTOR);
		mini_test_func<double>(size_of_vec, empty, "empty()", CONSTRUCTOR);
		mini_test_func<std::string>(size_of_vec, empty, "empty()", CONSTRUCTOR);
		mini_test_func<char>(size_of_vec, empty, "empty()", CONSTRUCTOR);
		mini_test_func<char *>(size_of_vec, empty, "empty()", CONSTRUCTOR);
		mini_test_func<char **>(size_of_vec, empty, "empty()", CONSTRUCTOR);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif

	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		mini_test_func<int>(size_of_vec, get_allocator, "get_allocator()", CONSTRUCTOR);
		mini_test_func<float>(size_of_vec, get_allocator, "get_allocator()", CONSTRUCTOR);
		mini_test_func<double>(size_of_vec, get_allocator, "get_allocator()", CONSTRUCTOR);
		mini_test_func<std::string>(size_of_vec, get_allocator, "get_allocator()", CONSTRUCTOR);
		mini_test_func<char>(size_of_vec, get_allocator, "get_allocator()", CONSTRUCTOR);
		mini_test_func<char *>(size_of_vec, get_allocator, "get_allocator()", CONSTRUCTOR);
		mini_test_func<char **>(size_of_vec, get_allocator, "get_allocator()", CONSTRUCTOR);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif

	/*
	mini_test_func<int>(size_of_vec, accses_operator, "[]()");
	mini_test_func<float>(size_of_vec, accses_operator, "[]()");
	mini_test_func<double>(size_of_vec, accses_operator, "[]()");
	mini_test_func<std::string>(size_of_vec, accses_operator, "[]()");
	mini_test_func<char>(size_of_vec, accses_operator, "[]()");
	mini_test_func<char *>(size_of_vec, accses_operator, "[]()");
	mini_test_func<char **>(size_of_vec, accses_operator, "[]()");

#ifdef LEAKS
	system("leaks a.out");
#endif
*/

	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		mini_test_func_2<int>(size_of_vec, assign_operator, "=(ft::vector)", CONSTRUCTOR);
		mini_test_func_2<float>(size_of_vec, assign_operator, "=(ft::vector)", CONSTRUCTOR);
		mini_test_func_2<double>(size_of_vec, assign_operator, "=(ft::vector)", CONSTRUCTOR);
		mini_test_func_2<std::string>(size_of_vec, assign_operator, "=(ft::vector)", CONSTRUCTOR);
		mini_test_func_2<char>(size_of_vec, assign_operator, "=(ft::vector)", CONSTRUCTOR);
		mini_test_func_2<char *>(size_of_vec, assign_operator, "=(ft::vector)", CONSTRUCTOR);
		mini_test_func_2<char **>(size_of_vec, assign_operator, "=(ft::vector)", CONSTRUCTOR);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif
	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		mini_test_func<int>(size_of_vec, reserve, "reserve(n)", CONSTRUCTOR);
		mini_test_func<float>(size_of_vec, reserve, "reserve(n)", CONSTRUCTOR);
		mini_test_func<double>(size_of_vec, reserve, "reserve(n)", CONSTRUCTOR);
		mini_test_func<std::string>(size_of_vec, reserve, "reserve(n)", CONSTRUCTOR);
		mini_test_func<char>(size_of_vec, reserve, "reserve(n)", CONSTRUCTOR);
		mini_test_func<char *>(size_of_vec, reserve, "reserve(n)", CONSTRUCTOR);
		mini_test_func<char **>(size_of_vec, reserve, "reserve(n)", CONSTRUCTOR);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif

	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		mini_test_func<int>(size_of_vec, size, "size", CONSTRUCTOR);
		mini_test_func<float>(size_of_vec, size, "size", CONSTRUCTOR);
		mini_test_func<double>(size_of_vec, size, "size", CONSTRUCTOR);
		mini_test_func<std::string>(size_of_vec, size, "size", CONSTRUCTOR);
		mini_test_func<char>(size_of_vec, size, "size", CONSTRUCTOR);
		mini_test_func<char *>(size_of_vec, size, "size", CONSTRUCTOR);
		mini_test_func<char **>(size_of_vec, size, "size", CONSTRUCTOR);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif

/*
 * max_size m8 differ based on impelentation so there is no reason for use 
 * to cmp it with stl vector
	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		mini_test_func<int>(size_of_vec, max_size, "size_of_vec()", CONSTRUCTOR);
		mini_test_func<float>(size_of_vec, max_size, "size_of_vec()", CONSTRUCTOR);
		mini_test_func<double>(size_of_vec, max_size, "size_of_vec()", CONSTRUCTOR);
		mini_test_func<std::string>(size_of_vec, max_size, "size_of_vec()", CONSTRUCTOR);
		mini_test_func<char>(size_of_vec, max_size, "size_of_vec()", CONSTRUCTOR);
		mini_test_func<char *>(size_of_vec, max_size, "size_of_vec()", CONSTRUCTOR);
		mini_test_func<char **>(size_of_vec, max_size, "size_of_vec()", CONSTRUCTOR);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif
*/
	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		mini_test_func<int>(size_of_vec, begin, "begin()", CONSTRUCTOR);
		mini_test_func<float>(size_of_vec, begin, "begin()", CONSTRUCTOR);
		mini_test_func<double>(size_of_vec, begin, "begin()", CONSTRUCTOR);
		mini_test_func<std::string>(size_of_vec, begin, "begin()", CONSTRUCTOR);
		mini_test_func<char>(size_of_vec, begin, "begin()", CONSTRUCTOR);
		mini_test_func<char *>(size_of_vec, begin, "begin()", CONSTRUCTOR);
		mini_test_func<char **>(size_of_vec, begin, "begin()", CONSTRUCTOR);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif

	/*
	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		mini_test_func<int>(size_of_vec, end, "end()", CONSTRUCTOR);
		mini_test_func<float>(size_of_vec, end, "end()", CONSTRUCTOR);
		mini_test_func<double>(size_of_vec, end, "end()", CONSTRUCTOR);
		mini_test_func<std::string>(size_of_vec, end, "end()", CONSTRUCTOR);
		mini_test_func<char>(size_of_vec, end, "end()", CONSTRUCTOR);
		mini_test_func<char *>(size_of_vec, end, "end()", CONSTRUCTOR);
		mini_test_func<char **>(size_of_vec, end, "end()", CONSTRUCTOR);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif
*/

/*
 *	Add a singe arg resize test
 */
	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		int	size = std::rand() % 100;
		int	rand = std::rand() % INT_MAX;
		std::string rs = gen_random(std::rand() % 10);

		mini_test_func_3<int>(size_of_vec, resize, "resize(" + std::to_string(size) + ", " + std::to_string(rand) + ")", CONSTRUCTOR, size, rand);
		mini_test_func_3<float>(size_of_vec, resize, "resize(" + std::to_string(size) + ", " + std::to_string(rand) + ")", CONSTRUCTOR, size, (float)rand);
		mini_test_func_3<double>(size_of_vec, resize, "resize(" + std::to_string(size) + ", " + std::to_string(rand) + ")", CONSTRUCTOR, size, (double)rand);
		mini_test_func_3<std::string>(size_of_vec, resize, "resize(" + std::to_string(size) + ", " + rs + ")", CONSTRUCTOR, size, rs);
		mini_test_func_3<char>(size_of_vec, resize, "resize(" + std::to_string(size) + ", x)", CONSTRUCTOR, size, 'x'); 
	//	mini_test_func_3<char *>(size_of_vec, resize, "resize(" + std::to_string(size) + ", ",  CONSTRUCTOR, size, test); 
		mini_test_func_3<char **>(size_of_vec, resize, "resize(" + std::to_string(size) + ", " , CONSTRUCTOR, size, NULL);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif

/*
 *	Add a singe arg resize test
 */

	for (int CONSTRUCTOR = def; CONSTRUCTOR <= copy;  CONSTRUCTOR++)
	{
		int	size = std::rand() % 100;

		mini_test_func_4<int>(size_of_vec, resize, "resize(" + std::to_string(size) + ", " + std::to_string(rand) + ")", CONSTRUCTOR, size);
		mini_test_func_4<float>(size_of_vec, resize, "resize(" + std::to_string(size) + ", " + std::to_string(rand) + ")", CONSTRUCTOR, size);
		mini_test_func_4<double>(size_of_vec, resize, "resize(" + std::to_string(size) + ", " + std::to_string(rand) + ")", CONSTRUCTOR, size);
		mini_test_func_4<std::string>(size_of_vec, resize, "resize(" + std::to_string(size) + ", " + rs + ")", CONSTRUCTOR, size);
		mini_test_func_4<char>(size_of_vec, resize, "resize(" + std::to_string(size) + ", x)", CONSTRUCTOR, size); 
		mini_test_func_4<char **>(size_of_vec, resize, "resize(" + std::to_string(size) + ", " , CONSTRUCTOR, size);
	}

#ifdef LEAKS
	system("leaks a.out");
#endif

	std::cout << GREEN << "PASSED: "<< g_passed <<  RED << " FAILED: " << g_failed << RESET << std::endl;
	return (0);
}
