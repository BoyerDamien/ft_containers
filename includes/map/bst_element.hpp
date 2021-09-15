#include "utility.hpp"
#include <iostream>
#include <memory>

namespace ft
{
template < typename key_type, typename mapped_type, typename Compare,
           typename Alloc = std::allocator< ft::pair< key_type, mapped_type > > >
class bst_element
{
  public:
    typedef Alloc allocator_type;
    typedef ft::pair< key_type, mapped_type > value_type;
    typedef Compare key_compare;
    typedef bst_element< key_type, mapped_type, key_compare > *pointer;
    typedef typename allocator_type::pointer pair_pointer;
    typedef typename allocator_type::reference pair_reference;
    typedef typename allocator_type::difference_type pair_difference_type;
    typedef typename allocator_type::size_type pair_size_type;

    /*********************************************************************************
     *                  Constructors
     ********************************************************************************/

    bst_element(allocator_type alloc = allocator_type())
        : _pair(alloc.allocate(1)), _parent(NULL), _right(NULL), _left(NULL), _black(false)
    {
        alloc.construct(_pair, value_type());
    }

    bst_element(key_type key, mapped_type value, allocator_type alloc = allocator_type())
        : _pair(alloc.allocate(1)), _parent(NULL), _right(NULL), _left(NULL), _black(false)
    {
        alloc.construct(_pair, value_type(key, value));
    }

    bst_element(value_type pair, allocator_type alloc = allocator_type())
        : _pair(alloc.allocate(1)), _parent(NULL), _right(NULL), _left(NULL), _black(false)
    {
        alloc.construct(_pair, value_type(pair.first, pair.second));
    }

    bst_element(const bst_element &other, allocator_type alloc = allocator_type())
        : _pair(alloc.allocate(1)), _parent(other._parent), _right(other._right), _left(other._left),
          _black(other._black)
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
        _black = other._black;
        return *this;
    }

    ~bst_element()
    {
        allocator_type alloc = allocator_type();
        alloc.destroy(_pair);
        alloc.deallocate(_pair, 1);
    }
    /*********************************************************************************
     *                  Getters
     ********************************************************************************/
    pointer right(void) const
    {
        return _right;
    }

    pointer left(void) const
    {
        return _left;
    }

    pointer parent(void) const
    {
        return _parent;
    }
    pointer grandParent(void) const
    {
        pointer p = parent();
        if (p)
            return p->parent();
        return NULL;
    }
    pointer uncle(void) const
    {
        pointer gp = grandParent();
        if (gp && gp->left() != this)
            return gp->left();
        if (gp && gp->right() != this)
            return gp->right();
        return NULL;
    }

    value_type &getPair(void) const
    {
        return *_pair;
    }
    /*********************************************************************************
     *                  Setters
     ********************************************************************************/

    void setParent(pointer parent)
    {
        _parent = parent;
    }

    void setRight(pointer right)
    {
        if (_right)
            _right->setParent(right);
        right->setParent(this);
        _right = right;
    }

    void setLeft(pointer left)
    {
        if (_left)
            _left->setParent(left);
        left->setParent(this);
        _left = left;
    }

    void setLeftSafe(pointer left)
    {
        _left = left;
    }
    void setRightSafe(pointer right)
    {
        _right = right;
    }

    void setChild(pointer child)
    {
        bool result1 = key_compare()(child->_pair->first, _pair->first);
        bool result2 = key_compare()(_pair->first, child->_pair->first);

        if (!result1 && !result2)
            _pair->second = child->_pair->second;
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

    void setColor(const bool color)
    {
        _black = color;
    }

    bool black(void) const
    {
        return _black;
    }

  private:
    pair_pointer _pair;
    pointer _parent, _right, _left;
    bool _black;
};
} // namespace ft