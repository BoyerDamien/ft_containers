/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:17:50 by dboyer            #+#    #+#             */
/*   Updated: 2021/05/26 11:55:51 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_containers.hpp"

void unittest::assert(bool expr, const std::string &message) throw(std::exception)
{
    if (!expr)
        throw(unittest::FailedException(message));
}