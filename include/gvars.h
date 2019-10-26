#ifndef GVARS_H
# define GVARS_H

#include "fractol.h"
#include <stdlib.h>

t_fractal	g_fractals[FRACTALS_LEN] =
{
	[MANDELBROT] =
	{
		"Mandelbrot\n",
		11,
		NULL
	},
	[JULIA] =
	{
		"Julia\n",
		6,
		NULL
	}
};

#endif
