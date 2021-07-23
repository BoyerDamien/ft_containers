/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:07:21 by dboyer            #+#    #+#             */
/*   Updated: 2021/07/23 16:48:01 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include "./pair.hpp"
#include "./rbt_element.hpp"
#include "iterators/map_iterator.hpp"
#include "iterators/reverse_iterator.hpp"
#include <functional>
#include <memory>
namespace ft
{

template < typename key, typename T, typename Compare = std::less< key >,
           typename Alloc = std::allocator< ft::pair< const key, T > > >
class map
{
  public:
    typedef key key_type;

    typedef T mapped_type;

    typedef ft::pair< const key_type, mapped_type > value_type;

    typedef Compare key_compare;

    typedef Alloc allocator_type;

    typedef typename allocator_type::reference reference;

    typedef typename allocator_type::const_reference const_reference;

    typedef typename allocator_type::pointer pointer;

    typedef typename allocator_type::const_pointer const_pointer;

    typedef ft::rbt_element< const key_type, mapped_type, key_compare, allocator_type >
        node_type;

    typedef map_iterator< node_type > iterator;

    typedef map_iterator< const node_type > const_iterator;

    typedef reverse_iterator< const_iterator > const_reverse_iterator;

    typedef reverse_iterator< iterator > reverse_iterator;

    typedef typename allocator_type::difference_type difference_type;

    typedef typename allocator_type::size_type size_type;

    typedef typename Alloc::template rebind< node_type >::other node_allocator_type;

    /******************************************************************************
     *                  Nested Class
     *****************************************************************************/
    // See https://www.cplusplus.com/reference/map/map/value_comp/
    class value_compare
    {
        friend class map;

      protected:
        Compare comp;
        value_compare( Compare c ) : comp( c )
        {
        }

      public:
        typedef bool result_type;
        typedef value_type first_argument_type;
        typedef value_type second_argument_type;
        bool operator()( const value_type &x, const value_type &y ) const
        {
            return comp( x.first, y.first );
        }
    };

    /*****************************************************************************
     *                  Constructor
     ****************************************************************************/
    map( const Compare &comp = key_compare(), allocator_type alloc = allocator_type() )
        : _first( NULL ), _last( _first ), _root( new node_type( alloc ) ), _n( 0 )
    {
        (void)comp;
    }

    /*map( iterator first, iterator last, const key_compare &comp = key_compare(),
         allocator_type alloc = allocator_type() )
        : _first( node_type() ), _last( node_type() )
    {
    }*/

    ~map( void )
    {
        delete _root;
    }

    /************************************************************************************
     *          Iterators
     ***********************************************************************************/
    iterator begin( void )
    {
        return iterator( _first );
    }

    const_iterator begin( void ) const
    {
        return const_iterator( _first );
    }

    iterator end( void )
    {
        return iterator( _last );
    }

    const_iterator end( void ) const
    {
        return const_iterator( _last );
    }

    reverse_iterator rbegin( void )
    {
        return reverse_iterator( _last );
    }

    const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator( _last );
    }

    /************************************************************************************
     *          Capacity
     ***********************************************************************************/

    bool empty() const
    {
        return _n == 0;
    }

    size_type size() const
    {
        return _n;
    }

    size_type max_size() const
    {
        return node_allocator_type().max_size();
    }

    /************************************************************************************
     *                      Observers
     ***********************************************************************************/
    key_compare key_comp() const
    {
        return key_compare();
    }

    value_compare value_comp() const
    {
        return value_compare();
    }

    /************************************************************************************
     *                      Modifiers
     ***********************************************************************************/

    iterator _findLeaf( const key_type &k, node_type *node ) const
    {
        if ( node && node != _last )
        {
            value_type val = node->getPair();
            bool result_right = key_comp()( val.first, k );
            bool result_left = key_comp()( k, val.first );

            if ( !( !result_left && !result_right ) )
            {
                if ( result_left && node->left() && node->left() != _last )
                    return _findLeaf( k, node->left() );
                if ( result_right && node->right() && node->right() != _last )
                    return _findLeaf( k, node->right() );
            }
        }
        return iterator( node );
    }

    void _lineRotate( node_type *child )
    {
        node_type *parent = child->parent();
        node_type *grandGrandParent = NULL;

        if ( child->grandParent() )
            grandGrandParent = child->grandParent()->parent();

        parent->setChild( child->grandParent() );
        parent->setChild( child );

        if ( grandGrandParent )
            grandGrandParent->setChild( parent );

        if ( parent->left() )
            parent->left()->setColor( false );
        if ( parent->right() )
            parent->right()->setColor( false );
        parent->setColor( true );
    }

    void _rotate( node_type *child )
    {
        if ( child && child->parent() && child->grandParent() )
        {
            if ( child->parent()->left() == child &&
                 child->grandParent()->left() == child->parent() )
                _lineRotate( child );
            else if ( child->parent()->left() == child &&
                      child->grandParent()->right() == child->parent() )
                _lineRotate( child );
            else if ( child->parent()->right() == child &&
                      child->grandParent()->right() == child->parent() )
                _lineRotate( child );
            else if ( child->parent()->right() == child &&
                      child->grandParent()->left() == child->parent() )
                _lineRotate( child );
        }
    }
    pair< iterator, bool > insert( const value_type &val )
    {
        if ( !_first )
        {
            _last = _root;
            _last->setColor( true );
            node_type *n = new node_type( val.first, val.second );
            n->setColor( true );
            n->setRight( _last );
            _root = n;
            _first = n;
            _n++;
            return ft::pair< iterator, bool >( iterator( _root ), true );
        }

        if ( !count( val.first ) )
        {
            iterator r = _findLeaf( val.first, _root );

            node_type *child = new node_type( val.first, val.second );
            node_type *parent = r.getNode();
            parent->setChild( child );

            std::cout << "Parent = " << parent->getPair() << std::endl;
            if ( child->parent() && !child->parent()->black() )
            {
                if ( child->uncle() && !child->uncle()->black() )
                {
                    std::cout << "Parent red && uncle red" << std::endl;
                }
                else if ( ( child->uncle() && child->uncle()->black() ) ||
                          ( !child->uncle() ) )
                {
                    std::cout << "Parent red && uncle black" << std::endl;
                    _rotate( child );
                }
            }
            if ( child->parent() && child->parent()->black() )
            {
                std::cout << "Parent black" << std::endl;
            }
            if ( _root->parent() )
            {
                std::cout << "root parent = " << _root->parent() << std::endl;
                //_root = _root->parent();
            }
        }

        return ft::pair< iterator, bool >( iterator( _root ), false );
    }

    /************************************************************************************
     *                      Operations
     ***********************************************************************************/
    iterator _find( const key_type &k, node_type *node ) const
    {
        if ( node && node != _last )
        {
            value_type val = node->getPair();
            bool result_right = key_comp()( val.first, k );
            bool result_left = key_comp()( k, val.first );

            if ( !( !result_left && !result_right ) )
            {
                if ( result_left && node->left() && node->left() != _last )
                    return _find( k, node->left() );
                if ( result_right && node->right() && node->right() != _last )
                    return _find( k, node->right() );
            }
        }
        return iterator( _last );
    }

    iterator find( const key_type &k )
    {
        return _find( k, _root );
    }

    const_iterator find( const key_type &k ) const
    {
        return const_iterator( _find( k, _root ).getNode() );
    }

    size_type count( const key_type &k ) const
    {
        return find( k ) != end();
    }

    iterator _lower( const key_type &k, node_type *node )
    {
        if ( node && node != _last && node->left() )
        {
            value_type val = node->getPair();
            if ( key_comp()( k, val.first ) && node->left() )
                return _lower( k, node->left() );
        }
        return iterator( node );
    }

    iterator lower_bound( const key_type &k )
    {
        return _lower( k, _root );
    }

    const_iterator lower_bound( const key_type &k ) const
    {
        return const_iterator( lower_bound( k ).getNode() );
    }

    iterator _upper( const key_type &k, node_type *node )
    {
        if ( node && node != _last && node->right() )
        {
            value_type val = node->getPair();
            if ( key_comp()( val.first, k ) && node->right() )
                return _upper( k, node->right() );
        }
        return iterator( node );
    }

    iterator upper_bound( const key_type &k )
    {
        return _upper( k, _root );
    }

    const_iterator upper_bound( const key_type &k ) const
    {
        return const_iterator( upper_bound( k ).getNode() );
    }

    ft::pair< iterator, iterator > equal_range( const key_type &k )
    {
        return ft::pair< iterator, iterator >( lower_bound( k ), upper_bound( k ) );
    }

    ft::pair< const_iterator, const_iterator > equal_range( const key_type &k ) const
    {
        return ft::pair< const_iterator, const_iterator >( lower_bound( k ),
                                                           upper_bound( k ) );
    }

  private:
    node_type *_first, *_last, *_root;
    size_type _n;
};

} // namespace ft

#endif
