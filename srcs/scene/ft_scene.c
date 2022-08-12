/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:06:35 by mykman            #+#    #+#             */
/*   Updated: 2022/08/12 04:14:38 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_scene.h"
#include "ft_memory.h"

t_scene	new_scene(void *mlx, t_point size, int (*update)(), void *param)
{
	t_scene	scene;

	ft_bzero(&scene, sizeof(scene));
	scene.img = ft_new_image(mlx, size, 0);
	if (!scene.img.img)
		return (scene);
	scene.update = update;
	scene.param = param;
	return (scene);
}
