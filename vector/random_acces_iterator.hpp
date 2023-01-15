/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_acces_iterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:11:26 by abelqasm          #+#    #+#             */
/*   Updated: 2023/01/15 18:40:42 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "../iterators/iterator_traits.hpp"

namespace ft
{
    template <class T, class pointer = typename iterator_traits<T>::pointer>
    class random_acces_iterator
    {
        private:
            pointer _ptr;
        public:
            typedef typename iterator_traits<T>::difference_type         difference_type;
            typedef typename iterator_traits<T>::value_type              value_type;
            // typedef typename iterator_traits<T>::pointer                 pointer;
            typedef typename iterator_traits<T>::reference               reference;
            typedef typename iterator_traits<T>::iterator_category       iterator_category;
            random_acces_iterator() : _ptr(NULL)
            {
            }
            random_acces_iterator(pointer ptr) : _ptr(ptr)
            {
            }
            random_acces_iterator(const random_acces_iterator& src)
            {
                *this = src;
            }
            ~random_acces_iterator()
            {
            }
            random_acces_iterator& operator=(const random_acces_iterator& rhs)
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
            random_acces_iterator& operator++()
            {
                ++_ptr;
                return *this;
            }
            random_acces_iterator operator++(int)
            {
                random_acces_iterator tmp(*this);
                ++_ptr;
                return tmp;
            }
            random_acces_iterator& operator--()
            {
                --_ptr; return *this;
            }
            random_acces_iterator operator--(int)
            {
                random_acces_iterator tmp(*this);
                --_ptr;
                return tmp;
            }
            random_acces_iterator operator+(difference_type n) const
            {
                return random_acces_iterator(_ptr + n);
            }
            random_acces_iterator operator-(difference_type n) const
            {
                return random_acces_iterator(_ptr - n);
            }
            random_acces_iterator& operator+=(difference_type n)
            {
                _ptr += n;
                return *this;
            }
            random_acces_iterator& operator-=(difference_type n)
            {
                _ptr -= n;
                return *this;
            }
            reference operator[](difference_type n) const
            {
                return _ptr[n];
            }
            bool operator==(const random_acces_iterator& rhs) const
            { 
                return _ptr == rhs._ptr;
            }
            bool operator!=(const random_acces_iterator& rhs) const
            { 
                return _ptr != rhs._ptr;
            }
            bool operator<(const random_acces_iterator& rhs) const
            { 
                return _ptr < rhs._ptr;
            }
            bool operator<=(const random_acces_iterator& rhs) const
            { 
                return _ptr <= rhs._ptr; 
            }
            bool operator>(const random_acces_iterator& rhs) const
            { 
                return _ptr > rhs._ptr;
            }
            bool operator>=(const random_acces_iterator& rhs) const
            { 
                return _ptr >= rhs._ptr;
            }
    };
}

#endif