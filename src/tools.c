#include "fractol.h"
#include "tools.h"
#include "libft.h"
#include <mlx.h>
#include <stdlib.h>

int		ft_close(t_params *prms)
{
	(void)prms;
	exit(0);
	return (0);
}

void	reset_prms(t_params *prms)
{
	prms->scale = 1;
	prms->shift = (t_vector){-prms->n / 2, prms->m};
	prms->iter = 1000;
}

void	init_prms(t_params *prms)
{
	int			bits_per_pixel;
	int			size_line;
	int			endian;

	prms->mlx = mlx_init();
	prms->n = 1000;
	prms->m = 1000;
	prms->win = mlx_new_window(prms->mlx, prms->n, prms->m, "mlx");
	prms->img_ptr = mlx_new_image(prms->mlx, prms->n, prms->m);
	prms->img = (t_color *)mlx_get_data_addr(prms->img_ptr, &bits_per_pixel, &size_line, &endian);
	prms->lmb = 0;
	prms->rmb = 0;
	prms->boost_mode = 0;
	reset_prms(prms);
}
