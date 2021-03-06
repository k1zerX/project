/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 05:24:50 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/27 21:41:48 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOOLS_H
# define TOOLS_H

#include "fractol.h"

typedef struct s_close	t_close;

struct					s_close
{
	t_params			*prms;
	int					n;
	int					ind;
};

int						ft_close(t_close *close);
void					reset_prms(t_params *prms);
void					init_prms(t_params *prms, void *mlx);

#endif
