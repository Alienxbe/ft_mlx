/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 22:51:54 by mykman            #+#    #+#             */
/*   Updated: 2022/08/09 02:05:29 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

t_bool	ft_pixel_cpy(t_img src, t_point p_src, t_img dst, t_point p_dst)
{
	if (!issmaller_point(p_src, src.size) || !issmaller_point(p_dst, dst.size))
		return (false);
	return (ft_pixel_put(dst, p_dst, ft_get_pixel_color(src, p_src)));
}
