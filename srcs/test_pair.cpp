/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:46:13 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/21 12:29:56 by dboyer           ###   ########.fr       */
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
typedef unittest::state< test_type, ref_type > state_type;
typedef unittest::Test< test_type, ref_type, state_type > Test;

/******************************************************************************************
 *                       Tests
 ******************************************************************************************/

bool unittest::test_pair(void)
{
    test_type test_state[] = {
        ft::make_pair(5, 5),

        ft::make_pair(3, 3),

        ft::make_pair(1, 1),

        ft::make_pair(2, 2),

        ft::make_pair(6, 6),

        ft::make_pair(0, 0),
    };

    ref_type ref_state[] = {
        std::make_pair(5, 5),

        std::make_pair(3, 3),

        std::make_pair(1, 1),

        std::make_pair(2, 2),

        std::make_pair(6, 6),

        std::make_pair(0, 0),
    };

    state_type state(6, test_state, ref_state);

    const ::Test tests[] = {

        ::Test("test pair default constructor", unittest::test_default_constructor, unittest::check_pair),
        ::Test("test pair copy constructor", unittest::test_pair_copy_constructor, unittest::check_pair, state),
        ::Test("test pair assignation constructor", unittest::test_pair_assignation_constructor, unittest::check_pair,
               state),
        ::Test("test pair operators", unittest::test_pair_operator, unittest::check_pair, state),
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!tests[i].run())
            return false;
    }
    return true;
}
