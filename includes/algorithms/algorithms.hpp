/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:59:07 by dboyer            #+#    #+#             */
/*   Updated: 2021/05/26 10:59:24 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
#include <iostream>

namespace ft
{
template < typename T > void swap(T &v1, T &v2)
{
    T tmp = v1;

    v1 = v2;
    v2 = tmp;
}

template < typename Container, typename Func > void for_each(Container &container, Func f)
{
    for (typename Container::iterator begin = container.begin(); begin != container.end(); begin++)
        f(*begin);
}

template < typename Func, typename Iterator > void for_each(Iterator begin, Iterator end, Func f)
{
    while (begin != end)
        f(*begin++);
}

template < typename Iterator > void bubbleSort(Iterator begin, Iterator end)
{
    for (Iterator it = begin; it != end; it++)
    {
        for (Iterator sec = it; sec != end; sec++)
        {
            if (*sec < *it)
                swap(*it, *sec);
        }
    }
}

template < typename Iterator, typename Comp > void bubbleSort(Iterator begin, Iterator end, Comp comp)
{
    for (Iterator it = begin; it != end; it++)
    {
        for (Iterator sec = it; sec != end; sec++)
        {
            if (comp(*sec, *it))
                swap(*it, *sec);
        }
    }
}

} // namespace ft

#endif
