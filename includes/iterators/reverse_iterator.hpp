/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:53:18 by dboyer            #+#    #+#             */
/*   Updated: 2021/04/23 18:51:49 by dess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP
#include "iterator_traits.hpp"

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
    typedef reverse_iterator< iterator_type > _Self;
    typedef typename iterator_traits< Iterator >::iterator_category iterator_category;
    typedef typename iterator_traits< Iterator >::value_type value_type;
    typedef typename iterator_traits< Iterator >::difference_type difference_type;
    typedef typename iterator_traits< Iterator >::pointer pointer;
    typedef typename iterator_traits< Iterator >::reference reference;

    /*
     *			Constructors
     */
    reverse_iterator( void )
    {
    }
    reverse_iterator( iterator_type it ) : _base( it )
    {
    }
    reverse_iterator( const reverse_iterator< iterator_type > &rev_it )
        : _base( rev_it._base )
    {
    }
    reverse_iterator &operator=( const reverse_iterator< Iterator > &rev_it )
    {
        this->_base = rev_it;
        return *this;
    }
    ~reverse_iterator( void )
    {
    }

    /*
     *			Member functions
     */
    iterator_type base( void ) const
    {
        return this->_base;
    }
    reference &operator*( void ) const
    {
        return *this->_base;
    }
    reverse_iterator< iterator_type > &operator+( difference_type n ) const
    {
        return reverse_iterator< iterator_type >( this->_base - n );
    }

    reverse_iterator< iterator_type > operator++( int )
    {
        reverse_iterator< iterator_type > temp = *this;
        --this->_base;
        return temp;
    }
    reverse_iterator< iterator_type > &operator++( void )
    {
        --this->_base;
        return *this;
    }
    reverse_iterator< iterator_type > &operator+=( difference_type n )
    {
        return reverse_iterator< iterator_type >( this->_base - n );
    }

    reverse_iterator< iterator_type > &operator-( difference_type n ) const
    {
        return reverse_iterator< iterator_type >( this->_base + n );
    }
    reverse_iterator< iterator_type > operator--( int )
    {
        reverse_iterator< iterator_type > temp = *this;
        ++this->_base;
        return temp;
    }
    reverse_iterator< iterator_type > &operator--( void )
    {
        ++this->_base;
        return *this;
    }
    reverse_iterator< iterator_type > &operator-=( difference_type n ) const
    {
        return reverse_iterator< iterator_type >( this->_base + n );
    }

    pointer operator->( void ) const
    {
        return &( operator*() );
    }

    reference operator[]( difference_type n ) const
    {
        return this->_base[ -n - 1 ];
    }

    bool operator==( const _Self &other ) const
    {
        return _base == other._base;
    }

  private:
    iterator_type _base;
};

template < typename T >
bool operator!=( const reverse_iterator< T > &it1, const reverse_iterator< T > &it2 )
{
    return !( it1 == it2 );
}

#endif
