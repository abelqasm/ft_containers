/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:26:36 by abelqasm          #+#    #+#             */
/*   Updated: 2023/01/21 18:47:39 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../vector/vector.hpp"
namespace ft
{
    template <class T, class Container = ft::vector<T> >
    class stack
    {
    public:
        typedef T                                               value_type;
        typedef Container                                       container_type;
        typedef size_t                                          size_type;
    protected:
        container_type _container;
    public:
        explicit stack (const container_type& ctnr = container_type())
        {
            _container = ctnr;
        }
        stack& operator=( const stack& other )
        {
            _container = other._container;
            return *this;
        }
        ~stack()
        {
        }
        bool empty() const
        {
            return _container.empty();
        }
        size_type size() const
        {
            return _container.size();
        }
        value_type& top()
        {
            return _container.back();
        }
        const value_type& top() const
        {
            return _container.back();
        }
        void push (const value_type& val)
        {
            _container.push_back(val);
        }
        void pop()
        {
            _container.pop_back();
        }
        template <class T, class Container> 
        friend bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
        template <class T, class Container> 
        friend bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
        template <class T, class Container> 
        friend bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
        template <class T, class Container> 
        friend bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
        template <class T, class Container> 
        friend bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs);
    };
    template <class T, class Container> 
    bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs._container == rhs._container;
    }
    template <class T, class Container> 
    bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return !(lhs == rhs);
    }
    template <class T, class Container> 
    bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs._container < rhs._container;
    }
    template <class T, class Container> 
    bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs._container <= rhs._container;
    }
    template <class T, class Container> 
    bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs._container > rhs._container;
    }
    template <class T, class Container> 
    bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
    {
        return lhs._container >= rhs._container;
    }
}

#endif