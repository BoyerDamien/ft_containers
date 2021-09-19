/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operators.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 09:46:17 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/19 18:40:35 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_OPERATORS_HPP
#define TEST_OPERATORS_HPP

#include <cstddef>
#include <exception>

#include "./test_utils.hpp"

namespace unittest
{

template < typename test_type, typename ref_type, typename state_type >
void test_operator_eq(void (*check)(test_type &, ref_type &), state_type state)
{
    int size = len(state);
    test_type test(state, state + size / 2);
    ref_type test_ref(state, state + size / 2);

    test_type test2(state, state + size);
    ref_type test_ref2(state, state + size);

    check(test, test_ref);
    check(test2, test_ref2);
    unittest::assert((test == test2) == (test_ref == test_ref2), "not equal");

    test.clear();
    test2.clear();
    test_ref.clear();
    test_ref2.clear();
    check(test, test_ref);
    check(test2, test_ref2);
    unittest::assert((test == test2) == (test_ref == test_ref2), "not equal");
}

template < typename test_type, typename ref_type, typename state_type >
void test_operator_diff(void (*check)(test_type &, ref_type &), state_type state)
{
    int size = len(state);
    test_type test(state, state + size / 2);
    ref_type test_ref(state, state + size / 2);

    test_type test2(state, state + size);
    ref_type test_ref2(state, state + size);

    check(test, test_ref);
    check(test2, test_ref2);
    unittest::assert((test != test2) == (test_ref != test_ref2), "equal");

    test.clear();
    test2.clear();
    test_ref.clear();
    test_ref2.clear();
    check(test, test_ref);
    check(test2, test_ref2);
    unittest::assert(!(test != test2) == !(test_ref != test_ref2), "not equal");
}

template < typename test_type, typename ref_type, typename state_type >
void test_operator_inf_sup(void (*check)(test_type &, ref_type &), state_type state)
{
    int size = len(state);
    test_type test(state, state + size / 2);
    ref_type test_ref(state, state + size / 2);

    test_type test2(state, state + size);
    ref_type test_ref2(state, state + size);

    check(test, test_ref);
    check(test2, test_ref2);
    unittest::assert((test2 < test) == (test_ref2 < test_ref), "greater or equal");
    unittest::assert((test2 <= test) == (test_ref2 <= test_ref), "greater");
    unittest::assert((test > test2) == (test_ref > test_ref2), "less or equal");
    unittest::assert((test >= test2) == (test_ref >= test_ref2), "less");

    test.clear();
    test2.clear();
    test_ref.clear();
    test_ref2.clear();

    check(test, test_ref);
    check(test2, test_ref2);
    unittest::assert(!(test2 < test) == !(test_ref2 < test_ref), "not equal");
    unittest::assert((test2 <= test) == (test_ref2 <= test_ref), "not equal");
    unittest::assert(!(test > test2) == !(test_ref > test_ref2), "not equal");
    unittest::assert((test >= test2) == (test_ref >= test_ref2), "not equal");
}

template < typename test_type, typename ref_type, typename state_type >
void test_pair_operator(void (*check)(test_type &, ref_type &), state_type state)
{

    int size = len(state);

    for (int i = 0; i < size; i++)
    {
        test_type test(state[i], state[i]);
        ref_type test_ref(state[i], state[i]);
        check(test, test_ref);

        test_type test2(state[size - 1 - i], state[size - 1 - i]);
        ref_type test_ref2(state[size - 1 - i], state[size - 1 - i]);
        check(test2, test_ref2);

        unittest::assert((test == test2) == (test_ref == test_ref2), "wrong equal eval");
        unittest::assert((test != test2) == (test_ref != test_ref2), "wrong diff eval");
        unittest::assert((test < test2) == (test_ref < test_ref2), "wrong inf eval");
        unittest::assert((test <= test2) == (test_ref <= test_ref2), "wrong inf equal eval");
        unittest::assert((test > test2) == (test_ref > test_ref2), "wrong sup eval");
        unittest::assert((test >= test2) == (test_ref >= test_ref2), "wrong sup equal eval");
    }
}
} // namespace unittest

#endif
