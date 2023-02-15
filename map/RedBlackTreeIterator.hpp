/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTreeIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:06:43 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/15 18:56:47 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREEITERATOR_HPP
#define REDBLACKTREEITERATOR_HPP

#include "../iterators/iterator_traits.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "RedBlackTree.hpp"

enum Color
{
    RED,
    BLACK
};

template<class T>
struct  node
{
    typedef T              value_type;

    value_type          _value;
    node                *_left;
    node                *_right;
    node                *_parent;
    Color               _color;
    
    node(value_type value, node<T> *nill): _value(value), _left(nill), _right(nill), _parent(nill), _color(RED)
    {
    }
    ~node()
    {
    }
};
    template<class T>
    class RedBlackTreeIterator
    {
    public:
        typedef T                                           value_type;
        typedef node<value_type>                            node_type;
        typedef T&                                          reference;
        typedef T*                                          pointer;
        typedef std::ptrdiff_t                              difference_type;
        typedef std::bidirectional_iterator_tag             iterator_category;
    private:
        node_type  *_node;
        node_type  *_nill;
    public:
        RedBlackTreeIterator() : _node(nullptr), _nill(nullptr)
        {
        }
        RedBlackTreeIterator(node_type *node) : _node(node), _nill(node->_left)
        {
        }
        node_type *get() const
        {
            return _node;
        }
        template<class U>
        RedBlackTreeIterator(const RedBlackTreeIterator<U>& u) : _node(u.getNode), _nill(u.getNill())
        {
        }
        ~RedBlackTreeIterator()
        {
        }
        node_type *getNill() const
        {
            return _nill;
        }
        node_type *getNode() const
        {
            return _node;
        }
        RedBlackTreeIterator& operator=(const RedBlackTreeIterator& rhs)
        {
            _node = rhs._node;
            return *this;
        }
        value_type &operator*() const
        {
            return _node->_value;
        }
        node_type *operator&() const
        {
            return _node;
        }
        value_type operator->() const
        {
            return _node;
        }
        RedBlackTreeIterator& operator++()
        {
            if (_node->_right != _nill)
            {
                _node = _node->_right;
                while (_node->_left != _nill)
                    _node = _node->_left;
            }
            else
            {
                while (_node->_parent != _nill && _node == _node->_parent->_right)
                    _node = _node->_parent;
                _node = _node->_parent;
            }
            return *this;
        }
        RedBlackTreeIterator operator++(int)
        {
            RedBlackTreeIterator tmp(*this);
            if (_node->_right != _nill)
            {
                _node = _node->_right;
                while (_node->_left != _nill)
                    _node = _node->_left;
            }
            else
            {
                while (_node->_parent != _nill && _node == _node->_parent->_right)
                    _node = _node->_parent;
                _node = _node->_parent;
            }
            return tmp;
        }
        RedBlackTreeIterator& operator--()
        {
            if (_node->_left != _nill)
            {
                _node = _node->_left;
                while (_node->_right != _nill)
                    _node = _node->_right;
            }
            else
            {
                while (_node->_parent != _nill && _node == _node->_parent->_left)
                    _node = _node->_parent;
                _node = _node->_parent;
            }
            return *this;
        }
        RedBlackTreeIterator operator--(int)
        {
            RedBlackTreeIterator tmp(*this);
            if (_node->_left != _nill)
            {
                _node = _node->_left;
                while (_node->_right != _nill)
                    _node = _node->_right;
            }
            else
            {
                while (_node->_parent != _nill && _node == _node->_parent->_left)
                    _node = _node->p_arent;
                _node = _node->_parent;
            }
            return tmp;
        }
        bool operator==(const RedBlackTreeIterator& rhs) const
        {
            return _node == rhs.get();
        }
        bool operator!=(const RedBlackTreeIterator& rhs) const
        {
            return _node != rhs.get();
        }
};
#endif