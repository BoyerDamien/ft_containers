/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 10:51:00 by dboyer            #+#    #+#             */
/*   Updated: 2021/09/19 10:38:35 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstddef>

namespace ft
{
/*
 *		Reimplementaiton of all iterator tags
 *		Ref: https://www.cplusplus.com/reference/iterator/iterator/
 */
typedef struct input_iterator_tag
{

} input_iterator_tag;

typedef struct output_iterator_tag
{

} output_iterator_tag;

typedef struct forward_iterator_tag : public input_iterator_tag
{

} forward_iterator_tag;

typedef struct bidirectional_iterator_tag : public forward_iterator_tag
{

} bidirectional_iterator_tag;

typedef struct random_access_iterator_tag : public bidirectional_iterator_tag
{

} random_access_iterator_tag;

/*
 *		Reimplementation of iterator_traits
 *		ref: https://www.cplusplus.com/reference/iterator/iterator_traits/
 */

// Base iterator_traits template
template < typename Iterator > struct iterator_traits
{
    typedef typename Iterator::iterator_category iterator_category;
    typedef typename Iterator::value_type value_type;
    typedef typename Iterator::difference_type difference_type;
    typedef typename Iterator::pointer pointer;
    typedef typename Iterator::reference reference;
};

// Partial iterator_traits template specialisation for pointers type
template < typename T > struct iterator_traits< T * >
{
    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T *pointer;
    typedef T &reference;
};

// Partial iterator_traits template specialisation for const pointers type
template < typename T > struct iterator_traits< const T * >
{
    typedef random_access_iterator_tag iterator_category;
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef const T *pointer;
    typedef const T &reference;
};
} // namespace ft
