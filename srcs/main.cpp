/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:45:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/05 16:50:37 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
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
    /*if ( unittest::test_list() && unittest::test_vector() && unittest::test_pair() )
        return 0;*/
    ft::bst_element< int, int > test;
    test.setPair( ft::pair< int, int >( 5, 10 ) );
    ft::bst_element< int, int > test2;
    test2.setPair( ft::pair< int, int >( 11, 10 ) );

    ft::bst_element< int, int > test3;
    test3.setPair( ft::pair< int, int >( 1, 10 ) );

    test.setChild( &test2 );
    test.setChild( &test3 );
    ft::map_iterator< int, int > it( &test3 );

    std::cout << *it << std::endl;
    ++it;
    std::cout << *it << std::endl;
    ++it;
    std::cout << *it << std::endl;

    return -1;
}
