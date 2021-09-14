/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:45:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/14 19:29:03 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <iostream>
#include <vector>

int main(void)
{

    int arr[] = {1, 2, 3};
    ft::vector< int > vec(10, 10);

    for (ft::vector< int >::reverse_iterator it = vec.rbegin(); it != vec.rend(); it++)
    {
        std::cout << *it << std::endl;
    }
    return 0;
}
