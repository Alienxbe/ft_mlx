/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xpm_file_to_image.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 22:15:17 by mykman            #+#    #+#             */
/*   Updated: 2022/08/10 06:08:19 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "ft_memory.h"
#include "libft_mlx.h"

t_img	ft_xpm_file_to_image(void *mlx_ptr, char *filename)
{
	t_img	img;

	ft_bzero(&img, sizeof(img));
	img.img = mlx_xpm_file_to_image(mlx_ptr, filename, &img.size.x, &img.size.y);
	if (!img.img)
		return (img);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length,
		&img.endian);
	return (img);
}
