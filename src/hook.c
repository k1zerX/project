/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 01:50:27 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/27 22:00:15 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "tools.h"
#include "fractals.h"

int		ft_key_press(int keycode, t_close *close)
{
	t_params	*prms;

	prms = &close->prms[close->ind];
	if (keycode == 53)
	{
		ft_close(close);
		return (0);
	}
	else if (keycode == 15)
		reset_prms(prms);
	else if (keycode == 69)
		prms->scale *= 0.8;
	else if (keycode == 78)
		prms->scale *= 1.25;
	ft_draw(prms);
	return (0);
}
int		ft_mouse_press(int button, int x, int y, t_params *prms)
{
	prms->mouse_p.x = x;
	prms->mouse_p.y = y;
	if (button == 1)
	{
		if (x >= 0 && y >= 0 && x < prms->n && y < prms->m)
			prms->lmb = 1;
	}
	else if (button == 2)
	{
		if (x >= 0 && y >= 0 && x < prms->n && y < prms->m)
			prms->rmb = 1;
	}
	else if (button == 4)
	{
		prms->shift.x += x * prms->scale;
		prms->shift.y += y * prms->scale;
		prms->scale *= 0.8;
		prms->shift.x -= x * prms->scale;
		prms->shift.y -= y * prms->scale;
	}
	else if (button == 5)
	{
		prms->shift.x += x * prms->scale;
		prms->shift.y += y * prms->scale;
		prms->scale *= 1.25;
		prms->shift.x -= x * prms->scale;
		prms->shift.y -= y * prms->scale;
	}
	ft_draw(prms);
	return (0);
}

int		ft_mouse_release(int button, int x, int y, t_params *prms)
{
	(void)x;
	(void)y;
	if (button == 1)
		prms->lmb = 0;
	else if (button == 2)
	{
		prms->rmb = 0;
		prms->toggle = !prms->toggle;
	}
	return (0);
}

int		ft_mouse_move(int x, int y, t_params *prms)
{
	if (prms->toggle)
		fractal_motion(prms, (t_point){y, x});
	else if (prms->lmb)
	{
		prms->shift.x -= (double)(x - prms->mouse_p.x) * prms->scale;
		prms->shift.y -= (double)(y - prms->mouse_p.y) * prms->scale;
		prms->mouse_p.x = x;
		prms->mouse_p.y = y;
	}
	ft_draw(prms);
	return (0);
}
