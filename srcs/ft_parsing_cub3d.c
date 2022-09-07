/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_cub3d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:16:01 by lacruype          #+#    #+#             */
/*   Updated: 2020/01/15 11:14:10 by lacruype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_resolution(char *line, t_struct *r)
{
	int i;

	i = 0;
	if (r->check_key_res == 1)
		ft_error(8, r);
	while (line[i] != 'R')
		i++;
	i++;
	r->win_l = ft_atoi(&line[i]);
	while (line[i] == ' ')
		i++;
	while (ft_isdigit(line[i]) == 1)
		i++;
	r->win_h = ft_atoi(&line[i]);
	if (r->win_l > 2560 || r->win_l < 40)
		r->win_l = 2560;
	if (r->win_h > 1440 || r->win_h < 40)
		r->win_h = 1440;
	while ((r->win_l % 2 == 1 || ((r->win_l / 2) % 2 == 1)) && r->win_l > 1)
		r->win_l -= 1;
	while ((r->win_h % 2 == 1 || ((r->win_h / 2) % 2 == 1)) && r->win_h > 1)
		r->win_h -= 1;
	r->check_key_res = 1;
}

void	ft_color_roof(char *line, t_struct *r)
{
	int i;
	int	tmp;
	int	div;
	int cpt;

	i = 0;
	cpt = -1;
	div = 65536;
	r->c = 0;
	if (r->check_key_roof == 1)
		ft_error(8, r);
	ft_c_space(line, &i);
	while (cpt++ < 3 && line[i])
	{
		tmp = ft_atoi(&line[i]);
		if (tmp > 255 || tmp < 0)
			ft_error(2, r);
		r->c += (tmp * div);
		div /= 256;
		while (line[i] != ',' && line[i])
			i++;
		i++;
	}
	r->check_key_roof = 1;
}

void	ft_color_floor(char *line, t_struct *r)
{
	int i;
	int	tmp;
	int	div;
	int cpt;

	i = 0;
	cpt = -1;
	div = 65536;
	r->f = 0;
	if (r->check_key_floor == 1)
		ft_error(8, r);
	ft_f_space(line, &i);
	while (cpt++ < 3 && line[i])
	{
		tmp = ft_atoi(&line[i]);
		if (tmp > 255 || tmp < 0)
			ft_error(2, r);
		r->f += (tmp * div);
		div /= 256;
		while (line[i] != ',' && line[i])
			i++;
		i++;
	}
	r->check_key_floor = 1;
}

void	ft_path_sprite(char *line, t_struct *r)
{
	int i;

	i = 0;
	if (r->check_key_sprite == 1)
		ft_error(8, r);
	while (line[i] != 'S')
		i++;
	i++;
	while (line[i] == ' ')
		i++;
	r->sprite_name = ft_strdup((char*)&line[i]);
	r->check_key_sprite = 1;
}

void	ft_parsing_cub3d(t_struct *r)
{
	int i;

	ft_too_much_lines(r, &i);
	if (r->line[i] == 'R')
		ft_resolution(r->line, r);
	else if (r->line[i] == 'C')
		ft_color_roof(r->line, r);
	else if (r->line[i] == 'F')
		ft_color_floor(r->line, r);
	else if (r->line[i] == 'S' && r->line[i + 1] == 'O')
		ft_path_south(r->line, r);
	else if (r->line[i] == 'S')
		ft_path_sprite(r->line, r);
	else if (r->line[i] == 'N' && r->line[i + 1] == 'O')
		ft_path_north(r->line, r);
	else if (r->line[i] == 'W' && r->line[i + 1] == 'E')
		ft_path_west(r->line, r);
	else if (r->line[i] == 'E' && r->line[i + 1] == 'A')
		ft_path_east(r->line, r);
	else if (r->line[i] == '1')
		r->map_to_split = ft_strjoin_cub3d(r->map_to_split, r->line);
	else if (r->line[i] == '\0')
		return ;
	else
		ft_error(8, r);
}
