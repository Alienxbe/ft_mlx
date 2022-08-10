/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:33:45 by mykman            #+#    #+#             */
/*   Updated: 2022/08/10 05:15:04 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

t_bool	ft_pixel_put(t_img img, t_point pos, t_color color)
{
	char	*dst;

	if (issmaller_point(pos, img.size)
		&& isbigger_point(pos, (t_point){-1, -1}))
	{
		dst = img.addr + (pos.y * img.line_length + pos.x * (img.bpp / 8));
		*(t_color *)dst = color;
		return (true);
	}
	return (false);
}
