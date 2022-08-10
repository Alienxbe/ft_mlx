/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_mlx.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:26:06 by mykman            #+#    #+#             */
/*   Updated: 2022/08/10 07:10:21 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MLX_H
# define LIBFT_MLX_H

# include "ft_bool.h"
# include "ft_area.h"
# include "ft_point.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	t_point	size;
}	t_img;

typedef struct s_window
{
	void		*win_ptr;
	t_point		size;
	const char	*name;
	t_img		img;
}	t_window;

typedef unsigned int	t_color;

/*
** Window
*/

t_window	ft_new_window(void *mlx_ptr, t_point size, char *name, int (*f)());
t_bool		ft_put_image_to_window(void *mlx_ptr, t_window window, t_img img,
				t_point pos);
void		ft_update_window(void *mlx_ptr, t_window window);

/*
** Images
*/

t_img		ft_new_image(void *mlx_ptr, t_point size, t_color bg);
t_img		ft_new_subimage(void *mlx_ptr, t_img img, t_area area);
t_img		ft_xpm_file_to_image(void *mlx_ptr, char *filename);

/*
** Pixel
*/

t_bool		ft_pixel_put(t_img img, t_point pos, t_color color);
t_bool		ft_pixel_fill(t_img img, t_area area, t_color color);
t_bool		ft_pixel_replace_color(t_img img, t_color old, t_color new);
t_bool		ft_pixel_cpy(t_img src, t_point p_src, t_img dst, t_point p_dst);
t_bool		ft_pixel_area_cpy(t_img src, t_area a_src, t_img dst,
				t_point p_dst);
t_bool		ft_pixel_iter(t_img img, t_bool (*f)(t_img, t_point));
t_color		ft_pixel_get_color(t_img img, t_point pos);

#endif
