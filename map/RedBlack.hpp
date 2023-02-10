/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:25:40 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/10 18:34:39 by abelqasm         ###   ########.fr       */
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
    
    node(value_type value): _value(value), _left(), _right(), _parent(), _color(RED)
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
        _alloc.construct(_nill, node<T>(value_type()));
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
            _alloc.construct(_root, node<T>(value));
            _root->_color = BLACK;
            _root->_left = _nill;
            _root->_right = _nill;
            _root->_parent = _nill;
            return ;
        }
        node<T> *root = _root;
        while (root != _nill)
        {
            if (value < root->_value)
                root = root->_left;
            else
                root = root->_right;
        }
        node<T> *newNode = _alloc.allocate(1);
        _alloc.construct(newNode, node<T>(value));
        newNode->_left = _nill;
        newNode->_right = _nill;
        root->_left = newNode;
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