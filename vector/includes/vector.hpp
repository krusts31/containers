/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/28 14:13:08 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/03 19:09:14 by alkrusts      ########   odam.nl         */
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
			typedef _Tp                                      value_type;
			typedef value_type&                              reference;
			typedef const value_type&                        const_reference;
			typedef typename __alloc_traits::difference_type difference_type;
			typedef typename __alloc_traits::pointer         pointer;
			typedef typename __alloc_traits::const_pointer   const_pointer;
			typedef const_pointer                            const_iterator;
			typedef typename ft::iterator<value_type>	 iterator;


			explicit vector(const allocator_type &alloc = _Allocator())
			{
				_allocator = alloc;
				_t = _Tp();
			   	_size = size_type();
			   	_capacity = size_type();
				_start = pointer();
				_end = pointer();
			   	_end_of_storage = pointer();
			}

			//~vector();

			size_type capacity(void) const
			{
				return (_capacity);
			}
			bool	empty(void) const
			{
				return (_size == 0 ? true : false);
			}
			void clear(void)
			{
				//iterator over values and call deconstrucotr
				//set size to 0
				//do not dealloc space
			}

/*
			void resize (size_type n, value_type val = value_type())
			{
				;
			}
			void reserve (size_type n)
			{
				//alloc new bolck
				//copy all elements to new bock
				//deconstruct old objects
				//dealocate old objects
				;
			}
*/
			explicit vector(size_t n, const _Tp& val = _Tp(), const _Allocator& alloc = _Allocator()) : _allocator(alloc)
			{
				_allocator = alloc;	//set the std::allocator
				_t = _Tp();		//template what the fuck is the if we have value type
				_start = pointer();
				_end = pointer();
			   	_end_of_storage = pointer();
				_t = *_allocator.allocate(n); //this looks wrong
				_capacity = size_type(n);
			   	_size = size_type();
				(void)val;
				/*
				for (size_t i = 0; i < n; i++)
				{
					_allocator.construct(&this->_t[i], val);
				}
				*/
			}
			reference at (size_type n);
			const_reference at (size_type n) const;
		protected:
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
			size_type		_size;
			size_type		_capacity;
			//pointer			;
			pointer			_start;
			pointer			_end;
			pointer			_end_of_storage;//end of alloc space
	};
}
