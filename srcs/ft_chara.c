/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chara.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:21:11 by rledrin           #+#    #+#             */
/*   Updated: 2020/01/13 12:56:22 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	north(t_struct *r)
{
	r->dx = 0.0;
	r->dy = -1.0;
	r->cardaxe = 'n';
}

void	south(t_struct *r)
{
	r->dx = 0.0;
	r->dy = 1.0;
	r->cardaxe = 's';
}

void	ft_spawn2(t_struct *r, int i, int j)
{
	if (r->map[i][j] == 'N' || r->map[i][j] == 'E'
		|| r->map[i][j] == 'S' || r->map[i][j] == 'W')
	{
		r->posx = (double)(j + 0.5);
		r->posy = (double)(i + 0.5);
		if (r->map[i][j] == 'N')
			north(r);
		else if (r->map[i][j] == 'S')
			south(r);
		else if (r->map[i][j] == 'E')
		{
			r->dx = 1.0;
			r->dy = 0.0;
			r->cardaxe = 'e';
		}
		else if (r->map[i][j] == 'W')
		{
			r->dx = -1.0;
			r->dy = 0.0;
			r->cardaxe = 'w';
		}
		r->map[i][j] = '0';
		return ;
	}
}

void	ft_spawn(t_struct *r)
{
	int	i;
	int	j;

	i = 0;
	while (r->map[i])
	{
		j = 0;
		while (r->map[i][j])
		{
			ft_spawn2(r, i, j);
			j++;
		}
		i++;
	}
}
