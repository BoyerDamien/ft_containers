/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 09:59:10 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/15 10:38:07 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterator_traits.hpp"
#include <typeinfo>

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

/***********************************************************************************
 *                      Integral testing
 **********************************************************************************/

/*
 *       See https://www.cplusplus.com/reference/type_traits/is_integral/
 */
template < bool B, typename T > struct is_integral_type
{
    typedef T type;
    static const bool value = B;
};

template < typename T = void > struct is_integral : is_integral_type< false, T >
{
};

template <> struct is_integral< bool > : is_integral_type< true, bool >
{
};
template <> struct is_integral< char > : is_integral_type< true, char >
{
};
template <> struct is_integral< signed char > : is_integral_type< true, signed char >
{
};
template <> struct is_integral< unsigned char > : is_integral_type< true, unsigned char >
{
};

template <> struct is_integral< wchar_t > : is_integral_type< true, wchar_t >
{
};
template <> struct is_integral< short int > : is_integral_type< true, short int >
{
};

template <> struct is_integral< unsigned short int > : is_integral_type< true, unsigned short int >
{
};
template <> struct is_integral< int > : is_integral_type< true, int >
{
};
template <> struct is_integral< unsigned int > : is_integral_type< true, unsigned int >
{
};
template <> struct is_integral< long int > : is_integral_type< true, long int >
{
};
template <> struct is_integral< long long int > : is_integral_type< true, long long int >
{
};
template <> struct is_integral< unsigned long int > : is_integral_type< true, unsigned long int >
{
};
template <> struct is_integral< unsigned long long int > : is_integral_type< true, unsigned long long int >
{
};
} // namespace ft
