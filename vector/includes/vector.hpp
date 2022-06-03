/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/28 14:13:08 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/03 16:16:29 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iterator.hpp"

namespace ft
{
	template < class _Tp, class _Allocator = std::allocator<_Tp> >
	class vector
	{
		public:
			typedef _Allocator                               allocator_type;
			typedef std::allocator_traits<allocator_type>    __alloc_traits;
			typedef typename __alloc_traits::size_type       size_type;

			explicit vector(const allocator_type &alloc = _Allocator())
			{
				_allocator = alloc;
				_t = _Tp();
			   	_size = 0;
				_start = pointer();
				_end = pointer();
			   	_end_of_storage = pointer();
			}

			//~vector();

			bool	empty(void) const
			{
				return (_size == 0 ? true : false);
			}

			typedef _Tp                                      value_type;
			typedef value_type&                              reference;
			typedef const value_type&                        const_reference;
			typedef typename __alloc_traits::difference_type difference_type;
			typedef typename __alloc_traits::pointer         pointer;
			typedef typename __alloc_traits::const_pointer   const_pointer;
			typedef const_pointer                            const_iterator;
			typedef typename ft::iterator<value_type>		 iterator;

		protected:
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
			allocator_type	_allocator;
			value_type		_t;
			unsigned int	_size;
			pointer			_start;
			pointer			_end;
			pointer			_end_of_storage;//end of alloc space
	};
}
