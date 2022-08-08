/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 00:26:06 by mykman            #+#    #+#             */
/*   Updated: 2022/08/07 23:47:28 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_H
# define FT_MLX_H

# include "mlx.h"
# include "ft_memory.h"
# include "ft_point.h"
# include "ft_area.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	t_point	size;
}	t_img;

typedef unsigned int t_color;

/*
** Images
*/

t_img			ft_new_image(void *mlx_ptr, t_point size, t_color bg);
t_img			ft_new_subimage(void *mlx_ptr, t_img img, t_area area);
t_img			ft_xpm_file_to_image(void *mlx_ptr, char *filename);

/*
** Pixel
*/

void			ft_pixel_put(t_img img, t_point pos, t_color color);
void			ft_pixel_fill(t_img img, t_area area, t_color color);
void			ft_pixel_replace_color(t_img img, t_color old, t_color new);
t_color			ft_get_pixel_color(t_img img, t_point pos);

#endif
