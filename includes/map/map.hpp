/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 14:30:47 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/19 20:11:32 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "algorithms.hpp"
#include "bst_element.hpp"
#include "iterators/reverse_iterator.hpp"
#include "map_iterator.hpp"
#include "utility.hpp"
#include <functional>
#include <iostream>
#include <map>
#include <memory>

namespace ft
{

template < typename key, typename T, typename Compare = std::less< key >,
           typename Alloc = std::allocator< ft::pair< const key, T > > >
class map
{
  protected:
    typedef bst_element< const key, T, Compare, Alloc > node_type;

  public:
    typedef key key_type;

    typedef T mapped_type;

    typedef ft::pair< const key_type, mapped_type > value_type;

    typedef Compare key_compare;

    typedef Alloc allocator_type;

    typedef typename allocator_type::reference reference;

    typedef typename allocator_type::const_reference const_reference;

    typedef typename allocator_type::pointer pointer;

    typedef typename allocator_type::const_pointer const_pointer;

    typedef map_iterator< value_type, node_type > iterator;

    typedef map_iterator< const value_type, node_type > const_iterator;

    typedef reverse_iterator< const_iterator > const_reverse_iterator;

    typedef reverse_iterator< iterator > reverse_iterator;

    typedef typename allocator_type::difference_type difference_type;

    typedef typename allocator_type::size_type size_type;

    typedef typename Alloc::template rebind< node_type >::other node_allocator_type;

    /******************************************************************************
     *                  Nested Class
     *****************************************************************************/
    // See https://www.cplusplus.com/reference/map/map/value_comp/
    class value_compare
    {
        friend class map;

      protected:
        Compare comp;
        value_compare(Compare c) : comp(c)
        {
        }

      public:
        typedef bool result_type;
        typedef value_type first_argument_type;
        typedef value_type second_argument_type;
        bool operator()(const value_type &x, const value_type &y) const
        {
            return comp(x.first, y.first);
        }
    };

    /*****************************************************************************
     *                  Constructor
     ****************************************************************************/
    map(const Compare &comp = key_compare(), allocator_type alloc = allocator_type())
        : _root(NULL), _last(new node_type()), _n(0)
    {
        (void)comp;
        (void)alloc;
    }

    template < class InputIterator >
    map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(),
        const allocator_type &alloc = allocator_type())
        : _root(NULL), _last(new node_type()), _n(0)
    {
        insert(first, last);
    }

    map(const map &other) : _root(NULL), _last(new node_type()), _n(0)
    {
        insert(other.begin(), other.end());
    }

    ~map(void)
    {
        clear();
        delete _last;
    }

    /************************************************************************************
     *          Iterators
     ***********************************************************************************/

    iterator begin(void)
    {
        if (_root && _root->left())
            return iterator(_root->min(_root->left()));
        return iterator(_root);
    }

    const_iterator begin(void) const
    {
        if (_root && _root->left())
            return const_iterator(_root->min(_root->left()));
        return const_iterator(_root);
    }

    iterator end(void)
    {
        return iterator(_last);
    }

    const_iterator end(void) const
    {
        return const_iterator(_last);
    }

    reverse_iterator rbegin(void)
    {
        return reverse_iterator(--end());
    }

