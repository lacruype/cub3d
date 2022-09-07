/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_nsew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 20:59:47 by lacruype          #+#    #+#             */
/*   Updated: 2020/01/13 16:26:58 by lacruype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_path_north(char *line, t_struct *r)
{
	int i;

	i = 0;
	if (r->check_key_north == 1)
		ft_error(8, r);
	while (line[i] != 'O')
		i++;
	i++;
	while (line[i] == ' ')
		i++;
	r->no = ft_strdup((char*)&line[i]);
	r->check_key_north = 1;
}

void	ft_path_south(char *line, t_struct *r)
{
	int i;

	i = 0;
	if (r->check_key_south == 1)
		ft_error(8, r);
	while (line[i] != 'O')
		i++;
	i++;
	while (line[i] == ' ')
		i++;
	r->so = ft_strdup((char*)&line[i]);
	r->check_key_south = 1;
}

void	ft_path_west(char *line, t_struct *r)
{
	int i;

	i = 0;
	if (r->check_key_west == 1)
		ft_error(8, r);
	while (line[i] != 'E')
		i++;
	i++;
	while (line[i] == ' ')
		i++;
	r->we = ft_strdup((char*)&line[i]);
	r->check_key_west = 1;
}

void	ft_path_east(char *line, t_struct *r)
{
	int i;

	i = 0;
	if (r->check_key_east == 1)
		ft_error(8, r);
	while (line[i] != 'A')
		i++;
	i++;
	while (line[i] == ' ')
		i++;
	r->ea = ft_strdup((char*)&line[i]);
	r->check_key_east = 1;
}
