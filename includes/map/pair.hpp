/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 11:23:46 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/04 15:16:15 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft
{

template < typename key_type, typename value_type > struct pair
{
    typedef key_type first_type;
    typedef value_type second_type;
    typedef pair< first_type, second_type > _self;

    first_type first;
    second_type second;

    pair() : first( key_type() ), second( second_type() )
    {
    }

    pair( const _self &other ) : first( other.first ), second( other.second )
    {
    }

    pair( const first_type &first, const second_type &second ) : first( first ), second( second )
    {
    }

    _self operator=( const _self &other )
    {
        first = other.first;
        second = other.second;
        return *this;
    }

    ~pair()
    {
    }
};

template < typename key_type, typename value_type >
bool operator==( const pair< key_type, value_type > &p1, const pair< key_type, value_type > &p2 )
{
    return p1.first == p2.first && p1.second == p2.second;
}

template < typename key_type, typename value_type >
bool operator!=( const pair< key_type, value_type > &p1, const pair< key_type, value_type > &p2 )
{
    return !( p1 == p2 );
}

template < typename key_type, typename value_type >
bool operator<( const pair< key_type, value_type > &p1, const pair< key_type, value_type > &p2 )
{
    return p1.first < p2.first;
}

template < typename key_type, typename value_type >
bool operator<=( const pair< key_type, value_type > &p1, const pair< key_type, value_type > &p2 )
{
    return p1 < p2 || p1 == p2;
}

template < typename key_type, typename value_type >
bool operator>( const pair< key_type, value_type > &p1, const pair< key_type, value_type > &p2 )
{
    return p1.first > p2.first;
}

template < typename key_type, typename value_type >
bool operator>=( const pair< key_type, value_type > &p1, const pair< key_type, value_type > &p2 )
{
    return p1 > p2 || p1 == p2;
}

} // namespace ft

#endif