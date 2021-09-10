/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 17:15:48 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/10 17:00:22 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_HPP
#define TEST_UTILS_HPP
#include <iostream>

namespace unittest {

void assert(bool expr, const std::string &message);

template <typename test_type, typename ref_type>
void default_check(test_type &test, ref_type &test_ref) {
  typename test_type::iterator test_begin = test.begin();
  typename ref_type::iterator ref_begin = test_ref.begin();

  assert(test.empty() == test_ref.empty(), "empty differs");
  assert(test.size() == test_ref.size(), "wrong size");

  for (typename ref_type::size_type i = 0; i < test_ref.size(); i++) {
    assert(*test_begin == *ref_begin, "wrong init value");
    test_begin++;
    ref_begin++;
  }
}

template <typename test_type, typename ref_type>
void check_with_cap(test_type &test, ref_type &test_ref) {
  //   std::cout << test << std::endl;
  //    std::cout << "My size: " << test.size() << " Real size: " <<
  //    test_ref.size() << std::endl; std::cout << "My capacity: " <<
  //    test.capacity() << " Real capacity: "
  //    << test_ref.capacity() << std::endl;
  assert(test.capacity() == test_ref.capacity(), "wrong capacity");
  default_check(test, test_ref);
}

template <typename test_type, typename ref_type>
void check_pair(test_type &test, ref_type &test_ref) {
  // std::cout << "test_first: " << test.first << " ref_first: " <<
  // test_ref.first << std::endl; std::cout << "test_second: " << test.second <<
  // " ref_second: " << test_ref.second << std::endl;
  assert(test.first == test_ref.first, "wrong first check equal");
  assert(test.second == test_ref.second, "wrong second check equal");
}

}  // namespace unittest
#endif
