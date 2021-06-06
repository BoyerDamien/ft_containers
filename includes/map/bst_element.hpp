/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_element.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:23:57 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/05 16:52:03 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_ELEMENT_HPP
#define BST_ELEMENT_HPP
#include "./pair.hpp"
#include <iostream>

namespace ft
{
template < typename key_type, typename mapped_type > class bst_element
{
  public:
    typedef bst_element< key_type, mapped_type > _self;
    typedef ft::pair< key_type, mapped_type > _node_pair;
    typedef _self *pointer;
    typedef const pointer const_pointer;

    /*********************************************************************************
     *                  Constructors
     ********************************************************************************/

    bst_element() : _pair( _node_pair( key_type(), mapped_type() ) ), _parent( NULL ), _right( NULL ), _left( NULL )
    {
    }

    bst_element( key_type key, mapped_type value )
        : _pair( _node_pair( key, value ) ), _parent( NULL ), _right( NULL ), _left( NULL )
    {
    }

    bst_element( _node_pair pair ) : _pair( pair ), _parent( NULL ), _right( NULL ), _left( NULL )
    {
    }

    bst_element( const _self &other )
        : _pair( other.pair ), _parent( other.parent ), _right( other.right ), _left( other.left )
    {
    }

    _self &operator=( const _self &other )
    {
        _pair = other.pair;
        _parent = other.parent;
        _right = other.right;
        _left = other.left;
        return *this;
    }

    ~bst_element()
    {
    }
    /*********************************************************************************
     *                  Getters
     ********************************************************************************/
    pointer right( void ) const
    {
        return _right;
    }

    pointer left( void ) const
    {
        return _left;
    }

    pointer parent( void ) const
    {
        return _parent;
    }
    _node_pair &getPair( void )
    {
        return _pair;
    }
    /*********************************************************************************
     *                  Setters
     ********************************************************************************/

    void setParent( const_pointer parent )
    {
        _parent = parent;
    }

    void setRight( const_pointer right )
    {
        if ( _right )
            _right->setParent( right );
        right->setParent( this );
        _right = right;
    }

    void setLeft( const_pointer left )
    {
        if ( _left )
            _left->setParent( left );
        left->setParent( this );
        _left = left;
    }

    void setChild( const_pointer child )
    {
        if ( child->getPair() < _pair )
            setLeft( child );
        else if ( child->getPair() > _pair )
            setRight( child );
    }

    void setPair( const _node_pair &pair )
    {
        _pair = pair;
    }

  private:
    _node_pair _pair;
    pointer _parent;
    pointer _right;
    pointer _left;
};
} // namespace ft

#endif