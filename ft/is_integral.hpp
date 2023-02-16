/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:00:18 by abelqasm          #+#    #+#             */
/*   Updated: 2023/02/16 15:44:45 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
    template< class T >
    struct is_integral
    {
        static const bool value = false;
    };
    template<>
    struct is_integral<bool>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<char>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<signed char>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<unsigned char>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<wchar_t>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<char16_t>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<char32_t>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<short>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<unsigned short>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<int>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<unsigned int>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<long>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<unsigned long>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<long long>
    {
        static const bool value = true;
    };
    template<>
    struct is_integral<unsigned long long>
    {
        static const bool value = true;
    };
}
