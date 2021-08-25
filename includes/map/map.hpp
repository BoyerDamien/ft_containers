/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:07:21 by dboyer            #+#    #+#             */
/*   Updated: 2021/08/16 15:08:54 by dboyer           ###   ########.fr       */
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
        : _root( NULL ), _last( new node_type() ), _n( 0 )
    {
        (void)comp;
        (void)alloc;
    }

    map( iterator first, iterator last, const key_compare &comp = key_compare(),
         allocator_type alloc = allocator_type() )
        : _root( node_type() ), _last( node_type() ), _n( 0 )
    {
        for ( iterator it = first; it != last; it++ )
            insert( *it );
        (void)comp;
        (void)alloc;
    }

    map( const map &other ) : _root( other._root ), _last( other._last ), _n( other._n )
    {
    }

    map &operator=( const map &other )
    {
        _root = other._root;
        _n = other._n;
        _last = other._last;
        return *this;
    }

    ~map( void )
    {
        while ( _n > 0 )
        {
            std::cout << std::endl << "Before erase n = " << _n << std::endl;

            if ( _root )
                std::cout << "Root = " << _root << " " << _root->getPair() << std::endl;
            else
                std::cout << "No root shit!! " << std::endl;
            erase( begin() );
        }
        std::cout << "Finished" << std::endl;
        /* delete _last; */
    }

    /************************************************************************************
     *          Iterators
     ***********************************************************************************/

    iterator begin( void )
    {
        return iterator( _first( _root ) );
    }

    const_iterator begin( void ) const
    {
        return const_iterator( _first( _root ) );
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
        return reverse_iterator( _bLast( _root ) );
    }

    const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator( _bLast( _root ) );
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

    pair< iterator, bool > insert( const value_type &val )
    {
        if ( !_root )
        {
            node_type *n = new node_type( val.first, val.second );
            n->setParent( _last );
            _last->setLeftSafe( n );
            _last->setRightSafe( n );
            _root = n;
            _n++;
            return ft::pair< iterator, bool >( iterator( _root ), true );
        }
        if ( !count( val.first ) )
        {
            iterator r = _findLeaf( val.first, _root );

            node_type *child = new node_type( val.first, val.second );
            node_type *parent = r.getNode();
            parent->setChild( child );
            _n++;
            return ft::pair< iterator, bool >( iterator( _root ), true );
        }
        return ft::pair< iterator, bool >( iterator( _root ), false );
    }

    void erase( iterator position )
    {
        node_type *n = position.getNode();
        if ( n )
        {
            std::cout << n->getPair() << std::endl;
            if ( !n->left() && !n->right() )
            {
                std::cout << "No children" << std::endl;
                if ( n->parent() && n->parent()->left() == n )
                    n->parent()->setLeftSafe( NULL );
                if ( n->parent() && n->parent()->right() == n )
                    n->parent()->setRightSafe( NULL );
                delete n;
            }
            else if ( n->left() && !n->right() && n->parent() )
            {
                std::cout << "Child left" << std::endl;
                n->setPair( n->left()->getPair() );
                delete n->left();
                n->setLeftSafe( NULL );
            }
            else if ( !n->left() && n->right() && n->parent() )
            {
                std::cout << "Child right" << std::endl;
                n->setPair( n->right()->getPair() );
                delete n->right();
                n->setRightSafe( NULL );
            }
            else if ( n->left() && n->right() )
            {
                std::cout << "Double children" << std::endl;
                node_type *prev = ( --position ).getNode();
                if ( prev )
                {
                    n->setPair( prev->getPair() );
                    if ( prev->parent() && prev->parent()->left() == prev )
                        prev->parent()->setLeftSafe( NULL );
                    else if ( prev->parent() && prev->parent()->right() == prev )
                        prev->parent()->setRightSafe( NULL );
                    delete prev;
                }
            }
            _n--;
        }
    }
    /************************************************************************************
     *                      Operations
     ***********************************************************************************/

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

    iterator lower_bound( const key_type &k )
    {
        return _lower( k, _root );
    }

    const_iterator lower_bound( const key_type &k ) const
    {
        return const_iterator( lower_bound( k ).getNode() );
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

    /************************************************************************************
     *				Private attributes
     ***********************************************************************************/
  private:
    node_type *_root, *_last;
    size_type _n;

    /************************************************************************************
     *				Private member functions
     ***********************************************************************************/
    node_type *_first( node_type *node )
    {
        if ( node && node->left() )
            return _first( node->left() );
        return node;
    }

    node_type *_bLast( node_type *node )
    {
        if ( node && node->right() )
            return _bLast( node->right() );
        return node;
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
};

} // namespace ft

#endif
