/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:15:48 by dboyer            #+#    #+#             */
/*   Updated: 2021/05/31 10:10:47 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP
#include <iostream>

namespace unittest
{

void assert(bool expr, const std::string &message) throw(std::exception);

template < typename test_type, typename ref_type >
void default_check(test_type &test, ref_type &test_ref) throw(std::exception)
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

template < typename test_type, typename ref_type >
void check_with_cap(test_type &test, ref_type &test_ref) throw(std::exception)
{
    std::cout << test << std::endl;
    std::cout << "My size: " << test.size() << " Real size: " << test_ref.size() << std::endl;
    std::cout << "My capacity: " << test.capacity() << " Real capacity: " << test_ref.capacity() << std::endl;
    assert(test.capacity() == test_ref.capacity(), "wrong capacity");
    default_check(test, test_ref);
}

} // namespace unittest
#endif