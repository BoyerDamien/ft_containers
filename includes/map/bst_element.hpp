/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst_element.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:30:36 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/20 11:06:38 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "utility.hpp"
#include <iostream>
#include <memory>

namespace ft
{
template < typename T, typename Compare, typename Alloc = std::allocator< T > > class bst_element
{
  protected:
    typedef bst_element< T, Compare, Alloc > node_type;

  public:
    typedef Alloc allocator_type;
    typedef Compare key_compare;
    typedef T value_type;
    typedef value_type *pointer;
    typedef value_type &reference;
    typedef typename allocator_type::difference_type difference_type;
    typedef typename allocator_type::size_type size_type;
    typedef typename value_type::first_type key_type;
    typedef typename value_type::second_type mapped_type;

    /*********************************************************************************
     *                  Constructors
     ********************************************************************************/

    bst_element(allocator_type alloc = allocator_type())
        : _pair(alloc.allocate(1)), _parent(NULL), _right(NULL), _left(NULL)
    {
        alloc.construct(_pair, value_type());
    }

    bst_element(key_type key, mapped_type value, allocator_type alloc = allocator_type())
        : _pair(alloc.allocate(1)), _parent(NULL), _right(NULL), _left(NULL)
    {
        alloc.construct(_pair, value_type(key, value));
    }

    bst_element(value_type pair, allocator_type alloc = allocator_type())
        : _pair(alloc.allocate(1)), _parent(NULL), _right(NULL), _left(NULL)
    {
        alloc.construct(_pair, value_type(pair.first, pair.second));
    }

    bst_element(const bst_element &other, allocator_type alloc = allocator_type())
        : _pair(alloc.allocate(1)), _parent(other._parent), _right(other._right), _left(other._left)
    {
        alloc.construct(_pair, value_type(other._pair->first, other._pair->second));
    }

    bst_element &operator=(const bst_element &other)
    {
        allocator_type alloc = allocator_type();
        alloc.destroy(_pair);
        alloc.construct(_pair, value_type(other._pair->first, other._pair->second));

        _parent = other._parent;
        _right = other._right;
        _left = other._left;
        return *this;
    }

    virtual ~bst_element()
    {
        allocator_type alloc = allocator_type();
        alloc.destroy(_pair);
        alloc.deallocate(_pair, 1);
    }
    /*********************************************************************************
     *                  Getters
     ********************************************************************************/
    node_type *right(void) const
    {
        return _right;
    }

    node_type *left(void) const
    {
        return _left;
    }

    node_type *parent(void) const
    {
        return _parent;
    }

    value_type &getPair(void) const
    {
        return *_pair;
    }

    bool isRightChild() const
    {
        return (_parent && _parent->_right == this && _parent->_left != this);
    }

    bool isLeftChild() const
    {
        return (_parent && _parent->_left == this && _parent->_right != this);
    }
    /*********************************************************************************
     *                  Setters
     ********************************************************************************/

    void setParent(node_type *parent)
    {
        _parent = parent;
    }

    void setRight(node_type *right)
    {
        if (_right)
            _right->setParent(right);
        right->setParent(this);
        _right = right;
    }

    void setLeft(node_type *left)
    {
        if (_left)
            _left->setParent(left);
        left->setParent(this);
        _left = left;
    }

    void setLeftSafe(node_type *left)
    {
        _left = left;
    }
    void setRightSafe(node_type *right)
    {
        _right = right;
    }

    void setChild(node_type *child)
    {
        bool result1 = key_compare()(child->_pair->first, _pair->first);
        bool result2 = key_compare()(_pair->first, child->_pair->first);

        if (!result1 && !result2)
        {
            _pair->second = child->_pair->second;
            delete child;
        }
        else if (result1)
            setLeft(child);
        else if (result2)
            setRight(child);
    }

    void setPair(const value_type pair)
    {
        _pair->first = pair.first;
        _pair->second = pair.second;
    }

    /****************************************************************************
     *                  Operations
     ****************************************************************************/
    node_type *max(node_type *node) const
    {
        if (node && node->_right)
            return max(node->_right);
        return node;
    }

    node_type *min(node_type *node) const
    {
        if (node && node->_left)
            return min(node->_left);
        return node;
    }

    node_type *backNext(node_type *node) const
    {
        if (node && node->_parent && node->_parent->_right == node)
            return backNext(node->_parent);
        if (node && node->_parent && node->_parent->_left == node)
            return node->_parent;
        return node;
    }

    node_type *backPrev(node_type *node) const
    {
        if (node && node->_parent && node->_parent->_left == node)
            return backPrev(node->_parent);
        if (node && node->_parent && node->_parent->_right == node)
            return node->_parent;
        return node;
    }

    node_type *next(void) const
    {
        if (_right)
            return min(_right);
        if (_parent && _parent->_left == this)
            return _parent;
        return backNext(_parent);
    }
    node_type *previous(void) const
    {
        if (_left)
            return max(_left);
        if (_parent && _parent->_right == this)
            return _parent;
        return backPrev(_parent);
    }

    void deleteLeftChild(void)
    {
        if (_left && !_left->_left && !_left->_right)
        {
            delete _left;
            _left = NULL;
        }
        else if (_left && _left->_left && !_left->_right)
        {
            node_type *tmp = _left->_left;
            delete _left;
            _left = tmp;
            _left->setParent(this);
        }
        else if (_left && !_left->_left && _left->_right)
        {
            node_type *tmp = _left->_right;
            delete _left;
            _left = tmp;
            _left->setParent(this);
        }
        else if (_left && _left->_left && _left->_right)
        {
            node_type *tmp = _left->next();
            tmp->setChild(_left->_right);
            tmp->setChild(_left->_left);
            _left = tmp;
            _left->setParent(this);
        }
    }

    void deleteRightChild(void)
    {
        if (_right && !_right->_left && !_right->_right)
        {
            delete _right;
            _right = NULL;
        }
        else if (_right && _right->_left && !_right->_right)
        {
            node_type *tmp = _right->_left;
            delete _right;
            _right = tmp;
            _right->setParent(this);
        }
        else if (_right && !_right->_left && _right->_right)
        {
            node_type *tmp = _right->_right;
            delete _right;
            _right = tmp;
            _right->setParent(this);
        }
        else if (_right && _right->_left && _right->_right)
        {
            node_type *tmp = _right->next();
            tmp->setChild(_right->_right);
            tmp->setChild(_right->_left);
            _right = tmp;
            _right->setParent(this);
        }
    }

  private:
    pointer _pair;
    node_type *_parent, *_right, *_left;
};
} // namespace ft