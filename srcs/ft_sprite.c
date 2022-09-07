/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 09:38:09 by lacruype          #+#    #+#             */
/*   Updated: 2020/01/13 13:01:28 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_sprite(t_struct *r)
{
	int i;
	int j;
	int n;

	i = 0;
	n = 0;
	while (r->map[i] != NULL)
	{
		j = 0;
		while (r->map[i][j] != '\0')
		{
			if (r->map[i][j] == '2')
			{
				r->sprite_utils[n].x = j;
				r->sprite_utils[n].y = i;
				r->sprite_utils[n].sprite_dist = ((r->posx -
					r->sprite_utils[n].x) * (r->posx - r->sprite_utils[n].x)
						+ (r->posy - r->sprite_utils[n].y) *
							(r->posy - r->sprite_utils[n].y));
				n++;
			}
			j++;
		}
		i++;
	}
}

void	sort_sprite(t_struct *r)
{
	int			i;
	int			j;
	t_sprite_u	tmp;

	i = 0;
	while (i < r->nb_sprite_map)
	{
		j = i + 1;
		while (j < r->nb_sprite_map)
		{
			if (r->sprite_utils[i].sprite_dist
				< r->sprite_utils[j].sprite_dist)
			{
				tmp = r->sprite_utils[i];
				r->sprite_utils[i] = r->sprite_utils[j];
				r->sprite_utils[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	draw_sprite2(t_struct *r, double *zbuffer)
{
	int			y;
	int			d;

	r->s->stripe = r->s->startx;
	while (r->s->stripe < r->s->endx)
	{
		r->x_text = (int)(256 * (r->s->stripe - ((-1 * r->s->width)
			/ 2 + r->s->screenx)) * r->tex->width / r->s->width) / 256;
		if (r->s->transformy > 0 && r->s->stripe > 0 && r->s->stripe
			< r->win_l && r->s->transformy < zbuffer[r->s->stripe])
		{
			y = r->s->starty;
			while (y < r->s->endy)
			{
				d = (y) * 256 - r->win_h * 128 + r->s->height * 128;
				r->y_text = ((d * r->tex->height) / r->s->height) / 256;
				if ((r->tex[r->id].img[(int)r->y_text % 64
					* r->tex[r->id].sizeline + (int)r->x_text % 64
						* r->tex[r->id].bpp / 8]) != 0)
					put_pxl_to_img_sprite(r, r->s->stripe, y);
				y++;
			}
		}
		r->s->stripe++;
	}
}

void	draw_sprite(t_struct *r, int i, double *zbuffer)
{
	double		inv_det;

	r->s->x = r->sprite_utils[i].x - r->posx + 0.5;
	r->s->y = r->sprite_utils[i].y - r->posy + 0.5;
	inv_det = 1.0 / (r->x_plane * r->dy - r->dx * r->y_plane);
	r->s->transformx = inv_det * (r->dy * r->s->x - r->dx * r->s->y);
	r->s->transformy = inv_det * ((-1 * r->y_plane)
		* r->s->x + r->x_plane * r->s->y);
	r->s->screenx = (int)((r->win_l / 2)
		* (1 + r->s->transformx / r->s->transformy));
	r->s->height = abs((int)(r->win_h / (r->s->transformy)));
	r->s->starty = (-1 * r->s->height) / 2 + r->win_h / 2;
	if (r->s->starty < 0)
		r->s->starty = 0;
	r->s->endy = r->s->height / 2 + r->win_h / 2;
	if (r->s->endy >= r->win_h)
		r->s->endy = r->win_h - 1;
	r->s->width = abs((int)(r->win_h / r->s->transformy));
	r->s->startx = (-1 * r->s->width) / 2 + r->s->screenx;
	if (r->s->startx < 0)
		r->s->startx = 0;
	r->s->endx = r->s->width / 2 + r->s->screenx;
	if (r->s->endx >= r->win_l)
		r->s->endx = r->win_l - 1;
	draw_sprite2(r, zbuffer);
}

void	ft_sprite(t_struct *r, double *zbuffer, int i)
{
	r->id = 4;
	init_sprite(r);
	while (i < r->nb_sprite_map)
	{
		sort_sprite(r);
		draw_sprite(r, i, zbuffer);
		i++;
	}
}
