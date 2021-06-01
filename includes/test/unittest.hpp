/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittest.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:16:41 by dboyer            #+#    #+#             */
/*   Updated: 2021/05/27 09:51:27 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNITTEST_HPP
#define UNITTEST_HPP
#include "./test.hpp"
#include "./test_capacity.hpp"
#include "./test_constructors.hpp"
#include "./test_iterators.hpp"
#include "./test_modifiers.hpp"
#include "./test_operations.hpp"
#include "./test_operators.hpp"
namespace unittest
{

bool test_list(void);
bool test_vector(void);

} // namespace unittest
#endif