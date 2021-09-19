/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:53:18 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/19 10:39:50 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterator_traits.hpp"

namespace ft
{

/*
 *		Reimplementation of reverse_iterator
 *		Ref: https://www.cplusplus.com/reference/iterator/reverse_iterator/
 */
template < class Iterator > class reverse_iterator
{
  public:
    /*
     *			Member types
     */
    typedef Iterator iterator_type;
    typedef typename iterator_traits< Iterator >::iterator_category iterator_category;
    typedef typename iterator_traits< Iterator >::value_type value_type;
    typedef typename iterator_traits< Iterator >::difference_type difference_type;
    typedef typename iterator_traits< Iterator >::pointer pointer;
    typedef typename iterator_traits< Iterator >::reference reference;

    /*
     *			Constructors
     */
    reverse_iterator(void)
    {
    }
    reverse_iterator(iterator_type it) : _base(it)
    {
    }
    reverse_iterator(const reverse_iterator< iterator_type > &rev_it) : _base(rev_it._base)
    {
    }
    reverse_iterator &operator=(const reverse_iterator< Iterator > &rev_it)
    {
        _base = rev_it;
        return *this;
    }
    ~reverse_iterator(void)
    {
    }

    /*
     *			Member functions
     */
    iterator_type base(void) const
    {
        return this->_base;
    }
    reference &operator*(void) const
    {
        return *this->_base;
    }
    reverse_iterator< iterator_type > &operator+(difference_type n) const
    {
        return reverse_iterator< iterator_type >(this->_base - n);
    }

    reverse_iterator< iterator_type > operator++(int)
    {
        reverse_iterator< iterator_type > temp = *this;
        _base = --_base;
        return temp;
    }
    reverse_iterator< iterator_type > &operator++(void)
    {
        _base = --_base;
        return *this;
    }
    reverse_iterator< iterator_type > &operator+=(difference_type n)
    {
        return reverse_iterator< iterator_type >(_base - n);
    }

    reverse_iterator< iterator_type > &operator-(difference_type n) const
    {
        return reverse_iterator< iterator_type >(_base + n);
    }
    reverse_iterator< iterator_type > operator--(int)
    {
        reverse_iterator< iterator_type > temp = *this;
        _base = ++_base;
        return temp;
    }
    reverse_iterator< iterator_type > &operator--(void)
    {
        _base = ++_base;
        return *this;
    }
    reverse_iterator< iterator_type > &operator-=(difference_type n) const
    {
        return reverse_iterator< iterator_type >(_base + n);
    }

    pointer operator->(void) const
    {
        return &(operator*());
    }

    reference operator[](difference_type n) const
    {
        return _base[-n - 1];
    }

    bool operator==(const reverse_iterator &other) const
    {
        return _base == other._base;
    }

  private:
    iterator_type _base;
};

template < class iter1, class iter2 >
bool operator==(const reverse_iterator< iter1 > &x, const reverse_iterator< iter2 > &y)
{
    return x.base() == y.base();
}

template < class iter1, class iter2 >
bool operator<(const reverse_iterator< iter1 > &x, const reverse_iterator< iter2 > &y)
{
    return x.base() > y.base();
}

template < class iter1, class iter2 >
bool operator!=(const reverse_iterator< iter1 > &x, const reverse_iterator< iter2 > &y)
{
    return x.base() != y.base();
}

template < class iter1, class iter2 >
bool operator>(const reverse_iterator< iter1 > &x, const reverse_iterator< iter2 > &y)
{
    return x.base() < y.base();
}

template < class iter1, class iter2 >
bool operator>=(const reverse_iterator< iter1 > &x, const reverse_iterator< iter2 > &y)
{
    return x.base() <= y.base();
}

template < class iter1, class iter2 >
bool operator<=(const reverse_iterator< iter1 > &x, const reverse_iterator< iter2 > &y)
{
    return x.base() >= y.base();
}

template < class iter1, class iter2 >
typename reverse_iterator< iter1 >::difference_type operator-(const reverse_iterator< iter1 > &x,
                                                              const reverse_iterator< iter2 > &y)
{
    return y.base() - x.base();
}

template < class iter >
reverse_iterator< iter > operator+(typename reverse_iterator< iter >::difference_type n,
                                   const reverse_iterator< iter > &x)
{
    return reverse_iterator< iter >(x.base() - n);
}
} // namespace ft
