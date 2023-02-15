/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:52:09 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/15 16:18:13 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft
{
        template <class Iterator>
        class reverse_iterator
        {
            protected:
                Iterator current;
            public:
                typedef typename iterator_traits<Iterator>::difference_type         difference_type;
                typedef typename iterator_traits<Iterator>::value_type              value_type;
                typedef typename iterator_traits<Iterator>::pointer                 pointer;
                typedef typename iterator_traits<Iterator>::reference               reference;
                typedef typename iterator_traits<Iterator>::iterator_category       iterator_category;

                
                reverse_iterator() : current(Iterator())
                {
                }
                explicit reverse_iterator(Iterator x) : current(x)
                {
                }
                template <class U>
                reverse_iterator(const reverse_iterator<U>& u) : current(u.base())
                {
                }
                reverse_iterator& operator=(const reverse_iterator& x)
                {
                    current = x.current;
                    return *this;
                }
                Iterator base() const
                {
                    return current;
                }
                reference operator*() const
                {
                    Iterator tmp = current;
                    return *--tmp;
                }
                pointer operator->() const
                {
                    return &(operator*());
                }
                reverse_iterator& operator++()
                {
                    --current;
                    return *this;
                }
                reverse_iterator operator++(int)
                {
                    reverse_iterator tmp(*this);
                    --current;
                    return tmp;
                }
                reverse_iterator& operator--()
                {
                    ++current;
                    return *this;
                }
                reverse_iterator operator--(int)
                {
                    reverse_iterator tmp(*this);
                    ++current;
                    return tmp;
                }
                reference operator[](difference_type n) const
                {
                    return this->current[-n - 1];
                }
                reverse_iterator operator+ (difference_type n) const
                {
                    return reverse_iterator(current - n);
                }
                reverse_iterator& operator+=(difference_type n)
                {
                    current-=n;
                    return *this;
                }
                reverse_iterator operator- (difference_type n) const
                {
                    return reverse_iterator(current + n);
                }
                reverse_iterator& operator-=(difference_type n)
                {
                    current+=n;
                    return *this;   
                }
        };
        template <class Iterator>
        typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x, const reverse_iterator<Iterator>& y)
        {
            return y.base() - x.base();
        }
        template <class Iterator>
        reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& it)
        {
            return it + n;
        }
        template <class Iterator, class Iterator2> 
        bool operator==(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
        { 
            return lhs.base() == rhs.base();
        }
        template <class Iterator, class Iterator2> 
        bool operator!=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
        { 
            return lhs.base() != rhs.base();
        }
        template <class Iterator, class Iterator2> 
        bool operator<(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
        { 
            return lhs.base() > rhs.base();
        }
        template <class Iterator, class Iterator2> 
        bool operator>(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
        { 
            return lhs.base() < rhs.base();
        }
        template <class Iterator, class Iterator2> 
        bool operator>=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
        { 
            return lhs.base() <= rhs.base();
        }
        template <class Iterator, class Iterator2> 
        bool operator<=(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator2> &rhs)
        { 
            return lhs.base() >= rhs.base();
        }
}

#endif