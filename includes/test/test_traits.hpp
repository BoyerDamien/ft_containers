/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:20:31 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/10 18:42:19 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterators/iterator_traits.hpp"
#include "test_utils.hpp"
#include <iostream>
#include <iterator>

typedef random_access_iterator_tag iterator_category;
typedef T value_type;
typedef ptrdiff_t difference_type;
typedef T* pointer;
typedef T& reference;

template<typename test_type, typename ref_type>
void
test_iterator_traits()
{
  iterator_traits<test_type>::difference_type test_difference;
  std::iterator_traits<test_type> ref;

  unittest::check_type_traits<iterator_traits<test_type>::difference_type,
                              std::iterator_traits<test_type>::difference_type>
    test;
}