/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 16:11:29 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/01 20:19:07 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"
#include <string>
#include <iostream>

int main () {
std::string numbers[]={"Hallo", "waza", "'nye", "sadf", "BYEEEE"};
	ft::Iterator <std::string>from(numbers);
	ft::Iterator <std::string>until(numbers+5);
  for (ft::Iterator <std::string>it=from; it!=until; it++)
	  std::cout << *it << ' ';
  std::cout << '\n';

  return 0;
}
