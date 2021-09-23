/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:03:13 by dess              #+#    #+#             */
/*   Updated: 2021/09/23 15:37:02 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iterator.hpp"
#include "iterator_traits.hpp"
#include <cstddef>

namespace ft
{
template < typename T > class vector_iterator
{
  protected:
    typedef iterator_traits< T > __traits;

  public:
    typedef typename __traits::value_type value_type;
    typedef typename __traits::difference_type difference_type;
    typedef typename __traits::pointer pointer;
    typedef typename __traits::reference reference;
    typedef typename __traits::iterator_category iterator_category;
    typedef pointer iterator_type;

    vector_iterator(void) : _base(pointer(value_type()))
    {
    }

    vector_iterator(pointer current) : _base(current)
    {
        if (current == NULL)
            _base = pointer();
    }

    vector_iterator(const vector_iterator &other) : _base(other._base)
    {
    }

    vector_iterator &operator=(const vector_iterator &other)
    {
        _base = other._base;
        return *this;
    }

    ~vector_iterator(void)
    {
    }
    /**************************************************************************
     *				Getters
     *************************************************************************/
    pointer base() const
    {
        return _base;
    }
    /**************************************************************************
     *				Operator overloading
     *************************************************************************/

    vector_iterator &operator++(void)
    {
        _base++;
        return *this;
    }

    vector_iterator operator++(int)
    {
        vector_iterator temp = *this;
        _base++;
        return temp;
    }

    vector_iterator &operator--(void)
    {
        _base--;
        return *this;
    }

    vector_iterator operator--(int)
    {
        vector_iterator temp = *this;
        _base--;
        return temp;
    }

    vector_iterator &operator+=(int n)
    {
        _base += n;
        return *this;
    }

    vector_iterator &operator-=(int n)
    {
        _base -= n;
        return *this;
    }

    reference &operator*(void) const
    {
        return *_base;
    }
    pointer operator->(void) const
    {
        return &(this->operator*());
    }

    reference &operator[](difference_type n) const
    {
        return _base[n];
    }

    bool operator<(const vector_iterator &other) const
    {
        return *operator*() < *other;
    }

    bool operator<=(const vector_iterator &other) const
    {
        return operator*() <= *other;
    }

    bool operator>(const vector_iterator &other) const
    {
        return operator*() > *other;
    }

    bool operator>=(const vector_iterator &other) const
    {
        return operator*() >= *other;
    }

    difference_type operator-(const vector_iterator &other) const
    {
        return _base - other._base;
    }

    vector_iterator operator+(difference_type n)
    {
        return vector_iterator(_base + n);
    }

    vector_iterator operator-(difference_type n)
    {
        return vector_iterator(_base - n);
    }

  private:
    pointer _base;
};

template < typename T > vector_iterator< T > operator+(size_t n, vector_iterator< T > &it)
{
    return it += n;
}

template < typename T > vector_iterator< T > operator-(size_t n, vector_iterator< T > &it)
{
    return it -= n;
}

template < typename T > bool operator==(const vector_iterator< T > &it1, const vector_iterator< T > &it2)
{
    return it1.base() == it2.base();
}

template < typename T > bool operator!=(const vector_iterator< T > &it1, const vector_iterator< T > &it2)
{
    return !(it1 == it2);
}

} // namespace ft
