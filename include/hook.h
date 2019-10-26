/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 05:19:43 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/26 09:01:06 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

int		ft_mouse_move(int x, int y, t_params *prms);
int		ft_mouse_release(int button, int x, int y, t_params *prms);
int		ft_mouse_press(int button, int x, int y, t_params *prms);
int		ft_key_press(int keycode, t_params *prms);

#endif
