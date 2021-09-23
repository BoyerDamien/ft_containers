/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_operations.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 18:21:32 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/23 16:49:32 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "./test_utils.hpp"

namespace unittest
{
template < typename test_type, typename ref_type, typename state_type >
void test_find(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test = test_type(state.test_state, state.test_state + state.len);
    ref_type test_ref = ref_type(state.ref_state, state.ref_state + state.len);

    check(test, test_ref);

    assert(test.find(state.test_state[0].first) != test.end() &&
               test_ref.find(state.ref_state[0].first) != test_ref.end(),
           "wrong iterator value after find");
    unittest::check_pair(*(test.find(state.test_state[0].first)), state.test_state[0]);

    typename test_type::key_type k = (*test.begin()).first;
    test.erase(test.begin());
    test_ref.erase(test_ref.begin());

    assert(test.find(k) == test.end() && test_ref.find(k) == test_ref.end(), "wrong iterator value after wrong find");
}

template < typename test_type, typename ref_type, typename state_type >
void test_count(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test = test_type(state.test_state, state.test_state + state.len);
    ref_type test_ref = ref_type(state.ref_state, state.ref_state + state.len);

    check(test, test_ref);

    assert(test.count(state.test_state[0].first) == test_ref.count(state.ref_state[0].first),
           "wrong iterator value after find");

    typename test_type::key_type k = (*test.begin()).first;
    test.erase(test.begin());
    test_ref.erase(test_ref.begin());

    assert(test.count(k) == test_ref.count(k), "wrong iterator value after wrong find");
}

template < typename test_type, typename ref_type, typename state_type >
void test_lower_bound(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test = test_type(state.test_state, state.test_state + state.len);
    ref_type test_ref = ref_type(state.ref_state, state.ref_state + state.len);

    check(test, test_ref);

    if (!(test.lower_bound(state.test_state[0].first) == test.end() &&
          test_ref.lower_bound(state.ref_state[0].first) == test_ref.end()))
    {
        unittest::check_pair(*test.lower_bound(state.test_state[0].first),
                             *test_ref.lower_bound(state.ref_state[0].first));
    }

    typename test_type::key_type k = test.begin()->first;
    test.erase(test.begin());
    test_ref.erase(test_ref.begin());

    if (!(test.lower_bound(k) == test.end() && test_ref.lower_bound(k) == test_ref.end()))
    {
        unittest::check_pair(*test.lower_bound(k), *test_ref.lower_bound(k));
    }
    if (!(test.lower_bound(state.test_state[(int)state.len / 2].first) == test.end() &&
          test_ref.lower_bound(state.ref_state[(int)state.len / 2].first) == test_ref.end()))
    {
        unittest::check_pair(*test.lower_bound(state.test_state[(int)state.len / 2].first),
                             *test_ref.lower_bound(state.ref_state[(int)state.len / 2].first));
    }
}

template < typename test_type, typename ref_type, typename state_type >
void test_upper_bound(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test = test_type(state.test_state, state.test_state + state.len);
    ref_type test_ref = ref_type(state.ref_state, state.ref_state + state.len);

    check(test, test_ref);

    if (!(test.upper_bound(state.test_state[0].first) == test.end() &&
          test_ref.upper_bound(state.ref_state[0].first) == test_ref.end()))
    {
        unittest::check_pair(*test.upper_bound(state.test_state[0].first),
                             *test_ref.upper_bound(state.ref_state[0].first));
    }

    typename test_type::key_type k = test.begin()->first;
    test.erase(test.begin());
    test_ref.erase(test_ref.begin());

    if (!(test.upper_bound(k) == test.end() && test_ref.upper_bound(k) == test_ref.end()))
    {
        unittest::check_pair(*test.upper_bound(k), *test_ref.upper_bound(k));
    }
    if (!(test.upper_bound(state.test_state[(int)state.len / 2].first) == test.end() &&
          test_ref.upper_bound(state.ref_state[(int)state.len / 2].first) == test_ref.end()))
    {
        unittest::check_pair(*test.upper_bound(state.test_state[(int)state.len / 2].first),
                             *test_ref.upper_bound(state.ref_state[(int)state.len / 2].first));
    }
}
} // namespace unittest
