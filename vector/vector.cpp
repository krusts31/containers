/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/25 15:36:16 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/05/25 15:48:30 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
namespace ft
{
	template < class T, class Alloc = std::allocator<T> >
	class vector
	{
		//explicit make sure that the constructor will be invoked by maching the type you pass it
		//inplicit would mean that if I pass H(11) or h("HAHA") then the comppiler could try to just
		//convert the "haha" to a integer hence implicite
		//member funcitons
		public:
			explicit vector(const Alloc& alloc = Alloc()) : _allocator(alloc)
			{
				this->_T = _allocator.allocate();
				std::cout << "HELLLO from defaul" << std::endl;
			}
			explicit vector(size_t n, const T& val = T(), const Alloc& alloc = Alloc())
			{
				std::cout << "HELLLO from size" << std::endl;
				this->_T = _allocator.allocate(val, n);
				(void)alloc;
				;
			}
			/*template <class InputIterator>
			vector (InputIterator first, InputIterator last, const Alloc& alloc = Alloc())
			{
				std::cout << "HELLLO from iterator" << std::endl;
				(void)alloc;
				;
			}
			vector (const vector& x)
			{
				std::cout << "HELLLO from copy" << std::endl;
			}
			*/
		private:
			T						*_T;
			const std::allocator<T>	&_allocator;
	};
}
