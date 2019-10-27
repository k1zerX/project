/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_motion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:57:18 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/27 20:58:07 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "complex.h"

void	fractal_motion(t_params *prms, t_point p)
{
	prms->k = (t_complex){ \
			4.0 * ((double)(prms->n - p.y) / (double)prms->n - 0.5), \
			4.0 * ((double)p.x / (double)prms->m - 0.5)};
}
