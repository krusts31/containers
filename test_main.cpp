/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 18:13:07 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/04 13:27:03 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "test_func.hpp"

#include <string>

int main ()
{
	/*
	(ft::test(test_3, "Default int constructor"));
	(ft::test(is_default_construct_vec_char_empty, "ft::vector<char> ft_char_vec.empty()"));
	(ft::test(is_default_construct_vec_float_empty, "ft::vector<float> ft_float_vec.empty()"));
	(ft::test(is_default_construct_vec_string_empty, "ft::vector<string> ft_string_vec.empty()"));
	(ft::test(is_default_construct_vec_int_empty, "ft::vector<int> ft_int_vec.empty()"));
	(ft::test(is_fill_constructor_working, "ft::vector<int> fill construcor"));
	*/
	(ft::test(test_2<int>, "ft::vector<int> ft_vec.capacity()", 100));
	(ft::test(test_2<double>, "ft::vector<double> ft_vec.capacity()", 100));
	(ft::test(test_2<char>, "ft::vector<char> ft_vec.capacity()", 100));
	(ft::test(test_2<float>, "ft::vector<float> ft_vec.capacity()", 100));
	(ft::test(test_2<std::string>, "ft::vector<std::string> ft_vec.capacity()", 100));

	(ft::test(test_1<int>, "ft::vector<int> ft_vec.empty()", 100));
	(ft::test(test_1<double>, "ft::vector<double> ft_vec.empty()", 100));
	(ft::test(test_1<char>, "ft::vector<char> ft_vec.empty()", 100));
	(ft::test(test_1<float>, "ft::vector<float> ft_vec.empty()", 100));
	(ft::test(test_1<std::string>, "ft::vector<std::string> ft_vec.empty()", 100));
	std::cout << GREEN << "PASSED: "<< ft::g_passed <<  RED << " FAILED: " << ft::g_failed << RESET << std::endl;
	return (0);
}
