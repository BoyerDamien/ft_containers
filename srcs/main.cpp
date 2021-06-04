/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:45:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/03 12:41:08 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include "list/list.hpp"
#include "test/test_utils.hpp"
#include "vector/vector.hpp"
#include <iostream>
#include <vector>

int main( void )
{
    if ( unittest::test_list() && unittest::test_vector() )
        return 0;
    int init[] = { 3, 6, 5, 4, 1, 2 };
    ft::list< int > test( init, init + sizeof( init ) / sizeof( int ) );

    test.sort();

    std::cout << test << std::endl;

    return -1;
}