    const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator(--end());
    }

    reverse_iterator rend(void)
    {
        return reverse_iterator(--begin());
    }

    const_reverse_iterator rend() const
    {
        return const_reverse_iterator(--begin());
    }

    /************************************************************************************
     *          Capacity
     ***********************************************************************************/

    bool empty() const
    {
        return _n == 0;
    }

    size_type size() const
    {
        return _n;
    }

    size_type max_size() const
    {
        return node_allocator_type().max_size();
    }

    /************************************************************************************
     *                      Observers
     ***********************************************************************************/
    key_compare key_comp() const
    {
        return key_compare();
    }

    value_compare value_comp() const
    {
        return value_compare();
    }

    /************************************************************************************
     *                      Modifiers
     ***********************************************************************************/

    ft::pair< iterator, bool > insert(const value_type &val)
    {
        if (!_root)
        {
            _root = new node_type(val.first, val.second);
            _root->setParent(_last);
            _last->setLeftSafe(_root);
            _last->setRightSafe(_root);
            _n++;
            return ft::make_pair< iterator, bool >(iterator(_root), true);
        }
        else
        {
            iterator r = _findLeaf(val.first, _root);
            node_type *child = new node_type(val.first, val.second);
            node_type *parent = r.base();

            parent->setChild(child);

            if (parent && parent->getPair().first != val.first)
            {
                _n++;
                return ft::make_pair< iterator, bool >(iterator(child), true);
            }
            return ft::make_pair< iterator, bool >(iterator(parent), false);
        }
    }

    ft::pair< iterator, bool > insert(iterator position, value_type &val)
    {
        static_cast< void >(position);
        return insert(val);
    }

    template < class InputIterator > void insert(InputIterator first, InputIterator last)
    {
        for (; first != last; first++)
            insert(*first);
    }

    void erase(iterator position)
    {
        if (_n)
        {
            node_type *n = position.base();
            if (n && n->parent())
            {
                node_type *parent = n->parent();
                if (n->isLeftChild())
                    parent->deleteLeftChild();
                else if (n->isRightChild())
                    parent->deleteRightChild();
                else
                {
                    parent->deleteLeftChild();
                    parent->setRightSafe(parent->left());
                    _root = parent->right();
                }
                _n--;
            }
        }
    }

    size_type erase(const key_type &k)
    {
        if (_n)
        {
            iterator f = find(k);
            if (f != end())
            {
                erase(f);
                return 1;
            }
        }
        return 0;
    }

    void erase(iterator first, iterator last)
    {
        if (first != last && _n)
        {
            iterator tmp = iterator(first.base()->next());
            erase(first);
            erase(tmp, last);
        }
    }

    void clear(void)
    {
        erase(begin(), end());
    }

    void swap(map &x)
    {
        ft::swap(_last, x._last);
        ft::swap(_root, x._root);
        ft::swap(_n, x._n);
    }

    /************************************************************************************
     *                      Operations
     ***********************************************************************************/

    iterator find(const key_type &k)
    {
        return _find(k, _root);
    }

    const_iterator find(const key_type &k) const
    {
        return const_iterator(_find(k, _root).base());
    }

    size_type count(const key_type &k) const
    {
        return find(k) != end();
    }

    iterator lower_bound(const key_type &k)
    {
        return _lower(k, _root);
    }

    const_iterator lower_bound(const key_type &k) const
    {
        return const_iterator(lower_bound(k).base());
    }

    iterator upper_bound(const key_type &k)
    {
        return _upper(k, _root);
    }

    const_iterator upper_bound(const key_type &k) const
    {
        return const_iterator(upper_bound(k).base());
    }

    ft::pair< iterator, iterator > equal_range(const key_type &k)
    {
        return ft::pair< iterator, iterator >(lower_bound(k), upper_bound(k));
    }

    ft::pair< const_iterator, const_iterator > equal_range(const key_type &k) const
    {
        return ft::pair< const_iterator, const_iterator >(lower_bound(k), upper_bound(k));
    }

  private:
    node_type *_root, *_last;
    size_type _n;

    /**************************************************************************************
     *              Private member functions
     *************************************************************************************/

    iterator _findLeaf(const key_type &k, node_type *node) const
    {
        if (node && node != _last)
        {
            value_type val = node->getPair();
            bool result_right = key_comp()(val.first, k);
            bool result_left = key_comp()(k, val.first);

            if (!(!result_left && !result_right))
            {
                if (result_left && node->left() && node->left() != _last)
                    return _findLeaf(k, node->left());
                if (result_right && node->right() && node->right() != _last)
                    return _findLeaf(k, node->right());
            }
        }
        return iterator(node);
    }

    iterator _find(const key_type &k, node_type *node) const
    {
        if (node && node != _last)
        {
            value_type val = node->getPair();
            bool result_right = key_comp()(val.first, k);
            bool result_left = key_comp()(k, val.first);

            if (!(!result_left && !result_right))
            {
                if (result_left && node->left() && node->left() != _last)
                    return _find(k, node->left());
                if (result_right && node->right() && node->right() != _last)
                    return _find(k, node->right());
            }
        }
        return iterator(_last);
    }

    iterator _lower(const key_type &k, node_type *node)
    {
        if (node && node != _last && node->left())
        {
            value_type val = node->getPair();
            if (key_comp()(k, val.first) && node->left())
                return _lower(k, node->left());
        }
        return iterator(node);
    }

    iterator _upper(const key_type &k, node_type *node)
    {
        if (node && node != _last && node->right())
        {
            value_type val = node->getPair();
            if (key_comp()(val.first, k) && node->right())
                return _upper(k, node->right());
        }
        return iterator(node);
    }
};

template < class Key, class T, class Compare, class Alloc >
void swap(map< Key, T, Compare, Alloc > &x, map< Key, T, Compare, Alloc > &y)
{
    x.swap(y);
}

template < class Key, class T, class Compare, class Alloc >
bool operator==(const map< Key, T, Compare, Alloc > &lhs, const map< Key, T, Compare, Alloc > &rhs)
{
    return ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template < class Key, class T, class Compare, class Alloc >
bool operator!=(const map< Key, T, Compare, Alloc > &lhs, const map< Key, T, Compare, Alloc > &rhs)
{
    return !(lhs == rhs);
}
template < class Key, class T, class Compare, class Alloc >
bool operator<(const map< Key, T, Compare, Alloc > &lhs, const map< Key, T, Compare, Alloc > &rhs)
{
    return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template < class Key, class T, class Compare, class Alloc >
bool operator<=(const map< Key, T, Compare, Alloc > &lhs, const map< Key, T, Compare, Alloc > &rhs)
{
    return !(rhs < lhs);
}

template < class Key, class T, class Compare, class Alloc >
bool operator>(const map< Key, T, Compare, Alloc > &lhs, const map< Key, T, Compare, Alloc > &rhs)
{
    return rhs < lhs;
}

template < class Key, class T, class Compare, class Alloc >
bool operator>=(const map< Key, T, Compare, Alloc > &lhs, const map< Key, T, Compare, Alloc > &rhs)
{
    return !(lhs < rhs);
}

} // namespace ft