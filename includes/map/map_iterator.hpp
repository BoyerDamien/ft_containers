/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 09:33:43 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/23 15:35:05 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "map/bst_element.hpp"
#include "utility.hpp"
#include <cstddef>

namespace ft
{

template < typename T, typename node_type > class map_iterator
{
  protected:
    typedef node_type *node_pointer;

  public:
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef value_type *pointer;
    typedef value_type &reference;
    typedef bidirectional_iterator_tag iterator_category;

    map_iterator(void)
    {
    }

    map_iterator(node_type *current) : _base(current)
    {
    }

    map_iterator(const map_iterator &other) : _base(other._base)
    {
    }

    map_iterator &operator=(const map_iterator &other)
    {
        _base = other._base;
        return *this;
    }

    ~map_iterator(void)
    {
    }

    /**************************************************************************
     *              Getters
     **************************************************************************/
    node_pointer base() const
    {
        return _base;
    }

    /**************************************************************************
     *				Operator overloading
     *************************************************************************/

    map_iterator &operator++(void)
    {
        _base = _base->next();
        return *this;
    }

    map_iterator operator++(int)
    {
        map_iterator tmp = *this;
        _base = _base->next();
        return tmp;
    }
    map_iterator &operator--(void)
    {
        _base = _base->previous();
        return *this;
    }

    map_iterator operator--(int)
    {
        map_iterator tmp = *this;
        _base = _base->previous();
        return tmp;
    }

    reference operator*(void) const
    {
        return _base->getPair();
    }
    pointer operator->(void) const
    {
        return &(this->operator*());
    }

  private:
    node_pointer _base;
};

template < typename T, typename U > map_iterator< T, U > operator+(size_t n, map_iterator< T, U > &it)
{
    return it += n;
}

template < typename T, typename U > map_iterator< T, U > operator-(size_t n, map_iterator< T, U > &it)
{
    return it -= n;
}

template < typename T, typename U > bool operator==(const map_iterator< T, U > &it1, const map_iterator< T, U > &it2)
{
    return it1.base() == it2.base();
}

template < typename T, typename U > bool operator!=(const map_iterator< T, U > &it1, const map_iterator< T, U > &it2)
{
    return !(it1 == it2);
}

} // namespace ft