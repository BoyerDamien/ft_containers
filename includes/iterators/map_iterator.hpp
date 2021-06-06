/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 09:33:43 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/06 18:13:13 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include "category.hpp"
#include "iterator_base.hpp"
#include "map/bst_element.hpp"
#include "map/pair.hpp"

namespace ft
{

template < typename key_type, typename mapped_type >
class map_iterator
    : public ft::iterator_base< ft::pair< key_type, mapped_type >, ft::bst_element< key_type, mapped_type > >
{
  public:
    typedef ft::pair< key_type, mapped_type > value_type;
    typedef ft::bst_element< key_type, mapped_type > node_type;
    typedef map_iterator< key_type, mapped_type > self;
    typedef ft::iterator_base< value_type, node_type > base;
    typedef typename base::pointer pointer;
    typedef typename base::reference reference;
    typedef typename base::difference_type difference_type;
    typedef typename base::size_type size_type;
    typedef bidirectional_iterator_tag iterator_category;

    map_iterator( node_type *current ) : base( current )
    {
    }

    map_iterator( const self &other ) : base( other )
    {
    }

    self &operator=( const self &other )
    {
        this->setCurrent( other._current );
        this->setNull( other._null );
        return *this;
    }

    ~map_iterator< key_type, mapped_type >( void )
    {
    }

    /**************************************************************************
     *				Operator overloading
     *************************************************************************/
    node_type *_next( node_type *current, bool down = false, bool up = false, bool left = false, bool right = false )
    {
        node_type *parent = current->parent();
        if ( up && ( left || ( right && !parent ) ) )
            return current;
        if ( down && !current->left() )
            return current;
        if ( down && current->left() )
            return _next( current->left(), true, false, true, false );
        if ( parent && ( ( up && right ) || ( !current->left() && !current->right() ) ) )
            return _next( parent, false, true, parent->left() == current, parent->right() == current );
        if ( current->right() )
            return _next( current->right(), true, false, false, true );
        return current;
    }
    node_type *_previous( node_type *current, bool down = false, bool up = false, bool left = false,
                          bool right = false )
    {
        node_type *parent = current->parent();
        if ( up && ( right || ( left && !parent ) ) )
            return current;
        if ( down && !current->right() )
            return current;
        if ( down && current->right() )
            return _previous( current->right(), true, false, false, true );
        if ( ( left || !current->left() ) && up && parent )
            return _previous( parent, false, true, parent->left() == current, parent->right() == current );
        if ( ( ( !current->left() && !current->right() ) || !current->left() ) && parent )
            return _previous( parent, false, true, parent->left() == current, parent->right() == current );
        if ( current->left() )
            return _previous( current->left(), true, false, true, false );
        return current;
    }

    self &operator++( void )
    {
        if ( this->getNode() )
            this->setCurrent( _next( this->getNode() ) );
        return *this;
    }

    self operator++( int )
    {
        self tmp = *this;
        if ( this->getNode() )
            this->setCurrent( _next( this->getNode() ) );
        return tmp;
    }
    self &operator--( void )
    {
        if ( this->getNode() )
            this->setCurrent( _previous( this->getNode() ) );
        return *this;
    }

    self operator--( int )
    {
        self tmp = *this;
        if ( this->getNode() )
            this->setCurrent( _previous( this->getNode() ) );
        return tmp;
    }

    reference operator*( void ) const
    {
        return this->getNode()->getPair();
    }

  private:
    map_iterator( void )
    {
    }
};

} // namespace ft

#endif