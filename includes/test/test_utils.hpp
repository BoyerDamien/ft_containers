/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:15:48 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/19 19:42:15 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP
#include <iostream>
#include <map>

namespace unittest
{

void assert(bool expr, const std::string &message);

template < typename test_type, typename ref_type > void default_check(test_type &test, ref_type &test_ref)
{
    typename test_type::iterator test_begin = test.begin();
    typename ref_type::iterator ref_begin = test_ref.begin();

    assert(test.empty() == test_ref.empty(), "empty differs");
    assert(test.size() == test_ref.size(), "wrong size");

    for (typename ref_type::size_type i = 0; i < test_ref.size(); i++)
    {
        assert(*test_begin == *ref_begin, "wrong init value");
        test_begin++;
        ref_begin++;
    }
}

template < typename test_type, typename ref_type > void check_with_cap(test_type &test, ref_type &test_ref)
{
    assert(test.capacity() == test_ref.capacity(), "wrong capacity");
    default_check(test, test_ref);
}

template < typename test_type, typename ref_type > void check_pair(test_type &test, ref_type &test_ref)
{
    assert(test.first == test_ref.first, "wrong first check equal");
    assert(test.second == test_ref.second, "wrong second check equal");
}

template < typename test_type, typename ref_type > void check_map(test_type &test, ref_type &test_ref)
{
    typename test_type::iterator b1 = test.begin();
    typename ref_type::iterator b2 = test_ref.begin();

    for (; (b1 != test.end()) && (b2 != test_ref.end()); b1++, (void)b2++)
    {
        assert((*b1).first == (*b2).first, "wrong key");
        assert((*b1).second == (*b2).second, "wrong value");
    }
}

template < typename state_type > int len(state_type state)
{
    int i = 0;
    while (state[i])
        i++;
    return i;
}
} // namespace unittest
#endif
