/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   category.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 09:38:10 by dboyer            #+#    #+#             */
/*   Updated: 2021/03/18 10:55:33 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CATEGORY_HPP
#define CATEGORY_HPP

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

#endif
