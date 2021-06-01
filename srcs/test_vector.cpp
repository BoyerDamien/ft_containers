/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 17:01:18 by dess              #+#    #+#             */
/*   Updated: 2021/05/31 10:49:15 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <vector>

/******************************************************************************************
 *                       Types
 ******************************************************************************************/
typedef ft::vector< int > test_type;
typedef std::vector< int > ref_type;
typedef unittest::Test< test_type, ref_type > Test;

/**********************************************************************************
 *                      Constructor tests
 *********************************************************************************/
/*static void test_vector_def_const(void) throw(std::exception)
{
    ft::vector< int > test;
    std::vector< int > test_ref;

    // unittest::test_default_constructor< ft::vector< int >, std::vector< int > >();
    unittest::assert(test.capacity() == test_ref.capacity(), "wrong capacity");
}

static void test_vector_constructor_size(void) throw(std::exception)
{
    ft::vector< int > test(10, 10);
    std::vector< int > test_ref(10, 10);

    unittest::assert(test.capacity() == test_ref.capacity(), "wrong capacity");
    // unittest::test_constructor_size< ft::vector< int >, std::vector< int > >();
}

static void test_vector_constructor_iter(void) throw(std::exception)
{
    ft::vector< int > test_init(3, 3);
    ft::vector< int > test = ft::vector< int >(test_init.begin(), test_init.end());

    std::vector< int > test_ref_init(3, 3);
    std::vector< int > test_ref = std::vector< int >(test_ref_init.begin(), test_ref_init.end());

    unittest::assert(test.capacity() == test_ref.capacity(), "wrong capacity");
    // unittest::test_constructor_iter< ft::vector< int >, std::vector< int > >();
}

static void test_vector_copy_constructor(void) throw(std::exception)
{
    ft::vector< int > test_init(3, 3);
    ft::vector< int > test(test_init);

    std::vector< int > test_ref_init(3, 3);
    std::vector< int > test_ref(test_ref_init);

    unittest::assert(test.capacity() == test_ref.capacity(), "wrong capacity");
    // unittest::test_copy_constructor< ft::vector< int >, std::vector< int > >();
}

static void test_vector_assignation_constructor(void) throw(std::exception)
{
    ft::vector< int > test_init(3, 3);
    ft::vector< int > test = test_init;

    std::vector< int > test_ref_init(3, 3);
    std::vector< int > test_ref = test_ref_init;

    unittest::assert(test.capacity() == test_ref.capacity(), "wrong capacity");
    // unittest::test_copy_constructor< ft::vector< int >, std::vector< int > >();
}*/

/**********************************************************************************
 *                      Modifier tests
 *********************************************************************************/
/*static void inside_test_clear(void) throw(std::exception)
{
    ft::vector< int > test = ft::vector< int >(4, 4);
    std::vector< int > test_ref = std::vector< int >(4, 4);

    test.clear();
    test_ref.clear();

    unittest::assert(test.capacity() == test_ref.capacity(), "wrong capacity");
    // unittest::test_clear< ft::vector< int >, std::vector< int > >();
}

static void inside_test_insert(void) throw(std::exception)
{
    std::vector< int > test_ref(4, 4);
    ft::vector< int > test(4, 4);

    test.insert(test.begin(), 3);
    test_ref.insert(test_ref.begin(), 3);
    unittest::assert(test.capacity() == test_ref.capacity(), "wrong capacity");

    // unittest::test_insert< ft::vector< int >, std::vector< int > >();
}*/

/*static void test_push_back(void) throw(std::exception)
{
    int init[] = {1, 2};
}*/

/*static void test_pop_back(void) throw(std::exception)
{
    int init[] = {1, 2};

    ft::vector< int > l = ft::vector< int >();
    ft::vector< int > final_state = ft::vector< int >(init, init + sizeof(init) / sizeof(int));

    l.push_back(1);
    l.push_back(2);

    unittest::assert(l == final_state, "l && l2 are different");

    l.pop_back();
    unittest::assert(l.size() == 1, "wrong size");
    unittest::assert(l.capacity() == 2, "wrong capacity");
    unittest::assert(l.back() == l.front(), "wrong back and front");

    l.pop_back();
    unittest::assert(l.size() == 0, "wrong size");
    unittest::assert(l.capacity() == 2, "wrong capacity");
    unittest::assert(l.back() == l.front(), "wrong back and front");
}*/

