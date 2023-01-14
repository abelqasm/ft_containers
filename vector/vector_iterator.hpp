/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:11:26 by abelqasm          #+#    #+#             */
/*   Updated: 2023/01/14 17:36:44 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
    template <class T>
    class vector_iterator : public ft::iterator_traits<T>
    {
        private:
            pointer _ptr;
        public:
            vector_iterator() : _ptr(NULL)
            {
            }
            vector_iterator(pointer ptr) : _ptr(ptr)
            {
            }
            vector_iterator(const vector_iterator& src)
            {
                *this = src;
            }
            ~vector_iterator() {}

            vector_iterator& operator=(const vector_iterator& rhs)
            {
                if (this != &rhs)
                    _ptr = rhs._ptr;
                return *this;
            }

            reference operator*() const
            {
                return *_ptr;
            }
            pointer operator->() const
            {
                return _ptr;
            }
            vector_iterator& operator++()
            {
                ++_ptr;
                return *this;
            }
            vector_iterator operator++(int)
            {
                vector_iterator tmp(*this);
                ++_ptr;
                return tmp;
            }
            vector_iterator& operator--()
            {
                --_ptr; return *this;
            }
            vector_iterator operator--(int)
            {
                vector_iterator tmp(*this);
                --_ptr;
                return tmp;
            }
            vector_iterator operator+(difference_type n) const
            {
                return vector_iterator(_ptr + n);
            }
            vector_iterator operator-(difference_type n) const
            {
                return vector_iterator(_ptr - n);
            }
            vector_iterator& operator+=(difference_type n)
            {
                _ptr += n;
                return *this;
            }
            vector_iterator& operator-=(difference_type n)
            {
                _ptr -= n;
                return *this;
            }
            reference operator[](difference_type n) const
            {
                return _ptr[n];
            }
            bool operator==(const vector_iterator& rhs) const
            { 
                return _ptr == rhs._ptr;
            }
            bool operator!=(const vector_iterator& rhs) const
            { 
                return _ptr != rhs._ptr;
            }
            bool operator<(const vector_iterator& rhs) const
            { 
                return _ptr < rhs._ptr;
            }
            bool operator<=(const vector_iterator& rhs) const
            { 
                return _ptr <= rhs._ptr; 
            }
            bool operator>(const vector_iterator& rhs) const
            { 
                return _ptr > rhs._ptr;
            }
            bool operator>=(const vector_iterator& rhs) const
            { 
                return _ptr >= rhs._ptr;
            }
    };
}

#endif