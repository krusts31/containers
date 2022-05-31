/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterator.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 16:11:23 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/05/31 16:17:32 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "iterator_traits.hpp"

template <class T>
class MyIterator : public ft::iterator<std::input_iterator_tag, int>
{
	T		*p;

	public:
		MyIterator(T* x) :p(x) {}
		MyIterator(const MyIterator& mit) : p(mit.p) {}
		MyIterator& operator++() {++p;return *this;}
		MyIterator operator++(int) {MyIterator tmp(*this); operator++(); return tmp;}
		bool operator==(const MyIterator& rhs) const {return p==rhs.p;}
		bool operator!=(const MyIterator& rhs) const {return p!=rhs.p;}
		T& operator*() {return *p;}
}; 
