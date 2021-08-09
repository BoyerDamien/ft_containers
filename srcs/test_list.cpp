/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 17:23:11 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/02 14:57:58 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <list>

/******************************************************************************************
 *                       Types
 ******************************************************************************************/
typedef ft::list< int > test_type;
typedef std::list< int > ref_type;
typedef unittest::Test< test_type, ref_type > Test;

/******************************************************************************************
 *                       Tests
 ******************************************************************************************/
bool unittest::test_list( void )
{
    const ::Test tests[] = {

        ::Test( "test list default constructor",
                unittest::test_default_constructor< test_type, ref_type >,
                unittest::default_check ),

        ::Test( "test list constructor with size",
                unittest::test_constructor_size< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list constructor with iterator",
                unittest::test_constructor_iter< test_type, ref_type >,
                unittest::default_check ),

        ::Test( "test list copy constructor",
                unittest::test_copy_constructor< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list assignation constructor",
                unittest::test_assignation_constructor< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list iterator", unittest::test_iterator< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list reverse iterator",
                unittest::test_rev_iterator< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list empty()", unittest::test_empty< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list size()", unittest::test_size< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list max_size()", unittest::test_max_size< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list front()", unittest::test_front< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list back()", unittest::test_back< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list assign()", unittest::test_assign< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list push_front()",
                unittest::test_push_front< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list pop_front()", unittest::test_pop_front< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list push_back()", unittest::test_push_back< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list pop_back()", unittest::test_pop_back< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list insert()", unittest::test_insert< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list erase()", unittest::test_erase< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list swap()", unittest::test_swap< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list resize()", unittest::test_resize< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list clear()", unittest::test_clear< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list splice()", unittest::test_splice< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list remove()", unittest::test_remove< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list remove_if()", unittest::test_remove_if< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list unique()", unittest::test_unique< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list merge()", unittest::test_merge< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list sort()", unittest::test_sort< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list reverse()", unittest::test_reverse< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list operator==()",
                unittest::test_operator_eq< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list operator!=()",
                unittest::test_operator_diff< test_type, ref_type >,
                unittest::default_check ),
        ::Test( "test list operator<() and operator>()",
                unittest::test_operator_inf_sup< test_type, ref_type >,
                unittest::default_check ),
    };

    for ( size_t i = 0; i < sizeof( tests ) / sizeof( tests[ 0 ] ); i++ )
    {
        if ( !tests[ i ].run() )
            return false;
    }
    return true;
}
