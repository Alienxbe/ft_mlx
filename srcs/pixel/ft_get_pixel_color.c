/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_pixel_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:36:59 by mykman            #+#    #+#             */
/*   Updated: 2022/08/07 23:07:30 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

t_color	ft_get_pixel_color(t_img img, t_point pos)
{
	char	*dst;

	dst = img.addr + (pos.y * img.line_length + pos.x * (img.bpp / 8));
	return (*(t_color *)dst);
}
