/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/28 14:16:15 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/04 08:03:03 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iterator>
#include <iostream>

int	main()
{
	std::vector<int>	std_vec;
	ft::vector<int>	ft_vec(4);

	std_vec.reserve(10);
	std::cout << std_vec.size() << " " << ft_vec.size() << std::endl;
	return (0);
}
