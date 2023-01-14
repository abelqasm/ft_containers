/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:53:35 by abelqasm          #+#    #+#             */
/*   Updated: 2023/01/14 16:49:16 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYLIB_HPP
#define MYLIB_HPP
#include "iterator_traits.hpp"

template <class _ForwardIterator, class _Size, class _Tp>
_ForwardIterator
my_uninitialized_fill_n(_ForwardIterator __f, _Size __n, const _Tp& __x)
{
    typedef typename ft::iterator_traits<_ForwardIterator>::value_type value_type;
    _ForwardIterator __s = __f;
    try
    {
        for (; __n > 0; ++__f, (void) --__n)
            ::new (static_cast<void*>(&__f)) value_type(__x);
    }
    catch (...)
    {
        for (; __s != __f; ++__s)
            __s->~value_type();
        throw;
    }
    return __f;
}

template <class _InputIterator, class _ForwardIterator>
_ForwardIterator
my_uninitialized_copy(_InputIterator __f, _InputIterator __l, _ForwardIterator __r)
{
    typedef typename ft::iterator_traits<_ForwardIterator>::value_type value_type;
    _ForwardIterator __s = __r;
    try
    {
        for (; __f != __l; ++__f, (void) ++__r)
            ::new (static_cast<void*>(&__r)) value_type(*__f);
    }
    catch (...)
    {
        for (; __s != __r; ++__s)
            __s->~value_type();
        throw;
    }
    return __r;
}

#endif