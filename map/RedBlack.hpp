/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:25:40 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/11 12:28:28 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACK_HPP
#define REDBLACK_HPP

#include <memory>
#include <iostream>
#include <functional>
#include "../ft/pair.hpp"
#include "../ft/make_pair.hpp"

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
    node                * _right;
    node                *_parent;
    Color               _color;
    
    node(value_type value, node<T> *parent, node<T> *nill): _value(value), _left(nill), _right(nill), _parent(parent), _color(RED)
    {
    }
    ~node()
    {
    }
};

template<class T, class Allocator = std::allocator<node<T> > >
class RedBlackTree
{
public:
    typedef T               value_type;
    typedef Allocator       allocator_type;
private:
    allocator_type      _alloc;
    node<T>             *_root;
    node<T>             *_end;
    node<T>             *_nill;
public:
    RedBlackTree(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _root(), _end(_root)
    {
        _nill = _alloc.allocate(1);
        _alloc.construct(_nill, node<T>(value_type(), nullptr, nullptr));
        _nill->_color = BLACK;
    }
    ~RedBlackTree()
    {
    }
    void LeftRotate(node<T> *node)
    {
    }
    void RightRotate(node<T> *node)
    {
    }
    void Insert(value_type value)
    {
        if (!_root)
        {
            _root = _alloc.allocate(1);
            _alloc.construct(_root, node<T>(value, _nill, _nill));
            _root->_color = BLACK;
            return ;
        }
        node<T> *root = _root;
        node<T> *parent = _nill;
        while (root != _nill)
        {
            parent = root;
            value < root->_value ? root = root->_left : root = root->_right;
            root->_parent = parent;
        }
        root = _alloc.allocate(1);
        _alloc.construct(root, node<T>(value, root->_parent, _nill));
        value < parent->_value ? parent->_left = root : parent->_right = root;
    }
    void InsertFixup(node<T> *node)
    {
    }
    void Deletion(node<T> *node)
    {
    }
    node<T> *getRoot() const
    {
        return _root;
    }
    node<T> *getEnd() const
    {
        return _end;
    }
    node<T> *getNill() const
    {
        return _nill;
    }
};

#endif