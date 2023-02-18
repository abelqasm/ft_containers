/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:02:07 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/18 15:11:21 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map.hpp"
#include <iostream>
#include <vector>
#include <map>

int main()
{
//---------------------------------ft::map-------------------------------------------------
    ft::map<int, int> ft_map;
    std::vector<ft::pair<int, int> > vec(3);

    ft_map.insert(ft::make_pair(10, 20));
    ft_map.insert(ft::make_pair(20, 30));
    ft_map.insert(ft::make_pair(5, 40));
    ft_map.insert(vec.begin(), vec.end());
    std::cout << "ft::map  after insert " << std::endl;
    for (ft::map<int ,int>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
        std::cout << "the key -> " << it->first << " its value " << it->second << "////";
    std::cout << std::endl;
    // ft::map<int, int>::const_iterator it = ft_map.begin();
    // ft::map<int, int>::const_iterator cstIt(it);
    // if (cstIt == it)
    //     std::cout << "cstIt == it" << std::endl;
//-----------------------------------------std::map-----------------------------------------
    std::map<int, int> std_map;
    std::vector<std::pair<int, int> > vec2(3);
    std_map.insert(std::make_pair(10, 20));
    std_map.insert(std::make_pair(20, 30));
    std_map.insert(std::make_pair(5, 40));
    std_map.insert(vec2.begin(), vec2.end());
    std::cout << "std::map  after insert " << std::endl;
    for (std::map<int ,int>::iterator it = std_map.begin(); it != std_map.end(); it++)
        std::cout << "the key -> " << it->first << " its value " << it->second << "////";
    std::map<int, int>::iterator stdIt = std_map.begin();
    std::map<int, int>::const_iterator stdCstIt = stdIt;
    if (stdCstIt == stdIt)
        std::cout << "stdCstIt == stdIt" << std::endl;
    std::cout << std::endl;
}