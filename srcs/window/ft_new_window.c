/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 06:14:52 by mykman            #+#    #+#             */
/*   Updated: 2022/08/10 06:23:32 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft_mlx.h"

t_window	ft_new_window(void *mlx_ptr, t_point size, char *name, int (*f)())
{
	t_window	win;

	win.win_ptr = mlx_new_window(mlx_ptr, size.x, size.y, name);
	if (!win.win_ptr)
		return ((t_window){0});
	win.size = size;
	mlx_hook(mlx_ptr, 17, 0, f, NULL);
	return (win);
}
