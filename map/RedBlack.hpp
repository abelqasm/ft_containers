/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:25:40 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/14 13:56:10 by abelqasm         ###   ########.fr       */
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

enum LeftRight
{
    LEFT,
    RIGHT
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

template<class T, class Allocator = std::allocator<node<T> > >
class RedBlackTree
{
public:
    typedef T                       value_type;
    typedef Allocator               allocator_type;
    typedef node<value_type>        node_type;
private:
    allocator_type        _alloc;
    node_type             *_root;
    node_type             *_end;
    node_type             *_nill;

//------------------------------------------------------------------------------------------------
    // allocate node and construct it
    void allocateNode(node_type **locatedNode, value_type value)
    {
        *locatedNode = _alloc.allocate(1);
        _alloc.construct(*locatedNode, node_type(value, _nill));
    }
    // deallocate node and destroy it
    void deallocateNode(node_type *node)
    {
        _alloc.destroy(node);
        _alloc.deallocate(node, 1);
    }
//------------------------------------------------------------------------------------------------
    // insert fixup helpers
    void uncleRed(node_type **node, node_type **uncle, node_type **grandParent)
    {
        (*node)->_parent->_color = BLACK;
        (*uncle)->_color = BLACK;
        (*grandParent)->_color = RED;
        (*node) = (*grandParent);
    }
    void uncleBlack(node_type **node, node_type **grandParent, LeftRight leftright)
    {
        if (((*node) == (*node)->_parent->_right && leftright == LEFT) || ((*node) == (*node)->_parent->_left && leftright == RIGHT))
        {
            (*node) = (*node)->_parent;
            leftright == LEFT ? LeftRotate(*node) : RightRotate(*node);
        }
        (*node)->_parent->_color = BLACK;
        (*grandParent)->_color = RED;
        leftright == LEFT ? RightRotate(*grandParent) : LeftRotate(*grandParent);
    }
    void Parent(node_type **node, LeftRight leftright)
    {
        node_type *uncle;
        node_type *grandParent = (*node)->_parent->_parent;
        leftright == LEFT ? uncle = (*node)->_parent->_parent->_right : uncle = (*node)->_parent->_parent->_left;
        uncle->_color == RED ? uncleRed(node, &uncle, &grandParent): uncleBlack(node, &grandParent, leftright); 
    }
//------------------------------------------------------------------------------------------------
    // delete helpers
    void transplant(node_type *node, node_type *transplanteNode)
    {
        node->_parent == _nill ? _root = transplanteNode :
                    (node == node->_parent->_left ? node->_parent->_left = transplanteNode : node->_parent->_right = transplanteNode);
        transplanteNode->_parent = node->_parent;
    }
    node_type *hasOneChild(node_type *node)
    {
        node->_left == _nill ? transplant(node, node->_right) : transplant(node, node->_left);
        return node->_left == _nill ? node->_right : node->_left;
    }
    node_type *hasTwoChild(node_type *node, Color *yOriginalColor)
    {
        node_type *y = minimum(node->_right);
        node_type *x;
        y = minimum(node->_right);
        *yOriginalColor = y->_color;
        x = y->_right;
        if (y != node->_right)
        {
            transplant(y, y->_right);
            y->_right = node->_right;
            y->_right->_parent = y;
        }
        else
            x->_parent = y;
        transplant(node, y);
        y->_left = node->_left;
        y->_left->_parent = y;
        y->_color = node->_color;
        return x;
    }
//------------------------------------------------------------------------------------------------
    node_type *minimum(node_type *node)
    {
        while (node->_left != _nill)
            node = node->_left;
        return node;
    }
    node_type *maximum(node_type *node)
    {
        while (node->_right != _nill)
            node = node->_right;
        return node;
    }
public:
//------------------------------------------------------------------------------------------------
    //constructors
    RedBlackTree(const allocator_type &alloc = allocator_type()) : _alloc(alloc), _root(), _end(_root)
    {
        _nill = _alloc.allocate(1);
        _alloc.construct(_nill, node_type(value_type(), nullptr));
        _nill->_color = BLACK;
    }
    //destructor
    ~RedBlackTree()
    {
    }
//------------------------------------------------------------------------------------------------
    // left and right rotate
    void LeftRotate(node_type *node)
    {
        node_type *rightNode = node->_right;
        node->_right = rightNode->_left;
        rightNode->_left != _nill ? rightNode->_left->_parent = node : 0;
        rightNode->_parent = node->_parent;
        node->_parent == _nill ? _root = rightNode :
                    (node == node->_parent->_left ? node->_parent->_left = rightNode : node->_parent->_right = rightNode);
        rightNode->_left = node;
        node->_parent = rightNode;
    }
    void RightRotate(node_type *node)
    {
        node_type *leftNode = node->_left;
        node->_left = leftNode->_right;
        leftNode->_right != _nill ? leftNode->_right->_parent = node : 0;
        leftNode->_parent = node->_parent;
        node->_parent == _nill ? _root = leftNode :
                    (node == node->_parent->_right ? node->_parent->_right = leftNode : node->_parent->_left = leftNode);
        leftNode->_right = node;
        node->_parent = leftNode;
    }
//------------------------------------------------------------------------------------------------
    // insert
    void Insert(value_type value)
    {
        if (!_root)
        {
            allocateNode(&_root, value);
            _root->_color = BLACK;
            return;
        }
        node_type *root = _root;
        node_type *parent = _nill;
        while (root != _nill) 
        {
            parent = root;
            value < root->_value ? root = root->_left : root = root->_right;
        }
        allocateNode(&root, value);
        root->_parent = parent;
        value < parent->_value ? parent->_left = root : parent->_right = root;
        InsertFixup(root);
    }
    void InsertFixup(node_type *node)
    {
        while (node->_parent->_color == RED)
            node->_parent == node->_parent->_parent->_left ? Parent(&node, LEFT) : Parent(&node, RIGHT);
        _root->_color = BLACK;
    }
    // delete
    void Delete(node_type *node)
    {
        node_type   *x;
        Color       yOriginalColor = node->_color;
        node->_left == _nill || node->_right == _nill ? x = hasOneChild(node) : x = hasTwoChild(node, &yOriginalColor);
        // if (yOriginalColor == BLACK)
        //     DeleteFixup(x);
    }
    void DeleteFixup(node_type *node);
    node_type *find(value_type value)
    {
        node_type *root = _root;
        while (root != _nill)
        {
            if (root->_value == value)
                return root;
            value < root->_value ? root = root->_left : root = root->_right;
        }
        return _nill;
    }
//------------------------------------------------------------------------------------------------
    // getters functions
    node_type *getRoot() const
    {
        return _root;
    }
    node_type *getEnd() const
    {
        return _end;
    }
    node_type *getNill() const
    {
        return _nill;
    }
};

#endif