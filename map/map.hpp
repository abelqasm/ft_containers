/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:46:20 by abelqasm          #+#    #+#             */
/*   Updated: 2023/01/29 16:22:45 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "../ft/pair.hpp"
#include "../ft/make_pair.hpp"
#include "../ft/enable_if.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "bidirectional_iterator.hpp"
#include "RedBlack.hpp"
#include <memory>
#include <functional>

namespace ft
{
    template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
    public:
        typedef Key                                         key_type;
        typedef T                                           mapped_type;
        typedef pair<const Key, T>                          value_type;
        typedef Compare                                     key_compare;
        typedef Allocator                                   allocator_type;
        
        typedef typename allocator_type::reference          reference;
        typedef typename allocator_type::const_reference    const_reference;
        typedef typename allocator_type::pointer            pointer;
        typedef typename allocator_type::const_pointer      const_pointer;
        typedef typename allocator_type::size_type          size_type;
        typedef typename allocator_type::difference_type    difference_type;

    
        typedef ft::bidirectional_iterator<pointer>         iterator;
        typedef ft::bidirectional_iterator<const_pointer>   const_iterator;
        typedef ft::reverse_iterator<iterator>              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>        const_reverse_iterator;
    private:

            allocator_type  _alloc;
            key_compare     _comp;
            size_type       _size;
            node            *_root;
            node            *_end;
    public:
        //------------------------------------------------------------------------------------------------------------------------------------
            //constructors
            //default ------------------------------------------------------------------------------------------------------------------------------------
            explicit map(const key_compare& comp = key_compare(),
                        const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _size(0), _root(NULL), _end(NULL)
            {
            }
            allocator_type get_allocator() const
            {
                return _alloc;
            }
        //-------------------------------------------------------------------------------------------------//    
            //iterators
            iterator begin();
            iterator begin() const;
            iterator end();
            iterator end() const;
            //reverse iterators
            reverse_iterator rbegin();
            reverse_iterator rbegin() const;
            reverse_iterator rend();
            reverse_iterator rend() const;
        //------------------------------------------------------------------------------------------------------------------------------------
            // Element access member functions
            mapped_type& operator[](const key_type& k);
        //------------------------------------------------------------------------------------------------------------------------------------
            // Capacity member functions
            bool empty() const
            {
                return _size == 0;
            }
            size_type size() const
            {
                return _size;
            }
            size_type max_size() const
            {
                return std::min<size_type>(_alloc.max_size(), std::numeric_limits<difference_type>::max());
            }
        //------------------------------------------------------------------------------------------------------------------------------------
            // Observers member functions
            key_compare key_comp() const;
            value_compare value_comp() const;
        //------------------------------------------------------------------------------------------------------------------------------------
            // Operations member functions
            iterator find(const key_type& k);
            const_iterator find(const key_type& k) const;
            size_type count(const key_type& k) const;
            iterator lower_bound(const key_type& k);
            const_iterator lower_bound(const key_type& k) const;
            iterator upper_bound(const key_type& k);
            const_iterator upper_bound(const key_type& k) const;
            ft::pair<iterator,iterator> equal_range(const key_type& k);
            ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
        //------------------------------------------------------------------------------------------------------------------------------------
            // Modifiers member functions
            ft::pair<iterator, bool> insert(const value_type& val);
            iterator insert(iterator position, const value_type& val);
            template <class InputIterator>
            void insert(InputIterator first, InputIterator last);
            void erase(iterator position);
            size_type erase(const key_type& k);
            void erase(iterator first, iterator last);
            void swap(map& x);
            void clear();
    };
}

#endif