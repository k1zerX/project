/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:10:55 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/27 20:12:00 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLEX_H
# define COMPLEX_H

typedef struct s_complex	t_complex;

struct						s_complex
{
	double					i;
	double					r;
};

t_complex	complex_add(t_complex a, t_complex b);
t_complex	complex_mul(t_complex a, t_complex b);

#endif
