/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 18:13:07 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/03 12:49:13 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "test_func.hpp"

int main ()
{
	signal(SIGUSR1, ft::signalPass);
	signal(SIGUSR2, ft::signalFail);

	(ft::test(test_3, "Default int constructor"));
	std::cout << GREEN << "PASSED: "<< ft::g_passed <<  RED << " FAILED: " << ft::g_failed << RESET << std::endl;
	return (0);
}
