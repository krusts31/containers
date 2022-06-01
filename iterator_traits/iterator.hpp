/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 16:11:23 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/01 20:18:09 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iterator_traits.hpp"
#include "iterator_tags.hpp"

namespace ft
{
	template <class T>
	class Iterator : public ft::iterator<ft::input_iterator_tag, T>
	{
		T		*p;

		public:
			Iterator(T* x) :p(x) {}

			Iterator(const Iterator& mit) : p(mit.p) {}

			Iterator	&operator++() {++p;return *this;}
			Iterator	operator++(int) {Iterator tmp(*this); operator++(); return tmp;}
			bool		operator==(const Iterator& rhs) const {return p==rhs.p;}
			bool		operator!=(const Iterator& rhs) const {return p!=rhs.p;}
			T			&operator*() {return *p;}
	}; 
}
