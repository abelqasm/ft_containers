/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:02:07 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/16 10:57:39 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map.hpp"
#include <iostream>
#include <map>

int main()
{
//---------------------------------ft::map-------------------------------------------------
    ft::map<int, int> ft_map;
    ft_map.insert(ft::make_pair(1, 1));
    ft::map<int ,int>::iterator it = ft_map.begin();
    std::cout << it->first << " " << it->second << std::endl;
//-----------------------------------------std::map-----------------------------------------
    
}