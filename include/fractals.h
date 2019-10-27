/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 20:02:22 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/27 22:12:22 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTALS_H
# define FRACTALS_H

#include "fractol.h"
#include "complex.h"

typedef struct s_fractal	t_fractal;
typedef enum e_fractal_nbr	t_fractal_nbr;

struct						s_fractal
{
	const char				*name;
	int						len;
	double					(*f)(t_params *prms, t_point p);
};

enum						e_fractal_nbr
{
	MANDELBROT,
	JULIA,
	BEAUTIFUL,
	FRACTALS_LEN
};

extern t_fractal			g_fractals[];

double						mandelbrot(t_params *prms, t_point p);
double						julia(t_params *prms, t_point p);
double						beautiful(t_params *prms, t_point p);
void						fractal_motion(t_params *prms, t_point p);

#endif
