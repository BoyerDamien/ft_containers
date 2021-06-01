/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_base.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dess <dboyer@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 10:42:29 by dess              #+#    #+#             */
/*   Updated: 2021/04/14 19:53:15 by dess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_BASE_HPP
#define ITERATOR_BASE_HPP
#include "category.hpp"
#include <cstddef>
#include <iostream>

namespace ft
{
template < typename T, typename N > class iterator_base
{
  public:
	typedef T value_type;
	typedef N node_type;
	typedef iterator_base< value_type, node_type > self;
	typedef value_type *pointer;
	typedef value_type &reference;
	typedef std::ptrdiff_t difference_type;
	typedef size_t size_type;

	iterator_base< value_type, node_type >(node_type *current) : _current(current), _null(current == NULL)
	{
		if (_null)
			_current = new node_type(value_type());
	}

	iterator_base< value_type, node_type >(const self &other) : _current(other._current), _null(other._null)
	{
	}

	virtual ~iterator_base< value_type, node_type >(void)
	{
		if (_null)
			delete _current;
	}

	virtual iterator_base< value_type, node_type > &operator=(const self &other)
	{
		_current = other._current;
		_null = other._null;
		return *this;
	}

	/**************************************************************************
	 *				Getters
	 *************************************************************************/
	node_type *getNode(void) const
	{
		return _current;
	}
	const node_type *getConstNode(void) const
	{
		return static_cast< const node_type * >(_current);
	}

	pointer *operator->(void) const
	{
		return &operator*();
	}

	virtual reference operator*(void) const = 0;
	/**************************************************************************
	 *				Setters
	 *************************************************************************/
	void setCurrent(node_type *current)
	{
		_current = current;
	}
	void setNull(bool val)
	{
		_null = val;
	}

  private:
	node_type *_current;
	bool _null;

	iterator_base< value_type, node_type >(void)
	{
	} // Private default constructor
};

template < typename T, typename N > bool operator==(const iterator_base< T, N > &it1, const iterator_base< T, N > &it2)
{
	return it1.getNode() == it2.getNode();
}

template < typename T, typename N > bool operator!=(const iterator_base< T, N > &it1, const iterator_base< T, N > &it2)
{
	return !(it1 == it2);
}

} // namespace ft
#endif
