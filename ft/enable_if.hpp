/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enable_if.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:47:11 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/16 15:44:55 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
