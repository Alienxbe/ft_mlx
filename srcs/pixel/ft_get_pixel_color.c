/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixel_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:36:59 by mykman            #+#    #+#             */
/*   Updated: 2022/08/09 02:46:55 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

t_color	ft_get_pixel_color(t_img img, t_point pos)
{
	char	*dst;

	if (!issmaller_point(pos, img.size))
		return ((t_color)0x0);
	dst = img.addr + (pos.y * img.line_length + pos.x * (img.bpp / 8));
	return (*(t_color *)dst);
}
