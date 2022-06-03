/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/03 12:54:14 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/03 12:57:06 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator_traits
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

/*
** difference_type	Type to express the result of subtracting one iterator from another.
** value_type		The type of the element the iterator can point to.
** pointer			The type of a pointer to an element the iterator can point to.
** reference		The type of a reference to an element the iterator can point to.
** category			The iterator category. It can be one of these:

    input_iterator_tag
    output_iterator_tag
    forward_iterator_tag
    bidirectional_iterator_tag
    random_access_iterator_tag

*/

	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class _Tp>
	class iterator : public iterator_traits<random_access_iterator_tag, _Tp>
	{
		private:
			typedef _Tp	*pointer;
			typedef _Tp	&reference;

			pointer		p;

		public:
			iterator() :p(0) {}

			iterator(const iterator& mit) : p(mit.p) {}

			iterator	&operator++() {++p;return *this;}
			iterator	operator++(int) {iterator tmp(*this); operator++(); return tmp;}
			bool		operator==(const iterator& rhs) const {return p==rhs.p;}
			bool		operator!=(const iterator& rhs) const {return p!=rhs.p;}
			reference	operator*() {return *p;}
	}; 
}
