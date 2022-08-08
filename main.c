/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:30:40 by mykman            #+#    #+#             */
/*   Updated: 2022/08/07 23:10:12 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_mlx.h"

int main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	t_img	win_img;
	t_img	sprite;
	t_img	frame;
	t_point	win_size = {500, 500};

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, win_size.x, win_size.y, "mlx window");

	win_img = ft_new_image(mlx_ptr, win_size, 0xFF000000);
	for (int i = 0; i < 100; i++)
		ft_pixel_put(win_img, (t_point){i, 100}, 0x00FF0000);

	sprite = ft_xpm_file_to_image(mlx_ptr, "assets/beladonis_sprite.xpm");
	if (!sprite.img)
		ft_printf("Image failed to load\n");
	else
	{
		ft_pixel_replace_color(sprite, 0xFF000000, 0x00FF0000);
		mlx_put_image_to_window(mlx_ptr, mlx_win, sprite.img, 0, 0);
	}
	// Should do my own put_image_to_win for safety

	frame = ft_new_subimage(mlx_ptr, sprite, (t_area){{0, 0}, {64, 64}});
	if (!frame.img)
		ft_printf("Image failed to load\n");
	else
		mlx_put_image_to_window(mlx_ptr, mlx_win, frame.img, 400, 400);

	ft_printf("Pixel color: Ox%08X\n", ft_get_pixel_color(sprite, (t_point){0, 0}));
	ft_printf("Pixel color: Ox%08X\n", ft_get_pixel_color(win_img, (t_point){0, 0}));
	
	ft_pixel_fill(win_img, (t_area){{350, 350}, {600, 600}}, 0x5F0000FF);

	ft_pixel_put(win_img, (t_point){400, 400}, 0x00FF0000);
	ft_pixel_put(win_img, (t_point){464, 464}, 0x00FF0000);

	mlx_put_image_to_window(mlx_ptr, mlx_win, win_img.img, 0, 0);
	mlx_loop(mlx_ptr);
	return 0;
}
