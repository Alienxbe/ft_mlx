/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:51:54 by mykman            #+#    #+#             */
/*   Updated: 2022/08/10 05:22:28 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

t_bool	ft_pixel_cpy(t_img src, t_point p_src, t_img dst, t_point p_dst)
{
	t_color	pixel_color;

	if (!issmaller_point(p_src, src.size) || !issmaller_point(p_dst, dst.size))
		return (false);
	pixel_color = ft_pixel_get_color(src, p_src);
	if ((pixel_color & 0xFF000000) == 0xFF000000)
		return (true);
	return (ft_pixel_put(dst, p_dst, pixel_color));
}
