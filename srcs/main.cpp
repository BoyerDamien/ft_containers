/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:45:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/07/22 14:53:49 by dboyer           ###   ########.fr       */
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
    ft::pair< const std::string, int > p( "ok", 10 );
    ft::pair< const std::string, int > p2( "p2", 20 );
    ft::pair< const std::string, int > p3( "p3", 20 );

    test.insert( p );
    test.insert( p2 );

    test.insert( p3 );

    std::cout << test.upper_bound( "p" ).getNode()->getPair() << std::endl;
    // for ( ft::map< std::string, int >::iterator it = test.begin(); it != test.end(); it++ )
    //  std::cout << *it << std::endl;
    return 0;
}
