/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 15:25:53 by abelqasm          #+#    #+#             */
/*   Updated: 2023/01/11 16:11:31 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

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


            //constructors
            explicit vector (const allocator_type& alloc = allocator_type())
            {
                sizeElemnts = numElemnts = 0;
                elemnts = alloc.allocate(0);
            }
            explicit vector (size_type n, const value_type& value = value_type(), const allocator_type& alloc = allocator_type())
            {
                sizeElemnts = numElemnts = n;
                elemnts = alloc.allocate(n);
                uninitialized_fill_n(elemnts, n, value);
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
            
            //iterators
            iterator               begin() noexcept;
            const_iterator         begin()   const noexcept;
            iterator               end() noexcept;
            const_iterator         end()     const noexcept;
            
            //revers iterators
            reverse_iterator       rbegin() noexcept;
            const_reverse_iterator rbegin()  const noexcept;
            reverse_iterator       rend() noexcept;
            const_reverse_iterator rend()    const noexcept;
            


            // Capacity member functions
            size_type size() const noexcept
            {
                return numElemnts;
            }
            size_type max_size() const noexcept
            {
            }
            size_type capacity() const noexcept
            {
                return sizeElemnts;
            }
            bool empty() const noexcept
            {
                return (numElemnts == 0);
            }
            void reserve(size_type n)
            {
                if (n <= sizeElemnts)
                    return;
                T* tempMem = alloc.allocate(n);
                uninitialized_copy(elemnts, elemnts + numElemnts, tempMem);
                for (size_type i = 0; i < numElemnts; i++)
                    alloc.destroy(&elemnts[i]);
                alloc.deallocate(elemnts, sizeElemnts);
                elemnts = tempMem;
                sizeElemnts = n;
            }
    };
}

#endif