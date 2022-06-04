/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 18:13:07 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/04 14:07:01 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "test_func.hpp"

#include <time.h>
#include <string>

int main ()
{
	srand(time(0));

	(ft::test(capcity<int>, "ft::vector<int> ft_vec.capacity()", 10000, 100));
	(ft::test(capcity<double>, "ft::vector<double> ft_vec.capacity()", 100, 100));
	(ft::test(capcity<char>, "ft::vector<char> ft_vec.capacity()", 100, 100));
	(ft::test(capcity<float>, "ft::vector<float> ft_vec.capacity()", 100, 100));
	(ft::test(capcity<std::string>, "ft::vector<std::string> ft_vec.capacity()", 100, 100));

	(ft::test(empty<int>, "ft::vector<int> ft_vec.empty()", 10000, 100));
	(ft::test(empty<double>, "ft::vector<double> ft_vec.empty()", 100, 100));
	(ft::test(empty<char>, "ft::vector<char> ft_vec.empty()", 100, 100));
	(ft::test(empty<float>, "ft::vector<float> ft_vec.empty()", 100, 100));
	(ft::test(empty<std::string>, "ft::vector<std::string> ft_vec.empty()", 100, 100));

	std::cout << GREEN << "PASSED: "<< ft::g_passed <<  RED << " FAILED: " << ft::g_failed << RESET << std::endl;
	return (0);
}
