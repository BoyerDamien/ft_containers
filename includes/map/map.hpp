/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:07:21 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/04 17:22:05 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include "./bst_element.hpp"
#include "./pair.hpp"
#include <functional>
#include <memory>
namespace ft
{

template < typename key, typename T, typename Compare = std::less< key >,
           typename Alloc = std::allocator< ft::pair< key, T > > >
class Map
{
  public:
    typedef key key_type;

    typedef T mapped_type;

    typedef ft::pair< const key_type, mapped_type > value_type;

    typedef Alloc allocator_type;

    typedef typename allocator_type::reference reference;

    typedef typename allocator_type::const_reference const_reference;

    typedef typename allocator_type::pointer pointer;

    typedef typename allocator_type::const_pointer const_pointer;

    typedef typename allocator_type::difference_type difference_type;

    typedef typename allocator_type::size_type size_type;

    typedef Compare key_compare;

    typedef ft::bst_element< key_type, mapped_type > node_type;

    // typedef iterator ?
    // typedef const_iterator ?
    // typedef reverse_iterator ?
    // typedef cons_reverse_iterator ?
};

} // namespace ft

#endif