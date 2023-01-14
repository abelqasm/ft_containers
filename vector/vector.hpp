/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:25:53 by abelqasm          #+#    #+#             */
/*   Updated: 2023/01/14 17:56:22 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "mylib.hpp"
#include "random_access_iterator.hpp"

namespace ft
{
    template < class T, class Allocator = std::allocator<T> >
    class vector
    {
        private:
            T*          _container;
            size_type   _containerSize;
            size_type   _containerCapacity;

        public::
            typedef T                                           value_type;
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef typename allocator_type::difference_type    difference_type;

            typedef implementation-defined                      iterator;
            typedef implementation-defined                      const_iterator;
            typedef std::reverse_iterator<iterator>             reverse_iterator;
            typedef std::reverse_iterator<const_iterator>       const_reverse_iterator;


        //-------------------------------------------------------------------------------------------------//
            //constructors
            explicit vector (const allocator_type& alloc = allocator_type())
            {
                _containerCapacity = _containerSize = 0;
                _container = alloc.allocate(0);
            }
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            {
                _containerCapacity = _containerSize = n;
                _container = alloc.allocate(n);
                my_uninitialized_fill_n(_container, n, val);
            }
            template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
            {
                _containerCapacity = _containerSize = (last - first);
                _container = alloc.allocate(last - first);
                my_uninitialized_copy(first, last, _container);
            }
            vector (const vector& x)
            {
                _containerCapacity = x.capacity();
                _containerSize = x.size();
                _container = alloc.allocate(_containerCapacity);
                my_uninitialized_copy(x.begin(), x.end(), _container);
            }
            //destructor
            ~vector()
            {
                for (iterator it = data(); it != end(); it++)
                    alloc.destroy(&it);
                alloc.deallocate(_container, _containerCapacity);
            }
            // assignment operator
            vector& operator= (const vector& x)
            {
                if (this == &x)
                    return *this;
                if (_containerCapacity < x.size())
                {
                    for (iterator it = data(); it != end(); it++)
                        alloc.destroy(&it);
                    alloc.deallocate(_container, _containerCapacity);
                    _containerCapacity = x.capacity();
                    _container = alloc.allocate(_containerCapacity);
                }
                _containerSize = x.size();
                my_uninitialized_copy(x.begin(), x.end(), _container);
                return *this;
            }
            template <class InputIterator>
            void assign(InputIterator first, InputIterator last);
            void assign(size_type n, const T& u);
            allocator_type get_allocator() const;
            
        //-------------------------------------------------------------------------------------------------//    
            //iterators
            iterator               begin();
            const_iterator         begin()   const;
            iterator               end();
            const_iterator         end()     const;
            
            //revers iterators
            reverse_iterator       rbegin();
            const_reverse_iterator rbegin()  const;
            reverse_iterator       rend();
            const_reverse_iterator rend()    const;

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
                return alloc.max_size();
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
                T* tempMem = alloc.allocate(n);
                my_uninitialized_copy(_container, _container + _containerSize, tempMem);
                for (size_type i = 0; i < _containerSize; i++)
                    alloc.destroy(&_container[i]);
                alloc.deallocate(_container, _containerCapacity);
                _container = tempMem;
                _containerCapacity = n;
            }
            void resize (size_type n, value_type val = value_type())
            {
                if (n <= _containerSize)
                {
                    for (iterator it = data(); it != end(); it++)
                        alloc.destroy(&it);
                    _containerSize = n;
                    return;
                }
                else
                    reserve(n);
                my_uninitialized_fill_n(_container + _containerSize, n - _containerSize, val);
                _containerSize = n;
            }

        //-------------------------------------------------------------------------------------------------//
            //Modifiers member functions
            //insert
            iterator insert (iterator position, const value_type& val)
            {
                if (_containerSize + 1 > _containerCapacity)
                    reserve(_containerCapacity * 2);
                my_uninitialized_copy(position, _container + _containerSize, position + 1);
                alloc.construct(position, val);
                _containerSize++;
                return position;
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                if (_containerSize + n > _containerCapacity)
                    reserve(_containerCapacity * 2);
                my_uninitialized_copy(position , _container + _containerSize, position + n);
                my_uninitialized_fill_n(position, n, val);
                _containerSize += n;
            }
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last)
            {
                if (_containerSize + (last - first) > _containerCapacity)
                    reserve(_containerCapacity * 2);
                my_uninitialized_copy(position, _container + _containerSize, position + (last - first));
                my_uninitialized_copy(first, last, position);
                _containerSize += (last - first);   
            }
            //erase
            iterator erase(iterator position)
            {
                alloc.destroy(position);
                my_uninitialized_copy(position + 1, _container + _containerSize, position);
                _containerSize--;
                return position;
            }
            iterator erase(iterator first, iterator last)
            {
                for (iterator it = first; it != last; it++)
                    alloc.destroy(it);
                my_uninitialized_copy(last, _container + _containerSize, first);
                _containerSize -= (last - first);
                return first;
            }
            //clear
            void clear()
            {
                for (iterator it = data(); it != end(); it++)
                    alloc.destroy(&it);
                _containerSize = 0;
            }
    };
}

#endif