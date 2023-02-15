/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTreeIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:06:43 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/15 14:17:34 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDBLACKTREEITERATOR_HPP
#define REDBLACKTREEITERATOR_HPP

namespace ft
{
    template<class T>
    class RedBllackTreeIterator
    {
    public:
        typedef typename iterator_traits<T>::difference_type     difference_type;
        typedef typename iterator_traits<T>::value_type          value_type;
        typedef typename iterator_traits<T>::pointer             pointer;
        typedef typename iterator_traits<T>::reference           reference;
        typedef typename std::bidirectional_iterator_tag         iterator_category;
    private:
        pointer _ptr;
    public:
        RedBllackTreeIterator() : _ptr(nullptr)
        {
        }
        RedBllackTreeIterator(pointer ptr) : _ptr(ptr)
        {
        }
        pointer get() const
        {
            return _ptr;
        }
        template <class U>
        RedBllackTreeIterator(const RedBllackTreeIterator<U>& u) : _ptr(u.get())
        {
        }
        ~RedBllackTreeIterator()
        {
        }
        RedBllackTreeIterator& operator=(const RedBllackTreeIterator& rhs)
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
        RedBllackTreeIterator& operator++()
        {
            _ptr++;
            return *this;
        }
        RedBllackTreeIterator operator++(int)
        {
            RedBllackTreeIterator tmp(*this);
            return tmp;
        }
        RedBllackTreeIterator& operator--()
        {
            _ptr--;
            return *this;
        }
        RedBllackTreeIterator operator--(int)
        {
            RedBllackTreeIterator tmp(*this);
            return tmp;
        }
        template <class U>
        bool operator==(const RedBllackTreeIterator<U>& rhs) const
        {
            return _ptr == rhs.get();
        }
        template <class U>
        bool operator!=(const RedBllackTreeIterator<U>& rhs) const
        {
            return _ptr != rhs.get();
        }
    };
}
#endif