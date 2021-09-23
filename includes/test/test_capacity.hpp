/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_capacity.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:12:28 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/23 17:52:01 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "test_utils.hpp"

namespace unittest
{

template < typename test_type, typename ref_type, typename state_type >
void test_max_size(void (*check)(test_type &, ref_type &), state_type state)
{
    (void)state;

    test_type test;
    ref_type test_ref;

    check(test, test_ref);

    unittest::assert(test.max_size() == test_ref.max_size(), "wrong max size value");
}

template < typename test_type, typename ref_type, typename state_type >
void test_size(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test;
    ref_type test_ref;

    unittest::assert(test.size() == test_ref.size(), "wrong size");
    unittest::assert(test.empty() == test_ref.empty(), "wrong size");
    check(test, test_ref);

    test_type test2(state.test_state, state.test_state + state.len);
    ref_type test_ref2(state.ref_state, state.ref_state + state.len);

    unittest::assert(test2.empty() == test_ref2.empty(), "wrong size");
    unittest::assert(test2.size() == test_ref2.size(), "wrong size");
    check(test2, test_ref2);
}

template < typename test_type, typename ref_type, typename state_type >
void test_stack_size(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test;
    ref_type test_ref;

    unittest::assert(test.size() == test_ref.size(), "wrong size");
    unittest::assert(test.empty() == test_ref.empty(), "wrong size");
    check(test, test_ref);

    for (int i = 0; i < state.len; i++)
    {
        test.push(state.test_state[i]);
        test_ref.push(state.ref_state[i]);
    }

    unittest::assert(test.empty() == test_ref.empty(), "wrong size");
    unittest::assert(test.size() == test_ref.size(), "wrong size");
    check(test, test_ref);
}

template < typename test_type, typename ref_type, typename state_type >
void test_capacity(void (*check)(test_type &, ref_type &), state_type state)
{
    (void)state;

    test_type test;
    ref_type test_ref;
    check(test, test_ref);

    test.reserve(10);
    test_ref.reserve(10);
    check(test, test_ref);

    test.clear();
    test_ref.clear();
    check(test, test_ref);

    test.push_back(2);
    test_ref.push_back(2);
    check(test, test_ref);
}

template < typename test_type, typename ref_type, typename state_type >
void test_reserve(void (*check)(test_type &, ref_type &), state_type state)
{
    (void)state;
    test_type test;
    ref_type test_ref;
    check(test, test_ref);

    int size_test[] = {0, 10, 0, 100, 1, 5};

    for (size_t i = 0; i < sizeof(size_test) / sizeof(int); i++)
    {
        test.reserve(i);
        test_ref.reserve(i);
        check(test, test_ref);
    }
}

template < typename test_type, typename ref_type, typename state_type >
void test_resize(void (*check)(test_type &, ref_type &), state_type state)
{
    int test_size[] = {2, 10, 1, 0, 3};
    test_type test(state.test_state, state.test_state + state.len);
    ref_type test_ref(state.ref_state, state.ref_state + state.len);
    check(test, test_ref);

    for (int i = 0; i < 5; i++)
    {
        test.resize(test_size[i]);
        test_ref.resize(test_size[i]);
        check(test, test_ref);
    }
}

template < typename test_type, typename ref_type, typename state_type >
void test_empty(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test;
    ref_type test_ref;
    check(test, test_ref);

    assert(test.empty() == test_ref.empty(), "wrong empty value");

    test_type test2(state.test_state, state.test_state + state.len);
    ref_type test_ref2(state.ref_state, state.ref_state + state.len);

    check(test2, test_ref2);

    assert(test2.empty() == test_ref2.empty(), "wrong empty value");

    test2.clear();
    test_ref2.clear();
    assert(test2.empty() == test_ref2.empty(), "wrong empty value");
}

template < typename test_type, typename ref_type, typename state_type >
void test_stack_empty(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test;
    ref_type test_ref;
    check(test, test_ref);

    assert(test.empty() == test_ref.empty(), "wrong empty value");

    for (int i = 0; i < state.len; i++)
    {
        test.push(state.test_state[i]);
        test_ref.push(state.ref_state[i]);
    }

    check(test, test_ref);

    assert(test.empty() == test_ref.empty(), "wrong empty value");

    while (test.size())
    {
        test.pop();
        test_ref.pop();
    }
    assert(test.empty() == test_ref.empty(), "wrong empty value");
}

} // namespace unittest
