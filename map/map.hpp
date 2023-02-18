/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:46:20 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/18 15:38:30 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

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
        typedef ft::reverse_iterator<iterator>                                              reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>                                        const_reverse_iterator;

    private:
            allocator_type                  _alloc;
            key_compare                     _comp;
            size_type                       _containerSize;
            container_type                  _container;
    public:
        //------------------------------------------------------------------------------------------------------------------------------------
            //constructors
            //default ------------------------------------------------------------------------------------------------------------------------------------
            explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _containerSize(0), _container()
            {
            }
            template <class InputIterator>
            map (InputIterator first, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type last,
                    const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _comp(comp), _containerSize(0), _container()
            {
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
                return _container.end();
            }
            const_reverse_iterator rbegin() const
            {
                return _container.end();
            }
            reverse_iterator rend()
            {
                return _container.begin();
            }
            const_reverse_iterator rend() const
            {
                return _container.begin();
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
                iterator it = _container.begin();
                while (it != _container.end())
                {
                    if (it->first == k)
                        return it;
                    ++it;
                }
                return it;
            }
            const_iterator find(const key_type& k) const
            {
                const_iterator it = _container.begin();
                while (it != _container.end())
                {
                    if (it->first == k)
                        return it;
                    ++it;
                }
                return it;
            }
            size_type count(const key_type& k) const;
            iterator lower_bound(const key_type& k)
            {
                iterator it = _container.begin();
                while (it != _container.end())
                {
                    if (it->first >= k)
                        return it;
                    ++it;
                }
                return it;
            }
            const_iterator lower_bound(const key_type& k) const
            {
                const_iterator it = _container.begin();
                while (it != _container.end())
                {
                    if (it->first >= k)
                        return it;
                    ++it;
                }
                return it;
            }
            iterator upper_bound(const key_type& k)
            {
                iterator it = _container.begin();
                while (it != _container.end())
                {
                    if (it->first > k)
                        return it;
                    ++it;
                }
                return it;
            }
            const_iterator upper_bound(const key_type& k) const
            {
                const_iterator it = _container.begin();
                while (it != _container.end())
                {
                    if (it->first > k)
                        return it;
                    ++it;
                }
                return it;
            }
            ft::pair<iterator,iterator> equal_range(const key_type& k);
            ft::pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
        //------------------------------------------------------------------------------------------------------------------------------------
            // Modifiers member functions
            ft::pair<iterator, bool> insert(const value_type& val)
            {
                ft::pair<iterator, bool> ret;
                ret.first = _container.insert(val);
                ret.second = ret.first != end();
                if (ret.second)
                    _containerSize++;
                return ret;
            }
            iterator insert(iterator position, const value_type& val)
            {
                iterator ret = _container.insert(position, val);
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
                _container.deleteNode(position.getNode());
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
            void swap(map& x)
            {
                key_compare                     tempComp = _comp;
                size_type                       tempSize = _containerSize;
                container_type                  tempContainer = _container;

                _comp = x._comp;
                _containerSize = x._containerSize;
                _container = x._container;
                x._comp = tempComp;
                x._containerSize = tempSize;
                x._container = tempContainer;
            }
            void clear()
            {
                _container.clear();
                _containerSize = 0;
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
