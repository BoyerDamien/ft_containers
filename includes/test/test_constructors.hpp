/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_constructors.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:05:44 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/21 12:11:26 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_CONSTRUCTORS_HPP
#define TEST_CONSTRUCTORS_HPP
#include "./test_utils.hpp"

namespace unittest
{

template < typename test_type, typename ref_type, typename state_type >
void test_default_constructor(void (*check)(test_type &, ref_type &), state_type state)
{

    test_type test;
    ref_type test_ref;

    check(test, test_ref);
}

template < typename test_type, typename ref_type, typename state_type >
void test_constructor_size(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test(state.len, state.len);
    ref_type test_ref(state.len, state.len);

    check(test, test_ref);
}

template < typename test_type, typename ref_type, typename state_type >
void test_constructor_iter(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test_init = test_type(state.test_state, state.test_state + state.len);
    ref_type ref_init = ref_type(state.ref_state, state.ref_state + state.len);

    test_type test = test_type(test_init.begin(), test_init.end());
    ref_type test_ref = ref_type(ref_init.begin(), ref_init.end());

    check(test, test_ref);
}

template < typename test_type, typename ref_type, typename state_type >
void test_copy_constructor(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test = test_type(state.test_state[0]);
    ref_type test_ref = ref_type(state.ref_state[0]);

    test_type cp_test(test);
    ref_type cp_ref(test_ref);

    assert(test == cp_test && test_ref == cp_ref, "wrong copy value");
    check(test, test_ref);
}

template < typename test_type, typename ref_type, typename state_type >
void test_assignation_constructor(void (*check)(test_type &, ref_type &), state_type state)
{
    test_type test = test_type(state.test_state[0]);
    ref_type test_ref = ref_type(state.ref_state[0]);

    test_type test_cp = test;
    ref_type ref_cp = test_ref;

    assert(test == test_cp && test_ref == ref_cp, "wrong assignation value");
    check(test, test_ref);
}

} // namespace unittest

#endif
