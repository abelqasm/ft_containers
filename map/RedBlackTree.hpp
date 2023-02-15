/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:25:40 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/15 14:20:40 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACK_HPP
#define REDBLACK_HPP

#include <memory>
#include <iostream>
#include <functional>
#include "../ft/pair.hpp"
#include "../ft/make_pair.hpp"
#include "RedBlackTreeIterator.hpp"

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
    typedef T                                           value_type;
    typedef Allocator                                   allocator_type;
    typedef node<value_type>                            node_type;
    typedef typename allocator_type::size_type          size_type;
    typedef typename allocator_type::reference          reference;
    typedef typename allocator_type::const_reference    const_reference;
    typedef typename allocator_type::pointer            pointer;
    typedef typename allocator_type::const_pointer      const_pointer;
    typedef typename allocator_type::difference_type    difference_type;

    typedef ft::RedBlackTreeIterator<value_type>        iterator;
    typedef ft::RedBlackTreeIterator<const value_type>  const_iterator;
    typedef ft::reverse_iterator<iterator>              reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
private:
    allocator_type        _alloc;
    node_type             *_root;
    node_type             *_end;
    node_type             *_begin;
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
            leftright == LEFT ? leftRotate(*node) : rightRotate(*node);
        }
        (*node)->_parent->_color = BLACK;
        (*grandParent)->_color = RED;
        leftright == LEFT ? rightRotate(*grandParent) : leftRotate(*grandParent);
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
                    node == node->_parent->_left ? node->_parent->_left = transplanteNode : node->_parent->_right = transplanteNode;
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
    // delete fixup helpers
    void siblingRed(node_type **node, node_type **sibling, LeftRight leftright)
    {
        (*sibling)->_color = BLACK;
        (*node)->_parent->_color = RED;
        leftright == RIGHT ? leftRotate((*node)->_parent) : rightRotate((*node)->_parent);
        leftright == RIGHT ? *sibling = (*node)->_parent->_right : *sibling = (*node)->_parent->_left;
    }
    void noRedChild(node_type **node, node_type **sibling)
    {
        (*sibling)->_color = RED;
        (*node) = (*node)->_parent;
    }
    void redChild(node_type **node, node_type **sibling, LeftRight leftright)
    {
        node_type *secondChild;
        leftright == RIGHT ? secondChild = (*sibling)->_left : secondChild = (*sibling)->_right;
        if (secondChild->_color == RED)
        {
            secondChild->_color = BLACK;
            (*sibling)->_color = RED;
            leftright == RIGHT ? rightRotate(*sibling) : leftRotate(*sibling);
            leftright == RIGHT ? *sibling = (*node)->_parent->_right : *sibling = (*node)->_parent->_left;
        }
        (*sibling)->_color = (*node)->_parent->_color;
        (*node)->_parent->_color = BLACK;
        leftright == RIGHT ? (*sibling)->_right->_color = BLACK : (*sibling)->_left->_color = BLACK;
        leftright == RIGHT ? leftRotate((*node)->_parent) : rightRotate((*node)->_parent);
        (*node) = _root;
    }
    void Sibling(node_type **node, LeftRight leftright)
    {
        node_type *sibling;
        leftright == RIGHT ? sibling = (*node)->_parent->_right : sibling = (*node)->_parent->_left;
        sibling->_color == RED ? siblingRed(node, &sibling, leftright) : void();
        sibling->_left->_color == BLACK && sibling->_right->_color == BLACK ? noRedChild(node, &sibling) : redChild(node, &sibling, leftright);
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
    // RedBlackTree(const RedBlackTree &t)
    // {
    //     *this = t;
    // }
    // RedBlackTree &operator=(const RedBlackTree &t)
    // {
    //     if (this == &t)
    //         return ;
    //     clear();
    //     return *this;
    // }
    //destructor
    ~RedBlackTree()
    {
    }
//------------------------------------------------------------------------------------------------
    // left and right rotate
    void leftRotate(node_type *node)
    {
        node_type *rightNode = node->_right;
        node->_right = rightNode->_left;
        rightNode->_left != _nill ? rightNode->_left->_parent = node : 0;
        rightNode->_parent = node->_parent;
        node->_parent == _nill ? _root = rightNode :
                    node == node->_parent->_left ? node->_parent->_left = rightNode : node->_parent->_right = rightNode;
        rightNode->_left = node;
        node->_parent = rightNode;
    }
    void rightRotate(node_type *node)
    {
        node_type *leftNode = node->_left;
        node->_left = leftNode->_right;
        leftNode->_right != _nill ? leftNode->_right->_parent = node : 0;
        leftNode->_parent = node->_parent;
        node->_parent == _nill ? _root = leftNode :
                    node == node->_parent->_right ? node->_parent->_right = leftNode : node->_parent->_left = leftNode;
        leftNode->_right = node;
        node->_parent = leftNode;
    }
//------------------------------------------------------------------------------------------------
    // insert
    void insert(value_type value)
    {
        if (!_root)
        {
            allocateNode(&_root, value);
            _root->_color = BLACK;
            _begin = _end = _root;
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
        value < _begin->_value ? _begin = root : 0;
        value > _end->_value ? _end = root : 0;
        insertFixup(root);
    }
    void insertFixup(node_type *node)
    {
        while (node->_parent->_color == RED)
            node->_parent == node->_parent->_parent->_left ? Parent(&node, LEFT) : Parent(&node, RIGHT);
        _root->_color = BLACK;
    }
    // delete
    void deleteNode(node_type *node)
    {
        node_type   *x;
        Color       yOriginalColor = node->_color;
        node->_left == _nill || node->_right == _nill ? x = hasOneChild(node) : x = hasTwoChild(node, &yOriginalColor);
        if (yOriginalColor == BLACK)
            deleteFixup(x);
    }
    void deleteFixup(node_type *node)
    {
        while (node != _root && node->_color == BLACK)
            node == node->_parent->_left ? Sibling(&node, RIGHT) : Sibling(&node, LEFT);
        node->_color = BLACK;
    }
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
    // traversal
    void inOrderTraversal()
    {
        node_type *root = _root;
        bool flag = false;
        while (root)
        {
            if (!flag)
                root = minimum(root);
            std::cout << root->_value << " ";
            flag = true;
            if (root->_right != _nill)
            {
                root = root->_right;
                flag = false;
            }
            else if (root->_parent != _nill)
            {
                while (root->_parent != _nill && root == root->_parent->_right)
                    root = root->_parent;
                if (root->_parent == _nill)
                    break;
                root = root->_parent;
            }
            else 
                break;
        }
    }
//------------------------------------------------------------------------------------------------
    // clear
    void clear()
    {
        _root = _end = _nill;
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
//------------------------------------------------------------------------------------------------
    // iterators
    iterator begin()
    {
        return iterator(_begin);
    }
    iterator end()
    {
        return iterator(_end);
    }
    reverse_iterator rbegin()
    {
        return reverse_iterator(_end);
    }
    reverse_iterator rend()
    {
        return reverse_iterator(_begin);
    }
    const_iterator begin() const
    {
        return const_iterator(_begin);
    }
    const_iterator end() const
    {
        return const_iterator(_end);
    }
    const_reverse_iterator rbegin() const
    {
        return const_reverse_iterator(_end);
    }
    const_reverse_iterator rend() const
    {
        return const_reverse_iterator(_begin);
    }
};
#endif