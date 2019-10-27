#include "fractol.h"
#include "hook.h"
#include "tools.h"
#include "gvars.h"
#include "libft.h"
#include "complex.h"
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include <math.h>


#include <stdio.h>//
t_color	get_color(t_params *prms, double iter)
{
	t_color		color;

	iter /= prms->iter;
	(void)prms;
	color.o = 0;
	color.r = (t_byte)(9 * (1 - iter) * pow(iter, 3) * 0xff);
	color.g = (t_byte)(15 * pow((1 - iter), 2) * pow(iter, 2) * 0xff);
	color.b = (t_byte)(8.5 * pow((1 - iter), 3) * iter * 0xff);
	return (color);
}

void	ft_draw(t_params *prms)
{
	t_point		p;

	mlx_clear_window(prms->mlx, prms->win);
	mlx_put_image_to_window(prms->mlx, prms->win, prms->img_ptr, 0, 0);
	if (prms->boost_mode)
	{
		// vulcan api
	}
	else
	{
		p.y = 0;
		while (p.y < prms->n)
		{
			p.x = 0;
			while (p.x < prms->m)
			{
				prms->img[p.y * prms->m + p.x] = \
						get_color(prms, prms->fractal(prms, p));
				++p.x;
			}
			++p.y;
		}
	}
	mlx_put_image_to_window(prms->mlx, prms->win, prms->img_ptr, 0, 0);
}

int		main(int ac, char *av[])
{
	void			*mlx;
	t_params		prms[ac - 1];
	t_close			close[ac - 1];
	int				n;
	t_fractal_nbr	i;

	mlx = mlx_init();
	if (ac < 2)
	{
		i = 0;
		while (i < FRACTALS_LEN)
		{
			write(1, g_fractals[i].name, g_fractals[i].len);
			++i;
		}
		return (0);
	}
	n = 0;
	while (n < ac - 1)
	{
		printf("before:\n");
		init_prms(&prms[n], mlx);
		i = 0;
		while (i < FRACTALS_LEN)
		{
			if (ft_strnequ(av[n + 1], g_fractals[i].name, g_fractals[i].len - 1))
				break ;
			++i;
		}
		prms[n].fractal = g_fractals[i].f;
		ft_draw(&prms[n]);
		mlx_hook(prms[n].win, 4, 0, &ft_mouse_press, &prms[n]);
		mlx_hook(prms[n].win, 5, 0, &ft_mouse_release, &prms[n]);
		mlx_hook(prms[n].win, 6, 0, &ft_mouse_move, &prms[n]);
		close[n].prms = prms;
		close[n].n = ac - 1;
		close[n].ind = n;
		mlx_hook(prms[n].win, 17, 0, &ft_close, &close[n]);
		mlx_hook(prms[n].win, 2, 0, &ft_key_press, &close[n]);
		++n;
		printf("after:\n");
	}
	mlx_loop(mlx);
	return (0);
}
