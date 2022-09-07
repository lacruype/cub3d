/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:53:32 by atodesco          #+#    #+#             */
/*   Updated: 2020/01/13 18:24:42 by lacruype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	put_pxl_to_img(t_struct *r, int x, int y)
{
	if (x < r->win_l && y < r->win_h)
	{
		r->y_text = abs((((y * 256 - r->win_h * 128 + r->lineheight * 128) * 64)
					/ r->lineheight) / 256);
		ft_memcpy(r->img.img + 4 * r->win_l * y + x * 4,
				&r->tex[r->id].img[(int)r->y_text % 64
					* r->tex[r->id].sizeline + (int)r->x_text % 64
						* r->tex[r->id].bpp / 8], sizeof(int));
	}
}

void	put_pxl_to_img_sprite(t_struct *r, int x, int y)
{
	if (x < r->win_l && y < r->win_h)
	{
		ft_memcpy(r->img.img + 4 * r->win_l * y + x * 4,
				&r->tex[r->id].img[(int)r->y_text
					% 64 * r->tex[r->id].sizeline + (int)r->x_text
						% 64 * r->tex[r->id].bpp / 8], sizeof(int));
	}
}

void	ray_casting_init(t_struct *r, int x)
{
	r->x_cam = 2 * (x / (double)(r->win_l)) - 1;
	r->x_raypos = r->posx;
	r->y_raypos = r->posy;
	r->x_raydir = r->dx + (r->x_plane * r->x_cam);
	r->y_raydir = r->dy + (r->y_plane * r->x_cam);
	r->x_map = r->x_raypos;
	r->y_map = r->y_raypos;
	dda_init(r);
	dda(r);
	if (r->side == 0)
		r->walldist = (r->x_map - r->x_raypos +
				(1 - r->x_step) / 2) / r->x_raydir;
	else
		r->walldist = (r->y_map - r->y_raypos +
				(1 - r->y_step) / 2) / r->y_raydir;
}

void	ray_casting(t_struct *r)
{
	int		i;
	double	zbuffer[r->win_l + 1];

	i = 0;
	r->x = -1;
	r->img.img_ptr = mlx_new_image(r->mlx, r->win_l, r->win_h);
	r->img.img = mlx_get_data_addr(r->img.img_ptr, &r->img.bpp,
		&r->img.sizeline, &r->img.endian);
	while (r->x++ < r->win_l)
	{
		ray_casting_init(r, r->x);
		r->lineheight = (int)(r->win_h / r->walldist);
		r->start = -r->lineheight / 2 + r->win_h / 2;
		if (r->start < 0)
			r->start = 0;
		r->end = r->lineheight / 2 + r->win_h / 2;
		if (r->end >= r->win_h)
			r->end = r->win_h - 1;
		ft_color_walls(r);
		floor_and_ceiling(r, r->x);
		draw_wall(r->x, r->start - 1, r->end, r);
		zbuffer[r->x] = r->walldist;
	}
	ft_sprite(r, zbuffer, i);
	mlx_put_image_to_window(r->mlx, r->window, r->img.img_ptr, 0, 0);
}
