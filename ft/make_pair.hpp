/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pair.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:12:21 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/16 15:45:07 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "pair.hpp"

namespace ft
{
    template< class T1, class T2 >
    ft::pair<T1, T2> make_pair( T1 t, T2 u )
    {
        return ft::pair<T1, T2>(t, u);
    }
}
