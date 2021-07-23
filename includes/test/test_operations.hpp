/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operations.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:21:32 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/04 15:17:32 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_OPERATIONS_HPP
#define TEST_OPERATIONS_HPP
#include "./test_utils.hpp"
#include <iostream>

namespace unittest
{

template < typename test_type, typename ref_type >
void test_merge( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{

    int init[] = { 1, 2, 3 };
    int init2[] = { 4, 5, 6 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );

    test_type test2( init2, init2 + sizeof( init2 ) / sizeof( int ) );
    ref_type test_ref2( init2, init2 + sizeof( init2 ) / sizeof( int ) );

    test.merge( test2 );
    test_ref.merge( test_ref2 );
    check( test, test_ref );
    check( test2, test_ref2 );

    test.resize( 0 );
    test_ref.resize( 0 );
    test.merge( test2 );
    test_ref.merge( test_ref2 );
    check( test, test_ref );
    check( test2, test_ref2 );

    test.resize( 0 );
    test2.resize( 0 );
    test_ref.resize( 0 );
    test_ref2.resize( 0 );
    test.merge( test2 );
    test_ref.merge( test_ref2 );
    check( test, test_ref );
    check( test2, test_ref2 );
}

template < typename test_type, typename ref_type >
void test_splice( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { 1, 2, 3 };
    int init2[] = { 4, 5, 6 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    test_type test2( init2, init2 + sizeof( init2 ) / sizeof( int ) );

    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref2( init2, init2 + sizeof( init2 ) / sizeof( int ) );

    test.splice( test.end(), test2 );
    test_ref.splice( test_ref.end(), test_ref2 );

    check( test, test_ref );
    check( test2, test_ref2 );

    test2.resize( 10, 2 );
    test_ref2.resize( 10, 2 );
    test.splice( test.begin(), test2 );
    test_ref.splice( test_ref.begin(), test_ref2 );
    check( test, test_ref );
    check( test2, test_ref2 );

    test2.resize( 10, 2 );
    test_ref2.resize( 10, 2 );
    test.splice( ++test.begin(), test2 );
    test_ref.splice( ++test_ref.begin(), test_ref2 );
    check( test, test_ref );
    check( test2, test_ref2 );
}

template < typename test_type, typename ref_type >
void test_remove( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { -1, 1, 2, 3, 4, 4, 4, 4, 5, 1, 2, 6, 7, 8, 8, 10 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );

    for ( int i = -1; i < 11; i++ )
    {
        test.remove( i );
        test_ref.remove( i );
        check( test, test_ref );
    }
}

template < typename number > bool is_four( const number &n )
{
    return n == 4;
}

template < typename test_type, typename ref_type >
void test_remove_if( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { -1, 1, 2, 3, 4, 4, 4, 4, 5, 1, 2, 6, 7, 8, 8, 10 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );

    test.remove_if( is_four< int > );
    test_ref.remove_if( is_four< int > );
    check( test, test_ref );
}

template < typename test_type, typename ref_type >
void test_unique( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { -1, 1, 2, 3, 4, 4, 4, 4, 5, 1, 2, 6, 7, 8, 8, 10 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );

    test.unique();
    test_ref.unique();
    check( test, test_ref );

    test.unique();
    test_ref.unique();
    check( test, test_ref );
}

template < typename number > bool compare( const number &n1, const number &n2 )
{
    return n1 >= n2;
}

template < typename test_type, typename ref_type >
void test_sort( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { 2, 5, 3, 4, 1, -3, -5 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );

    test_type test2( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref2( init, init + sizeof( init ) / sizeof( int ) );

    test.sort();
    test_ref.sort();
    check( test, test_ref );

    test2.sort( compare< int > );
    test_ref2.sort( compare< int > );
    check( test2, test_ref2 );
}

template < typename test_type, typename ref_type >
void test_reverse( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { 1, 2, 3, 4, 5 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );

    test.reverse();
    test_ref.reverse();
    check( test, test_ref );

    test.reverse();
    test_ref.reverse();
    check( test, test_ref );
}
} // namespace unittest

#endif
