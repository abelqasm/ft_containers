/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:25:53 by abelqasm          #+#    #+#             */
/*   Updated: 2023/01/18 20:14:20 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <iostream>
#include "random_acces_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../enable_if.hpp"
#include "../is_integral.hpp"

namespace ft
{
    template < class T, class Allocator = std::allocator<T> >
    class vector
    {
    public:
            typedef T                                           value_type;
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef typename allocator_type::difference_type    difference_type;

            typedef ft::random_acces_iterator<pointer>          iterator;
            typedef ft::random_acces_iterator<const_pointer>    const_iterator;
            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
        
    private:
            Allocator   _alloc;
            T*          _container;
            size_type   _containerSize;
            size_type   _containerCapacity;
            template< class BidirIt1, class BidirIt2 >
            BidirIt2 my_copy_backward(BidirIt1 first, BidirIt1 last, BidirIt2 d_last)
            {
                while (first != last)
                    *(--d_last) = *(--last);
                return d_last;
            }
            template< class BidirIt1, class BidirIt2 >
            BidirIt2 my_copy_forward(BidirIt1 first, BidirIt1 last, BidirIt2 d_first)
            {
                while (first != last)
                    *(d_first++) = *(first++);
                return d_first;
            }
    public:
        //-------------------------------------------------------------------------------------------------//
            //constructors
            explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc)
            {
                _containerCapacity = _containerSize = 0;
                _container = NULL;
            }
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc)
            {
                _containerCapacity = _containerSize = n;
                _container = _alloc.allocate(n);
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_container + i, val);
            }
            template <class InputIterator>
            vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()) : _alloc(alloc)
            {
                size_type n = 0;
                for (InputIterator it = first; it != last; it++, n++);
                _containerCapacity = _containerSize = n;
                _container = _alloc.allocate(n);
                n = 0;
                for (InputIterator it = first; it != last; n++, ++it)
                    _alloc.construct(_container + n, *it);
            }
            vector (const vector& x)
            {
                _containerCapacity = x._containerCapacity;
                _containerSize = x._containerSize;
                _alloc = x._alloc;
                _container = _alloc.allocate(_containerCapacity);
                for (size_type i = 0; i < _containerSize; i++)
                    _alloc.construct(_container + i, x._container + i);
            }
            //destructor
            ~vector()
            {
                if (!_container)
                    return ;
                for (size_type i = 0; i < _containerSize; i++)
                    _alloc.destroy(_container + i);
                _alloc.deallocate(_container, _containerCapacity);
            }
            // assignment operator
            vector& operator= (const vector& x)
            {
                if (this == &x)
                    return *this;
                for (size_type i = 0; i < _containerSize ;i++)
                    _alloc.destroy(_container + i);
                _alloc.deallocate(_container, _containerCapacity);
                _containerCapacity = x._containerCapacity;
                _containerSize = x._containerSize;
                _container = _alloc.allocate(_containerCapacity);
                for (size_type i = 0; i < _containerSize; i++)
                    _alloc.construct(_container[i], x._container[i]);
                return *this;
            }
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last);
            void assign(size_type n, const T& u);
            allocator_type get_allocator() const
            {
                return _alloc;
            }
            
        //-------------------------------------------------------------------------------------------------//    
            //iterators
            iterator               begin()
            {
                return iterator(_container);
            }
            const_iterator         begin()   const
            {
                return const_iterator(_container);
            }
            iterator               end()
            {
                return iterator(_container + _containerSize);
            }
            const_iterator         end()     const
            {
                return const_iterator(_container + _containerSize);
            }
            
            //revers iterators
            reverse_iterator       rbegin()
            {
                return reverse_iterator(_container);
            }
            const_reverse_iterator rbegin()  const
            {
                return const_reverse_iterator(_container);
            }
            reverse_iterator       rend()
            {
                return reverse_iterator(_container + _containerSize);
            }
            const_reverse_iterator rend()    const
            {
                return reverse_iterator(_container + _containerSize);
            }

        //-------------------------------------------------------------------------------------------------//
            // Element access
            reference       operator[](size_type n)
            {
                return  _container[n];
            }
            const_reference operator[](size_type n) const
            {
                return  _container[n];
            }
            reference       at(size_type n)
            {
                if (n >= _containerSize)
                    throw std::out_of_range("out of range");
                return _container[n];  
            }
            const_reference at(size_type n) const
            {
                if (n >= _containerSize)
                    throw std::out_of_range("out of range");
                return _container[n];
            }

            reference       front()
            {
                return _container[0];
            }
            const_reference front() const
            {
                return _container[0];
            }
            reference       back()
            {
                return _container[_containerSize - 1];
            }
            const_reference back() const
            {
                return _container[_containerSize - 1];
            }

            value_type*       data()
            {
                return _container;
            }
            const value_type* data() const
            {
                return _container;
            }

        //-------------------------------------------------------------------------------------------------//
            // Capacity member functions
            size_type size() const
            {
                return _containerSize;
            }
            size_type max_size() const
            {
                return _alloc.max_size();
            }
            size_type capacity() const
            {
                return _containerCapacity;
            }
            bool empty() const
            {
                return _containerSize == 0;
            }
            // Capacity modifiers
            void reserve(size_type n)
            {
                if (n <= _containerCapacity)
                    return;
                T* tempContainer = _alloc.allocate(n);
                my_copy_forward(_container, _container + _containerSize, tempContainer);
                if (_container)
                    _alloc.deallocate(_container, _containerCapacity);
                _container = tempContainer;
                _containerCapacity = n;
            }
            // void resize (size_type n, value_type val = value_type())
            // {
            //     if (n <= _containerSize)
            //     {
            //         for (iterator it = data(); it != end(); it++)
            //             _alloc.destroy(&it);
            //         _containerSize = n;
            //         return;
            //     }
            //     else
            //         reserve(n);
            // }

        //-------------------------------------------------------------------------------------------------//
            //Modifiers member functions
            //insert
            iterator insert (iterator position, const value_type& val)
            {
                size_type pos = 0;
                for (iterator it = begin(); it != position; it++, pos++);
                if (_containerSize == _containerCapacity)
                    reserve(_containerCapacity * 2);
                my_copy_backward(_container + pos, end(), end() + 1);
                _alloc.construct(_container + pos, val);
                _containerSize++;
                return position;
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                size_type pos = 0;
                for (iterator it = begin(); it != position; it++, pos++);
                if (_containerSize + n >= _containerCapacity)
                    reserve(_containerCapacity * 2);
                my_copy_backward(_container + pos, _container + pos + n, end() + n);
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_container + pos + i, val);
                _containerSize += n;
            }
            template <class InputIterator>
            void insert (iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
            {
                size_type n = 0;
                size_type pos = 0;
                for (iterator it = begin(); it != position; it++, pos++);
                for (InputIterator it = first; it != last; it++, n++);
                if (_containerSize + n > _containerCapacity)
                    reserve(_containerCapacity * 2);
                my_copy_backward(_container + pos, _container + pos + n, end() + n);
                for (InputIterator it = first; it != last; ++it, ++pos)
                    _alloc.construct(_container + pos, *it);
                _containerSize += n;
            }
            //erase
            iterator erase(iterator position)
            {
                iterator it = position;
                iterator retIt = position;
                while (position != end() - 1)
                    *it++ = *++position;
                _alloc.destroy(&(*position));
                _containerSize--;
                return retIt;
            }
            iterator erase(iterator first, iterator last)
            {
                size_type n = 0;
                iterator retIt = first;        
                while (last != end() - 1 && n++)
                    *first++ = *++last;
                while (n--)
                    _alloc.destroy(&(*last++)); 
                return retIt;
            }
            //clear
            void clear()
            {
                for (size_type i = 0; i < _containerSize; i++)
                    _alloc.destroy(_container + i);
                _containerSize = 0;
            }
    };
}

#endif