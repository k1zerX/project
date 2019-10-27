#include "fractol.h"
#include "tools.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>


int		ft_close(t_close *close)
{
	t_params	*prms;
	int			i;
	char		f;

	prms = &close->prms[close->ind];
	mlx_destroy_image(prms->mlx, prms->img_ptr);
	prms->img_ptr = NULL;
	prms->img = NULL;
	mlx_destroy_window(prms->mlx, prms->win);
	prms->win = NULL;
	f = 1;
	i = 0;
	while (i < close->n)
	{
		if (close->prms[i].win != NULL)
			f = 0;
		++i;
	}
	if (f)
		exit(0);
	return (0);
}

void	reset_prms(t_params *prms)
{
	prms->scale = 1;
	prms->shift = (t_vector){-prms->n / 2, -prms->m / 2};
	prms->iter = 50;
}

void	init_prms(t_params *prms, void *mlx)
{
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	prms->mlx = mlx;
	prms->n = 250;
	prms->m = 250;
	prms->win = mlx_new_window(prms->mlx, prms->n, prms->m, "mlx");
	prms->img_ptr = mlx_new_image(prms->mlx, prms->n, prms->m);
	prms->img = (t_color *)mlx_get_data_addr(prms->img_ptr, &bits_per_pixel, &size_line, &endian);
	prms->lmb = 0;
	prms->rmb = 0;
	prms->boost_mode = 0;
	prms->toggle = 0;
	reset_prms(prms);
}
