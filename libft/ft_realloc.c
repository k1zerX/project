/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:54:50 by kbatz             #+#    #+#             */
/*   Updated: 2018/12/17 21:17:01 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_realloc(void *src, size_t size, long dif)
{
	void	*res;

	res = ft_memalloc(size + dif);
	if (src && res)
	{
		ft_memcpy(res, src, size);
		if (size)
			ft_memdel(&src);
	}
	return (res);
}
