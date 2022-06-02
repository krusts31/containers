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

int	main()
{
	std::vector<int>	std_vec;
	static const int arr[] = {16,2,77,29};
	std::vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	std::vector<int>::iterator ptr;

	ft::vector<int>	ft_vec;
	ft::vector<int>::iterator ft_ptr;
	(void)ft_ptr;

	return (0);
}
