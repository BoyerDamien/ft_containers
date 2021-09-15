/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:45:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/15 15:09:04 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <iostream>
#include <map>
#include <vector>

int main(void)
{
    ft::map< const std::string, int > m;
    ft::pair< const std::string, int > p = ft::make_pair< const std::string, int >("ok", 1);
    m.insert(p);

    std::cout << *m.begin() << std::endl;

    return 0;
}
