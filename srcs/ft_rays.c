/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 12:12:27 by rledrin           #+#    #+#             */
/*   Updated: 2020/01/13 12:57:36 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	dda_init(t_struct *r)
{
	r->x_deltadist = fabs(1 / r->x_raydir);
	r->y_deltadist = fabs(1 / r->y_raydir);
	if (r->x_raydir < 0)
	{
		r->x_step = -1;
		r->x_sidedist = (r->x_raypos - r->x_map) * r->x_deltadist;
	}
	else
	{
		r->x_step = 1;
		r->x_sidedist = (r->x_map + 1.0 - r->x_raypos) * r->x_deltadist;
	}
	if (r->y_raydir < 0)
	{
		r->y_step = -1;
		r->y_sidedist = (r->y_raypos - r->y_map) * r->y_deltadist;
	}
	else
	{
		r->y_step = 1;
		r->y_sidedist = (r->y_map + 1.0 - r->y_raypos) * r->y_deltadist;
	}
}

void	dda(t_struct *r)
{
	r->hit = 0;
	while (r->hit == 0)
	{
		if (r->x_sidedist < r->y_sidedist)
		{
			r->x_sidedist += r->x_deltadist;
			r->x_map = (r->x_map + r->x_step);
			r->side = 0;
		}
		else
		{
			r->y_sidedist += r->y_deltadist;
			r->y_map = (r->y_map + r->y_step);
			r->side = 1;
		}
		if (r->map[r->y_map][r->x_map] == '1')
			r->hit = 1;
	}
}
