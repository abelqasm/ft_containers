/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:45:41 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/10 14:41:40 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "../iterators/iterator_traits.hpp"

namespace ft
{
    template <class T>
    class bidirectional_iterator
    {
        public:
                typedef typename iterator_traits<T>::difference_type         difference_type;
                typedef typename iterator_traits<T>::value_type              value_type;
                typedef typename iterator_traits<T>::pointer                 pointer;
                typedef typename iterator_traits<T>::reference               reference;
                typedef typename std::bidirectional_iterator_tag             iterator_category;
        private:
                pointer _ptr;
        public:
                bidirectional_iterator() : _ptr(NULL)
                {
                }
                bidirectional_iterator(pointer ptr) : _ptr(ptr)
                {
                }
                pointer get() const
                {
                    return _ptr;
                }
                template <class U>
                bidirectional_iterator(const bidirectional_iterator<U>& u) : _ptr(u.get())
                {
                }
                ~bidirectional_iterator()
                {
                }
                bidirectional_iterator& operator=(const bidirectional_iterator& rhs)
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
                bidirectional_iterator& operator++()
                {
                    _ptr++;
                    return *this;
                }
                bidirectional_iterator operator++(int)
                {
                    bidirectional_iterator tmp(*this);
                    operator++();
                    return tmp;
                }
                bidirectional_iterator& operator--()
                {
                    _ptr--;
                    return *this;
                }
                bidirectional_iterator operator--(int)
                {
                    bidirectional_iterator tmp(*this);
                    operator--();
                    return tmp;
                }
    };
}
#endif