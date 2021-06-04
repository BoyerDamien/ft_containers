/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittest.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:16:41 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/04 14:52:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNITTEST_HPP
#define UNITTEST_HPP
#include "./test.hpp"
#include "./test_accessors.hpp"
#include "./test_capacity.hpp"
#include "./test_constructors.hpp"
#include "./test_iterators.hpp"
#include "./test_modifiers.hpp"
#include "./test_operations.hpp"
#include "./test_operators.hpp"
namespace unittest
{

bool test_list( void );
bool test_vector( void );
bool test_pair( void );

} // namespace unittest
#endif