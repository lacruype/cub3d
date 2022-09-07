/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 11:18:30 by rledrin           #+#    #+#             */
/*   Updated: 2020/01/13 12:51:51 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_forward(t_struct *r)
{
	if (r->map[(int)(r->posy + r->dy * r->move_speed)][(int)r->posx] == '0')
		r->posy += r->dy * r->move_speed;
	if (r->map[(int)r->posy][(int)(r->posx + r->dx * r->move_speed)] == '0')
		r->posx += r->dx * r->move_speed;
}

void	move_back(t_struct *r)
{
	if (r->map[(int)(r->posy - r->dy * r->move_speed)][(int)r->posx] == '0')
		r->posy -= r->dy * r->move_speed;
	if (r->map[(int)r->posy][(int)(r->posx - r->dx * r->move_speed)] == '0')
		r->posx -= r->dx * r->move_speed;
}

void	move_left(t_struct *r)
{
	double tmpdx;
	double tmpdy;

	tmpdx = r->dx * cos(-(3.14 / 2)) - r->dy * sin(-(3.14 / 2));
	tmpdy = r->dx * sin(-(3.14 / 2)) + r->dy * cos(-(3.14 / 2));
	if (r->map[(int)(r->posy + tmpdy * r->move_speed)][(int)r->posx] == '0')
		r->posy += tmpdy * (r->move_speed / 2);
	if (r->map[(int)r->posy][(int)(r->posx + tmpdx * r->move_speed)] == '0')
		r->posx += tmpdx * (r->move_speed / 2);
}

void	move_right(t_struct *r)
{
	double tmpdx;
	double tmpdy;

	tmpdx = r->dx * cos((3.14 / 2)) - r->dy * sin((3.14 / 2));
	tmpdy = r->dx * sin((3.14 / 2)) + r->dy * cos((3.14 / 2));
	if (r->map[(int)(r->posy + tmpdy * r->move_speed)][(int)r->posx] == '0')
		r->posy += tmpdy * (r->move_speed / 2);
	if (r->map[(int)r->posy][(int)(r->posx + tmpdx * r->move_speed)] == '0')
		r->posx += tmpdx * (r->move_speed / 2);
}

void	move(t_struct *r)
{
	if ((r->mvleft == 1 && (r->cardaxe == 'n' || r->cardaxe == 'e'))
		|| (r->mvright == 1 && (r->cardaxe == 's' || r->cardaxe == 'w')))
		move_left(r);
	if ((r->rotleft == 1 && (r->cardaxe == 'n' || r->cardaxe == 'e'))
		|| (r->rotright == 1 && (r->cardaxe == 's' || r->cardaxe == 'w')))
		rotate_left(r);
	if ((r->mvright == 1 && (r->cardaxe == 'n' || r->cardaxe == 'e'))
		|| (r->mvleft == 1 && (r->cardaxe == 's' || r->cardaxe == 'w')))
		move_right(r);
	if ((r->rotright == 1 && (r->cardaxe == 'n' || r->cardaxe == 'e'))
		|| (r->rotleft == 1 && (r->cardaxe == 's' || r->cardaxe == 'w')))
		rotate_right(r);
	if (r->back == 1)
		move_back(r);
	if (r->forward == 1)
		move_forward(r);
}
