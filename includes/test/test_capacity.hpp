/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_capacity.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:12:28 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/04 15:17:58 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_CAPACITY_HPP
#define TEST_CAPACITY_HPP
#include "test_utils.hpp"

namespace unittest
{

template < typename test_type, typename ref_type >
void test_max_size( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    test_type test( 10, 2 );
    ref_type test_ref( 10, 2 );

    check( test, test_ref );

    // std::cout << test.max_size() << " " << test_ref.max_size() << std::endl;
    unittest::assert( test.max_size() == test_ref.max_size(), "wrong max size value" );
}

template < typename test_type, typename ref_type >
void test_size( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    test_type test;
    ref_type test_ref;

    unittest::assert( test.size() == test_ref.size(), "wrong size" );
    unittest::assert( test.empty() == test_ref.empty(), "wrong size" );
    check( test, test_ref );

    test_type test2( 10, 10 );
    ref_type test_ref2( 10, 10 );

    unittest::assert( test.empty() == test_ref.empty(), "wrong size" );
    unittest::assert( test.size() == test_ref.size(), "wrong size" );
    check( test, test_ref );
}

template < typename test_type, typename ref_type >
void test_capacity( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    test_type test;
    ref_type test_ref;
    check( test, test_ref );

    test.reserve( 10 );
    test_ref.reserve( 10 );
    check( test, test_ref );

    test.clear();
    test_ref.clear();
    check( test, test_ref );

    test.push_back( 2 );
    test_ref.push_back( 2 );
    check( test, test_ref );
}

template < typename test_type, typename ref_type >
void test_reserve( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    test_type test;
    ref_type test_ref;
    check( test, test_ref );

    int size_test[] = { 0, 10, 0, 100, 1, 5 };

    for ( size_t i = 0; i < sizeof( size_test ) / sizeof( int ); i++ )
    {
        test.reserve( i );
        test_ref.reserve( i );
        check( test, test_ref );
    }
}

template < typename test_type, typename ref_type >
void test_empty( void ( *check )( test_type &, ref_type & ) ) throw( std::exception )
{
    test_type test;
    ref_type test_ref;
    check( test, test_ref );

    assert( test.empty() == test_ref.empty(), "wrong empty value" );

    test.push_back( 10 );
    test_ref.push_back( 10 );
    assert( test.empty() == test_ref.empty(), "wrong empty value" );

    test.clear();
    test_ref.clear();
    assert( test.empty() == test_ref.empty(), "wrong empty value" );
}

} // namespace unittest

#endif