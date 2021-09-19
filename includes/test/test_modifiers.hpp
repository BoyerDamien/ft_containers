/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_modifiers.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:07:59 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/19 18:16:43 by dboyer           ###   ########.fr       */
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
    while (state[i])
    {
        test.push_back(state[i]);
        test_ref.push_back(state[i]);
        check(test, test_ref);
        i++;
    }
    check(test, test_ref);
}

template < typename test_type, typename ref_type, typename state_type >
void test_pop_back(void (*check)(test_type &, ref_type &), state_type state)
{
    int size = len(state);
    test_type test(state, state + size);
    ref_type test_ref(state, state + size);

    check(test, test_ref);

    for (int i = 0; i < len(state); i++)
    {
        test.pop_back();
        test_ref.pop_back();
        check(test, test_ref);
    }
}

template < typename test_type, typename ref_type, typename state_type >
void test_clear(void (*check)(test_type &, ref_type &), state_type state)
{

    int size = len(state);
    test_type test(state, state + size);
    ref_type test_ref(state, state + size);

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
    int size = len(state);
    test_type test(state, state + size);
    ref_type test_ref(state, state + size);

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
    while (i < len(state))
    {
        test.insert(test.begin(), state[i]);
        test_ref.insert(test_ref.begin(), state[i]);
        check(test, test_ref);
        i++;
    }

    while (i)
    {
        test.insert(test.end(), state[i - 1]);
        test_ref.insert(test_ref.end(), state[i - 1]);
        check(test, test_ref);
        i--;
    }

    test.insert(++test.begin(), state[0]);
    test_ref.insert(++test_ref.begin(), state[0]);
    check(test, test_ref);

    test.insert(--test.end(), state[1]);
    test_ref.insert(--test_ref.end(), state[1]);
    check(test, test_ref);
}

template < typename test_type, typename ref_type, typename state_type >
void test_swap(void (*check)(test_type &, ref_type &), state_type state)
{
    int size = len(state);
    test_type test(state, state + size / 2);
    ref_type test_ref(state, state + size / 2);

    test_type test2(state, state + size);
    ref_type test_ref2(state, state + size);

    test_ref.swap(test_ref2);
    test.swap(test2);

    check(test, test_ref);
    check(test2, test_ref2);
}

template < typename test_type, typename ref_type, typename state_type >
void test_assign(void (*check)(test_type &, ref_type &), state_type state)
{
    int size = len(state);
    test_type test(state, state + size);
    ref_type test_ref(state, state + size);

    test_type test2(state, state + size);
    ref_type test_ref2(state, state + size);

    test.assign(test2.begin(), test2.begin());
    test_ref.assign(test_ref2.begin(), test_ref2.begin());

    check(test, test_ref);
    check(test2, test_ref2);

    test.assign(test2.begin(), test2.end());
    test_ref.assign(test_ref2.begin(), test_ref2.end());

    check(test, test_ref);
    check(test2, test_ref2);
}

} // namespace unittest
#endif
