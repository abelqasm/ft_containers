/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:46:20 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/15 13:39:40 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "../ft/pair.hpp"
#include "../ft/make_pair.hpp"
#include "../ft/enable_if.hpp"
#include "../ft/is_integral.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "bidirectional_iterator.hpp"
#include "RedBlackTree.hpp"
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
            allocator_type  _alloc;
            key_compare     _comp;
            size_type       _containerSize;
            RedBlackTree    _container;
    public:
        //------------------------------------------------------------------------------------------------------------------------------------
            //constructors
            //default ------------------------------------------------------------------------------------------------------------------------------------
            explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp)
            {
                _containerSize = 0;
                _container = RedBlackTree();
            }
            template <class InputIterator> 
            map (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
                    const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
            {
                _alloc = alloc;
                _comp = comp;
                _containerSize = 0;
                _container = RedBlackTree();
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
                clear();
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
                return iterator(_contaier.getRoot());
            }
            iterator begin() const
            {
                return iterator(_contaier.getRoot());
            }
            iterator end()
            {
                return iterator(_contaier.getEnd());
            }
            iterator end() const
            {
                return iterator(_contaier.getEnd());
            }
            //reverse iterators
            reverse_iterator rbegin()
            {
                return reverse_iterator(_contaier.getEnd());
            }
            reverse_iterator rbegin() const
            {
                return reverse_iterator(_contaier.getEnd());
            }
            reverse_iterator rend()
            {
                return reverse_iterator(_contaier.getRoot());
            }
            reverse_iterator rend() const
            {
                return reverse_iterator(_contaier.getRoot());
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
            value_compare value_comp() const;
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
            ft::pair<iterator, bool> insert(const value_type& val);
            iterator insert(iterator position, const value_type& val);
            template <class InputIterator>
            void insert(InputIterator first, InputIterator last);
            void erase(iterator position);
            size_type erase(const key_type& k);
            void erase(iterator first, iterator last);
            void swap(map& x);
            void clear()
            {
                _container.clear();
                _containerSize = 0;
            }
    };
}

#endif