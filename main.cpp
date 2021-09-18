/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 16:45:01 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/18 10:22:15 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"
#include <iostream>
#include <map>
#include <vector>

int main(void)
{
    ft::map< const std::string, int > m;
    ft::pair< const std::string, int > p = ft::make_pair< const std::string, int >("a", 1);

    ft::pair< const std::string, int > p2 = ft::make_pair< const std::string, int >("b", 2);

    ft::pair< const std::string, int > p3 = ft::make_pair< const std::string, int >("c", 3);

    ft::pair< const std::string, int > p4 = ft::make_pair< const std::string, int >("d", 4);

    m.insert(p3);
    m.insert(p4);
    m.insert(p);
    m.insert(p2);

    for (ft::map< const std::string, int >::iterator it = m.begin(); it != m.end(); it++)
    {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl << std::endl;
    int i = 0;
    for (ft::map< const std::string, int >::reverse_iterator it = m.rbegin(); it != m.rend(); it++)
    {
        std::cout << *it << std::endl;
        i++;
    }
    return 0;
}
