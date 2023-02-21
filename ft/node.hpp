/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:32:10 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/18 14:45:06 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

enum Color
{
    RED,
    BLACK
};

namespace ft
{
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
        node(const node& rhs): _value(rhs._value), _left(rhs._left), _right(rhs._right), _parent(rhs._parent), _color(rhs._color)
        {
        }
        ~node()
        {
        }
    };
}
