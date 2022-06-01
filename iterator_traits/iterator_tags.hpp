/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   iterator_tags.hpp                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: alkrusts <alkrusts@student.codam.n>          +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/01 20:19:29 by alkrusts      #+#    #+#                 */
/*   Updated: 2022/06/01 20:19:30 by alkrusts      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_TAGS_HPP
# define ITERATOR_TAGS_HPP
namespace ft
{
	struct input_iterator_tag {};
	struct output_iterator_tag {};
	struct forward_iterator_tag       : public input_iterator_tag {};
	struct bidirectional_iterator_tag : public forward_iterator_tag {};
	struct random_access_iterator_tag : public bidirectional_iterator_tag {};
}
#endif
