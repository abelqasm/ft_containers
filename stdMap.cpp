/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdMap.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:30:42 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/22 11:30:55 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "map/map.hpp"
#include <iostream>
#include <vector>
#include <map>

int main()
{
    //----------------------------------------------------------------------------------std::map----------------------------------------------------------------------------------
    std::cout << "-----------------------------------------std::map-----------------------------------------" << std::endl;
    std::map<int, int> std_map;
    std::vector<std::pair<int, int> > vec2(3);
    //---------------------------------std::insert-------------------------------------------------
    std_map.insert(std::make_pair(10, 20));
    std_map.insert(std::make_pair(20, 30));
    std_map.insert(std::make_pair(5, 40));
    std_map.insert(vec2.begin(), vec2.end());
    std::cout << "std::map  after insert " << std::endl;
    for (std::map<int ,int>::iterator it = std_map.begin(); it != std_map.end(); it++)
        std::cout << "the key -> " << it->first << " its value " << it->second << std::endl;
    std::cout << std::endl;
    //---------------------------------std::size-------------------------------------------------
    std::cout << "std::map size after insert " << std_map.size() << std::endl;
    //---------------------------------std::assignement-------------------------------------------------
    std::map<int, int> std_map2;
    std_map2 = std_map;
    std::cout << "std::map  after assignement " << std::endl;
    for (std::map<int ,int>::iterator it = std_map2.begin(); it != std_map2.end(); it++)
        std::cout << "the key -> " << it->first << " its value " << it->second << std::endl;
    std::cout << std::endl;
}