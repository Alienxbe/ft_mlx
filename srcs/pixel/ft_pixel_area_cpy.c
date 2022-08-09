/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_area_cpy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 02:16:42 by mykman            #+#    #+#             */
/*   Updated: 2022/08/09 02:46:55 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

t_bool	ft_pixel_area_cpy(t_img src, t_area a_src, t_img dst, t_point p_dst)
{
	t_point	size;
	t_point	i;
	t_bool	ret;

	ret = true;
	size = area_to_size(a_src);
	i.y = -1;
	while (++i.y < size.y)
	{
		i.x = -1;
		while (++i.x < size.x)
			if (!ft_pixel_cpy(src, add_point(a_src.p1, i), dst,
				add_point(p_dst, i)))
				ret = false;
	}
	return (ret);
}
