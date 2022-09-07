/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_cub3d4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rledrin <rledrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 16:16:22 by lacruype          #+#    #+#             */
/*   Updated: 2020/01/13 13:30:47 by rledrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_check_map_content2(t_struct *r)
{
	int i;
	int j;
	int check;

	i = -1;
	check = 0;
	r->nb_sprite_map = 0;
	while (r->map[++i] != NULL)
	{
		j = -1;
		while (r->map[i][++j] != '\0')
		{
			if ((r->map[i][j] == 'N' || r->map[i][j] == 'S' ||
				r->map[i][j] == 'E' || r->map[i][j] == 'W') && check == 1)
				ft_error(3, r);
			else if (r->map[i][j] == 'N' || r->map[i][j] == 'S' ||
				r->map[i][j] == 'E' || r->map[i][j] == 'W')
				check = 1;
			if (r->map[i][j] == '2')
				r->nb_sprite_map++;
		}
	}
	if (check == 0)
		ft_error(3, r);
	return (0);
}
