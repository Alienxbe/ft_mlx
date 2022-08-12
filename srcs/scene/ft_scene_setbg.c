/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene_setbg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 06:49:45 by mykman            #+#    #+#             */
/*   Updated: 2022/08/12 06:51:51 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scene.h"

t_bool	ft_scene_setbg(t_scene scene, t_color c)
{
	return (ft_pixel_fill(scene.img, size_to_area(scene.img.size), c));
}
