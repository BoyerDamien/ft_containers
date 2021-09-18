/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 15:06:25 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/18 15:19:57 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "vector/vector.hpp"

namespace ft
{
template < class T, class Container = vector< T > > class stack
{
  public:
    typedef T value_type;
    typedef Container container_type;
    typedef typename Container::size_type size_type;

    /**************************************************************************
     *              Member functions
     *************************************************************************/

    bool empty() const
    {
        return _content.empty();
    }

    size_type size() const
    {
        return _content.size();
    }

    value_type &top()
    {
        return _content.back();
    }

    const value_type &top() const
    {
        return _content.back();
    }

    void push(const value_type &val)
    {
        _content.push_back(val);
    }

    void pop()
    {
        _content.pop_back();
    }

    friend bool operator==(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
    {
        return lhs._container == rhs._container;
    }

    friend bool operator<(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
    {
        return lhs._container < rhs._container;
    }

  private:
    container_type _content;
};

template < class T, class Container >
bool operator!=(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
{
    return !(lhs == rhs);
}

template < class T, class Container >
bool operator<=(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
{
    return !(rhs < lhs);
}

template < class T, class Container > bool operator>(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
{
    return (rhs < lhs);
}

template < class T, class Container >
bool operator>=(const stack< T, Container > &lhs, const stack< T, Container > &rhs)
{
    return !(lhs < rhs);
}
} // namespace ft
