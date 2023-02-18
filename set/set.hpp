/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:22:48 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/18 14:01:55 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../ft/enable_if.hpp"
#include <memory>
#include <functional>

namespace ft
{
    template< class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
    class set
    {    
    };
}
