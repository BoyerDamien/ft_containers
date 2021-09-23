/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_modifiers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:07:59 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/23 18:00:19 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_MODIFIERS_HPP
#define TEST_MODIFIERS_HPP

#include <exception>

#include "./test_utils.hpp"

namespace unittest
{

template < typename test_type, typename ref_type, typename state_type >
void test_push_back(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test;
    ref_type test_ref;

    int i = 0;
    while (i < state.len)
    {
        test.push_back(state.test_state[i]);
        test_ref.push_back(state.ref_state[i]);
        check(test, test_ref);
        i++;
    }
    check(test, test_ref);
}

template < typename test_type, typename ref_type, typename state_type >
void test_pop_back(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test(state.test_state, state.test_state + state.len);
    ref_type test_ref(state.ref_state, state.ref_state + state.len);

    check(test, test_ref);

    for (int i = 0; i < state.len; i++)
    {
        test.pop_back();
        test_ref.pop_back();
        check(test, test_ref);
    }
}

template < typename test_type, typename ref_type, typename state_type >
void test_clear(void (*check)(test_type &, ref_type &), state_type state)
{

    test_type test(state.test_state, state.test_state + state.len);
    ref_type test_ref(state.ref_state, state.ref_state + state.len);

    assert(test.size() == test_ref.size(), "wrong size at init");
    check(test, test_ref);

    test.clear();
    test_ref.clear();

    assert(test.empty() == test_ref.empty(), "not empty after clear");
    check(test, test_ref);
}

template < typename test_type, typename ref_type, typename state_type >
void test_erase(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test(state.test_state, state.test_state + state.len);
    ref_type test_ref(state.ref_state, state.ref_state + state.len);

    test.erase(test.begin());
    test_ref.erase(test_ref.begin());
    check(test, test_ref);

    test.erase(test.begin(), test.end());
    test_ref.erase(test_ref.begin(), test_ref.end());
    check(test, test_ref);
}

template < typename test_type, typename ref_type, typename state_type >
void test_insert(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test;
    ref_type test_ref;

    int i = 0;
    while (i < state.len)
    {
        test.insert(test.begin(), state.test_state[i]);
        test_ref.insert(test_ref.begin(), state.ref_state[i]);
        check(test, test_ref);
        i++;
    }

    while (i)
    {
        test.insert(test.end(), state.test_state[i - 1]);
        test_ref.insert(test_ref.end(), state.ref_state[i - 1]);
        check(test, test_ref);
        i--;
    }

    test.insert(++test.begin(), state.test_state[0]);
    test_ref.insert(++test_ref.begin(), state.ref_state[0]);
    check(test, test_ref);

    test.insert(--test.end(), state.test_state[1]);
    test_ref.insert(--test_ref.end(), state.ref_state[1]);
    check(test, test_ref);
}

template < typename test_type, typename ref_type, typename state_type >
void test_swap(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test(state.test_state, state.test_state + state.len / 2);
    ref_type test_ref(state.ref_state, state.ref_state + state.len / 2);

    test_type test2(state.test_state, state.test_state + state.len);
    ref_type test_ref2(state.ref_state, state.ref_state + state.len);

    test_ref.swap(test_ref2);
    test.swap(test2);

    check(test, test_ref);
    check(test2, test_ref2);
}

template < typename test_type, typename ref_type, typename state_type >
void test_assign(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test(state.test_state, state.test_state + state.len);
    ref_type test_ref(state.ref_state, state.ref_state + state.len);

    test_type test2(state.test_state, state.test_state + state.len);
    ref_type test_ref2(state.ref_state, state.ref_state + state.len);

    test.assign(test2.begin(), test2.begin());
    test_ref.assign(test_ref2.begin(), test_ref2.begin());

    check(test, test_ref);
    check(test2, test_ref2);

    test.assign(test2.begin(), test2.end());
    test_ref.assign(test_ref2.begin(), test_ref2.end());

    check(test, test_ref);
    check(test2, test_ref2);
}

template < typename test_type, typename ref_type, typename state_type >
void test_stack_push(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test;
    ref_type test_ref;

    for (int i = 0; i < state.len; i++)
    {
        test.push(state.test_state[i]);
        test_ref.push(state.ref_state[i]);
        check_stack(test, test_ref);
    }
}

template < typename test_type, typename ref_type, typename state_type >
void test_stack_pop(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test;
    ref_type test_ref;

    for (int i = 0; i < state.len; i++)
    {
        test.push(state.test_state[i]);
        test_ref.push(state.ref_state[i]);
        check_stack(test, test_ref);
    }

    while (test_ref.size())
    {
        test.pop();
        test_ref.pop();
        check_stack(test, test_ref);
    }
}

} // namespace unittest
#endif
