/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:30:40 by mykman            #+#    #+#             */
/*   Updated: 2022/08/02 16:17:56 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx.h"

int main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	win_img;
	t_point	win_size = {500, 500};

	ft_bzero(&win_img, sizeof(t_img));
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, win_size.x, win_size.y, "mlx window");
	win_img = ft_new_image(mlx_ptr, win_size);
	for (int i = 0; i < 100; i++)
		ft_pixel_put(win_img, (t_point){i, 100}, 0x00FF0000);
	mlx_put_image_to_window(mlx_ptr, mlx_win, win_img.img, 0, 0);
	mlx_loop(mlx_ptr);
	return 0;
}
