/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 09:33:43 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/17 20:42:09 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "map/bst_element.hpp"
#include "utility.hpp"

namespace ft
{

template < typename node_type >
class map_iterator : public iterator< bidirectional_iterator_tag, typename node_type::value_type >
{
  public:
    typedef typename iterator< bidirectional_iterator_tag, typename node_type::value_type >::value_type value_type;
    typedef typename iterator< bidirectional_iterator_tag, typename node_type::value_type >::difference_type
        difference_type;
    typedef typename iterator< bidirectional_iterator_tag, typename node_type::value_type >::pointer pointer;
    typedef typename iterator< bidirectional_iterator_tag, typename node_type::value_type >::reference reference;
    typedef node_type *node_pointer;
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
    pointer *operator->(void) const
    {
        return &(this->operator*());
    }

  private:
    node_pointer _base;
};

template < typename T > map_iterator< T > operator+(size_t n, map_iterator< T > &it)
{
    return it += n;
}

template < typename T > map_iterator< T > operator-(size_t n, map_iterator< T > &it)
{
    return it -= n;
}

template < typename T > bool operator==(const map_iterator< T > &it1, const map_iterator< T > &it2)
{
    return it1.base() == it2.base();
}

template < typename T > bool operator!=(const map_iterator< T > &it1, const map_iterator< T > &it2)
{
    return !(it1 == it2);
}

} // namespace ft