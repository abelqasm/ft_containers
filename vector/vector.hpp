/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:25:53 by abelqasm          #+#    #+#             */
/*   Updated: 2023/01/12 18:08:47 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>
#include <mylib.hpp>

namespace ft
{
    template < class T, class Allocator = std::allocator<T> >
    class vector
    {
        private:
            T*          elemnts;
            size_type   numElemnts;
            size_type   sizeElemnts;

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
                sizeElemnts = numElemnts = 0;
                elemnts = alloc.allocate(0);
            }
            explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
            {
                sizeElemnts = numElemnts = n;
                elemnts = alloc.allocate(n);
                uninitialized_fill_n(elemnts, n, val);
            }
            template <class InputIterator>
            vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
            {
                sizeElemnts = numElemnts = (last - first);
                elemnts = alloc.allocate(last - first);
                uninitialized_copy(first, last, elemnts);
            }
            vector (const vector& x)
            {
            }
            ~vector()
            {   
            }
        
            vector& operator= (const vector& x)
            {
            }
            vector<T,Allocator>& operator=(const vector<T,Allocator>& x);
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
                return  elemnts[n];
            }
            const_reference operator[](size_type n) const
            {
                return  elemnts[n];
            }
            reference       at(size_type n)
            {
                if (n >= numElemnts)
                    throw std::out_of_range("out of range");
                return elemnts[n];  
            }
            const_reference at(size_type n) const
            {
                if (n >= numElemnts)
                    throw std::out_of_range("out of range");
                return elemnts[n];
            }

            reference       front()
            {
                return elemnts[0];
            }
            const_reference front() const
            {
                return elemnts[0];
            }
            reference       back()
            {
                if (numElemnts == 0)
                    return elemnts[0];
                return elemnts[numElemnts - 1];
            }
            const_reference back() const
            {
                if (numElemnts == 0)
                    return elemnts[0];
                return elemnts[numElemnts - 1];
            }

            value_type*       data()
            {
                return elemnts;
            }
            const value_type* data() const
            {
                return elemnts;
            }

        //-------------------------------------------------------------------------------------------------//
            // Capacity member functions
            size_type size() const
            {
                return numElemnts;
            }
            size_type max_size() const
            {
                return alloc.max_size();
            }
            size_type capacity() const
            {
                return sizeElemnts;
            }
            bool empty() const
            {
                return numElemnts == 0;
            }
            void reserve(size_type n)
            {
                if (n <= sizeElemnts)
                    return;
                T* tempMem = alloc.allocate(n);
                my_uninitialized_copy(elemnts, elemnts + numElemnts, tempMem);
                for (size_type i = 0; i < numElemnts; i++)
                    alloc.destroy(&elemnts[i]);
                alloc.deallocate(elemnts, sizeElemnts);
                elemnts = tempMem;
                sizeElemnts = n;
            }
            void resize (size_type n, value_type val = value_type())
            {
                if (n <= numElemnts)
                {
                    for (size_type i = n; i < sizeElemnts; i++)
                        alloc.destroy(&elemnts[i]);
                    numElemnts = n;
                    return;
                }
                else
                    reserve(n);
                my_uninitialized_fill_n(elemnts + numElemnts, n - numElemnts, val);
                numElemnts = n;
            }

        //-------------------------------------------------------------------------------------------------//
            //Modifiers
            iterator insert (iterator position, const value_type& val)
            {
                if (numElemnts + 1 > sizeElemnts)
                    reserve(sizeElemnts * 2);
                my_uninitialized_copy(elemnts + (position - elemnts), elemnts + numElemnts, elemnts + (position - elemnts) + 1);
                alloc.construct(elemnts + (position - elemnts), val);
                numElemnts++;
                return position;
            }
            void insert (iterator position, size_type n, const value_type& val)
            {
                if (numElemnts + n > sizeElemnts)
                    reserve(sizeElemnts * 2);
                my_uninitialized_copy(elemnts + (position - elemnts), elemnts + numElemnts, elemnts + (position - elemnts) + n);
                my_uninitialized_fill_n(elemnts + (position - elemnts), n, val);
                numElemnts += n;
            }
            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last);
    };
}

#endif