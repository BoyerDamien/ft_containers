/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_iterators.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:10:45 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/19 17:15:04 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_ITERATORS_HPP
#define TEST_ITERATORS_HPP
#include <iostream>

#include "test/test_utils.hpp"

namespace unittest
{

template < typename test_type, typename ref_type, typename state_type >
void test_begin(void (*check)(test_type &, ref_type &), state_type state)
{
    int size = len(state);
    test_type test(state, state + size);
    ref_type test_ref(state, state + size);

    check(test, test_ref);

    assert(test.begin() != test.end() && test_ref.begin() != test_ref.end(), "begin == end");
    assert(*test.begin() == *test_ref.begin(), "begin != end");
}

template < typename test_type, typename ref_type, typename state_type >
void test_rbegin(void (*check)(test_type &, ref_type &), state_type state)
{
    int size = len(state);
    test_type test(state, state + size);
    ref_type test_ref(state, state + size);

    check(test, test_ref);

    assert(test.rbegin() != test.rend() && test_ref.rbegin() != test_ref.rend(), "rbegin == rend");
    assert(*test.rbegin() == *test_ref.rbegin(), "rbegin != rend");
}

template < typename test_type, typename ref_type, typename state_type >
void test_iterator_inc_dec(void (*check)(test_type &, ref_type &), state_type state)
{

    int size = len(state);
    test_type test(state, state + size);
    ref_type test_ref(state, state + size);
    check(test, test_ref);

    assert(test.begin()++ == test.begin() && test_ref.begin()++ == test_ref.begin(),
           "wrong value after post incrementation");
    assert(test.end()-- == test.end()-- && test_ref.end()-- == test_ref.end()--,
           "wrong value after post decrementation");
    assert(*++test.begin() == *++test_ref.begin(), "wrong value after pre incrementation");
    assert(*--test.end() == *--test_ref.end(), "wrong value after pre decrementation");
}

template < typename test_type, typename ref_type, typename state_type >
void test_rev_iterator_inc_dec(void (*check)(test_type &, ref_type &), state_type state)
{
    int size = len(state);
    test_type test(state, state + size);
    ref_type test_ref(state, state + size);
    check(test, test_ref);

    assert(test.rbegin()++ == test.rbegin() && test_ref.rbegin()++ == test_ref.rbegin(),
           "wrong value after post incrementation");
    assert(test.rend()-- == test.rend()-- && test_ref.rend()-- == test_ref.rend()--,
           "wrong value after post decrementation");
    assert(*++test.rbegin() == *++test_ref.rbegin(), "wrong value after pre incrementation");
    assert(*--test.rend() == *--test_ref.rend(), "wrong value after pre decrementation");
}

} // namespace unittest

#endif
