/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 06:14:52 by mykman            #+#    #+#             */
/*   Updated: 2022/08/10 07:14:32 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "mlx.h"
#include "libft_mlx.h"

t_window	ft_new_window(void *mlx_ptr, t_point size, char *name, int (*f)())
{
	t_window	win;

	win.win_ptr = mlx_new_window(mlx_ptr, size.x, size.y, name);
	if (!win.win_ptr)
		return ((t_window){0});
	win.img = ft_new_image(mlx_ptr, size, 0xFF000000);
	if (!win.img.img)
	{
		mlx_destroy_window(mlx_ptr, win.win_ptr);
		return ((t_window){0});
	}
	if (f)
		mlx_hook(win.win_ptr, 17, 0, f, NULL);
	win.size = size;
	win.name = name;
	return (win);
}
