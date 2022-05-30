#ifndef MAP_HPP
# define MAP_HPP
#include <iostream>
#include <iterator>
#include <memory>
namespace ft
{
	template <class T>
	class mapIterator : public std::iterator<std::input_iterator_tag, T>
	{
		public:
			mapIterator()
			{
				_t = NULL;
			}
		private:
			T	*_t;
	};

	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
	class map
	{
		public:

			typedef std::pair<const Key, T>	value_type;

			typedef mapIterator<value_type>	iterator;
			typedef Key			key_type;
			typedef unsigned int 		size_type;
			typedef value_type*		pointer;

			explicit map(const Compare& comp = Compare(), const Alloc& alloc = Alloc()) : _compare(comp)
			{
				_t = NULL;
				_key = NULL;
				_val = NULL;
				_alloc = alloc;
			}
			template <class InputIterator>
			map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Alloc& alloc = Alloc()) : _alloc(alloc), _compare(comp)
			{
			
			}
			map(const map& x)
			{

			}
			~map()
			{
				//destroy(_ptr);
				if (!empty())
					_alloc.deallocate(_ptr, size());
			}
			bool empty() const
			{
				if (_val == NULL)
					return (true);
				return (false);
			}
			
			size_type	size(void)
			{
				unsigned int	test = 0;

				if (empty())
					return (0);
				return (test);
			}
			/*
			mapped_type& operator[] (const key_type& k)
			{
				;
			}
			pair<iterator,bool> insert(const value_type& val)
			{
				_val_tmp = _val;
				_val = _alloc.deallocate
			}
			map& operator=(const map& x)
			{
				//Copies all the elements from x into the container, changing its size accordingly. The container preserves its current allocator, which is used to allocate additional storage if needed.
			}

			iterator	begin()
			{
				return (t);
			}
			iterator	end();
			*/
		private:
			/*
			void	re_alloc(size_t size)
			{
				new_value_block = _alloc.allocate(size);

				
			}
			*/
			value_type	*_val;
			pointer		_ptr;
			T		*_t;
			Key		*_key;
			const Compare	&_compare;
			Alloc		_alloc;
	};
}
#endif
