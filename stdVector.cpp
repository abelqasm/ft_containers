/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdVector.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 11:31:11 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/22 11:31:40 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"
#include <iostream>
#include <vector>

int main()
{
     //----------------------std::vector--------------------------
    std::vector<int> stdvec(5, 10);
    std::vector<int>::iterator stdit = stdvec.begin();

    std::cout << "----------------------std::vector----------------------" << stdvec.empty() << std::endl << std::endl << std::endl;
    std::cout << "std::vector is empty ---> " << stdvec.empty() << std::endl;
    std::cout << "std::vector size ---> " << stdvec.size() << std::endl;
    std::cout << "std::vector max_size ---> " << stdvec.max_size() << std::endl;
    std::cout << "dereference iterator ---> "<< *stdit << std::endl;
    //---------------------------------std::erase---------------------------------
    stdit = stdvec.begin() + 1;
    stdvec.erase(stdit);
    std::cout << "std::vector after erase a position ---> ";
    for(std::vector<int>::iterator it = stdvec.begin(); it != stdvec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    stdvec.erase(stdvec.begin() + 1,  stdvec.end() - 1);
    std::cout << "std::vector after erase a ranged iterator ---> "; 
    for(std::vector<int>::iterator it = stdvec.begin(); it != stdvec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "std::vector size after erase ---> " << stdvec.size() << std::endl;
    //---------------------------------std::insert---------------------------------
    stdvec.insert(stdvec.begin(), 1);
    std::cout << "std::vector after insert a value at the begin---> ";
    for(std::vector<int>::iterator it = stdvec.begin(); it != stdvec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    stdvec.insert(stdvec.end(), 6);
    std::vector<int>::iterator inss = stdvec.insert(stdvec.end(), 63);
    std::cout << *inss << std::endl;
    std::cout << "std::vector after insert a value at the end---> ";
    for(std::vector<int>::iterator it = stdvec.begin(); it != stdvec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::vector<int>::const_iterator stdcstItr = stdvec.begin();
    // std::vector<int>::iterator stditr = stdcstItr;
    // *stdcstItr = 100;
    stdvec.erase(stdcstItr);
    std::cout << "std::vector size after insert ---> " << stdvec.size() << std::endl;
    //---------------------------------std::assign---------------------------------
    std::vector<int> stdvec2;
    stdvec2.assign(10, 1);
    std::cout << "std::vector after assign 10 copies of the value 1 ---> ";
    for(std::vector<int>::iterator it = stdvec2.begin(); it != stdvec2.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    stdvec2.assign(stdvec.begin(), stdvec.end());
    std::cout << "std::vector after assign the values of stdvec ---> ";
    for(std::vector<int>::iterator it = stdvec2.begin(); it != stdvec2.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    //---------------------------------std::push_back---------------------------------
    stdvec.push_back(5);
    std::cout << "std::vector after push_back 5 ---> ";
    for(std::vector<int>::iterator it = stdvec.begin(); it != stdvec.end(); it++)
        std::cout << *it << " ";
    std::vector<int>::iterator nd = stdvec.end();
    nd--;
    std::cout << "nd afet minus minus ---> " << std::endl;
    std::cout << *nd << std::endl;
    std::vector<int> test;
    std::vector<int>::reference ref = test.back();
    (void)(ref);
    std::cout << std::endl;
}