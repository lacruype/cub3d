/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 09:40:11 by lacruype          #+#    #+#             */
/*   Updated: 2020/01/13 12:55:23 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_wall(int x, int start, int end, t_struct *r)
{
	if (r->side == 0)
		r->x_wall = r->y_raypos + r->walldist * r->y_raydir;
	else
		r->x_wall = r->x_raypos + r->walldist * r->x_raydir;
	r->x_text = (int)(r->x_wall * (double)(64));
	if (r->side == 0 && r->x_raydir > 0)
		r->x_text = 64 - r->x_text - 1;
	if (r->side == 1 && r->y_raydir < 0)
		r->x_text = 64 - r->x_text - 1;
	r->x_text = abs(r->x_text);
	while (++start <= end)
		put_pxl_to_img(r, x, start);
}

void	floor_and_ceiling(t_struct *r, int x)
{
	if (r->start > 0)
	{
		r->y = r->start;
		if (x < r->win_l && r->y > 0)
			while (r->y-- >= 0)
				ft_memcpy(r->img.img + 4 * r->win_l * r->y + x * 4,
						&r->c, sizeof(int));
	}
	if (r->end > 0)
	{
		r->y = r->end - 1;
		if (x < r->win_l && r->y < r->win_h)
			while (++r->y < r->win_h)
				ft_memcpy(r->img.img + 4 * r->win_l * r->y + x * 4,
						&r->f, sizeof(int));
	}
}
