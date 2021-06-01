/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_element.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 11:55:10 by dboyer            #+#    #+#             */
/*   Updated: 2021/04/14 18:35:35 by dess             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_ELEMENT_HPP
#define LIST_ELEMENT_HPP
#include "../algorithms/algorithms.hpp"
#include <iostream>
#include <memory>

template < class T, class Alloc = std::allocator< T > > class list_element
{
  public:
    typedef T value_type;

    typedef Alloc allocator_type;

    typedef typename allocator_type::reference reference;

    typedef typename allocator_type::const_reference const_reference;

    typedef typename allocator_type::pointer pointer;

    typedef typename allocator_type::const_pointer const_pointer;

    typedef list_element< value_type, allocator_type > self;

    typedef typename allocator_type::difference_type difference_type;

    typedef typename allocator_type::size_type size_type;

    /*
     *	Constructors
     */

    list_element(const_reference val, allocator_type alloc = allocator_type())
        : _content(alloc.allocate(1)), _next(this), _previous(this)
    {
        alloc.construct(_content, val);
    }

    list_element(const self &other, allocator_type alloc = allocator_type())
        : _content(alloc.allocate(1)), _next(other._next), _previous(other._previous)
    {
        alloc.construct(_content, other._content);
    }

    ~list_element(void)
    {
        allocator_type alloc = allocator_type();
        if (_previous != this)
            _previous->setNext(_next);
        alloc.destroy(_content);
        alloc.deallocate(_content, 1);
    }

    self &operator=(const self &other)
    {
        (void)other;
        return *this;
    }

    /*
     *	Getters
     */
    self *next(void) const
    {
        return _next;
    }
    self *previous(void) const
    {
        return _previous;
    }
    reference getContent(void) const
    {
        return *_content;
    }

    /*
     *	Setters
     */
    void setNext(self *next)
    {
        _next = next;
        next->_previous = this;
    }
    void setNext(const value_type &val)
    {
        setNext(new list_element< value_type >(val));
    }

    void setPrevious(self *previous)
    {
        _previous = previous;
        previous->_next = this;
    }
    void setPrevious(const value_type &val)
    {
        setPrevious(new list_element< value_type >(val));
    }

    void init(void)
    {
        _next = this;
        _previous = this;
    }

  private:
    pointer _content;
    self *_next;
    self *_previous;

    list_element(void)
    {
    }
};

#endif
