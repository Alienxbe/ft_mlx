/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:33:45 by mykman            #+#    #+#             */
/*   Updated: 2022/08/02 16:17:43 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

void	ft_pixel_put(t_img img, t_point pos, unsigned int color)
{
	char	*dst;

	dst = img.addr + (pos.y * img.line_length + pos.x * (img.bpp / 8));
	*(unsigned int *)dst = color;
}
