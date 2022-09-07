/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 11:09:19 by rledrin           #+#    #+#             */
/*   Updated: 2020/01/13 12:51:51 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		downhook(int keycode, t_struct *r)
{
	if (keycode == 123)
		r->rotleft = 1;
	if (keycode == 124)
		r->rotright = 1;
	if (keycode == 0)
		r->mvleft = 1;
	if (keycode == 2)
		r->mvright = 1;
	if (keycode == 1)
		r->back = 1;
	if (keycode == 13)
		r->forward = 1;
	if (keycode == 53)
		ft_exit(r);
	return (0);
}

int		uphook(int keycode, t_struct *r)
{
	if (keycode == 123)
		r->rotleft = 0;
	if (keycode == 124)
		r->rotright = 0;
	if (keycode == 0)
		r->mvleft = 0;
	if (keycode == 2)
		r->mvright = 0;
	if (keycode == 1)
		r->back = 0;
	if (keycode == 13)
		r->forward = 0;
	return (0);
}

int		loop_hook(t_struct *r)
{
	move(r);
	mlx_destroy_image(r->mlx, r->img.img_ptr);
	ray_casting(r);
	return (0);
}
