/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_accessors.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:18:02 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/02 14:52:44 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_ACCESSORS_HPP
#define TEST_ACCESSORS_HPP

#include "test/test_utils.hpp"
#include <exception>
#include <iostream>
#include <stdexcept>

namespace unittest
{

template < typename test_type, typename ref_type >
void test_operator_access( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { 1, 2, 3, 4, 5 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );
    check( test, test_ref );

    for ( size_t i = 0; i < sizeof( init ) / sizeof( int ); i++ )
    {
        assert( test[ i ] == test_ref[ i ], "wrong value" );
    }
    test.clear();
    test_ref.clear();
    assert( test[ 0 ] == test[ 0 ], "wrong value" );
}

template < typename test_type, typename ref_type >
void test_front( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { 1, 2, 3, 4, 5 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );
    check( test, test_ref );
    assert( test.front() == test_ref.front(), "wrong value" );

    test.clear();
    test_ref.clear();
    assert( test.front() == test_ref.front(), "wrong value" );
}

template < typename test_type, typename ref_type >
void test_back( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { 1, 2, 3, 4, 5 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );
    check( test, test_ref );
    assert( test.back() == test_ref.back(), "wrong value" );

    test.clear();
    test_ref.clear();
    std::cout << test.back() << test_ref.back() << std::endl;
    assert( test.back() == test_ref.back(), "wrong value" );
}

template < typename test_type, typename ref_type >
void test_at( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    int init[] = { 1, 2, 3, 4, 5 };

    test_type test( init, init + sizeof( init ) / sizeof( int ) );
    ref_type test_ref( init, init + sizeof( init ) / sizeof( int ) );
    check( test, test_ref );

    for ( size_t i = 0; i < sizeof( init ) / sizeof( int ); i++ )
        assert( test.at( i ) == test_ref.at( i ), "wrong value" );

    test.clear();
    test_ref.clear();

    try
    {
        assert( test.at( 0 ) == 1, "no exception error" );
        assert( test.at( 100 ) == 1, "no exception error" );
    }
    catch ( std::out_of_range &e )
    {
        std::cerr << e.what() << std::endl;
    }
}
} // namespace unittest

#endif