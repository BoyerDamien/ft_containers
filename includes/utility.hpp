/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:42:31 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/15 14:42:35 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

namespace ft
{

template < typename key_type, typename mapped_type > struct pair
{
    typedef key_type first_type;
    typedef mapped_type second_type;
    typedef pair< first_type, second_type > _self;

    first_type first;
    second_type second;

    pair() : first(key_type()), second(second_type())
    {
    }

    pair(const _self &other) : first(other.first), second(other.second)
    {
    }

    pair(const first_type &first, const second_type &second) : first(first), second(second)
    {
    }

    _self &operator=(const _self &other)
    {
        first = other.first;
        second = other.second;
        return *this;
    }

    ~pair()
    {
    }
};

template < typename key_type, typename mapped_type >
bool operator==(const pair< key_type, mapped_type > &p1, const pair< key_type, mapped_type > &p2)
{
    return p1.first == p2.first && p1.second == p2.second;
}

template < typename key_type, typename mapped_type >
bool operator!=(const pair< key_type, mapped_type > &p1, const pair< key_type, mapped_type > &p2)
{
    return !(p1 == p2);
}

template < typename key_type, typename mapped_type >
bool operator<(const pair< key_type, mapped_type > &p1, const pair< key_type, mapped_type > &p2)
{
    return p1.first < p2.first;
}

template < typename key_type, typename mapped_type >
bool operator<=(const pair< key_type, mapped_type > &p1, const pair< key_type, mapped_type > &p2)
{
    return !(p2 < p1) || p1 == p2;
}

template < typename key_type, typename mapped_type >
bool operator>(const pair< key_type, mapped_type > &p1, const pair< key_type, mapped_type > &p2)
{
    return p1.first > p2.first;
}

template < typename key_type, typename mapped_type >
bool operator>=(const pair< key_type, mapped_type > &p1, const pair< key_type, mapped_type > &p2)
{
    return p1 > p2 || p1 == p2;
}

template < typename key_type, typename mapped_type >
std::ostream &operator<<(std::ostream &os, const ft::pair< key_type, mapped_type > &p)
{
    return os << "(" << p.first << ", " << p.second << ")";
}

template < class T1, class T2 > ft::pair< T1, T2 > make_pair(T1 t, T2 u)
{
    return ft::pair< T1, T2 >(t, u);
}
} // namespace ft