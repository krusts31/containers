/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/28 14:16:15 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/05 22:40:55 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <iterator>
#include <iostream>

int	main()
{
	std::vector<int>	std_vec;
	ft::vector<int>		ft_vec(4);
	ft::vector<int>		ft_vec_2(8);

	std::cout << ft_vec.size() << " " << ft_vec_2.size() << std::endl;
	ft_vec_2 = ft_vec;
	std::cout << ft_vec.size() << " " << ft_vec_2.size() << std::endl;
	return (0);
}
