/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_cub3d3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 12:05:42 by lacruype          #+#    #+#             */
/*   Updated: 2020/01/13 15:49:04 by lacruype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_check_map_spaces(t_struct *r)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	while (r->map_to_split[i])
	{
		if (r->map_to_split[i] != ' ')
			j++;
		i++;
	}
	if (!(dst = malloc(sizeof(char) * (j + 1))))
		ft_error(9, r);
	i = 0;
	j = 0;
	while (r->map_to_split[i])
	{
		while (r->map_to_split[i] == ' ')
			i++;
		dst[j++] = r->map_to_split[i++];
	}
	dst[j] = '\0';
	free(r->map_to_split);
	return (dst);
}

int		ft_check_map_line_len(t_struct *r)
{
	int i;
	int j;

	i = 0;
	j = 0;
	r->map_line_len = ft_strlen_gnl(r->map[i]);
	i++;
	while (r->map[i] != NULL)
	{
		j = ft_strlen_gnl(r->map[i]);
		if (j != r->map_line_len)
		{
			ft_error(3, r);
			return (-1);
		}
		i++;
	}
	return (0);
}

int		ft_check_map_content(t_struct *r)
{
	int i;
	int j;

	i = 0;
	while (r->map[i] != NULL)
	{
		j = 0;
		while (r->map[i][j] != '\0')
		{
			if ((r->map[i][j] != '0' && r->map[i][j] != '1'
				&& r->map[i][j] != '2' && r->map[i][j] != 'N'
				&& r->map[i][j] != 'S' && r->map[i][j] != 'E'
				&& r->map[i][j] != 'W'))
			{
				ft_error(3, r);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_check_map_walls(t_struct *r)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (r->map[i] != NULL)
	{
		if (r->map[i][j] != '1' || r->map[i][r->map_line_len - 1] != '1')
		{
			ft_error(3, r);
			return (-1);
		}
		i++;
	}
	while (r->map[0][j] != '\0')
	{
		if (r->map[0][j] != '1' || r->map[i - 1][j] != '1')
		{
			ft_error(3, r);
			return (-1);
		}
		j++;
	}
	return (0);
}

int		ft_check_map(t_struct *r)
{
	int i;

	i = 0;
	if ((ft_check_map_line_len(r) != 0) ||
		(ft_check_map_content(r) != 0) ||
		(ft_check_map_walls(r) != 0) ||
		(ft_check_map_content2(r) != 0))
		return (-1);
	return (0);
}
