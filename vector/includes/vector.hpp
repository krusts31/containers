/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vector.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/28 14:13:08 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/10 23:55:53 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <iostream>
# include <assert.h>
# include "iterator.hpp"

namespace ft
{
	template < class _Tp, class _Allocator = std::allocator<_Tp> >
	class vector
	{
		public:
			#ifdef MINI_TEST
				friend class mini_test;
			#endif
			typedef _Allocator                               allocator_type;
			typedef std::allocator_traits<allocator_type>    __alloc_traits;

			typedef typename __alloc_traits::size_type       size_type;
			typedef _Tp                                      value_type;

			typedef const _Tp                                const_value_type;
			typedef value_type&                              reference;
			typedef const value_type&                        const_reference;

			typedef typename __alloc_traits::difference_type difference_type;
			typedef typename __alloc_traits::pointer         pointer;
			typedef typename __alloc_traits::const_pointer   const_pointer;

			typedef typename ft::iterator<value_type>	 	 iterator;
			typedef typename ft::iterator<const_value_type>	 const_iterator;


			explicit vector(const allocator_type &alloc = _Allocator())
			{
				_allocator = alloc;
				_t = _Tp();
			   	_size = size_type(0);
			   	_capacity = size_type(0);
				_iterator = iterator();
				_value = _allocator.allocate(0);
				_begin = &this->_value[0];
				_end = &this->_value[_size];
			   	_end_of_storage = &this->_value[_size + 1];
			}

			//fill constructo
			explicit vector(size_t n, const _Tp& val = _Tp(), const _Allocator& alloc = _Allocator()) : _allocator(alloc)
			{
				_allocator = alloc;
				_t = val;
				_value = _allocator.allocate(n);
				_capacity = size_type(n);
			   	_size = size_type(n);
				_iterator = iterator();
				for (size_t i = 0; i < n; i++)
				{
					_allocator.construct(&this->_value[i], val);
					//so to copy it we need a = operator overload
				}
				_begin = &this->_value[0];
				_end = &this->_value[_size];
			   	_end_of_storage = &this->_value[_size + 1];
			}
			~vector()
			{
				for (size_t i = 0; i < _size; i++)
					_allocator.destroy(&this->_value[i]);
				_allocator.deallocate(this->_value, _capacity);
			}
/*
vector<_Tp, _Allocator>::operator[](size_type __n) _NOEXCEPT
{
    _LIBCPP_ASSERT(__n < size(), "vector[] index out of bounds");
    return this->__begin_[__n];
}
*/
			vector& operator=(const vector& src)
			{
				if (this != &src)
				{
					_allocator = src.get_allocator();
					_t = src._t;
					_iterator = src._iterator;
					for (size_t i = 0; i < _size; i++)
						_allocator.destroy(&this->_value[i]);
					_allocator.deallocate(this->_value, _capacity);
					_size = src.size();
					_value = _allocator.allocate(_size);
					_capacity = size_type(_size);
					for (size_t i = 0; i < _size; i++)
						_allocator.construct(&this->_value[i], _t);
					_begin = &src._value[0];
					_end = &src._value[_size];
					_end_of_storage = &src._value[_size + 1];
				}
				return (*this);
			}

			/*
			void push_back(const value_type& val)
			{
				
			}
			*/

			allocator_type get_allocator(void) const
			{
				return (_allocator);
			}

			size_type size(void) const
			{
				return (_size);
			}


			size_type max_size(void) const
			{
				return (_allocator.max_size());
			}

			vector<_Tp, _Allocator>operator[](size_type)
			{
				assert(index < size());
				return(this->_begin[index]);
			}

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

			void reserve(size_type n)
			{
				//reserver is tricky
				if (n > _size)
				{
					pointer _tmp_value = _allocator.allocate(n);
					for (size_t i = 0; i < n; i++)
						_allocator.construct(&_tmp_value[i], _t);
					for (size_t i = 0; i < _size; i++)
						_allocator.destroy(&this->_value[i]);
					_allocator.deallocate(this->_value, _capacity);
					_value = _tmp_value;
					_capacity = n;
					_begin = &this->_value[0];
					_end = &this->_value[_size];
					_end_of_storage = &this->_value[_size + 1];
				}
			}

			iterator begin(void)
			{
				return(iterator(_begin));
			}

			const_iterator begin(void) const
			{
				return(const_iterator(_begin));
			}

			iterator end(void)
			{
				return(iterator(_end));
			}

			const_iterator end(void) const
			{
				return(const_iterator(_end));
			}
/*
			void resize (size_type n, value_type val = value_type())
			{
				;
			}
*/
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
			value_type				_t;
			//const_value_type		_ct;
			size_type		_size;
			size_type		_capacity;
			pointer			_value;
			pointer			_begin;
			pointer			_end;
			iterator		_iterator;
			pointer			_end_of_storage;//end of alloc space
	};
}
#endif
