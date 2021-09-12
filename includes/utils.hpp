/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/10 17:40:22 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/10 23:42:08 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

/******************************************************************************
 *                       Enable if
 ******************************************************************************/
template < bool B, class T = void > struct enable_if
{
};

template < class T > struct enable_if< true, T >
{
    typedef T type;
};

/*******************************************************************************
 *                       Is Integral
 *******************************************************************************/
template < class T, T v > struct integral_constant
{
    static T value = v;
    T operator()()
    {
        return value;
    }
};