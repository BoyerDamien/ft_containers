/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unittest.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 14:16:41 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/19 12:54:27 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "test/test.hpp"
#include "test/test_accessors.hpp"
#include "test/test_capacity.hpp"
#include "test/test_constructors.hpp"
#include "test/test_intern_type.hpp"
#include "test/test_iterators.hpp"
#include "test/test_modifiers.hpp"
#include "test/test_operations.hpp"
#include "test/test_operators.hpp"
namespace unittest
{

bool test_vector(void);
bool test_pair(void);
bool test_stack(void);

} // namespace unittest
