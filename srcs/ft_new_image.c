/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:08:32 by mykman            #+#    #+#             */
/*   Updated: 2022/08/02 16:29:24 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

t_img	ft_new_image(void *mlx_ptr, t_point size)
{
	t_img	img;

	ft_bzero(&img, sizeof(img));
	img.img = mlx_new_image(mlx_ptr, size.x, size.y);
	if (!img.img)
		return (img);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
		&img.endian);
	img.size = size;
	return (img);
}

