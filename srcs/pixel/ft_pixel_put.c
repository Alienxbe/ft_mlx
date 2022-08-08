/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:33:45 by mykman            #+#    #+#             */
/*   Updated: 2022/08/07 23:08:06 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	ft_pixel_put(t_img img, t_point pos, t_color color)
{
	char	*dst;

	if (pos.x < img.size.x && pos.y < img.size.y)
	{
		dst = img.addr + (pos.y * img.line_length + pos.x * (img.bpp / 8));
		*(t_color *)dst = color;
	}
}
