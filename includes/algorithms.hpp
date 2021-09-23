/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:59:07 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/21 16:29:05 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterator_traits.hpp"
#include <iostream>

namespace ft
{
template < typename T > void swap(T &v1, T &v2)
{
    T tmp = v1;

    v1 = v2;
    v2 = tmp;
}

template < class InputIt1, class InputIt2 >
bool lexicographical_compare(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
{
    for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
    {
        if (*first1 < *first2)
            return true;
        if (*first2 < *first1)
            return false;
    }
    return (first1 == last1) && (first2 != last2);
}

template < class InputIt1, class InputIt2 > bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2, InputIt2 last2)
{
    while (first1 != last1 && first2 != last2)
    {if (*first1 != *first2)
            return false;
        first1++;
        first2++;
    }
    return (first1 == last1) && (first2 == last2);
}

} // namespace ft
