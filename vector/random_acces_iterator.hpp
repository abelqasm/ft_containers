/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_acces_iterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:11:26 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/20 11:39:27 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../iterators/iterator_traits.hpp"

namespace ft
{
    template <class T>
    class random_acces_iterator
    {
    public:
            typedef typename ft::iterator_traits<T>::difference_type         difference_type;
            typedef typename ft::iterator_traits<T>::value_type              value_type;
            typedef typename ft::iterator_traits<T>::pointer                 pointer;
            typedef typename ft::iterator_traits<T>::reference               reference;
            typedef typename std::random_access_iterator_tag                 iterator_category;
    private:
            pointer _ptr;
    public:
            random_acces_iterator() : _ptr(nullptr)
            {
            }
            random_acces_iterator(pointer ptr) : _ptr(ptr)
            {
            }
            pointer get() const
            {
                return _ptr;
            }
            template <class U>
            random_acces_iterator(const random_acces_iterator<U>& u) : _ptr(u.get())
            {
            }
            ~random_acces_iterator()
            {
            }
            random_acces_iterator& operator=(const random_acces_iterator& rhs)
            {
                _ptr = rhs._ptr;
                return *this;
            }
            reference operator*() const
            {
                return *_ptr;
            }
            T operator->() const
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
            reference operator[](difference_type n) const
            {
                return _ptr[n];
            }
            random_acces_iterator operator+(difference_type n) const
            {
                return random_acces_iterator(_ptr + n);
            }
            random_acces_iterator operator-(difference_type n) const
            {
                return random_acces_iterator(_ptr - n);
            }
            difference_type operator-(const random_acces_iterator& y) const
            {
                return _ptr -  y._ptr;
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
        template <class T>
        typename random_acces_iterator<T>::difference_type operator-(const random_acces_iterator<T>& x, const random_acces_iterator<T>& y)
        {
            return y.get() - x.get();
        }
        template <class T>
        random_acces_iterator<T> operator+(typename random_acces_iterator<T>::difference_type n, const random_acces_iterator<T>& it)
        {
            return it + n;
        }
        template <class T, class T2> 
        bool operator==(const random_acces_iterator<T> &lhs, const random_acces_iterator<T2> &rhs)
        { 
            return lhs.get() == rhs.get();
        }
        template <class T, class T2> 
        bool operator!=(const random_acces_iterator<T> &lhs, const random_acces_iterator<T2> &rhs)
        { 
            return lhs.get() != rhs.get();
        }
        template <class T, class T2> 
        bool operator<(const random_acces_iterator<T> &lhs, const random_acces_iterator<T2> &rhs)
        { 
            return lhs.get() < rhs.get();
        }
        template <class T, class T2> 
        bool operator>(const random_acces_iterator<T> &lhs, const random_acces_iterator<T2> &rhs)
        { 
            return lhs.get() > rhs.get();
        }
        template <class T, class T2> 
        bool operator>=(const random_acces_iterator<T> &lhs, const random_acces_iterator<T2> &rhs)
        { 
            return lhs.get() >= rhs.get();
        }
        template <class T, class T2> 
        bool operator<=(const random_acces_iterator<T> &lhs, const random_acces_iterator<T2> &rhs)
        { 
            return lhs.get() <= rhs.get();
        }
}

