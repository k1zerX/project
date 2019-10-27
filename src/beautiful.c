/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   beautiful.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 22:06:27 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/27 22:29:08 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fractals.h"
#include "complex.h"
#include <math.h>

double	beautiful(t_params *prms, t_point p)
{
	t_complex		z;
	double			iter;
	double			log_zn;
	double			nu;
	const t_complex	c = (t_complex){ \
			(2.0 - (double)p.y * prms->scale - prms->shift.y) * (4.0 / (double)prms->n), \
			(2.0 + (double)p.x * prms->scale + prms->shift.x) * (4.0 / (double)prms->m)};

	z = c;
	iter = 0.0;
	while (z.r * z.r + z.i * z.i <= (1 << 16) && iter < prms->iter)
	{
		z = complex_add(complex_mul(complex_add(c, (t_complex){1.0, 1.0}), z), c);
		z = (t_complex){prms->k.r + z.i * z.i - z.r * z.r, -prms->k.i * z.r * z.i};
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
