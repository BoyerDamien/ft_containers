/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:03:13 by dess              #+#    #+#             */
/*   Updated: 2021/05/30 15:23:41 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vector_ITERATOR_HPP
#define vector_ITERATOR_HPP
#include "category.hpp"
#include "iterator_base.hpp"
#include <cstddef>

namespace ft
{
template < typename T > class vector_iterator : public ft::iterator_base< T, T >
{

  public:
    typedef T value_type;
    typedef value_type *node_type;
    typedef vector_iterator< value_type > self;
    typedef ft::iterator_base< value_type, value_type > base;
    typedef typename base::pointer pointer;
    typedef typename base::reference reference;
    typedef typename base::difference_type difference_type;
    typedef typename base::size_type size_type;
    typedef input_iterator_tag iterator_category;

    vector_iterator< value_type >( node_type current ) : base( current )
    {
    }

    vector_iterator< value_type >( const self &other ) : base( other )
    {
    }

    self &operator=( const self &other )
    {
        this->setCurrent( other._current );
        this->setNull( other._null );
        return *this;
    }

    ~vector_iterator< value_type >( void )
    {
    }

    /**************************************************************************
     *				Operator overloading
     *************************************************************************/

    self &operator++( void )
    {
        this->setCurrent( this->getNode() + 1 );
        return *this;
    }

    self operator++( int )
    {
        self temp = *this;
        this->setCurrent( this->getNode() + 1 );
        return temp;
    }

    self &operator--( void )
    {
        this->setCurrent( this->getNode() - 1 );
        return *this;
    }

    self operator--( int )
    {
        self temp = *this;
        this->setCurrent( this->getNode() - 1 );
        return temp;
    }

    self &operator+=( int n )
    {
        this->setCurrent( this->getNode() + n );
        return *this;
    }

    self &operator-=( int n )
    {
        this->setCurrent( this->getNode() + n );
        return *this;
    }

    reference &operator*( void ) const
    {
        return *this->getNode();
    }

    reference &operator[]( size_type n ) const
    {
        return this->getNode()[ n ];
    }

    bool operator<( const self &other ) const
    {
        return *operator*() < *other;
    }
    bool operator<=( const self &other ) const
    {
        return operator*() <= *other;
    }

    bool operator>( const self &other ) const
    {
        return operator*() > *other;
    }
    bool operator>=( const self &other ) const
    {
        return operator*() >= *other;
    }
    difference_type operator-( const self &other ) const
    {
        return this->getNode() - other.getNode();
    }
    self operator+( size_type n )
    {
        return self( this->getNode() + n );
    }
    self operator-( size_type n )
    {
        return self( this->getConstNode() - n );
    }

  private:
    vector_iterator< T >( void )
    {
    }
};

template < typename T >
vector_iterator< T > operator+( size_t n, vector_iterator< T > &it )
{
    return it += n;
}

template < typename T >
vector_iterator< T > operator-( size_t n, vector_iterator< T > &it )
{
    return it -= n;
}
} // namespace ft

#endif
