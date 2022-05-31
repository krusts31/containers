/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 16:11:29 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/05/31 18:41:15 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"
#include <string>
#include <iostream>

int main () {
std::string numbers[]={"Hallo", "waza", "'nye", "sadf", "BYEEEE"};
  MyIterator <std::string>from(numbers);
  MyIterator <std::string>until(numbers+5);
  for (MyIterator <std::string>it=from; it!=until; it++)
	  std::cout << *it << ' ';
  std::cout << '\n';

  return 0;
}
