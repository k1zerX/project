/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 01:50:27 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/26 09:01:05 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "tools.h"

int		ft_key_press(int keycode, t_params *prms)
{
	if (keycode == 53)
		ft_close(prms);
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
		prms->scale *= 0.8;
		prms->shift.x += x * (1 - prms->scale);
		prms->shift.y += y * (1 - prms->scale);
	}
	else if (button == 5)
	{
		prms->scale *= 1.25;
		prms->shift.x += x * (1 - prms->scale);
		prms->shift.y += y * (1 - prms->scale);
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
		prms->rmb = 0;
	return (0);
}

int		ft_mouse_move(int x, int y, t_params *prms)
{
	if (prms->lmb)
	{
		prms->shift.x -= (double)(x - prms->mouse_p.x) * prms->scale;
		prms->shift.y -= (double)(y - prms->mouse_p.y) * prms->scale;
		prms->mouse_p.x = x;
		prms->mouse_p.y = y;
	}
	else if (prms->lmb)
	{/*
		axis = turn_vector(get_vector(0, 1, 0), prms->q, 0);
		q = get_qtrn(axis, (double)(x - prms->lmb_p.x) / 100);
		prms->q = mul_qtrn(prms->q, q);
		axis = turn_vector(get_vector(-1, 0, 0), prms->q, 0);
		q = get_qtrn(axis, (double)(y - prms->lmb_p.y) / 100);
		prms->q = mul_qtrn(prms->q, q);
		prms->lmb_p.x = x;
		prms->lmb_p.y = y;*/
	}
	ft_draw(prms);
	return (0);
}
