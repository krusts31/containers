/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterator_traits.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/31 13:29:55 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/01 18:12:58 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <cstddef>

namespace ft
{
	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator
	{
		typedef T			value_type;
		typedef Distance	difference_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};
}

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
