/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:46:13 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/19 18:39:12 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include "test/test_operators.hpp"
#include "test/test_utils.hpp"
#include <exception>
#include <map>

/******************************************************************************************
 *                       Types
 ******************************************************************************************/

typedef int type;

typedef ft::pair< type, type > test_type;
typedef std::pair< type, type > ref_type;
typedef unittest::Test< test_type, ref_type, type * > Test;

/******************************************************************************************
 *                       Tests
 ******************************************************************************************/

bool unittest::test_pair(void)
{
    int state[] = {1, 2, 3, 4, 5, 6};

    const ::Test tests[] = {

        ::Test("test pair default constructor", unittest::test_default_constructor, unittest::check_pair),
        ::Test("test pair copy constructor", unittest::test_copy_constructor, unittest::check_pair),
        ::Test("test pair assignation constructor", unittest::test_assignation_constructor, unittest::check_pair),
        ::Test("test pair operators", unittest::test_pair_operator, unittest::check_pair, state),
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!tests[i].run())
            return false;
    }
    return true;
}
