/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_pair.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 14:46:13 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/04 14:56:36 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include "test/test_operators.hpp"
#include "test/test_utils.hpp"
#include <exception>
#include <map>

/******************************************************************************************
 *                       Types
 ******************************************************************************************/
typedef ft::pair< int, int > test_type;
typedef std::pair< int, int > ref_type;
typedef unittest::Test< test_type, ref_type > Test;

/******************************************************************************************
 *                       Tests
 ******************************************************************************************/

bool unittest::test_pair( void )
{
    const ::Test tests[] = {

        ::Test( "test pair default constructor", unittest::test_default_constructor< test_type, ref_type >,
                unittest::check_pair ),

        ::Test( "test pair copy constructor", unittest::test_copy_constructor< test_type, ref_type >,
                unittest::check_pair ),
        ::Test( "test pair assignation constructor", unittest::test_assignation_constructor< test_type, ref_type >,
                unittest::check_pair ),
        ::Test( "test pair operators", unittest::test_pair_operator< test_type, ref_type >, unittest::check_pair ),
    };

    for ( size_t i = 0; i < sizeof( tests ) / sizeof( tests[ 0 ] ); i++ )
    {
        if ( !tests[ i ].run() )
            return false;
    }
    return true;
}
