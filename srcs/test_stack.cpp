/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 17:20:34 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/23 20:00:49 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include "test/test_accessors.hpp"
#include "test/test_capacity.hpp"
#include "test/unittest.hpp"
#include <stack>

/******************************************************************************************
 *                       Types
 ******************************************************************************************/
typedef int type;
typedef ft::stack< type > test_type;
typedef std::stack< type > ref_type;
typedef unittest::state< type, type > state_type;
typedef unittest::Test< test_type, ref_type, state_type > Test;

bool unittest::test_stack(void)
{
    int init[] = {5, 2, 1, 3, 0};
    state_type state(5, init, init);

    const ::Test tests[] = {

        ::Test("test stack intern_type", unittest::test_stack_intern_types, unittest::check_stack, state),
        ::Test("test stack default constructor", unittest::test_default_constructor, unittest::check_stack, state),
        ::Test("test stack size()", unittest::test_stack_size, unittest::check_stack, state),
        ::Test("test stack empty()", unittest::test_stack_empty, unittest::check_stack, state),
        ::Test("test stack top()", unittest::test_stack_top, unittest::check_stack, state),
        ::Test("test stack push()", unittest::test_stack_push, unittest::check_stack, state),
        ::Test("test stack pop()", unittest::test_stack_pop, unittest::check_stack, state),
        ::Test("test stack operator<() and operator>()", unittest::test_stack_operator_inf_sup, unittest::check_stack,
               state),
        ::Test("test stack operator==() and operator!=()", unittest::test_stack_operator_eq, unittest::check_stack,
               state),
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!tests[i].run())
            return false;
    }
    return true;
}
