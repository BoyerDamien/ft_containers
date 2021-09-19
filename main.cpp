/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:45:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/19 10:29:54 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <iostream>
#include <map>
#include <vector>

int main(void)
{
    ft::pair< const std::string, int > l[] = {
        ft::make_pair< const std::string, int >("c", 3), ft::make_pair< const std::string, int >("e", 5),
        ft::make_pair< const std::string, int >("a", 1), ft::make_pair< const std::string, int >("d", 4),
        ft::make_pair< const std::string >("b", 2),
    };

    ft::map< const std::string, int > m(l, l + sizeof(l) / sizeof(ft::pair< const std::string, int >));

    for (ft::map< const std::string, int >::iterator it = m.begin(); it != m.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl << std::endl;

    for (ft::map< const std::string, int >::reverse_iterator it = m.rbegin(); it != m.rend(); it++)
    {
        std::cout << *it << std::endl;
    }
    m.clear();
    std::cout << "AFTER clear = " << m.size() << std::endl;
    return 0;
}
