/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 07:09:54 by mykman            #+#    #+#             */
/*   Updated: 2022/08/10 07:10:31 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

void	ft_update_window(void *mlx_ptr, t_window window)
{
	ft_put_image_to_window(mlx_ptr, window, window.img, (t_point){0});
}
