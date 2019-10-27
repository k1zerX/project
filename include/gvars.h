#ifndef GVARS_H
# define GVARS_H

#include "fractals.h"
#include <stdlib.h>

t_fractal	g_fractals[FRACTALS_LEN] =
{
	[MANDELBROT] =
	{
		"Mandelbrot\n",
		11,
		&mandelbrot
	},
	[JULIA] =
	{
		"Julia\n",
		6,
		&julia
	},
	[BEAUTIFUL] =
	{
		"Beautiful\n",
		10,
		&beautiful
	}
};

#endif
