/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scene.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mykman <mykman@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 02:14:46 by mykman            #+#    #+#             */
/*   Updated: 2022/08/12 04:14:02 by mykman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SCENE_H
# define FT_SCENE_H

# include "libft_mlx.h"
# include "ft_point.h"

typedef struct s_scene
{
	t_img	img;
	int		(*update)();
	void	*param;
}	t_scene;

t_scene	new_scene(void *mlx, t_point size, int (*update)(), void *param);

#endif
