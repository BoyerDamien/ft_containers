/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 17:14:32 by dess              #+#    #+#             */
/*   Updated: 2021/06/02 14:44:38 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "../algorithms/algorithms.hpp"
#include "../iterators/iterator_traits.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../iterators/vector_iterator.hpp"
#include <bits/c++config.h>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>
namespace ft
{

/*
 *		Reimplementation of vector template
 *		Refs:
 *		-	https://www.cplusplus.com/reference/vector/vector/?kw=vector
 *		-	https://en.cppreference.com/w/cpp/container/vector
 */
template < typename T, class Alloc = std::allocator< T > > class vector
{
  public:
    typedef T value_type;

    typedef Alloc allocator_type;

    typedef vector< value_type > self;

    typedef typename allocator_type::pointer node_type;

    typedef typename allocator_type::reference reference;

    typedef typename allocator_type::const_reference const_reference;

    typedef typename allocator_type::pointer pointer;

    typedef typename allocator_type::const_pointer const_pointer;

    typedef typename allocator_type::difference_type difference_type;

    typedef typename allocator_type::size_type size_type;

    typedef vector_iterator< value_type > iterator;

    typedef const iterator const_iterator;

    typedef reverse_iterator< iterator > reverse_iterator;

    typedef const reverse_iterator const_reverse_iterator;

    typedef typename Alloc::template rebind< value_type >::other node_allocator_type;

    /********************************************************************************
     * 				Constructor
     ********************************************************************************/
    vector( void ) : _n( 0 ), _capacity( 0 ), _content( _alloc( _capacity ) )
    {
    }

    vector( size_type n, const value_type &val = value_type(), allocator_type alloc = allocator_type() )
        : _n( n ), _capacity( _n ), _content( _alloc( _capacity ) )
    {
        for ( size_type i = 0; i < _n; i++ )
            alloc.construct( _content + i, val );
    }

    vector( pointer first, pointer last, allocator_type alloc = allocator_type() )
        : _n( last - first ), _capacity( _n ), _content( _alloc( _capacity ) )
    {
        for ( size_type i = 0; first + i != last; i++ )
            alloc.construct( _content + i, *( first + i ) );
    }

    vector( iterator first, iterator last, allocator_type alloc = allocator_type() )
        : _n( last - first ), _capacity( _n ), _content( _alloc( _capacity ) )
    {
        for ( size_type i = 0; first + i != last; i++ )
            alloc.construct( _content + i, *( first + i ) );
    }

    vector( const self &x, allocator_type alloc = allocator_type() )
        : _n( x._n ), _capacity( x._capacity ), _content( _alloc( _capacity ) )
    {
        for ( size_type i = 0; i < _n; i++ )
            alloc.construct( _content + i, x._content[ i ] );
    }

    ~vector( void )
    {
        clear();
        _dealloc( _content, _capacity + 1 );
    }

    vector &operator=( const self &x )
    {
        this->swap( x );
        x.clear();
        return *this;
    }

    /********************************************************************************
     *				Accessors
     ********************************************************************************/
    reference operator[]( size_type n )
    {
        return _content[ n ];
    }

    const_reference operator[]( size_type n ) const
    {
        return _content[ n ];
    }

    reference at( size_type n ) throw( std::out_of_range )
    {
        if ( n < _capacity )
            return _content[ n ];
        throw( std::out_of_range( "Error: out of range" ) );
    }

    const_reference at( size_type n ) const throw( std::out_of_range )
    {
        if ( n < _capacity )
            return _content[ n ];
        throw( std::out_of_range( "Error: out of range" ) );
    }

    reference front( void )
    {
        return _content[ 0 ];
    }

    const_reference front( void ) const
    {
        return _content[ 0 ];
    }
    reference back( void )
    {
        return size() ? _content[ _n - 1 ] : _content[ _capacity ];
    }
    const_reference back( void ) const
    {
        return size() ? _content[ _n - 1 ] : _content[ _capacity ];
    }

    /********************************************************************************
     *			Capacity
     ********************************************************************************/

    size_type size( void ) const
    {
        return _n;
    }
    size_type capacity( void ) const
    {
        return _capacity;
    }
    bool empty( void ) const
    {
        return _n == 0;
    }
    size_type max_size( void ) const
    {
        return node_allocator_type().max_size();
    }

    void resize( size_type n, value_type val = value_type() )
    {
        size_type tmp_size = n < _capacity ? _capacity : n;
        vector< value_type > tmp( tmp_size, val );
        if ( n < _capacity )
            tmp.assign( begin(), begin() + n );
        else
        {
            tmp.assign( begin(), end() );
            for ( size_type i = n - _n; i > 0; i-- )
                tmp.push_back( val );
        }
        this->swap( tmp );
    }

    void reserve( size_type n )
    {
        if ( n > _capacity )
        {
            vector< value_type > tmp( n, value_type() );
            tmp.assign( begin(), end() );
            this->swap( tmp );
        }
    }

    /********************************************************************************
     *			Iterators
     ********************************************************************************/
    iterator begin( void )
    {
        return iterator( _content );
    }

    const_iterator begin( void ) const
    {
        return static_cast< const_iterator >( iterator( _content ) );
    }
    iterator end( void )
    {
        return iterator( _content + _n );
    }

    const_iterator end( void ) const
    {
        return static_cast< const_iterator >( iterator( _content + _n ) );
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

    /********************************************************************************
     *			Modifiers
     ********************************************************************************/

    void clear()
    {
        erase( begin(), end() );
    }

    iterator insert( iterator position, const value_type &val )
    {
        difference_type diff = position - begin();
        vector< value_type > tmp;
        tmp.reserve( _capacity );
        tmp.assign( begin(), position );
        tmp.push_back( val );
        for ( int i = 0; position + i != end(); i++ )
            tmp.push_back( *( position + i ) );
        this->swap( tmp );
        return begin() + diff;
    }

    void insert( iterator position, size_type n, const value_type &val )
    {
        if ( n > 0 )
            insert( insert( position, val ), n - 1, val );
    }

    void insert( iterator position, pointer first, pointer last )
    {
        if ( first && last && first != last )
            insert( ++insert( position, *first ), first + 1, last );
    }

    void push_back( const value_type &val )
    {
        if ( _n + 1 > _capacity )
        {
            size_type cap = _capacity > 0 ? _capacity * 2 : 1;
            pointer tmp = _alloc( cap );
            for ( size_type i = 0; i <= _n; i++ )
                tmp[ i ] = _content[ i ];
            tmp[ _n ] = val;
            _dealloc( _content, _capacity + 1 );
            _content = tmp;
            _capacity = cap;
        }
        else
            _content[ _n ] = val;
        _n++;
    }

    void pop_back( void )
    {
        if ( _n > 0 )
        {
            allocator_type alloc = allocator_type();
            alloc.destroy( _content + _n );
            _n--;
        }
    }

    iterator erase( iterator position )
    {
        difference_type diff = position - begin() + 1;
        vector< value_type > tmp;
        tmp.reserve( _capacity );
        tmp.insert( tmp.end(), &*begin(), &*position );
        if ( position != end() )
            tmp.insert( tmp.end(), &*++position, &*end() );
        this->swap( tmp );
        return begin() + diff;
    }

    iterator erase( iterator first, iterator last )
    {
        if ( _n > 0 )
        {
            allocator_type alloc = allocator_type();
            for ( int i = 0; first + i != last; i++ )
                alloc.destroy( &*( first + i ) );
            for ( int i = 0; last + i != end(); i++ )
                *( first + i ) = *( last + i );
            _n -= ( last - first );
        }
        return first;
    }

    void assign( iterator first, iterator last )
    {
        clear();
        for ( int i = 0; first + i != last; i++ )
            push_back( *( first + i ) );
    }

    void assign( size_type n, const value_type &val )
    {
        clear();
        for ( size_type i = 0; i < n; i++ )
            push_back( val );
    }

    void swap( self &v )
    {
        ft::swap( _content, v._content );
        ft::swap( _capacity, v._capacity );
        ft::swap( _n, v._n );
    }

  private:
    size_type _n;
    size_type _capacity;
    node_type _content;

    pointer _alloc( size_type n, value_type val = value_type() )
    {
        allocator_type alloc = allocator_type();
        pointer ret = alloc.allocate( n + 1 );
        for ( size_type i = 0; i < n + 1; i++ )
            alloc.construct( ret + i, val );
        return ret;
    }

    void _dealloc( pointer ptr, size_type size, allocator_type alloc = allocator_type() )
    {
        for ( size_type i = 0; i < size; i++ )
            alloc.destroy( ptr + i );
        alloc.deallocate( ptr, size );
    }
};

/******************************************************************************
 *			Operator overloading
 *****************************************************************************/
template < typename T > bool operator==( const ft::vector< T > &l1, const ft::vector< T > &l2 )
{
    typename ft::vector< T >::iterator beg1 = l1.begin();
    typename ft::vector< T >::iterator beg2 = l2.begin();

    while ( beg1 != l1.end() )
    {
        if ( *beg1 != *beg2 || beg2 == l2.end() )
            return false;
        beg1++;
        beg2++;
    }
    return beg2 == l2.end();
}

template < typename T > bool operator!=( const ft::vector< T > &l1, const ft::vector< T > &l2 )
{
    return !( l1 == l2 );
}

template < typename T > bool operator<( const ft::vector< T > &l1, const ft::vector< T > &l2 )
{
    typename ft::vector< T >::iterator beg1 = l1.begin();
    typename ft::vector< T >::iterator beg2 = l2.begin();

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

template < typename T > bool operator<=( const ft::vector< T > &l1, const ft::vector< T > &l2 )
{
    typename ft::vector< T >::iterator beg1 = l1.begin();
    typename ft::vector< T >::iterator beg2 = l2.begin();

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

template < typename T > bool operator>( const ft::vector< T > &l1, const ft::vector< T > &l2 )
{
    typename ft::vector< T >::iterator beg1 = l1.begin();
    typename ft::vector< T >::iterator beg2 = l2.begin();

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

template < typename T > bool operator>=( const ft::vector< T > &l1, const ft::vector< T > &l2 )
{
    typename ft::vector< T >::iterator beg1 = l1.begin();
    typename ft::vector< T >::iterator beg2 = l2.begin();

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

template < typename T > std::ostream &operator<<( std::ostream &os, const ft::vector< T > &l )
{
    os << "[ ";

    for ( typename ft::vector< T >::iterator it = l.begin(); it != l.end(); it++ )
        os << *it << " ";

    os << "]";
    return os;
}
} // namespace ft

#endif
