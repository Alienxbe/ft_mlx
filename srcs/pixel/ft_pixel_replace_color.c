/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_replace_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:01:10 by mykman            #+#    #+#             */
/*   Updated: 2022/08/07 23:07:20 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	ft_pixel_replace_color(t_img img, t_color old, t_color new)
{
	t_point	i;

	i.y = -1;
	while (++i.y < img.size.y)
	{
		i.x = -1;
		while (++i.x < img.size.x)
			if (ft_get_pixel_color(img, i) == old)
				ft_pixel_put(img, i, new);
	}
}
