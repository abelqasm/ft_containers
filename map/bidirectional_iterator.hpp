/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:06:43 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/16 13:16:55 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../iterators/iterator_traits.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "node.hpp"

namespace ft
{
    template<class T>
    class bidirectional_iterator
    {
    public:
        typedef T                                           value_type;
        typedef ft::node<value_type>                        node_type;
        typedef T&                                          reference;
        typedef T*                                          pointer;
        typedef std::ptrdiff_t                              difference_type;
        typedef std::bidirectional_iterator_tag             iterator_category;
    private:
        node_type  *_node;
        node_type  *_nill;
    public:
        bidirectional_iterator() : _node(nullptr), _nill(nullptr)
        {
        }
        bidirectional_iterator(node_type *node) : _node(node), _nill(node->_left)
        {
        }
        template<class U>
        bidirectional_iterator(const bidirectional_iterator<U>& u) : _node(u.getNode()), _nill(u.getNill())
        {
        }
        ~bidirectional_iterator()
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
        bidirectional_iterator& operator=(const bidirectional_iterator& rhs)
        {
            _node = rhs._node;
            return *this;
        }
        value_type &operator*() const
        {
            return _node->_value;
        }
        value_type *operator->() const
        {
            return &_node->_value;
        }
        value_type getValue() const
        {
            return _node->_value;
        }
        bidirectional_iterator& operator++()
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
        bidirectional_iterator operator++(int)
        {
            bidirectional_iterator tmp(*this);
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
        bidirectional_iterator& operator--()
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
        bidirectional_iterator operator--(int)
        {
            bidirectional_iterator tmp(*this);
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
        bool operator==(const bidirectional_iterator& rhs) const
        {
            return _node == rhs.getNode();
        }
        bool operator!=(const bidirectional_iterator& rhs) const
        {
            return _node != rhs.getNode();
        }
    };
    template<class T, class T2>
    bool operator==(const bidirectional_iterator<T>& lhs, const bidirectional_iterator<T2>& rhs)
    {
        return lhs.getNode() == rhs.getNode();
    }
    template<class T, class T2>
    bool operator!=(const bidirectional_iterator<T>& lhs, const bidirectional_iterator<T2>& rhs)
    {
        return lhs.getNode() != rhs.getNode();
    }
}
