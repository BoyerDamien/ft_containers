/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:45:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/06 20:36:09 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include "iterators/map_iterator.hpp"
#include "list/list.hpp"
#include "map/bst_element.hpp"
#include "map/map.hpp"
#include "map/pair.hpp"
#include "test/test_utils.hpp"
#include "test/unittest.hpp"
#include "vector/vector.hpp"
#include <iostream>
#include <map>
#include <string>
#include <utility>

int main( void )
{
    ft::map< int, int > test;

    ft::map< int, int >::iterator it = test.begin();
    ft::map< int, int >::iterator it2 = test.end();
    ft::map< int, int >::reverse_iterator rev_it = test.rbegin();
    ft::map< int, int >::reverse_iterator rev_it2 = test.end();

    std::cout << *it << std::endl;
    std::cout << *it2 << std::endl;
    std::cout << *rev_it << std::endl;
    std::cout << *rev_it2 << std::endl;
    /*if ( unittest::test_list() && unittest::test_vector() && unittest::test_pair() )
        return 0;*/
    /*ft::bst_element< int, int > test1;
    test1.setPair( ft::pair< int, int >( 1, 10 ) );

    ft::bst_element< int, int > test3;
    test3.setPair( ft::pair< int, int >( 3, 10 ) );

    ft::bst_element< int, int > test2;
    test2.setPair( ft::pair< int, int >( 2, 10 ) );

    ft::bst_element< int, int > test6;
    test6.setPair( ft::pair< int, int >( 6, 10 ) );

    ft::bst_element< int, int > test4;
    test4.setPair( ft::pair< int, int >( 4, 10 ) );

    ft::bst_element< int, int > test7;
    test7.setPair( ft::pair< int, int >( 7, 10 ) );

    ft::bst_element< int, int > test8;
    test8.setPair( ft::pair< int, int >( 8, 10 ) );

    ft::bst_element< int, int > test9;
    test9.setPair( ft::pair< int, int >( 9, 10 ) );

    ft::bst_element< int, int > test10;
    test10.setPair( ft::pair< int, int >( 10, 10 ) );

    ft::bst_element< int, int > test14;
    test14.setPair( ft::pair< int, int >( 14, 10 ) );

    ft::bst_element< int, int > test13;
    test13.setPair( ft::pair< int, int >( 13, 10 ) );

    test3.setChild( &test6 );
    test3.setChild( &test1 );
    test1.setChild( &test2 );
    test6.setChild( &test4 );
    test6.setChild( &test7 );
    test8.setChild( &test3 );
    test8.setChild( &test9 );
    test9.setChild( &test10 );
    test10.setChild( &test14 );
    test14.setChild( &test13 );

    ft::map_iterator< int, int > it( &test1 );

    for ( int i = 0; i < 11; i++ )
    {
        std::cout << *it << std::endl;
        it++;
    }
    for ( int i = 0; i < 11; i++ )
    {
        std::cout << *it << std::endl;
        it--;
    }*/
    return 0;
}
