/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:25:53 by abelqasm          #+#    #+#             */
/*   Updated: 2023/01/15 18:57:16 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include "mylib.hpp"
#include "random_acces_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"

namespace ft
{
    template < class T, class Allocator = std::allocator<T> , class size_type = typename Allocator::size_type>
    class vector
    {
        private:
            Allocator   _alloc;
            T*          _container;
            size_type   _containerSize;
            size_type   _containerCapacity;

        public:
            typedef T                                           value_type;
            typedef Allocator                                   allocator_type;
            // typedef typename allocator_type::size_type          size_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef typename allocator_type::difference_type    difference_type;

            typedef ft::random_acces_iterator<pointer>          iterator;
            typedef ft::random_acces_iterator<const_pointer>    const_iterator;
            typedef ft::reverse_iterator<iterator>              reverse_iterator;
            typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;


        //-------------------------------------------------------------------------------------------------//
            //constructors
            explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc)
            {
                _containerCapacity = _containerSize = 0;
                _container = _alloc.allocate(0);
            }
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc)
            {
                _containerCapacity = _containerSize = n;
                _container = _alloc.allocate(n);
                my_uninitialized_fill_n(_container, n, val);
            }
            template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _alloc(alloc)
            {
                _containerCapacity = _containerSize = (last - first);
                _container = _alloc.allocate(last - first);
                my_uninitialized_copy(first, last, _container);
            }
            vector (const vector& x)
            {
                _containerCapacity = x.capacity();
                _containerSize = x.size();
                _alloc = x.get_allocator();
                _container = _alloc.allocate(_containerCapacity);
                // for (iterator it = x.begin(); it != x.end(); it++)
                //     _alloc.construct();
            }
            //destructor
            ~vector()
            {
                // for (size_type it = 0; it < _containerSize; it++)
                //     _alloc.destroy(_container[it]);
                // _alloc.deallocate(_container, _containerCapacity);
            }
            // assignment operator
            vector& operator= (const vector& x)
            {
                if (this == &x)
                    return *this;
                if (_containerCapacity < x.size())
                {
                    for (iterator it = data(); it != end(); it++)
                        _alloc.destroy(&it);
                    _alloc.deallocate(_container, _containerCapacity);
                    _containerCapacity = x.capacity();
                    _container = _alloc.allocate(_containerCapacity);
                }
                _containerSize = x.size();
                my_uninitialized_copy(x.begin(), x.end(), _container);
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
                // for(iterator it = begin(); it != end(); ++it)
                //     _alloc.construct(tempContainer[i], )
                _alloc.deallocate(_container, _containerCapacity);
                _container = tempContainer;
                _containerCapacity = n;
            }
            void resize (size_type n, value_type val = value_type())
            {
                if (n <= _containerSize)
                {
                    for (iterator it = data(); it != end(); it++)
                        _alloc.destroy(&it);
                    _containerSize = n;
                    return;
                }
                else
                    reserve(n);
            }

        //-------------------------------------------------------------------------------------------------//
            //Modifiers member functions
            //insert
            iterator insert (iterator position, const value_type& val)
            {
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
            }
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last)
            {   
            }
            //erase
            iterator erase(iterator position)
            {
            }
            iterator erase(iterator first, iterator last)
            {
            }
            //clear
            void clear()
            {
                for (iterator it = data(); it != end(); it++)
                    _alloc.destroy(&it);
                _containerSize = 0;
            }
    };
}

#endif