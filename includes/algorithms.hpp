/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 17:59:07 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/18 15:38:20 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP
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

template < typename value_type > bool defaultSortComp(value_type curr, value_type pivot)
{
    return curr <= pivot;
}

template < typename iterator, typename Compare > iterator partition(iterator &begin, iterator &last, Compare comp)
{
    iterator i = begin;
    iterator j = begin;

    if (begin == last)
        return begin;
    while (j != last)
    {
        if (comp(*j, *last))
        {
            swap(*i, *j);
            i++;
        }
        j++;
    }
    swap(*i, *last);
    return i;
}

template < typename iterator, typename Compare > void QSort(iterator begin, iterator last, Compare comp)
{
    if (begin != last)
    {
        iterator p = partition(begin, last, comp);
        if (p != begin)
            QSort(begin, --p, comp);
        QSort(++p, last, comp);
    }
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
    for (; (first1 != last1) && (first2 != last2); ++first1, (void)++first2)
    {
        if (*first1 != *first2)
            return false;
    }
    return (first1 == last1) && (first2 != last2);
}

} // namespace ft

#endif
