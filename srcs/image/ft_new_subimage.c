/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_subimage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:23:57 by mykman            #+#    #+#             */
/*   Updated: 2022/08/07 22:57:02 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

t_img	ft_new_subimage(void *mlx_ptr, t_img img, t_area area)
{
	t_img	new;
	t_point	size;
	t_point	i;

	size = sub_point(area.p2, area.p1);
	if (size.x < 0 || size.y < 0
		|| area.p1.x < 0 || area.p1.y < 0
		|| area.p2.x > img.size.x || area.p2.y > img.size.y)
		return ((t_img){0});
	new = ft_new_image(mlx_ptr, size, 0);
	if (!new.img)
		return (new);
	i.y = -1;
	while (++i.y < size.y)
	{
		i.x = -1;
		while (++i.x < size.x)
			ft_pixel_put(new, i, \
				ft_get_pixel_color(img, add_point(area.p1, i)));
	}
	return (new);
}
