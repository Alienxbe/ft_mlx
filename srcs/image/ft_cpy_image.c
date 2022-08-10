/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:26:19 by mykman            #+#    #+#             */
/*   Updated: 2022/08/10 07:27:04 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_mlx.h"

/*
* Copy the area from src to dst_p on dst
* return: true or false
*/
t_bool	ft_cpy_image(t_img src, t_img dst, t_point p_dst)
{
	return (ft_pixel_area_cpy(src, size_to_area(src.size), dst, p_dst));
}
