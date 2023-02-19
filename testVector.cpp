/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:56:50 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/19 15:08:07 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector/vector.hpp"
#include <iostream>
#include <vector>


int main()
{
    // ----------------------ft::vector--------------------------------

    ft::vector<int> ftvec(5, 10);
    ft::vector<int>::iterator it = ftvec.begin();
    std::string b_string[64] = {                                                                   \
        "uvg6KqtcgduR31n3ajsv", "wbiAcjgojb9JOagZwyMn", "ATZKCzaPOqgkhPjwuGlf",                    \
        "MOhaJs56yjOw8f6nLPRA", "0gyB2Tr42v6awMw2nK7J", "e6GsiLFUuoDpVFEhJKZ1",                    \
        "z0jXAhiV9keBsaLOY0Xf", "P68p2ZAosHJdmoZh1C7N", "Pu3EuZVeY0TCO3ojdK0t",                    \
        "z7jCHMooHCS73M8GygKB", "uT4KoK83JrZxZjkul7ty", "g8gfrZoY5XwfzRusvHvv",                    \
        "7PGmkM0OSRnYREt9mFIP", "q1od7mBIpPEsCtpF9kdw", "XQo0LWId5TdZnLnpUNOb",                    \
        "U0m1R0kFFhAFyS6hmHHw", "K0lPKfxJxIOnE8QB90xn", "cZ5xyQifMJhrKxqBK9A7",                    \
        "cFBiwjfYw7Js6qEGy5Kt", "1tW0KWfXxeFO69tByqcE", "3Fvq9NxBrhPXHe0IlIVx",                    \
        "MSRDjdFRvHAhFGhiMtDe", "zGm2joMh71jQkYzg5L4V", "Mq4RRaeLvSAO0z2ibp8Q",                    \
        "WnLFYnQKP8TNJkqVVbUg", "E98UphbbVSzrW5Mzurmg", "F8HRxeEcaTZDkFPkioij",                    \
        "jmUVl4Q8X5BwVNzXN219", "n7Xp4w4FwzGKit7AI4SO", "4MxXYr6rKOcXLt9UkVd2",                    \
        "4RVTDsADtRyboaai9d29", "XaSqsrrtdhAfFoJIc5KK", "9Z9jdVCrTT09bg348ceb",                    \
        "I6uqLG9dO5mfNdSMwOYm", "UwMTzJPlbnhgwbHpDi6w", "DebjMP9afncYE6GhhO00",                    \
        "YGPuscYDiGfAjY1UWST0", "K6gbvgGjVZgEFUDlkdSk", "8xCBPI0w6TpC0RA62c2W",                    \
        "fYMxkNwmKg3moP8KvD9v", "QpPdhwhEYjIugg3OPcPH", "qQBXjSn43I3EMP54SyxZ",                    \
        "7qvdKwoW1CQEZTWPvuSC", "rCT212rdYO0zTGHXesKg", "dBHvlHsBwcR9MkkenYYG",                    \
        "NQiSlergqR8fVbOeivLj", "xYVqsV147UIe7jVBVwXo", "tcxayO4DdEJ885TbqUMy",                    \
        "9TGSMTD8U8ksRpHqq0cL", "TIJ16jCv9BSUiWvhbF9T", "BM9GL2ig1hePkA6lM6Ck",                    \
        "TfJTYB9JQMU6CGcYg20Q", "Fg6e5YT2FQbpTZNTDqdo", "LI5q6ml40MeE9H1dPb93",                    \
        "OaxJUSm3nYN9Y8Ela7sS", "BgBeODAwXz7xJo50Rwqd", "xdkgKj1dEoJ6zuVhkvvo",                    \
        "olIewtUEvXJgs1lB9bCn", "dTsPDS0x2uXtcgOIJHb8", "DYvJ2phLppGNZKboTBrd",                    \
        "DjNFMtt9PxkzqvWBHI6j", "1Z3YkeTFlPniKnzFhzgu", "76XqQg6hqMf5IXxKPOEs",                    \
        "gzaapTWW7i9EZjjzLeK6"                                                                     \
    };
    ft::vector<std::string> strvec;
    strvec.insert(strvec.end(), b_string[54]);                                                                                    
    std::cout << "----------------------ft::vector----------------------" << ftvec.empty() << std::endl << std::endl << std::endl;
    std::cout << "ft::vector is empty ---> " << ftvec.empty() << std::endl;
    std::cout << "ft::vector size ---> " << ftvec.size() << std::endl;
    std::cout << "ft::vector max_size ---> " << ftvec.max_size() << std::endl;
    std::cout << "dereference iterator ---> "<< *it << std::endl;
    //----------------------ft::erase--------------------------
    it = ftvec.begin() + 1;
    ftvec.erase(it);
    std::cout << "ft::vector after erase a position ---> ";
    for(ft::vector<int>::iterator it = ftvec.begin(); it != ftvec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    ftvec.erase(ftvec.begin() + 1,  ftvec.end() - 1);
    std::cout << "ft::vector after erase a ranged iterator ---> ";
    for(ft::vector<int>::iterator it = ftvec.begin(); it != ftvec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "ft::vector size after erase ---> " << ftvec.size() << std::endl;
    //----------------------ft::insert--------------------------
    ftvec.insert(ftvec.begin(), 1);
    std::cout << "ft::vector after insert a value at the begin---> ";
    for(ft::vector<int>::iterator it = ftvec.begin(); it != ftvec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    ftvec.insert(ftvec.end(), 6);
    ft::vector<int>::iterator ins = ftvec.insert(ftvec.end(), 63);
    std::cout << *ins << std::endl;
    std::cout << "ft::vector after insert a value at the end---> ";
    for(ft::vector<int>::iterator it = ftvec.begin(); it != ftvec.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "ft::vector size after insert ---> " << ftvec.size() << std::endl;
    //----------------------ft::insert m3essba--------------------------
    ft::vector<int> insert;
    insert.insert(insert.begin(), 0, 64);
    insert.insert(insert.end(), 0, 64);
    insert.insert(insert.end(), 10, 64);
    insert.insert(insert.begin(), 5, -1);
    insert.insert(insert.begin() + 1, 1, -9);
    for (ft::vector<int>::iterator it = insert.begin(); it != insert.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "ft::vector after insert m3essba ---> " << std::endl;
    std::cout << std::endl;

    //----------------------ft::assign--------------------------
    ft::vector<int> ftvec2;
    ftvec2.assign(10, 1);
    std::cout << "ft::vector after assign 10 copies of the value 1 ---> ";
    for(ft::vector<int>::iterator it = ftvec2.begin(); it != ftvec2.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    ftvec2.assign(ftvec.begin(), ftvec.end());
    std::cout << "ft::vector after assign the values of ftvec ---> ";
    for(ft::vector<int>::iterator it = ftvec2.begin(); it != ftvec2.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    //----------------------ft::push_back--------------------------
    ft::vector<int> ftvecpush;
    ftvecpush.reserve(16);
    for (int i = 0; i < 5; i++)
        ftvecpush.push_back(i);
    std::cout << "ft::vector after push_back ---> ";
    for(ft::vector<int>::iterator it = ftvecpush.begin(); it != ftvecpush.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
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