/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 14:32:10 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/16 14:37:54 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
#define NODE_HPP


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
        ~node()
        {
        }
    };
}
#endif