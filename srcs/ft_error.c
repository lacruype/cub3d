/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:17:22 by lacruype          #+#    #+#             */
/*   Updated: 2020/01/15 10:42:24 by lacruype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_error(int error, t_struct *r)
{
	ft_putstr_fd("Error\n", 1);
	if (error == 1)
		ft_putstr_fd("There's a line in the .CUB that's wrong !\n", 1);
	else if (error == 2)
		ft_putstr_fd("Colors aren't valid !\n", 1);
	else if (error == 3)
		ft_putstr_fd("Map is incorrect !\n", 1);
	else if (error == 4)
		ft_putstr_fd("Color of the walls weird !\n", 1);
	else if (error == 5)
		ft_putstr_fd("Resolution isn't valid !\n", 1);
	else if (error == 6)
		ft_putstr_fd("A file isn't valid !\n", 1);
	else if (error == 7)
		ft_putstr_fd("Missing file !\n", 1);
	else if (error == 8)
		ft_putstr_fd("Double key in .CUB !\n", 1);
	else if (error == 9)
		ft_putstr_fd("Malloc memory problem !\n", 1);
	else if (error == 10)
		ft_putstr_fd("MAPPPPPP\n", 1);
	ft_exit(r);
}

int			ft_exit(t_struct *r)
{
	int i;

	i = 0;
	if (r->map_was_created == 1)
	{
		while (r->map[i] != NULL)
		{
			free(r->map[i]);
			i++;
		}
		free(r->map);
	}
	if (r->s_was_created == 1)
		free(r->s);
	if (r->sprite_was_created == 1)
		free(r->sprite_utils);
	if (r->tex_was_created == 1)
		free(r->tex);
	if (r->file_was_created == 1)
		free(r->file);
	if (r->window_was_created == 1)
		mlx_destroy_window(r->mlx, r->window);
	exit(0);
	return (0);
}
