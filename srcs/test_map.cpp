/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:47:10 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/23 16:52:38 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <map>

/******************************************************************************************
 *                       Types
 ******************************************************************************************/

typedef int type;

typedef ft::map< type, type > test_type;
typedef std::map< type, type > ref_type;
typedef unittest::state< ft::pair< type, type >, std::pair< type, type > > state_type;
typedef unittest::Test< test_type, ref_type, state_type > Test;

bool unittest::test_map(void)
{
    ft::pair< type, type > test_state[] = {
        ft::make_pair(5, 5), ft::make_pair(2, 2), ft::make_pair(3, 3),

        ft::make_pair(4, 4), ft::make_pair(1, 1),

        ft::make_pair(0, 0),
    };

    std::pair< type, type > ref_state[] = {
        std::make_pair(5, 5), std::make_pair(2, 2), std::make_pair(3, 3),

        std::make_pair(4, 4), std::make_pair(1, 1),

        std::make_pair(0, 0),
    };

    state_type state(sizeof(test_state) / sizeof(ft::pair< type, type >), test_state, ref_state);

    const ::Test tests[] = {

        ::Test("test map intern_type", unittest::test_map_itern_types, unittest::check_map),
        ::Test("test map iterator intern_type", unittest::test_bidirectional_iterator_intern_type, unittest::check_map),
        ::Test("test map default constructor", unittest::test_default_constructor, unittest::check_map),
        ::Test("test map constructor with iterator", unittest::test_constructor_iter, unittest::check_map, state),
        ::Test("test map copy constructor", unittest::test_copy_constructor, unittest::check_map, state),
        ::Test("test map assignation constructor", unittest::test_assignation_constructor, unittest::check_map, state),
        ::Test("test map begin", unittest::test_begin, unittest::check_map, state),
        ::Test("test map rbegin", unittest::test_rbegin, unittest::check_map, state),
        ::Test("test map iterator incrementation/decrementation", unittest::test_map_iterator_inc_dec,
               unittest::check_map, state),
        ::Test("test map rev_iterator incrementation/decrementation", unittest::test_map_rev_iterator_inc_dec,
               unittest::check_map, state),
        ::Test("test map size()", unittest::test_size, unittest::check_map, state),
        ::Test("test map max_size()", unittest::test_max_size, unittest::check_map, state),
        ::Test("test map empty()", unittest::test_empty, unittest::check_map, state),
        ::Test("test map at()", unittest::test_at, unittest::check_map, state),
        ::Test("test map operator[]()", unittest::test_operator_access, unittest::check_map, state),
        ::Test("test map insert()", unittest::test_insert, unittest::check_map, state),
        ::Test("test map erase()", unittest::test_erase, unittest::check_map, state),
        ::Test("test map swap()", unittest::test_swap, unittest::check_map, state),
        ::Test("test map clear()", unittest::test_clear, unittest::check_map, state),
        ::Test("test map operator<() and operator>()", unittest::test_operator_inf_sup, unittest::check_map, state),
        ::Test("test map operator==()", unittest::test_operator_eq, unittest::check_map, state),
        ::Test("test map operator!=()", unittest::test_operator_diff, unittest::check_map, state),
        ::Test("test map find()", unittest::test_find, unittest::check_map, state),
        ::Test("test map count()", unittest::test_count, unittest::check_map, state),
        ::Test("test map lower_bound()", unittest::test_lower_bound, unittest::check_map, state),
        ::Test("test map upper_bound()", unittest::test_upper_bound, unittest::check_map, state),
        ::Test("test map equal_range()", unittest::test_equal_range, unittest::check_map, state),
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!tests[i].run())
            return false;
    }
    return true;
}