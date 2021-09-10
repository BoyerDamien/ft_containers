/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_traits.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 18:18:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/10 18:19:47 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

/******************************************************************************************
 *                       Types
 ******************************************************************************************/

typedef unittest::Test<test_type, ref_type> Test;

bool
unittest::test_vector(void)
{
  const ::Test tests[] = {

    ::Test("test vector default constructor",
           unittest::test_default_constructor<test_type, ref_type>,
           unittest::check_with_cap),
  };

  for (size_t i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
    if (!tests[i].run())
      return false;
  }
  return true;
}