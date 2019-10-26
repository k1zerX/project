#include "fractol.h"
#include "hook.h"
#include "tools.h"
#include "gvars.h"
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>


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

#include <stdio.h>//
t_color	get_color(t_params *prms, double iter)
{
	t_color		color;

	(void)prms;
	color.r = (char)(9 * (1 - iter) * pow(iter, 3) * 0xff);
	color.g = (char)(15 * pow((1 - iter), 2) * pow(iter, 2) * 0xff);
	color.b = (char)(8.5 * pow((1 - iter), 3) * iter * 0xff);
	return (color);
}

void	get_pixel(t_params *prms, int i, int j)
{
//	const double	y0 = i / (2.0) + 1.0;
//	const double	x0 = j / (3.5) - 2.5;
//	const double	y0 = i / (4.0) + 2.0;
//	const double	x0 = j / (4.0) - 2.0;
	const t_complex	c = (t_complex){((double)i * prms->scale + prms->shift.y) / ((double)prms->n) * (4.0) - 2.0, \
		((double)j * prms->scale + prms->shift.x) / ((double)prms->m) * (4.0) + 2.0};
/*	const double b = 256;
	double n = 0;
	t_complex z = (t_complex){0.0, 0.0};
	for (int i=0; i < 200; ++i)
	{
		z = (t_complex){z.r * z.r - z.i * z.i, 2.0 * z.r * z.i};
		z.r += x0;
		z.i += y0;
		if (z.r * z.r + z.i * z.i > b * b)
			break ;
		n += 1.0;
	}
	double sn = n - log(log(z.r * z.r + z.i * z.i) / log(2)) / log(2) + 4.0;
	double iter = sn;*/
	t_complex		z;
	double			iter;
	double			log_zn;
	double			nu;

	z.i = 0.0;
	z.r = 0.0;
	iter = 0.0;
	while (z.r * z.r + z.i * z.i <= (1 << 16) && iter < prms->iter)
	{
//		printf("----------\n");
//		printf("z = %f + %f * i\n", z.r, z.i);
//		printf("c = %f + %f * i\n", c.r, c.i);
		z = complex_mul(z, z);
//		printf("z^2 = %f + %f * i\n", z.r, z.i);
		z = complex_add(z, c);
//		printf("z^2 + c = %f + %f * i\n", z.r, z.i);
//		printf("----------\n");
//		z = complex_add(complex_mul(z, z), c);
		++iter;
	}
	if (iter < prms->iter)
	{
		log_zn = log(z.r * z.r + z.i * z.i) / 2;
		nu = log(log_zn / log(2)) / log(2);
		iter = iter + 1 - nu;
	}
	prms->img[i * prms->m + j] = get_color(prms, iter);
//	t_color color = prms->img[i * prms->m + j];
//	printf("(%d, %d) ||| r: %d, g: %d, b: %d === %x ||| %f\n", j, i, color.r, color.g, color.b, *(int *)&color, iter);
}

void	ft_draw(t_params *prms)
{
	int		i;
	int		j;

	mlx_clear_window(prms->mlx, prms->win);
	if (prms->boost_mode)
	{
		// vulcan api
	}
	else
	{
		i = 0;
		while (i < prms->n)
		{
			j = 0;
			while (j < prms->m)
			{
				get_pixel(prms, i, j);
				++j;
			}
			++i;
		}
	}
	mlx_put_image_to_window(prms->mlx, prms->win, prms->img_ptr, 0, 0);
}

int		main(int ac, char *av[])
{
	t_params		prms;
	t_fractal_nbr	i;

	init_prms(&prms);
	if (ac == 2)
	{
		i = 0;
		while (i < FRACTALS_LEN)
		{
			if (ft_strnequ(av[1], g_fractals[i].name, g_fractals[i].len - 1))
				break ;
			++i;
		}
	}
	if (ac != 2 || i == FRACTALS_LEN)
	{
		i = 0;
		while (i < FRACTALS_LEN)
		{
			write(1, g_fractals[i].name, g_fractals[i].len);
			++i;
		}
		return (0);
	}
	ft_draw(&prms);
	mlx_hook(prms.win, 2, 0, &ft_key_press, &prms);
	mlx_hook(prms.win, 4, 0, &ft_mouse_press, &prms);
	mlx_hook(prms.win, 5, 0, &ft_mouse_release, &prms);
	mlx_hook(prms.win, 6, 0, &ft_mouse_move, &prms);
	mlx_hook(prms.win, 17, 0, &ft_close, &prms);
	mlx_loop(prms.mlx);
	return (0);
}
