/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 15:16:20 by lacruype          #+#    #+#             */
/*   Updated: 2020/01/13 12:51:51 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	rotate_left(t_struct *r)
{
	r->old_player_dx = r->dx;
	r->dx = r->dx * cos(-r->rot_spd) - r->dy * sin(-r->rot_spd);
	r->dy = r->old_player_dx * sin(-r->rot_spd) + r->dy * cos(-r->rot_spd);
	r->old_x_plane = r->x_plane;
	r->x_plane = r->x_plane * cos(-r->rot_spd) - r->y_plane * sin(-r->rot_spd);
	r->y_plane = r->old_x_plane * sin(-r->rot_spd)
		+ r->y_plane * cos(-r->rot_spd);
}

void	rotate_right(t_struct *r)
{
	r->old_player_dx = r->dx;
	r->dx = r->dx * cos(r->rot_spd) - r->dy * sin(r->rot_spd);
	r->dy = r->old_player_dx * sin(r->rot_spd) + r->dy * cos(r->rot_spd);
	r->old_x_plane = r->x_plane;
	r->x_plane = r->x_plane * cos(r->rot_spd) - r->y_plane * sin(r->rot_spd);
	r->y_plane = r->old_x_plane * sin(r->rot_spd)
		+ r->y_plane * cos(r->rot_spd);
}
