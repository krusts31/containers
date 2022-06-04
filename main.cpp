/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/28 14:16:15 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/02 15:24:09 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iterator>
#include <iostream>

int	main()
{
	std::vector<int>	std_vec(4);
	ft::vector<int>	ft_vec(4);

	std::cout << std_vec.capacity() << " " << ft_vec.capacity() << std::endl;
	return (0);
}
