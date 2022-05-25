/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   main.cpp                                            :+:    :+:           */
/*                                                      +:+                   */
/*   By: alkrusts <alkrusts@student.codam.nl >         +#+                    */
/*                                                    +#+                     */
/*   Created: 2022/05/23 18:15:55 by alkrusts       #+#    #+#                */
/*   Updated: 2022/05/23 20:43:17 by alkrusts        ########   odam.nl       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <string>
#include <iostream>

#include "test.hpp"

int	main()
{
	std::vector<int>	x(10);
	ft::vector<int>		y;

	for (std::vector<int>::iterator iter = x.begin(); iter != x.end(); iter++)
	{
		int	index = distance(x.begin(), iter);

		x[index] = 1; //so what happend is that i pu the valu in
		std::cout << x[index] << " " << x.size() << std::endl;
	}
	return (0);
}
