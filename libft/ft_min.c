/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:51:12 by kbatz             #+#    #+#             */
/*   Updated: 2018/12/20 13:56:39 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_min(void *a, void *b, size_t size)
{
	if (ft_memcmp(a, b, size) < 0)
		return (a);
	return (b);
}
