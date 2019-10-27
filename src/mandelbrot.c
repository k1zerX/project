/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:36:40 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/27 21:27:27 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractals.h"
#include "complex.h"
#include <math.h>

double	mandelbrot(t_params *prms, t_point p)
{
	t_complex		z;
	double			iter;
	double			log_zn;
	double			nu;
	const t_complex	c = (t_complex){ \
			(2.0 - (double)p.y * prms->scale - prms->shift.y) * (4.0 / (double)prms->n), \
			(2.0 + (double)p.x * prms->scale + prms->shift.x) * (4.0 / (double)prms->m)};

	z = (t_complex){0, 0};
	iter = 0.0;
	while (z.r * z.r + z.i * z.i <= (1 << 16) && iter < prms->iter)
	{
		z = complex_add(complex_mul(z, z), c);
		iter += 1.0;
	}
	if (iter < prms->iter)
	{
		log_zn = log(z.r * z.r + z.i * z.i) / 2;
		nu = log(log_zn / log(2)) / log(2);
		iter = iter + 1 - nu;
	}
	return (iter);
}
