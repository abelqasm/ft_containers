/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:46:20 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/16 14:50:36 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <iostream>
#include "../ft/pair.hpp"
#include "../ft/make_pair.hpp"
#include "../ft/enable_if.hpp"
#include "../ft/is_integral.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "bidirectional_iterator.hpp"
#include "RedBlackTree.hpp"
#include <functional>

namespace ft
{
    template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
    public: 
        typedef Key                                         key_type;
        typedef T                                           mapped_type;
        typedef ft::pair<const Key, T>                      value_type;
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
            allocator_type                  _alloc;
            key_compare                     _comp;
            size_type                       _containerSize;
            ft::RedBlackTree<value_type>    _container;
    public:
        //------------------------------------------------------------------------------------------------------------------------------------
            //constructors
            //default ------------------------------------------------------------------------------------------------------------------------------------
            explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp)
            {
                _containerSize = 0;
                _container = RedBlackTree<value_type>();
            }
            template <class InputIterator> 
            map (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
                    const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                _alloc = alloc;
                _comp = comp;
                _containerSize = 0;
                _container = RedBlackTree<value_type>();
                insert(first, last);
            }
            map (const map& x)
            {
                _alloc = x._alloc;
                _comp = x._comp;
                _containerSize = x._containerSize;
                _container = x._container;
            }
            ~map()
            {
            }
        //------------------------------------------------------------------------------------------------------------------------------------
            allocator_type get_allocator() const
            {
                return _alloc;
            }
        //-------------------------------------------------------------------------------------------------//    
            //iterators
            iterator begin()
            {
                return iterator(_container.begin());
            }
            const_iterator begin() const
            {
                return const_iterator(_container.begin());
            }
            iterator end()
            {
                return iterator(_container.end());
            }
            const_iterator end() const
            {
                return const_iterator(_container.end());
            }
            //reverse iterators
            reverse_iterator rbegin()
            {
                return reverse_iterator(_container.end());
            }
            const_reverse_iterator rbegin() const
            {
                return const_reverse_iterator(_container.end());
            }
            reverse_iterator rend()
            {
                return reverse_iterator(_container.begin());
            }
            const_reverse_iterator rend() const
            {
                return const_reverse_iterator(_container.begin());
            }
        //------------------------------------------------------------------------------------------------------------------------------------
            // Element access member functions
            mapped_type& operator[](const key_type& k);
        //------------------------------------------------------------------------------------------------------------------------------------
            // Capacity member functions
            bool empty() const
            {
                return _containerSize == 0;
            }
            size_type size() const
            {
                return _containerSize;
            }
            size_type max_size() const
            {
                return std::min<size_type>(_alloc.max_size(), std::numeric_limits<difference_type>::max());
            }
        //------------------------------------------------------------------------------------------------------------------------------------
            // Observers member functions
            key_compare key_comp() const
            {
                return _comp;
            }
            // value_compare value_comp() const;
        //------------------------------------------------------------------------------------------------------------------------------------
            // Operations member functions
            iterator find(const key_type& k)
            {
                return iterator(_container.find(k));
            }
            const_iterator find(const key_type& k) const
            {
                return const_iterator(_container.find(k));
            }
            size_type count(const key_type& k) const;
            iterator lower_bound(const key_type& k);
            const_iterator lower_bound(const key_type& k) const;
            iterator upper_bound(const key_type& k);
            const_iterator upper_bound(const key_type& k) const;
            ft::pair<iterator,iterator> equal_range(const key_type& k);
            ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
        //------------------------------------------------------------------------------------------------------------------------------------
            // Modifiers member functions
            ft::pair<iterator, bool> insert(const value_type& val)
            {
                ft::pair<iterator, bool> ret;
                ret.first = iterator(_container.insert(val));
                ret.second = ret.first != end();
                if (ret.second)
                    _containerSize++;
                return ret;
            }
            iterator insert(iterator position, const value_type& val)
            {
                iterator ret = iterator(_container.insert(position, val));
                if (ret != end())
                    _containerSize++;
                return ret;
            }
            template <class InputIterator>
            void insert(InputIterator first, InputIterator last)
            {
                while (first != last)
                {
                    _container.insert(*first++);
                    _containerSize++;
                }
            }
            void erase(iterator position)
            {
                _container.deletnode(&position);
                _containerSize--;
            }
            size_type erase(const key_type& k);
            void erase(iterator first, iterator last)
            {
                while (first != last)
                {
                    erase(first++);
                    _containerSize--;
                }
            }
            void swap(map& x);
            void clear()
            {
                _container.clear();
                _containerSize = 0;
            }
    };
}

#endif