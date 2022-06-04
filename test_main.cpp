/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 18:13:07 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/04 17:01:25 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "test_func.hpp"
#include "vector.hpp"

#include <time.h>
#include <string>

template < class T>
void	test_func(int size, bool (*f)(std::vector<T> *, ft::vector<T> *), std::string name)
{
	ft::vector<T>		*ft_vec;
	std::vector<T>		*std_vec;

	while (size != -1)
	{
		ft_vec = new ft::vector<T>(size);
		std_vec = new std::vector<T>(size);

		ft::test<T>(name, f, ft_vec, std_vec);
		delete ft_vec;
		delete std_vec;
		size--;
	}
}

int main()
{
	srand(time(0));

	test_func<int>(50, capacity, "capacity()");
	test_func<float>(50, capacity, "capacity()");
	test_func<double>(50, capacity, "capacity()");
	test_func<std::string>(50, capacity, "capacity()");
	test_func<char>(50, capacity, "capacity()");
	test_func<char *>(50, capacity, "capacity()");
	test_func<char **>(50, capacity, "capacity()");
#ifdef LEAKS
	system("leaks a.out");
#endif

	test_func<int>(50, empty, "empty()");
	test_func<float>(50, empty, "empty()");
	test_func<double>(50, empty, "empty()");
	test_func<std::string>(50, empty, "empty()");
	test_func<char>(50, empty, "empty()");
	test_func<char *>(50, empty, "empty()");
	test_func<char **>(50, empty, "empty()");
#ifdef LEAKS
	system("leaks a.out");
#endif

	std::cout << GREEN << "PASSED: "<< ft::g_passed <<  RED << " FAILED: " << ft::g_failed << RESET << std::endl;
	return (0);
}
