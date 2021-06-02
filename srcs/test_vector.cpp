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

bool unittest::test_vector( void )
{
    const ::Test tests[] = {

        ::Test( "test vector default constructor", unittest::test_default_constructor< test_type, ref_type >,
                unittest::check_with_cap ),

        ::Test( "test vector constructor with size", unittest::test_constructor_size< test_type, ref_type >,
                unittest::check_with_cap ),
        ::Test( "test vector constructor with iterator", unittest::test_constructor_iter< test_type, ref_type >,
                unittest::check_with_cap ),

        ::Test( "test vector copy constructor", unittest::test_copy_constructor< test_type, ref_type >,
                unittest::check_with_cap ),
        ::Test( "test vector assignation constructor", unittest::test_assignation_constructor< test_type, ref_type >,
                unittest::check_with_cap ),
        ::Test( "test vector iterator", unittest::test_iterator< test_type, ref_type >, unittest::check_with_cap ),
        ::Test( "test vector reverse iterator", unittest::test_rev_iterator< test_type, ref_type >,
                unittest::check_with_cap ),
        ::Test( "test vector size()", unittest::test_size< test_type, ref_type >, unittest::check_with_cap ),
        ::Test( "test vector max_size()", unittest::test_max_size< test_type, ref_type >, unittest::check_with_cap ),
        ::Test( "test vector clear()", unittest::test_clear< test_type, ref_type >, unittest::check_with_cap ),
        ::Test( "test vector swap()", unittest::test_swap< test_type, ref_type >, unittest::check_with_cap ),
        ::Test( "test vector push_back()", unittest::test_push_back< test_type, ref_type >, unittest::check_with_cap ),
        ::Test( "test vector assign()", unittest::test_assign< test_type, ref_type >, unittest::check_with_cap ),
        ::Test( "test vector resize()", unittest::test_resize< test_type, ref_type >, unittest::check_with_cap ),
        ::Test( "test vector insert()", unittest::test_insert< test_type, ref_type >, unittest::check_with_cap ),
        ::Test( "test vector erase()", unittest::test_erase< test_type, ref_type >, unittest::check_with_cap ),
        ::Test( "test vector pop_back()", unittest::test_pop_back< test_type, ref_type >, unittest::check_with_cap ),
        ::Test( "test vector operator==()", unittest::test_operator_eq< test_type, ref_type >,
                unittest::check_with_cap ),
        ::Test( "test vector operator!=()", unittest::test_operator_diff< test_type, ref_type >,
                unittest::check_with_cap ),
        ::Test( "test vector operator<() and operator>()", unittest::test_operator_inf_sup< test_type, ref_type >,
                unittest::check_with_cap ),
    };

    for ( size_t i = 0; i < sizeof( tests ) / sizeof( tests[ 0 ] ); i++ )
    {
        if ( !tests[ i ].run() )
            return false;
    }
    return true;
}
