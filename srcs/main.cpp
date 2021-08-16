/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:45:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/08/16 12:01:53 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include "iterators/map_iterator.hpp"
#include "list/list.hpp"
#include "map/map.hpp"
#include "map/pair.hpp"
#include "map/rbt_element.hpp"
#include "test/test_utils.hpp"
#include "test/unittest.hpp"
#include "vector/vector.hpp"
#include <iostream>
#include <map>
#include <string>
#include <utility>

int main( void )
{
    ft::map< std::string, int > test;
    ft::pair< const std::string, int > p( "1", 10 );
    ft::pair< const std::string, int > p2( "2", 20 );
    ft::pair< const std::string, int > p3( "3", 30 );
    ft::pair< const std::string, int > p4( "4", 40 );

    // std::cout << test.lower_bound( p.first ).getNode()->getPair() << std::endl;
    // std::cout << test.upper_bound( p.first ).getNode()->getPair() << std::endl;
    test.insert( p2 );

    // std::cout << test.lower_bound( p2.first ).getNode()->getPair() << std::endl;
    // std::cout << test.upper_bound( p2.first ).getNode()->getPair() << std::endl;
    test.insert( p );

    // std::cout << test.lower_bound( p3.first ).getNode()->getPair() << std::endl;
    // std::cout << test.upper_bound( p3.first ).getNode()->getPair() << std::endl;
    test.insert( p3 );

    // std::cout << test.lower_bound( p4.first ).getNode()->getPair() << std::endl;
    // std::cout << test.upper_bound( p4.first ).getNode()->getPair() << std::endl;
    test.insert( p4 );

    /*     for ( ft::map< std::string, int >::iterator it = test.begin(); it !=
     * test.end(); */
    /*           it++ ) */
    /*         std::cout << *it << std::endl; */
    /*  */

    test.erase( test.begin() );
    ft::map< std::string, int >::iterator it = test.begin();
    std::cout << *it << std::endl;
    std::cout << *++it << std::endl;
    std::cout << *++it << std::endl;
    std::cout << *++it << std::endl;
    std::cout << *++it << std::endl;
    std::cout << *++it << std::endl;
    std::cout << *++it << std::endl;

    return 0;
}
