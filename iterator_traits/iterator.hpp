/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 16:11:23 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/02 16:40:53 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iterator_traits.hpp"
#include "iterator_tags.hpp"

namespace ft
{
	template <class _Tp>
	class iterator : public ft::iterator_traits<ft::random_access_iterator_tag, _Tp>
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
