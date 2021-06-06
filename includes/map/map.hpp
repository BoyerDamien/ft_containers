/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 15:07:21 by dboyer            #+#    #+#             */
/*   Updated: 2021/06/06 20:35:41 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include "./bst_element.hpp"
#include "./pair.hpp"
#include "iterators/map_iterator.hpp"
#include "iterators/reverse_iterator.hpp"
#include <functional>
#include <memory>
namespace ft
{

template < typename key, typename T, typename Compare = std::less< key >,
           typename Alloc = std::allocator< ft::pair< key, T > > >
class map
{
  public:
    typedef key key_type;

    typedef T mapped_type;

    typedef Compare key_compare;

    typedef ft::pair< const key_type, mapped_type > value_type;

    typedef Alloc allocator_type;

    typedef typename allocator_type::reference reference;

    typedef typename allocator_type::const_reference const_reference;

    typedef typename allocator_type::pointer pointer;

    typedef typename allocator_type::const_pointer const_pointer;

    typedef typename allocator_type::difference_type difference_type;

    typedef typename allocator_type::size_type size_type;

    typedef ft::bst_element< key_type, mapped_type, allocator_type > node_type;

    typedef map_iterator< key_type, mapped_type > iterator;

    typedef const iterator const_iterator;

    typedef reverse_iterator< iterator > reverse_iterator;

    typedef const reverse_iterator const_reverse_iterator;

    map( const Compare &comp = key_compare(), allocator_type alloc = allocator_type() )
        : _first( new node_type() ), _last( _first )
    {
        (void)comp;
        (void)alloc;
    }

    /*map( iterator first, iterator last, const key_compare &comp = key_compare(),
         allocator_type alloc = allocator_type() )
        : _first( node_type() ), _last( node_type() )
    {
    }*/

    ~map( void )
    {
        delete _first;
    }

    /************************************************************************************
     *          Iterators
     ***********************************************************************************/
    iterator begin( void )
    {
        return iterator( _first );
    }

    const_iterator begin( void ) const
    {
        return const_iterator( _first );
    }

    iterator end( void )
    {
        return iterator( _last );
    }

    const_iterator end( void ) const
    {
        return const_iterator( _last );
    }

    reverse_iterator rbegin( void )
    {
        return reverse_iterator( _last );
    }

    const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator( _last );
    }

  private:
    node_type *_first, *_last;
    size_type _n;
};

} // namespace ft

#endif