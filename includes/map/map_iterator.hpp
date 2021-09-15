/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/05 09:33:43 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/15 14:28:55 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"
#include "iterator_traits.hpp"
#include "map/bst_element.hpp"
#include "utility.hpp"

namespace ft
{

template < typename node_type > class map_iterator : public iterator< bidirectional_iterator_tag, node_type >
{
  public:
    typedef typename iterator< bidirectional_iterator_tag, node_type >::value_type value_type;
    typedef typename iterator< bidirectional_iterator_tag, node_type >::difference_type difference_type;
    typedef typename iterator< bidirectional_iterator_tag, node_type >::pointer pointer;
    typedef typename iterator< bidirectional_iterator_tag, node_type >::reference reference;
    typedef node_type *node_pointer;
    typedef bidirectional_iterator_tag iterator_category;

    map_iterator(void) : _base(node_pointer(value_type()))
    {
    }
    map_iterator(node_pointer current) : _base(current)
    {
        if (current == NULL)
            _base = node_pointer(value_type());
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
     *				Operator overloading
     *************************************************************************/

    map_iterator &operator++(void)
    {
        _base = _next(_base);
        return *this;
    }

    map_iterator operator++(int)
    {
        map_iterator tmp = *this;
        _base = _next(_base);
        return tmp;
    }
    map_iterator &operator--(void)
    {
        _base = _previous(_base);
        return *this;
    }

    map_iterator operator--(int)
    {
        map_iterator tmp = *this;
        _base = _previous(_base);
        return tmp;
    }

    reference operator*(void) const
    {
        return _base->getPair();
    }

  private:
    node_type *_base;
    node_type *_next(node_type *current, bool down = false, bool up = false, bool left = false, bool right = false)
    {
        node_type *parent = current->parent();
        if (up && (left || (right && !parent)))
            return current;
        if (down && !current->left())
            return current;
        if (down && current->left())
            return _next(current->left(), true, false, true, false);
        if (parent && ((up && right) || (!current->left() && !current->right())))
            return _next(parent, false, true, parent->left() == current, parent->right() == current);
        if (current->right())
            return _next(current->right(), true, false, false, true);
        return current;
    }
    node_type *_previous(node_type *current, bool down = false, bool up = false, bool left = false, bool right = false)
    {
        node_type *parent = current->parent();
        if (up && (right || (left && !parent)))
            return current;
        if (down && !current->right())
            return current;
        if (down && current->right())
            return _previous(current->right(), true, false, false, true);
        if ((left || !current->left()) && up && parent)
            return _previous(parent, false, true, parent->left() == current, parent->right() == current);
        if (((!current->left() && !current->right()) || !current->left()) && parent)
            return _previous(parent, false, true, parent->left() == current, parent->right() == current);
        if (current->left())
            return _previous(current->left(), true, false, true, false);
        return current;
    }
};

} // namespace ft