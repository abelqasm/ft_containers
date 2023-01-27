/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 11:46:20 by abelqasm          #+#    #+#             */
/*   Updated: 2023/01/27 19:58:58 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include "../ft/pair.hpp"
#include "../ft/make_pair.hpp"
#include "../ft/enable_if.hpp"
#include "../iterators/reverse_iterator.hpp"
#include "bidirectional_iterator.hpp"
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
            typedef struct  s_node
            {
                value_type  value;
                s_node      *left;
                s_node      *right;
                s_node      *parent;
            }               t_node;

            allocator_type  _alloc;
            key_compare     _comp;
            size_type       _size;
            t_node          _*root;
            t_node          _*end;
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
                return std::min<size_type>(_alloc.max_size(), num);
            }
    };
}

#endif