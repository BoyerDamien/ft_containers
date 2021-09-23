/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:01:18 by dess              #+#    #+#             */
/*   Updated: 2021/09/20 12:19:31 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include "test/test_accessors.hpp"
#include "test/test_capacity.hpp"
#include <vector>

/******************************************************************************************
 *                       Types
 ******************************************************************************************/
typedef int type;
typedef ft::vector< type > test_type;
typedef std::vector< type > ref_type;
typedef unittest::state< type, type > state_type;
typedef unittest::Test< test_type, ref_type, state_type > Test;

bool unittest::test_vector(void)
{
    int init[] = {5, 2, 1, 3, 0};
    state_type state(5, init, init);

    const ::Test tests[] = {

        ::Test("test vector intern_type", unittest::test_vector_itern_types, unittest::check_with_cap),
        ::Test("test vector iterator intern_type", unittest::test_random_access_iterator_intern_type,
               unittest::check_with_cap),
        ::Test("test vector default constructor", unittest::test_default_constructor, unittest::check_with_cap),
        ::Test("test vector constructor with size", unittest::test_constructor_size, unittest::check_with_cap, state),
        ::Test("test vector constructor with iterator", unittest::test_constructor_iter, unittest::check_with_cap,
               state),
        ::Test("test vector copy constructor", unittest::test_copy_constructor, unittest::check_with_cap, state),
        ::Test("test vector assignation constructor", unittest::test_assignation_constructor, unittest::check_with_cap,
               state),
        ::Test("test vector begin", unittest::test_begin, unittest::check_with_cap, state),
        ::Test("test vector rbegin", unittest::test_rbegin, unittest::check_with_cap, state),
        ::Test("test vector iterator incrementation/decrementation", unittest::test_iterator_inc_dec,
               unittest::check_with_cap, state),
        ::Test("test vector rev_iterator incrementation/decrementation", unittest::test_rev_iterator_inc_dec,
               unittest::check_with_cap, state),
        ::Test("test vector size()", unittest::test_size, unittest::check_with_cap, state),
        ::Test("test vector max_size()", unittest::test_max_size, unittest::check_with_cap),
        ::Test("test vector capacity()", unittest::test_capacity, unittest::check_with_cap),
        ::Test("test vector empty()", unittest::test_empty, unittest::check_with_cap, state),
        ::Test("test vector resize()", unittest::test_resize, unittest::check_with_cap, state),
        ::Test("test vector reserve()", unittest::test_reserve, unittest::check_with_cap),
        ::Test("test vector front()", unittest::test_front, unittest::check_with_cap, state),
        ::Test("test vector back()", unittest::test_back, unittest::check_with_cap, state),
        ::Test("test vector at()", unittest::test_at, unittest::check_with_cap, state),
        ::Test("test vector operator[]()", unittest::test_operator_access, unittest::check_with_cap, state),
        ::Test("test vector assign()", unittest::test_assign, unittest::check_with_cap, state),
        ::Test("test vector push_back()", unittest::test_push_back, unittest::check_with_cap, state),
        ::Test("test vector pop_back()", unittest::test_pop_back, unittest::check_with_cap, state),
        ::Test("test vector insert()", unittest::test_insert, unittest::check_with_cap, state),
        ::Test("test vector erase()", unittest::test_erase, unittest::check_with_cap, state),
        ::Test("test vector swap()", unittest::test_swap, unittest::check_with_cap, state),
        ::Test("test vector clear()", unittest::test_clear, unittest::check_with_cap, state),
        ::Test("test vector operator<() and operator>()", unittest::test_operator_inf_sup, unittest::check_with_cap,
               state),
        ::Test("test vector operator==()", unittest::test_operator_eq, unittest::check_with_cap, state),
        ::Test("test vector operator!=()", unittest::test_operator_diff, unittest::check_with_cap, state),

    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!tests[i].run())
            return false;
    }
    return true;
}
