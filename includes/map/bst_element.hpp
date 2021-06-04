/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_element.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 16:23:57 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/04 17:05:05 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_ELEMENT_HPP
#define BST_ELEMENT_HPP
#include "./pair.hpp"
#include <iostream>

namespace ft
{
template < typename key_type, typename mapped_type > struct bst_element
{
    typedef bst_element< key_type, mapped_type > _self;
    typedef ft::pair< key_type, mapped_type > _node_pair;
    typedef _self *pointer;

    _node_pair pair;
    pointer parent;
    pointer right;
    pointer left;

    bst_element() : pair( _node_pair( key_type(), mapped_type() ) ), parent( NULL ), right( NULL ), left( NULL )
    {
    }

    bst_element( key_type key, mapped_type value )
        : pair( _node_pair( key, value ) ), parent( NULL ), right( NULL ), left( NULL )
    {
    }

    bst_element( const _self &other )
        : pair( other.pair ), parent( other.parent ), right( other.right ), left( other.left )
    {
    }

    _self &operator=( const _self &other )
    {
        pair = other.pair;
        parent = other.parent;
        right = other.right;
        left = other.left;
        return *this;
    }

    ~bst_element()
    {
    }
};
} // namespace ft

#endif