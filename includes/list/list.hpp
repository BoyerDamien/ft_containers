/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 10:28:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/04 10:29:37 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
#define LIST_HPP
#include "../algorithms/algorithms.hpp"
#include "../iterators/iterator.hpp"
#include "list_element.hpp"
#include <cstddef>
#include <iostream>
#include <limits>
#include <ostream>
#include <string>

namespace ft
{
/*
 *		Reimplementation of list template
 *		Refs:
 *		-	https://www.cplusplus.com/reference/list/list/
 *		-	https://en.cppreference.com/w/cpp/container/list/list
 */
template < class T, class Alloc = std::allocator< T > > class list
{
  public:
    typedef T value_type;

    typedef Alloc allocator_type;

    typedef list_element< value_type, allocator_type > node_type;

    typedef list< value_type > self;

    typedef typename allocator_type::reference reference;

    typedef typename allocator_type::const_reference const_reference;

    typedef typename allocator_type::pointer pointer;

    typedef typename allocator_type::const_pointer const_pointer;

    typedef typename allocator_type::difference_type difference_type;

    typedef typename allocator_type::size_type size_type;

    typedef ft::list_iterator< value_type, node_type > iterator;

    typedef ft::list_iterator< const value_type, node_type > const_iterator;

    typedef reverse_iterator< const_iterator > const_reverse_iterator;

    typedef reverse_iterator< iterator > reverse_iterator;

    typedef typename Alloc::template rebind< node_type >::other node_allocator_type;

    /******************************************************************************
     *							Constructor
     *****************************************************************************/
    list( void ) : _begin( new node_type( value_type() ) ), _n( 0 )
    {
    }

    list( size_t n, const value_type &val = value_type() ) : _begin( new node_type( value_type() ) ), _n( 0 )
    {
        assign( n, val );
    }

    list( pointer first, pointer last ) : _begin( new node_type( value_type() ) ), _n( 0 )
    {
        for ( pointer begin = first; begin != last; begin++ )
            push_back( *begin );
    }

    list( iterator first, iterator last ) : _begin( new node_type( value_type() ) ), _n( 0 )
    {
        assign( first, last );
    }

    list( const list &x ) : _begin( new node_type( value_type() ) ), _n( 0 )
    {
        assign( x.begin(), x.end() );
    }

    list &operator=( const self &x )
    {
        assign( x.begin(), x.end() );
        x.clear();
        return *this;
    }

    ~list( void )
    {
        clear();
        delete _begin;
    }

    /******************************************************************************
     *								Member functions
     *****************************************************************************/
    iterator begin( void ) const
    {
        return iterator( _begin->next() );
    }
    iterator end( void ) const
    {
        return iterator( _begin );
    }

    void assign( iterator first, iterator last )
    {
        clear();
        while ( first != last )
            push_back( *first++ );
    }
    void assign( size_type n, const value_type &val )
    {
        clear();
        while ( _n < n )
            push_back( val );
    }

    reference back( void )
    {
        return _begin->previous()->getContent();
    }
    const_reference back( void ) const
    {
        return static_cast< const_reference >( _begin->previous()->getContent() );
    }
    reference front( void )
    {
        return _begin->next()->getContent();
    }
    const_reference front( void ) const
    {
        return static_cast< const_reference >( _begin->next()->getContent() );
    }

    void clear( void )
    {
        while ( _n )
            pop_back();
    }

    bool empty( void ) const
    {
        return _n == 0 && _begin->next() == _begin && _begin->previous() == _begin;
    }

    size_type size( void ) const
    {
        return _n;
    }

    void swap( list &other )
    {
        ft::swap( _begin, other._begin );
        ft::swap( _n, other._n );
    }

    iterator erase( iterator position )
    {
        node_type *to_delete = position.getNode();
        iterator ret = ++position;
        if ( _n && _begin != to_delete )
        {
            delete to_delete;
            _n--;
        }
        return ret;
    }

    iterator erase( iterator begin, iterator end )
    {
        if ( begin != end )
        {
            return erase( erase( begin++ ), end );
        }
        return begin;
    }

    iterator insert( iterator position, const value_type &val )
    {
        node_type *to_insert = new list_element< value_type >( val );
        node_type *node = position.getNode();
        node->previous()->setNext( to_insert );
        to_insert->setNext( node );
        _n++;
        return iterator( to_insert );
    }

    size_type max_size( void ) const
    {
        // std::cout << "test = " << std::allocator< node_type >().max_size() << std::endl;
        // std::cout << value_type().max_size() / (sizeof(value_type) - sizeof(difference_type)) << std::endl;
        // return std::numeric_limits< size_t >::max() / (2 * sizeof(self));
        return node_allocator_type().max_size();
    }

    void pop_back( void )
    {
        if ( _n > 0 )
        {
            delete _begin->previous();
            --_n;
        }
    }

    void pop_front( void )
    {
        if ( _n > 0 )
        {
            delete _begin->next();
            --_n;
        }
    }

    void push_back( const value_type &val )
    {
        insert( end(), val );
    }

    void push_front( const value_type &val )
    {
        insert( begin(), val );
    }

    reverse_iterator rbegin( void )
    {
        return reverse_iterator( --end() );
    }
    const_reverse_iterator rbegin( void ) const
    {
        return const_reverse_iterator( --end() );
    }

    reverse_iterator rend( void )
    {
        return reverse_iterator( --begin() );
    }
    const_reverse_iterator rend( void ) const
    {
        return const_reverse_iterator( --begin() );
    }

    void remove( const value_type &val )
    {
        _remove( val, begin() );
    }

    template < class Predicate > void remove_if( Predicate pred )
    {
        _remove_if( pred, begin() );
    }

    void resize( size_type n, value_type val = value_type() )
    {
        while ( n > _n )
            push_back( val );
        while ( n < _n )
            erase( --end() );
    }

    void reverse( void )
    {
        iterator begin = this->begin();
        iterator end = this->end();
        while ( begin != --end )
            ft::swap< value_type >( *begin++, *end );
    }

    void sort( void )
    {
        if ( _n > 1 )
            ft::QSort( begin(), --end(), ft::defaultSortComp< value_type > );
    }

    template < class Compare > void sort( Compare comp )
    {
        if ( _n > 1 )
            ft::QSort( begin(), --end(), comp );
    }

    void splice( iterator position, list &x )
    {
        if ( x.size() )
        {
            node_type *pos_node = position.getNode();
            node_type *to_insert = x.begin().getNode();
            node_type *to_insert_end = x.rbegin().base().getNode();

            pos_node->previous()->setNext( to_insert );
            pos_node->setPrevious( to_insert_end );

            x._begin->init();

            _n += x.size();
            x._n = 0;
        }
    }

    void splice( iterator position, list &x, iterator i )
    {
        if ( x.size() )
        {
            node_type *pos_node = position.getNode();
            node_type *to_insert = i.getNode();

            to_insert->previous()->setNext( to_insert->next() );
            pos_node->previous()->setNext( to_insert );
            to_insert->setNext( pos_node );

            _n += 1;
            x._n--;

            if ( x._n == 0 )
                x._begin->init();
        }
    }

    void splice( iterator position, list &x, iterator first, iterator last )
    {
        while ( first != last )
            splice( position, x, first++ );
    }

    void merge( list &x )
    {
        splice( begin(), x );
        sort();
    }

    template < class Compare > void merge( list &x, Compare comp )
    {
        splice( begin(), x );
        sort( comp );
    }

    void unique( void )
    {
        _unique( begin(), ++begin() );
    }

    template < class BinaryPredicate > void unique( BinaryPredicate binary_pred )
    {
        sort();
        iterator it = begin();
        iterator tmp = it;
        while ( ++it != end() )
        {
            if ( binary_pred( *it, *tmp ) )
                erase( tmp );
            tmp = it;
        }
    }

    /******************************************************************************
     *			Private attributes
     *****************************************************************************/
  private:
    node_type *_begin;
    size_t _n;

    /******************************************************************************
     *			Private functions
     *****************************************************************************/

    void _remove( const value_type &val, iterator it )
    {
        if ( it != end() )
        {
            if ( *it == val )
                _remove( val, erase( it ) );
            else
                _remove( val, ++it );
        }
    }

    template < class Predicate > void _remove_if( Predicate pred, iterator it )
    {
        if ( it != end() )
        {
            if ( pred( *it ) )
                _remove_if( pred, erase( it ) );
            else
                _remove_if( pred, ++it );
        }
    }

    void _unique( iterator prev, iterator it )
    {
        if ( it != end() )
        {
            if ( *prev == *it )
                _unique( erase( prev ), ++it );
            else
                _unique( it, ++it );
        }
    }
};

/******************************************************************************
 *			Operator overloading
 *****************************************************************************/
template < typename T > bool operator==( const ft::list< T > &l1, const ft::list< T > &l2 )
{
    typename ft::list< T >::iterator beg1 = l1.begin();
    typename ft::list< T >::iterator beg2 = l2.begin();

    while ( beg1 != l1.end() )
    {
        if ( *beg1 != *beg2 || beg2 == l2.end() )
            return false;
        beg1++;
        beg2++;
    }
    return beg2 == l2.end();
}

template < typename T > bool operator!=( const ft::list< T > &l1, const ft::list< T > &l2 )
{
    return !( l1 == l2 );
}

template < typename T > bool operator<( const ft::list< T > &l1, const ft::list< T > &l2 )
{
    typename ft::list< T >::iterator beg1 = l1.begin();
    typename ft::list< T >::iterator beg2 = l2.begin();

    while ( beg1 != l1.end() )
    {
        if ( *beg1 > *beg2 || beg2 == l2.end() )
            return false;
        if ( *beg1 < *beg2 )
            return true;
        beg1++;
        beg2++;
    }
    return beg2 != l2.end();
}

template < typename T > bool operator<=( const ft::list< T > &l1, const ft::list< T > &l2 )
{
    typename ft::list< T >::iterator beg1 = l1.begin();
    typename ft::list< T >::iterator beg2 = l2.begin();

    while ( beg1 != l1.end() )
    {
        if ( *beg1 > *beg2 || beg2 == l2.end() )
            return false;
        if ( *beg1 < *beg2 )
            return true;
        beg1++;
        beg2++;
    }
    return true;
}

template < typename T > bool operator>( const ft::list< T > &l1, const ft::list< T > &l2 )
{
    typename ft::list< T >::iterator beg1 = l1.begin();
    typename ft::list< T >::iterator beg2 = l2.begin();

    while ( beg2 != l2.end() )
    {
        if ( *beg1 < *beg2 || beg1 == l1.end() )
            return false;
        if ( *beg1 > *beg2 )
            return true;
        beg1++;
        beg2++;
    }
    return beg1 != l1.end();
}

template < typename T > bool operator>=( const ft::list< T > &l1, const ft::list< T > &l2 )
{
    typename ft::list< T >::iterator beg1 = l1.begin();
    typename ft::list< T >::iterator beg2 = l2.begin();

    while ( beg2 != l2.end() )
    {
        if ( *beg1 < *beg2 || beg1 == l1.end() )
            return false;
        if ( *beg1 > *beg2 )
            return true;
        beg1++;
        beg2++;
    }
    return true;
}

template < typename T > std::ostream &operator<<( std::ostream &os, const ft::list< T > &l )
{
    os << "[ ";

    for ( typename ft::list< T >::iterator it = l.begin(); it != l.end(); it++ )
        os << *it << " ";

    os << "]";
    return os;
}

template < typename T > void swap( ft::list< T > &l1, ft::list< T > &l2 )
{
    l1.swap( l2 );
}

} // namespace ft
#endif
