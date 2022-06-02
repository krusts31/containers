/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 18:13:07 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/02 19:26:22 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"
#include "test_func.hpp"

int main ()
{
	signal(SIGUSR1, ft::signalPass);
	signal(SIGUSR2, ft::signalFail);

	while(1)
	{
		(ft::test(test_1, "test 1"));
		(ft::test(test_2, "test 2"));
		(ft::test(test_3, "test 3"));
		std::cout << ft::g_passed << " " << ft::g_failed << std::endl;
		sleep(1);
	}
	return (0);
}
