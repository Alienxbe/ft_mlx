/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 01:52:37 by mykman            #+#    #+#             */
/*   Updated: 2022/08/10 06:03:18 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

t_bool	ft_pixel_iter(t_img img, t_bool (*f)(t_img, t_point))
{
	t_bool	ret;
	t_point	i;

	ret = true;
	i.y = -1;
	while (++i.y < img.size.y)
	{
		i.x = -1;
		while (++i.x < img.size.x)
			if (!f(img, i))
				ret = false;
	}
	return (ret);
}
