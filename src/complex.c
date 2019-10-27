/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:11:06 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/27 20:11:49 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "complex.h"

t_complex	complex_add(t_complex a, t_complex b)
{
	a.r += b.r;
	a.i += b.i;
	return (a);
}

t_complex	complex_mul(t_complex a, t_complex b)
{
	return ((t_complex){a.r * b.i + a.i * b.r, a.r * b.r - a.i * b.i});
}
