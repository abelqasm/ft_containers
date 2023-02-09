/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:25:40 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/07 18:00:31 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACK_HPP
#define REDBLACK_HPP

#include <memory>

template <class T>
struct  node
{
    T         _value;
    node      *_left;
    node      *_right;
    node      *_parent;
    bool      _color;
};

namespace ft
{
    template <class T, class Allocator>
    class RedBlackTree
    {
    public:
        typedef T           value_type;
        typedef Allocator   allocator_type;
    private:
        allocator_type  _alloc;
        node<T>         *_root;
        node<T>         *_end;
        node<T>         *_nill;
    public:
        RedBlackTree(node<T> *root = nullptr, allocator_type &alloc = allocator_type()) : _alloc(alloc), _root(root), _nill(nullptr), _end(_root)
        {
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
        void Insertion(node<T> *node)
        {
        }
        void InsertionFixup(node<T> *node)
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
}

#endif