/*static void test_erase(void) throw(std::exception)
{
    int init[] = {1, 2, 3, 4, 5};
    int init2[] = {2, 3, 4};
    ft::vector< int > v = ft::vector< int >(init, init + sizeof(init) / sizeof(int));
    ft::vector< int > final_state = ft::vector< int >(init2, init2 + sizeof(init2) / sizeof(int));

    v.erase(v.begin());

    unittest::assert(v.size() == 4, "wrong vector size");
    unittest::assert(v.capacity() == 5, "wrong vector capacity");
    unittest::assert(v.front() == 2, "wrong vector front");
    unittest::assert(v.back() == 5, "wrong vector back");

    v.erase(--v.end());
    unittest::assert(v == final_state, "wrong final state");

    std::cout << v << std::endl;

    v.erase(v.begin(), v.end());
    std::cout << v << std::endl;
}*/

/*static void test_swap(void) throw(std::exception)
{
    int init[] = {1, 2, 3, 4, 5, 0};
    ft::vector< int > v1;
    ft::vector< int > v2;

    v1.insert(v1.begin(), init, &init[5]);
    v2.insert(v2.end(), init, &init[5]);
}*/

bool unittest::test_vector(void)
{
    const ::Test tests[] = {

        ::Test("test vector default constructor", unittest::test_default_constructor< test_type, ref_type >,
               unittest::check_with_cap),

        ::Test("test vector constructor with size", unittest::test_constructor_size< test_type, ref_type >,
               unittest::check_with_cap),
        ::Test("test vector constructor with iterator", unittest::test_constructor_iter< test_type, ref_type >,
               unittest::check_with_cap),

        ::Test("test vector copy constructor", unittest::test_copy_constructor< test_type, ref_type >,
               unittest::check_with_cap),
        ::Test("test vector assignation constructor", unittest::test_assignation_constructor< test_type, ref_type >,
               unittest::check_with_cap),
        ::Test("test vector iterator", unittest::test_iterator< test_type, ref_type >, unittest::check_with_cap),
        ::Test("test vector reverse iterator", unittest::test_rev_iterator< test_type, ref_type >,
               unittest::check_with_cap),
        ::Test("test vector size()", unittest::test_size< test_type, ref_type >, unittest::check_with_cap),
        ::Test("test vector max_size()", unittest::test_max_size< test_type, ref_type >, unittest::check_with_cap),
        ::Test("test vector clear()", unittest::test_clear< test_type, ref_type >, unittest::check_with_cap),
        ::Test("test vector swap()", unittest::test_swap< test_type, ref_type >, unittest::check_with_cap),
        ::Test("test vector push_back()", unittest::test_push_back< test_type, ref_type >, unittest::check_with_cap),
        ::Test("test vector assign()", unittest::test_assign< test_type, ref_type >, unittest::check_with_cap),
        ::Test("test vector resize()", unittest::test_resize< test_type, ref_type >, unittest::check_with_cap),
        ::Test("test vector insert()", unittest::test_insert< test_type, ref_type >, unittest::check_with_cap),
        ::Test("test vector erase()", unittest::test_erase< ::test_type, ::ref_type >, unittest::check_with_cap),
        ::Test("test vector pop_back()", unittest::test_pop_back< test_type, ref_type >, unittest::check_with_cap),
        ::Test("test vector operator==()", unittest::test_operator_eq< test_type, ref_type >, unittest::check_with_cap),
        ::Test("test vector operator!=()", unittest::test_operator_diff< test_type, ref_type >,
               unittest::check_with_cap),
        ::Test("test vector operator<() and operator>()", unittest::test_operator_inf_sup< test_type, ref_type >,
               unittest::check_with_cap),
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++)
    {
        if (!tests[i].run())
            return false;
    }
    return true;
}
