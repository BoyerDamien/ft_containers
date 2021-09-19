/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_intern_type.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 12:49:47 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/19 20:25:39 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterators/iterator.hpp"
#include "type_traits.hpp"
#include "vector/vector.hpp"
#include <deque>
#include <iterator>
#include <memory>
#include <vector>

namespace unittest
{

template < typename test_type, typename ref_type, typename state_type >
void test_vector_itern_types(void (*check)(test_type &, ref_type &), state_type state = state_type())
{
    (void)check;
    (void)state;

    assert(ft::is_type_equal< typename test_type::value_type, typename ref_type::value_type >::value,
           "wrong value_type");

    assert(ft::is_type_equal< typename test_type::allocator_type, typename ref_type::allocator_type >::value,
           "wrong allocator_type");

    assert(ft::is_type_equal< typename test_type::reference, typename ref_type::reference >::value, "wrong reference");

    assert(ft::is_type_equal< typename test_type::const_reference, typename ref_type::const_reference >::value,
           "wrong const_reference");

    assert(ft::is_type_equal< typename test_type::pointer, typename ref_type::pointer >::value, "wrong pointer");

    assert(ft::is_type_equal< typename test_type::difference_type, typename ref_type::difference_type >::value,
           "wrong difference_type");
}

template < typename test_type, typename ref_type, typename state_type >
void test_map_itern_types(void (*check)(test_type &, ref_type &), state_type state = state_type())
{
    (void)check;
    (void)state;

    typedef typename std::allocator< typename test_type::value_type > allocator_type;

    assert(ft::is_type_equal< typename test_type::value_type::first_type,
                              typename ref_type::value_type::first_type >::value,
           "wrong value_type key");

    assert(ft::is_type_equal< typename test_type::value_type::second_type,
                              typename ref_type::value_type::second_type >::value,
           "wrong value_type value");

    assert(ft::is_type_equal< typename test_type::allocator_type, allocator_type >::value, "wrong allocator_type");

    assert(ft::is_type_equal< typename test_type::reference, typename allocator_type::reference >::value,
           "wrong reference");

    assert(ft::is_type_equal< typename test_type::const_reference, typename allocator_type::const_reference >::value,
           "wrong const_reference");

    assert(ft::is_type_equal< typename test_type::pointer, typename allocator_type::pointer >::value, "wrong pointer");

    assert(ft::is_type_equal< typename test_type::difference_type, typename allocator_type::difference_type >::value,
           "wrong difference_type");
}

template < typename test_type, typename ref_type, typename state_type >
void test_random_access_iterator_intern_type(void (*check)(test_type &, ref_type &), state_type state)
{
    (void)check;
    (void)state;

    typedef typename test_type::iterator test_iterator;
    typedef typename ref_type::iterator ref_iterator;

    assert(ft::is_type_equal< typename test_iterator::value_type, typename ref_iterator::value_type >::value,
           "wrong value_type");
    assert(ft::is_type_equal< typename test_iterator::pointer, typename ref_iterator::pointer >::value,
           "wrong pointer type");
    assert(ft::is_type_equal< typename test_iterator::difference_type, typename ref_iterator::difference_type >::value,
           "wrong difference_type");
    assert(ft::is_type_equal< typename test_iterator::reference, typename ref_iterator::reference >::value,
           "wrong reference type");
    assert(ft::is_type_equal< typename test_iterator::iterator_type, typename ref_iterator::iterator_type >::value,
           "wrong iterator_type type");
    assert(ft::is_random_access_iterator< typename test_type::iterator::iterator_category >::value,
           "wrong iterator category");

    typedef typename test_type::const_iterator const_test_iterator;
    typedef typename ref_type::const_iterator const_ref_iterator;

    assert(
        ft::is_type_equal< typename const_test_iterator::value_type, typename const_ref_iterator::value_type >::value,
        "wrong const value_type");
    assert(ft::is_type_equal< typename const_test_iterator::pointer, typename const_ref_iterator::pointer >::value,
           "wrong const pointer type");
    assert(ft::is_type_equal< typename const_test_iterator::difference_type,
                              typename const_ref_iterator::difference_type >::value,
           "wrong const difference_type");
    assert(ft::is_type_equal< typename const_test_iterator::reference, typename const_ref_iterator::reference >::value,
           "wrong const reference type");
    assert(ft::is_type_equal< typename const_test_iterator::iterator_type,
                              typename const_ref_iterator::iterator_type >::value,
           "wrong const iterator_type type");
    assert(ft::is_random_access_iterator< typename test_type::iterator::iterator_category >::value,
           "wrong const iterator category");
}
template < typename test_type, typename ref_type, typename state_type >
void test_bidirectional_iterator_intern_type(void (*check)(test_type &, ref_type &), state_type state)
{
    (void)check;
    (void)state;

    typedef typename test_type::iterator test_iterator;
    typedef typename ref_type::iterator ref_iterator;

    assert(ft::is_type_equal< typename test_iterator::value_type, typename ref_iterator::value_type >::value,
           "wrong value_type");
    assert(ft::is_type_equal< typename test_iterator::pointer, typename ref_iterator::pointer >::value,
           "wrong pointer type");
    assert(ft::is_type_equal< typename test_iterator::difference_type, typename ref_iterator::difference_type >::value,
           "wrong difference_type");
    assert(ft::is_type_equal< typename test_iterator::reference, typename ref_iterator::reference >::value,
           "wrong reference type");
    assert(ft::is_bidirectional_iterator< typename test_type::iterator::iterator_category >::value,
           "wrong iterator category");

    typedef typename test_type::const_iterator const_test_iterator;
    typedef typename ref_type::const_iterator const_ref_iterator;

    assert(
        ft::is_type_equal< typename const_test_iterator::value_type, typename const_ref_iterator::value_type >::value,
        "wrong const value_type");
    assert(ft::is_type_equal< typename const_test_iterator::pointer, typename const_ref_iterator::pointer >::value,
           "wrong const pointer type");
    assert(ft::is_type_equal< typename const_test_iterator::difference_type,
                              typename const_ref_iterator::difference_type >::value,
           "wrong const difference_type");
    assert(ft::is_type_equal< typename const_test_iterator::reference, typename const_ref_iterator::reference >::value,
           "wrong const reference type");
    assert(ft::is_bidirectional_iterator< typename test_type::iterator::iterator_category >::value,
           "wrong const iterator category");
}
} // namespace unittest