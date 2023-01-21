/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:47:11 by abelqasm          #+#    #+#             */
/*   Updated: 2023/01/16 15:12:16 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENABLE_IF_HPP
#define ENABLE_IF_HPP

namespace ft
{
    template< bool B, class T = void >
    struct enable_if
    {
    };
    template< class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };
}

#endif