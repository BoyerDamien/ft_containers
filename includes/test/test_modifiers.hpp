/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_modifiers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:07:59 by dboyer            #+#    #+#             */
/*   Updated: 2021/05/31 10:41:45 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MODIFIERS_HPP
#define TEST_MODIFIERS_HPP

#include "./test_utils.hpp"
#include <exception>

namespace unittest
{

template < typename test_type, typename ref_type >
void test_push_back( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { 1, 2 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );

    test.push_back( 3 );
    test_ref.push_back( 3 );
    check( test, test_ref );

    test.push_back( 4 );
    test_ref.push_back( 4 );

    check( test, test_ref );
}

template < typename test_type, typename ref_type >
void test_pop_front( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { 1, 2, 5 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );

    check( test, test_ref );

    for ( int i = 0; i < 3; i++ )
    {
        test.pop_front();
        test_ref.pop_front();
        check( test, test_ref );
    }
}

template < typename test_type, typename ref_type >
void test_pop_back( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { 1, 2, 5 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );

    check( test, test_ref );

    for ( int i = 0; i < 3; i++ )
    {
        test.pop_back();
        test_ref.pop_back();
        check( test, test_ref );
    }
}

template < typename test_type, typename ref_type >
void test_clear( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    test_type test( 10, 2 );
    ref_type test_ref( 10, 2 );

    assert( test.size() == test_ref.size(), "wrong size at init" );
    check( test, test_ref );

    test.clear();
    test_ref.clear();

    assert( test.empty() == test_ref.empty(), "not empty after clear" );
    check( test, test_ref );
}

template < typename test_type, typename ref_type >
void test_erase( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { 1, 2, 3, 4 };
    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );
    check( test, test_ref );

    test.erase( test.begin() );
    test_ref.erase( test_ref.begin() );
    check( test, test_ref );

    test.erase( test.begin(), test.end() );
    test_ref.erase( test_ref.begin(), test_ref.end() );
    check( test, test_ref );
}

template < typename test_type, typename ref_type >
void test_insert( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { 1, 2, 3, 4 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );

    test.insert( test.begin(), 0 );
    test_ref.insert( test_ref.begin(), 0 );
    check( test, test_ref );

    test.insert( test.end(), 5 );
    test_ref.insert( test_ref.end(), 5 );
    check( test, test_ref );
}

template < typename test_type, typename ref_type >
void test_swap( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    ref_type test_ref( 4, 4 );
    ref_type test_ref2( 2, 2 );

    test_type test( 4, 4 );
    test_type test2( 2, 2 );

    test_ref.swap( test_ref2 );
    test.swap( test2 );

    check( test, test_ref );
    check( test2, test_ref2 );
}

template < typename test_type, typename ref_type >
void test_push_front( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    test_type test;
    ref_type test_ref;

    for ( int i = 0; i < 5; i++ )
    {
        test.push_front( i );
        test_ref.push_front( i );
        check( test, test_ref );
    }
}

template < typename test_type, typename ref_type >
void test_resize( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { 0, 1, 2, 3 };
    int test_size[] = { 2, 10, 1, 0, 3 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );

    for ( int i = 0; i < 4; i++ )
    {
        test.resize( test_size[ i ] );
        test_ref.resize( test_size[ i ] );
        check( test, test_ref );
    }
}

template < typename test_type, typename ref_type >
void test_assign( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { 0, 1, 2, 3 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );

    test_type test2( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref2( init, init + sizeof( init ) / sizeof( int ) );

    test.assign( test2.begin(), test2.begin() );
    test_ref.assign( test_ref2.begin(), test_ref2.begin() );

    check( test, test_ref );
    check( test2, test_ref2 );

    test.assign( test2.begin(), test2.end() );
    test_ref.assign( test_ref2.begin(), test_ref2.end() );

    check( test, test_ref );
    check( test2, test_ref2 );
}

} // namespace unittest
#endif
