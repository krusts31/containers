/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/28 14:13:08 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/01 13:33:55 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace ft
{
	template < class _Tp, class _Allocator = std::allocator<_Tp> >
	class vector
	{
		//explicit make sure that the constructor will be invoked by maching the type you pass it
		//inplicit would mean that if I pass H(11) or h("HAHA") then the comppiler could try to just
		//convert the "haha" to a integer hence implicite
		//member funcitons

		public:
			typedef _Allocator                               allocator_type;
			typedef std::allocator_traits<allocator_type>    __alloc_traits;
			typedef typename __alloc_traits::size_type       size_type;
		protected:
			typedef _Tp                                      value_type;
			typedef value_type&                              reference;
			typedef const value_type&                        const_reference;
			typedef typename __alloc_traits::difference_type difference_type;
			typedef typename __alloc_traits::pointer         pointer;
			typedef typename __alloc_traits::const_pointer   const_pointer;
			typedef pointer                                  iterator;
			typedef const_pointer                            const_iterator;

			explicit vector(const allocator_type &alloc = _Allocator()) : _allocator(alloc)
			{
				//std::cout << "HELLLO from defaul" << std::endl;
			}
			explicit vector(size_t n, const _Tp& val = _Tp(), const _Allocator& alloc = _Allocator()) : _allocator(alloc)
			{
				std::cout << "HELLLO from size" << std::endl;
				this->_T = _allocator.allocate(n);
				for (size_t i = 0; i < n; i++)
					_allocator.construct(&this->_T[i], val);
			}
			/*template <class InputIterator>
			vector (InputIterator first, InputIterator last, const _Allocator& alloc = _Allocator())
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
			value_type		t;
			allocator_type	_allocator;
			unsigned int	_size;
	};
}
