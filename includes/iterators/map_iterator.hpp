/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 09:33:43 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/05 16:32:26 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP
#include "category.hpp"
#include "iterator_base.hpp"
#include "map/bst_element.hpp"
#include "map/pair.hpp"
#include <bits/types/struct_sched_param.h>

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

    map_iterator( node_type *current ) : base( current ), _left( false ), _right( false )
    {
    }

    map_iterator( const self &other ) : base( other ), _left( other._left ), _right( other._right )
    {
    }

    self &operator=( const self &other )
    {
        this->setCurrent( other._current );
        this->setNull( other._null );
        _left = other._left;
        _right = other._right;
        return *this;
    }

    ~map_iterator< key_type, mapped_type >( void )
    {
    }

    /**************************************************************************
     *				Operator overloading
     *************************************************************************/
    node_type *_next( node_type *current )
    {
        node_type *parent = current->parent();
        if ( !_left && !_right && current->left() && !current->left()->left() )
            return current->left();
        if ( _left && current->right() && !current->right()->right() )
            return current->right();
        if ( parent && ( ( !current->right() && !current->left() ) || _right || ( _left && !current->right() ) ) )
        {
            _left = parent->left() == current;
            _right = parent->right() == current;
            if ( _left )
                return parent;
            return _next( parent );
        }
        if ( _left && current->right() )
        {
            _left = false;
            _right = false;
            return _next( current->right() );
        }
        std::cout << parent << " left: " << _left << " -- right: " << _right << std::endl;
        return _next( current->left() );
    }

    self &operator++( void )
    {
        if ( this->getNode() )
            this->setCurrent( _next( this->getNode() ) );
        return *this;
    }

    reference operator*( void ) const
    {
        return this->getNode()->getPair();
    }

  private:
    bool _left, _right;
    map_iterator( void )
    {
    }
};

} // namespace ft

#endif