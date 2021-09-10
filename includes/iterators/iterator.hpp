/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 09:31:57 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/10 17:15:13 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <cstddef>

#include "./category.hpp"
#include "./iterator_base.hpp"
#include "./iterator_traits.hpp"
#include "./reverse_iterator.hpp"
#include "./vector_iterator.hpp"

/*
 *		Reimplemantation of iterator base structure
 *		Ref: https://www.cplusplus.com/reference/iterator/iterator
 */
template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T *, class Reference = T &>
struct iterator {
  typedef T value_type;
  typedef Distance difference_type;
  typedef Pointer pointer;
  typedef Reference reference;
  typedef Category iterator_category;
};

#endif
