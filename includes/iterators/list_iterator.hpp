/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_iterator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:22:23 by dess              #+#    #+#             */
/*   Updated: 2021/06/06 18:16:03 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef list_ITERATOR_HPP
#define list_ITERATOR_HPP
#include "category.hpp"
#include "iterator_base.hpp"

namespace ft
{
template < typename T, typename N > class list_iterator : public ft::iterator_base< T, N >
{

  public:
    typedef T value_type;
    typedef N node_type;
    typedef list_iterator< value_type, node_type > self;
    typedef ft::iterator_base< value_type, node_type > base;
    typedef typename base::pointer pointer;
    typedef typename base::reference reference;
    typedef typename base::difference_type difference_type;
    typedef typename base::size_type size_type;
    typedef bidirectional_iterator_tag iterator_category;

    list_iterator( node_type *current ) : base( current )
    {
    }

    list_iterator( const self &other ) : base( other )
    {
    }

    self &operator=( const self &other )
    {
        this->setCurrent( other._current );
        this->setNull( other._null );
        return *this;
    }

    virtual ~list_iterator< T, N >( void )
    {
    }

    /**************************************************************************
     *				Operator overloading
     *************************************************************************/

    self &operator++( void )
    {
        this->setCurrent( this->getNode()->next() );
        return *this;
    }

    self operator++( int )
    {
        self temp = *this;
        this->setCurrent( this->getNode()->next() );
        return temp;
    }

    self &operator--( void )
    {
        this->setCurrent( this->getNode()->previous() );
        return *this;
    }

    self operator--( int )
    {
        self temp = *this;
        this->setCurrent( this->getNode()->previous() );
        return temp;
    }

    reference operator*( void ) const
    {
        return this->getNode()->getContent();
    }

  private:
    list_iterator< T, N >( void )
    {
    }
};
} // namespace ft
#endif
