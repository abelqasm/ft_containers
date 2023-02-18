/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMap.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 17:02:07 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/18 20:48:46 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map/map.hpp"
#include <iostream>
#include <vector>
#include <map>

int main()
{
//---------------------------------ft::map-------------------------------------------------
    std::cout << "---------------------------------ft::map-------------------------------------------------" << std::endl;
    ft::map<int, int> ft_map;
    std::vector<ft::pair<int, int> > vec(3);

    ft_map.insert(ft::make_pair(10, 20));
    ft_map.insert(ft::make_pair(20, 30));
    ft_map.insert(ft::make_pair(5, 40));
    ft_map.insert(vec.begin(), vec.end());
    std::cout << "ft::map  after insert " << std::endl;
    for (ft::map<int ,int>::iterator it = ft_map.begin(); it != ft_map.end(); it++)
        std::cout << "the key -> " << it->first << " its value " << it->second << std::endl;
    std::cout << std::endl;
    std::cout << "ft::map size after insert " << ft_map.size() << std::endl;
    std::cout << ft_map.find(200)->second << std::endl;
    ft::map<int, int>::const_iterator it = ft_map.begin();
    ft::map<int, int>::const_iterator cstIt(it);
    if (cstIt == it)
        std::cout << "cstIt == it" << std::endl;
//-----------------------------------------std::map-----------------------------------------
    std::cout << "-----------------------------------------std::map-----------------------------------------" << std::endl;
    std::map<int, int> std_map;
    std::vector<std::pair<int, int> > vec2(3);
    std_map.insert(std::make_pair(10, 20));
    std_map.insert(std::make_pair(20, 30));
    std_map.insert(std::make_pair(5, 40));
    std_map.insert(vec2.begin(), vec2.end());
    std::cout << "std::map  after insert " << std::endl;
    for (std::map<int ,int>::iterator it = std_map.begin(); it != std_map.end(); it++)
        std::cout << "the key -> " << it->first << " its value " << it->second << std::endl;
    std::cout << std::endl;
    std::cout << "std::map size after insert " << std_map.size() << std::endl;
    std::cout << std::endl;
}