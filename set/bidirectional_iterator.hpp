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
#include "./ft/node.hpp"

namespace ft
{
    template<class T>
    class bidirectional_iterator
    {
    public:
        typedef typename ft::iterator_traits<T*>::value_type              value_type;
        typedef typename ft::iterator_traits<T*>::reference               reference;
        typedef typename ft::iterator_traits<T*>::pointer                 pointer;
        typedef typename ft::iterator_traits<T*>::difference_type         difference_type;
        typedef std::bidirectional_iterator_tag                           iterator_category;
        typedef ft::node<value_type>                                      node_type;
    private:
        node_type  *_node;
        node_type  *_nill;

        node_type *maximum(node_type *node) const
        {
            while (node != _nill && node->_right != _nill)
                node = node->_right;
            return node;
        }
    public:
        bidirectional_iterator() : _node(nullptr), _nill(nullptr)
        {
        }
        bidirectional_iterator(node_type *node, node_type *nill) : _node(node), _nill(nill)
        {
        }
        node_type *get() const
        {
            return _node;
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
            if (_node == _nill)
                _node = _nill->_right;
            else if (_node->_left != _nill)
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
            if (_node == _nill)
                _node = _nill->_right;
            else if (_node->_left != _nill)
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
