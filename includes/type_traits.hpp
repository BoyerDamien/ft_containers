/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:59:10 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/14 17:35:34 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterator_traits.hpp"

namespace ft
{
/******************************************************************************
 *                       Enable if
 ******************************************************************************/

/*
 * Allow overload selection at compile time
 * See: https://en.cppreference.com/w/cpp/types/enable_if
 */
template < bool B, class T = void > struct enable_if
{
};

template < class T > struct enable_if< true, T >
{
    typedef T type;
};

/****************************************************************************
 *                  Iterator tag testing
 ***************************************************************************/

template < typename Derived, typename Base > struct is_base_of
{
    template < typename T > struct check
    {
        const static bool value = false;
    };

    template <> struct check< Base * >
    {
        const static bool value = true;
    };

    template <> struct check< void * >
    {
        const static bool value = false;
    };

    const static bool value = check< Derived * >::value;
};

template < typename T, typename U > struct is_type_equal
{
    const static bool value = is_base_of< T, U >::value;
};

template < typename T > struct is_type_equal< T, T >
{
    const static bool value = true;
};

template < typename T > struct is_input_iterator
{
    const static bool value = is_type_equal< T, input_iterator_tag >::value;
};

template < typename T > struct is_output_iterator
{
    const static bool value = is_type_equal< T, output_iterator_tag >::value;
};

template < typename T > struct is_forward_iterator
{
    const static bool value = is_type_equal< T, forward_iterator_tag >::value;
};

template < typename T > struct is_bidirectional_iterator
{
    const static bool value = is_type_equal< T, bidirectional_iterator_tag >::value;
};

template < typename T > struct is_random_access_iterator
{
    const static bool value = is_type_equal< T, random_access_iterator_tag >::value;
};

} // namespace ft
