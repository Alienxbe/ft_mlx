/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_replace_color.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 23:01:10 by mykman            #+#    #+#             */
/*   Updated: 2022/08/09 02:46:48 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

t_bool	ft_pixel_replace_color(t_img img, t_color old, t_color new)
{
	t_bool	ret;
	t_point	i;

	ret = true;
	i.y = -1;
	while (++i.y < img.size.y)
	{
		i.x = -1;
		while (++i.x < img.size.x)
			if (ft_get_pixel_color(img, i) == old)
				if (ft_pixel_put(img, i, new))
					ret = false;
	}
	return (ret);
}
