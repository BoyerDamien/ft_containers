/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:58:24 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/14 18:02:44 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator_traits.hpp"
#include "type_traits.hpp"
#include <cstddef>
#include <iostream>

namespace ft
{
template < typename T, typename node_type, typename iterator_tag > class iterator
{
  public:
    typedef T value_type;
    typedef value_type *pointer;
    typedef value_type &reference;
    typedef std::ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef iterator_tag iterator_category;

    /****************************************************************************
     *              Constructor
     ***************************************************************************/
    iterator(node_type current) : _base(current)
    {
        if (!current)
            _base = node_type(value_type());
    }

    iterator(const iterator &other) : _base(other._base)
    {
    }

    ~iterator(void)
    {
    }

    iterator &operator=(const iterator &other)
    {
        _base = other._base;
        return *this;
    }

    /**************************************************************************
     *				Operator overloading
     *************************************************************************/

    typename ft::enable_if< is_input_iterator< iterator_category >::value, iterator >::type &operator++(void)
    {
        _base++;
        return *this;
    }

    typename enable_if< is_input_iterator< iterator_category >::value, iterator >::type operator++(int)
    {
        iterator temp = *this;
        _base++;
        return temp;
    }

    typename enable_if< is_type_equal< iterator_category, bidirectional_iterator_tag >::value, iterator >::type &
    operator--(void)
    {
        _base--;
        return *this;
    }

    typename enable_if< is_type_equal< iterator_category, bidirectional_iterator_tag >::value, iterator >::type
    operator--(int)
    {
        iterator temp = *this;
        _base--;
        return temp;
    }

    typename enable_if< is_type_equal< iterator_category, random_access_iterator_tag >::value, iterator >::type &
    operator+=(int n)
    {
        _base + n;
        return *this;
    }

    typename enable_if< is_type_equal< iterator_category, random_access_iterator_tag >::value, iterator >::type &
    operator-=(int n)
    {
        _base - n;
        return *this;
    }

    reference &operator*(void) const
    {
        return *_base;
    }

    reference &operator[](size_type n) const
    {
        return _base[n];
    }

    bool operator<(const iterator &other) const
    {
        return *operator*() < *other;
    }
    bool operator<=(const iterator &other) const
    {
        return operator*() <= *other;
    }

    bool operator>(const iterator &other) const
    {
        return operator*() > *other;
    }

    bool operator>=(const iterator &other) const
    {
        return operator*() >= *other;
    }

    difference_type operator-(const iterator &other) const
    {
        return _base - other._base;
    }

    iterator operator+(size_type n)
    {
        return iterator(_base + n);
    }

    iterator operator-(size_type n)
    {
        return iterator(_base - n);
    }

    /**************************************************************************
     *				Getters
     *************************************************************************/
    node_type base(void) const
    {
        return _base;
    }

  protected:
    node_type _base;

    iterator(void)
    {
    } // Private default constructor
};

template < typename It > bool operator==(const It &it1, const It &it2)
{
    return it1.getNode() == it2.getNode();
}

template < typename It > bool operator!=(const It &it1, const It &it2)
{
    return !(it1 == it2);
}

template < typename It > It operator+(size_t n, It &it)
{
    return it += n;
}

template < typename It > It operator-(size_t n, It &it)
{
    return it -= n;
}
} // namespace ft
