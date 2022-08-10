/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image_to_window.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 06:24:07 by mykman            #+#    #+#             */
/*   Updated: 2022/08/10 06:59:12 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft_mlx.h"

t_bool	ft_put_image_to_window(void *mlx_ptr, t_window win, t_img img,
			t_point pos)
{
	if (!issmaller_point(pos, win.size)
		|| isbigger_point(add_point(pos, img.size), win.size))
		return (false);
	mlx_put_image_to_window(mlx_ptr, win.win_ptr, img.img, pos.x, pos.y);
	return (true);
}
