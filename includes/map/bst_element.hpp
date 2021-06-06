/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_element.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:23:57 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/06 20:03:56 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_ELEMENT_HPP
#define BST_ELEMENT_HPP
#include "./pair.hpp"
#include <iostream>
#include <memory>

namespace ft
{
template < typename key_type, typename mapped_type,
           typename Alloc = std::allocator< ft::pair< key_type, mapped_type > > >
class bst_element
{
  public:
    typedef bst_element< key_type, mapped_type > _self;
    typedef _self *pointer;
    typedef pointer const_pointer;
    typedef Alloc allocator_type;
    typedef ft::pair< key_type, mapped_type > _node_pair;
    typedef typename allocator_type::pointer pair_pointer;
    typedef typename allocator_type::reference pair_reference;
    typedef typename allocator_type::difference_type pair_difference_type;
    typedef typename allocator_type::size_type pair_size_type;

    /*********************************************************************************
     *                  Constructors
     ********************************************************************************/

    bst_element( allocator_type alloc = allocator_type() )
        : _pair( alloc.allocate( 1 ) ), _parent( NULL ), _right( NULL ), _left( NULL )
    {
        alloc.construct( _pair, _node_pair() );
    }

    bst_element( key_type key, mapped_type value, allocator_type alloc = allocator_type() )
        : _pair( alloc.allocate( 1 ) ), _parent( NULL ), _right( NULL ), _left( NULL )
    {
        alloc.construct( _pair, _node_pair( key, value ) );
    }

    bst_element( _node_pair pair, allocator_type alloc = allocator_type() )
        : _pair( alloc.allocate( 1 ) ), _parent( NULL ), _right( NULL ), _left( NULL )
    {
        alloc.construct( _pair, _node_pair( pair.first, pair.second ) );
    }

    bst_element( const _self &other, allocator_type alloc = allocator_type() )
        : _pair( alloc.allocate( 1 ) ), _parent( other._parent ), _right( other._right ), _left( other._left )
    {
        alloc.construct( _pair, _node_pair( other._pair->first, other._pair->second ) );
    }

    _self &operator=( const _self &other )
    {
        allocator_type alloc = allocator_type();
        alloc.destroy( _pair );
        alloc.construct( _pair, _node_pair( other._pair->first, other._pair->second ) );

        _parent = other._parent;
        _right = other._right;
        _left = other._left;
        return *this;
    }

    ~bst_element()
    {
        allocator_type alloc = allocator_type();
        alloc.destroy( _pair );
        alloc.deallocate( _pair, 1 );
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
        return *_pair;
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
        if ( child->getPair() < getPair() )
            setLeft( child );
        else if ( child->getPair() > getPair() )
            setRight( child );
    }

    void setPair( const _node_pair pair )
    {
        _pair->first = pair.first;
        _pair->second = pair.second;
    }

  private:
    pair_pointer _pair;
    pointer _parent;
    pointer _right;
    pointer _left;
};
} // namespace ft

#endif