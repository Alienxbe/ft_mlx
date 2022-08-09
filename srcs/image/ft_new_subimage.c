/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_subimage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:23:57 by mykman            #+#    #+#             */
/*   Updated: 2022/08/09 02:41:24 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

t_img	ft_new_subimage(void *mlx_ptr, t_img img, t_area area)
{
	t_img	new;
	t_point	size;

	size = area_to_size(area);
	if (size.x < 0 || size.y < 0
		|| area.p1.x < 0 || area.p1.y < 0
		|| area.p2.x > img.size.x || area.p2.y > img.size.y)
		return ((t_img){0});
	new = ft_new_image(mlx_ptr, size, 0);
	if (!new.img)
		return (new);
	ft_pixel_area_cpy(img, area, new, (t_point){0});
	return (new);
}
