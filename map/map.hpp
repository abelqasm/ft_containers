/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:46:20 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/21 17:55:54 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <iostream>
#include "../ft/equal.hpp"
#include "../ft/lexicographical_compare.hpp"
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
        typedef Key                                                                         key_type;
        typedef T                                                                           mapped_type;
        typedef ft::pair<const key_type, mapped_type>                                       value_type;
        typedef Compare                                                                     key_compare;
        typedef Allocator                                                                   allocator_type;
        class value_compare : public std::binary_function<value_type, value_type, bool>
        {
            friend class map;
            friend class ft::RedBlackTree<value_type, value_compare, key_compare, allocator_type>;
        protected:
            Compare comp;
            value_compare (Compare c) : comp(c) {}
        public:
            typedef bool result_type;
            typedef value_type first_argument_type;
            typedef value_type second_argument_type;
            bool operator() (const value_type& x, const value_type& y) const
            {
              return comp(x.first, y.first);
            }
        };
        typedef typename ft::RedBlackTree<value_type, value_compare, key_compare, allocator_type>        container_type;

        typedef typename allocator_type::reference                                          reference;
        typedef typename allocator_type::const_reference                                    const_reference;
        typedef typename allocator_type::pointer                                            pointer;
        typedef typename allocator_type::const_pointer                                      const_pointer;
        typedef typename allocator_type::size_type                                          size_type;
        typedef typename allocator_type::difference_type                                    difference_type;


        typedef typename container_type::iterator                                           iterator;
        typedef typename container_type::const_iterator                                     const_iterator;
        typedef typename container_type::reverse_iterator                                   reverse_iterator;
        typedef typename container_type::const_reverse_iterator                             const_reverse_iterator;

    private:
            allocator_type                  _alloc;
            key_compare                     _comp;
            container_type                  _container;
    public:
        //------------------------------------------------------------------------------------------------------------------------------------
            //constructors
            //default ------------------------------------------------------------------------------------------------------------------------------------
            explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _container()
            {
            }
            template <class InputIterator>
            map (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
                    const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _container()
            {
                insert(first, last);
            }
            map (const map& x) : _alloc(x._alloc), _comp(x._comp), _container(x._container)
            {
            }
            map& operator=(const map& x)
            {
                if (this == &x)
                    return *this;
                _container = x._container;
                return *this;
            }
            ~map()
            {
            }
        //------------------------------------------------------------------------------------------------------------------------------------
            allocator_type get_allocator() const
            {
                return _alloc;
            }
        //------------------------------------------------------------------------------------------------------------------------------------
            value_compare value_comp() const
            {
                return value_compare(_comp);
            }
        //-------------------------------------------------------------------------------------------------//    
            //iterators
            iterator begin()
            {
                return _container.begin();
            }
            const_iterator begin() const
            {
                return _container.begin();
            }
            iterator end()
            {
                return _container.end();
            }
            const_iterator end() const
            {
                return _container.end();
            }
            //reverse iterators
            reverse_iterator rbegin()
            {
                return _container.rbegin();
            }
            const_reverse_iterator rbegin() const
            {
                return _container.rbegin();
            }
            reverse_iterator rend()
            {
                return _container.rend();
            }
            const_reverse_iterator rend() const
            {
                return _container.rend();
            }
        //------------------------------------------------------------------------------------------------------------------------------------
            // Element access member functions
            mapped_type& operator[](const key_type& k)
            {
                return _container.insert(ft::make_pair(k, mapped_type()))->second;
            }
            mapped_type& at (const key_type& k)
            {
                iterator it = find(k);
                if (it == end())
                    throw std::out_of_range("key not found");
                return it->second;
            }
            const mapped_type& at (const key_type& k) const
            {
                const_iterator it = find(k);
                if (it == end())
                    throw std::out_of_range("key not found");
                return it->second;
            }
        //------------------------------------------------------------------------------------------------------------------------------------
            // Capacity member functions
            bool empty() const
            {
                return _container.getSize() == 0;
            }
            size_type size() const
            {
                return _container.getSize();
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
                node<value_type>  *root = _container.getRoot();
                while (root != _container.getNill())
                {
                    if (root->_value.first == k)
                        return iterator(root, _container.getNill());
                    _comp(root->_value.first , k) ? root = root->_right : root = root->_left;
                }
                return end();
            }
            const_iterator find(const key_type& k) const
            {
                node<value_type>  *root = _container.getRoot();
                while (root != _container.getNill())
                {
                    if (root->_value.first == k)
                        return iterator(root, _container.getNill());
                    _comp(root->_value.first , k) ? root = root->_right : root = root->_left;
                }
                return end();
            }
            size_type count(const key_type& k) const
            {
                size_type cnt = find(k) == end() ? 0 : 1;
                return cnt;
            }
            iterator lower_bound(const key_type& k)
            {
                node<value_type>  *root = _container.getRoot();
                node<value_type> *lowerBound = _container.getNill();
                while (root != _container.getNill())
                {
                    if (_comp(root->_value.first , k))
                        root = root->_right;
                    else
                    {
                        lowerBound = root;
                        root = root->_left;
                    }
                }
                return iterator(lowerBound, _container.getNill());
            }
            const_iterator lower_bound(const key_type& k) const
            {
                node<value_type>  *root = _container.getRoot();
                node<value_type> *lowerBound = _container.getNill();
                while (root != _container.getNill())
                {
                    if (_comp(root->_value.first , k))
                        root = root->_right;
                    else
                    {
                        lowerBound = root;
                        root = root->_left;
                    }
                }
                return iterator(lowerBound, _container.getNill());
            }
            iterator upper_bound(const key_type& k)
            {
                node<value_type>  *root = _container.getRoot();
                node<value_type> *upperBound = _container.getNill();
                while (root != _container.getNill())
                {
                    if (_comp(k , root->_value.first))
                    {
                        upperBound = root;
                        root = root->_left;
                    }
                    else
                        root = root->_right;
                }
                return iterator(upperBound, _container.getNill());
            }
            const_iterator upper_bound(const key_type& k) const
            {
                node<value_type>  *root = _container.getRoot();
                node<value_type> *upperBound = _container.getNill();
                while (root != _container.getNill())
                {
                    if (_comp(k , root->_value.first))
                    {
                        upperBound = root;
                        root = root->_left;
                    }
                    else
                        root = root->_right;
                }
                return iterator(upperBound, _container.getNill());
            }
            ft::pair<iterator,iterator> equal_range(const key_type& k)
            {
                return ft::pair<iterator,iterator>(lower_bound(k), upper_bound(k));
            }
            ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const
            {
                return ft::pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k));
            }
        //------------------------------------------------------------------------------------------------------------------------------------
            // Modifiers member functions
            ft::pair<iterator, bool> insert(const value_type& val)
            {
                ft::pair<iterator, bool> ret;
                size_type insrt = _container.getSize();
                ret.first = _container.insert(val);
                ret.second = (_container.getSize() != insrt);
                return ret;
            }
            iterator insert(iterator position, const value_type& val)
            {
                (void)position;
                return _container.insert(val);
            }
            template <class InputIterator>
            void insert(InputIterator first, InputIterator last)
            {
                iterator it;
                while (first != last)
                {
                    _container.insert(*first);
                    ++first;
                }
            }
            void erase(iterator position)
            {
                _container.deleteNode(position.getNode());
            }
            size_type erase(const key_type& k)
            {
                iterator it = find(k);
                if (it != end())
                {
                    erase(it);
                    return 1;
                }
                return 0;
            }
            void erase(iterator first, iterator last)
            {
                iterator it;
                while (first != last)
                {
                    it = first;
                    ++first;
                    erase(it);
                }
            }
            void swap(map& x)
            {
                key_compare     tempComp = _comp;

                _container.swap(x._container);
                x._comp = tempComp;
            }
            void clear()
            {
                _container.clear();
            }
    };
//------------------------------------------------------------------------------------------------------------------------------------
    // Non-member function overloads
    template <class Key, class T, class Compare, class Alloc>
    bool operator== (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
    {
        return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator!= (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator<  (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
    {
        return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator<= (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
    {
        return !(rhs < lhs);
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator>  (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
    {
        return rhs < lhs;
    }
    template <class Key, class T, class Compare, class Alloc>
    bool operator>= (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs)
    {
        return !(lhs < rhs);
    }
    template <class Key, class T, class Compare, class Alloc> 
    void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
    {
        x.swap(y);
    }
}
