/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_accessors.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 14:18:02 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/22 10:46:10 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <stdexcept>

#include "test/test_utils.hpp"

namespace unittest
{

template < typename test_type, typename ref_type, typename state_type >
void test_operator_access(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test(state.test_state, state.test_state + state.len);
    ref_type test_ref(state.ref_state, state.ref_state + state.len);

    check(test, test_ref);

    for (size_t i = 0; i < state.len; i++)
    {
        assert(test[i] == test_ref[i], "wrong value");
    }
    test.clear();
    test_ref.clear();
    assert(test[0] == test_ref[0], "wrong value");
}

template < typename test_type, typename ref_type, typename state_type >
void test_front(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test(state.test_state, state.test_state + state.len);
    ref_type test_ref(state.ref_state, state.ref_state + state.len);

    check(test, test_ref);

    assert(test.front() == test_ref.front(), "wrong value");
}

template < typename test_type, typename ref_type, typename state_type >
void test_back(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test(state.test_state, state.test_state + state.len);
    ref_type test_ref(state.ref_state, state.ref_state + state.len);

    check(test, test_ref);

    assert(test.back() == test_ref.back(), "wrong value");
}

template < typename test_type, typename ref_type, typename state_type >
void test_at(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test(state.test_state, state.test_state + state.len);
    ref_type test_ref(state.ref_state, state.ref_state + state.len);

    check(test, test_ref);

    for (size_t i = 0; i < state.len; i++)
        assert(test.at(i) == test_ref.at(i), "wrong value");

    test.clear();
    test_ref.clear();

    try
    {
        test.at(state.len + 1);
        assert(1 == 0, "no exception error");
    }
    catch (std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        test.at(-1);
        assert(1 == 0, "no exception error");
    }
    catch (std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

template < typename test_type, typename ref_type, typename state_type >
void test_map_at(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test(state.test_state, state.test_state + state.len);
    ref_type test_ref(state.ref_state, state.ref_state + state.len);

    check(test, test_ref);

    for (size_t i = 0; i < state.len; i++)
    {
        assert(test.at(i).first == test_ref.at(i).first, "wrong value");
        assert(test.at(i).second == test_ref.at(i).second, "wrong value");
    }

    test.clear();
    test_ref.clear();

    try
    {
        std::cout << test.at(state.len + 1) << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::cout << test.at(-1) << std::endl;
    }
    catch (std::out_of_range &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
} // namespace unittest
