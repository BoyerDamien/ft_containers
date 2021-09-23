/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:45:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/23 17:22:47 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include "unittest.hpp"
#include <iostream>
#include <map>
#include <vector>

int main(void)
{
    if (unittest::test_vector() && unittest::test_pair() && unittest::test_map() && unittest::test_stack())
        return 0;
    return 1;
}
