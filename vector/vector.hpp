/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:25:53 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/21 12:08:16 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <iostream>
#include "random_acces_iterator.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "../ft/enable_if.hpp"
#include "../ft/is_integral.hpp"
#include "../ft/equal.hpp"
#include "../ft/lexicographical_compare.hpp"

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
    public:
        //-------------------------------------------------------------------------------------------------//
            //constructors
            //default----------------------------------------------------------------------------------------------------------------//
            explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc)
            {
                _containerCapacity = _containerSize = 0;
                _container = nullptr;
            }
            //fill constructor------------------------------------------------------------------------------------------------------------------------------//
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _alloc(alloc)
            {
                _containerCapacity = _containerSize = n;
                _container = _alloc.allocate(n);
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_container + i, val);
            }
            //range constructor------------------------------------------------------------------------------------------------------------------------------//
            template <class InputIterator>
            vector(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last, const allocator_type& alloc = allocator_type()) : _alloc(alloc)
            {
                ft::vector<T> temp;
                size_type n = 0;
                for (InputIterator it = first; it != last; ++it, ++n)
                    temp.push_back(*it);
                _containerCapacity = _containerSize = n;
                _container = _alloc.allocate(n);
                n = 0;
                for (iterator it = temp.begin(); it != temp.end(); n++, ++it)
                    _alloc.construct(_container + n, *it);
            }
            //copy constructor------------------------------------------------------------------------------------------------------------------------------//  
            vector (const vector& x)
            {
                _containerCapacity = x._containerCapacity;
                _containerSize = x._containerSize;
                _alloc = x._alloc;
                _container = _alloc.allocate(_containerCapacity);
                for (size_type i = 0; i < _containerSize; i++)
                    _alloc.construct(_container + i, *(x._container + i));
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
                if (_container)
                    _alloc.deallocate(_container, _containerCapacity);
                _containerCapacity = x._containerCapacity;
                _containerSize = x._containerSize;
                _container = _alloc.allocate(_containerCapacity);
                for (size_type i = 0; i < _containerSize; i++)
                    _alloc.construct(_container + i, *(x._container + i));
                return *this;
            }
            // assign range iterators-------------------------------------------------------------------//
            template <class InputIterator>
            void assign(InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
            {
                ft::vector<T> temp;
                size_type n = 0;
                for (InputIterator it = first; it != last; ++it, ++n)
                    temp.push_back(*it);
                for (size_type i = 0; i < _containerSize; i++)
                    _alloc.destroy(_container + i);
                if (n > _containerCapacity)
                    reserve(n);
                n = 0;
                for (iterator it = temp.begin(); it != temp.end(); n++, ++it)
                    _alloc.construct(_container + n, *it);
                _containerSize = n;
            }
            // assign n element-------------------------------------------------------------------//
            void assign(size_type n, const T& u)
            {
                while (_containerSize)
                    _alloc.destroy(_container + --_containerSize);
                if (n > _containerCapacity)
                    reserve(n);
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_container + i, u);
                _containerSize = n;
            }
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
                return reverse_iterator(_container + _containerSize);
            }
            const_reverse_iterator rbegin()  const
            {
                return const_reverse_iterator(_container + _containerSize);
            }
            reverse_iterator       rend()
            {
                return reverse_iterator(_container);
            }
            const_reverse_iterator rend()    const
            {
                return reverse_iterator(_container);
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
                return std::min<size_type>(_alloc.max_size(), std::numeric_limits<difference_type>::max());
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
                size_type i = 0;
                for (iterator it = begin(); it != end(); it++ , i++)
                {
                    _alloc.construct(tempContainer + i , *it);
                    _alloc.destroy(&(*it));
                }
                if (_container)
                    _alloc.deallocate(_container, _containerCapacity);
                _container = tempContainer;
                _containerCapacity = n;
            }
            void resize (size_type n, value_type val = value_type())
            {
                if (n < _containerSize)
                    erase(begin() + n, end());
                else if (n > _containerSize)
                {
                    reserve(n);       
                    insert(end(), n - _containerSize, val);
                }
            }

        //-------------------------------------------------------------------------------------------------//
            //Modifiers member functions
            //push_back-------------------------------------------------------------------//
            void push_back (const value_type& val)
            {
                if (_containerCapacity == 0 || _containerSize == _containerCapacity)
                    _containerCapacity == 0 ? reserve(1) : reserve(_containerCapacity * 2);
                _alloc.construct(_container + _containerSize++, val);
            }
            //pop_back-------------------------------------------------------------------//
            void pop_back()
            {
                if (_containerSize == 0)
                    return;
                _alloc.destroy(_container + _containerSize-- - 1);
            }
            //insert in one position-------------------------------------------------------------------//
            iterator insert (iterator position, const value_type& val)
            {
                difference_type pos = position - begin();
                if (_containerCapacity == 0)
                    reserve(1);
                else if (_containerSize == _containerCapacity)
                    reserve(_containerCapacity * 2);
                position = begin() + pos;
                if (position == end())
                {
                    push_back(val);
                    return position;
                }
                for (iterator it = end(); it != position; it--)
                {
                    _alloc.construct(&(*it), *(it - 1));
                    _alloc.destroy(&(*(it - 1)));
                }
                _alloc.construct(&(*position), val);
                _containerSize++;
                return position;
            }
            //insert n element in positions-------------------------------------------------------------------//
            void insert (iterator position, size_type n, const value_type& val)
            {
                if (n == 0)
                    return;
                difference_type pos = position - begin();
                if (_containerSize + n > _containerCapacity)
                    n > _containerCapacity ? reserve(_containerCapacity + n) : reserve(_containerCapacity * 2);
                position = begin() + pos;
                if (position == end())
                {
                    for (size_type i = 0; i < n; i++)
                        push_back(val);
                    return;
                }
                for (iterator it = end() + n - 1; it != position + n - 1; it--)
                {
                    _alloc.construct(&(*it), *(it - n));
                    _alloc.destroy(&(*(it - n)));
                }
                for (size_type i = 0; i < n; i++)
                    _alloc.construct(_container + pos + i, val);
                _containerSize += n;
            }
            //insert range in positions-------------------------------------------------------------------//
            template <class InputIterator>
            void insert (iterator position, InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last)
            {
                if (first == last)
                    return;
                ft::vector<T> temp;
                size_type n = 0;
                for (InputIterator it = first; it != last; ++it, ++n)
                    temp.push_back(*it);
                difference_type pos = position - begin();
                if (_containerSize + n > _containerCapacity)
                    n > _containerCapacity ? reserve(_containerCapacity + n) : reserve(_containerCapacity * 2);
                position = begin() + pos;
                if (position == end())
                {
                    for (iterator it = temp.begin(); it != temp.end(); ++it)
                        push_back(*it);
                    return;
                }
                for (iterator it = end() + n - 1; it != position + n - 1; it--)
                {
                    _alloc.construct(&(*it), *(it - n));
                    _alloc.destroy(&(*(it - n)));
                }
                for (iterator it = temp.begin(); it != temp.end(); ++it, ++pos)
                    _alloc.construct(_container + pos, *it);
                _containerSize += n;
            }
            //swap
            void swap (vector& x)
            {
                T* tempContainer = _container;
                size_type tempSize = _containerSize;
                size_type tempCapacity = _containerCapacity;

                _container = x._container;
                _containerSize = x._containerSize;
                _containerCapacity = x._containerCapacity;
                x._container = tempContainer;
                x._containerSize = tempSize;
                x._containerCapacity = tempCapacity;
            }
            //erase
            //erase one element-------------------------------------------------------------------//
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
            //erase range-------------------------------------------------------------------//
            iterator erase(iterator first, iterator last)
            {
                iterator it = first;
                if (first == last)
                    return first;
                if (last == end())
                {
                    while (it != last && _containerSize--)
                        _alloc.destroy(&(*it++));
                    return first;
                }
                while (last != end())
                    *it++ = *last++;
                while (it != last && _containerSize--)
                    _alloc.destroy(&(*it++));
                return first;
            }
            //clear
            void clear()
            {
                for (size_type i = 0; i < _containerSize; i++)
                    _alloc.destroy(_container + i);
                _containerSize = 0;
            }
    };
    //non-member function overloads----------------------------------------------------------------------------------------------------------------//
    template <class T, class Alloc> 
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    template <class T, class Alloc>  
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }
    template <class T, class Alloc>  
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <class T, class Alloc>  
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
       return rhs < lhs;
    }
    template <class T, class Alloc>  
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(rhs < lhs);
    }
    template <class T, class Alloc>  
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs < rhs);
    }
    template <class T, class Alloc> 
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }
}
