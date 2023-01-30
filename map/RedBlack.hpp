/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlack.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:25:40 by abelqasm          #+#    #+#             */
/*   Updated: 2023/01/30 15:54:33 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACK_HPP
#define REDBLACK_HPP

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
    template <class T>
    void RedBlackInsertion(node<T> *root, node<T> *new_node)
    {
    }
    template <class T>
    void RedBlackInsertionFixup(node<T> *root, node<T> *new_node)
    {
    }
}

#endif