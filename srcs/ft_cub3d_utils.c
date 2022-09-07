/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 14:21:08 by lacruype          #+#    #+#             */
/*   Updated: 2020/01/15 10:42:16 by lacruype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_color_walls(t_struct *r)
{
	if (r->side == 1 && r->y_raydir > 0)
		r->id = 0;
	else if (r->side == 1 && r->y_raydir <= 0)
		r->id = 1;
	else if (r->side == 0 && r->x_raydir > 0)
		r->id = 2;
	else if (r->side == 0 && r->x_raydir <= 0)
		r->id = 3;
	else
		ft_error(4, r);
}

void	ft_too_much_lines(t_struct *r, int *i)
{
	*i = 0;
	while (r->line[*i] == ' ' && r->line[*i] != '\n' && r->line[*i])
		(*i)++;
	if (ft_strchr_gnl("RNSWEFC1\n", r->line[*i]) == NULL)
		ft_error(1, r);
}

char	*ft_strjoin_cub3d(char *s1, char *s2)
{
	char	*str;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen_gnl(s1) + ft_strlen_gnl(s2);
	if (!(str = (char *)malloc(sizeof(char) * (i + 2))))
		return (0);
	i = -1;
	if (s1)
	{
		while (s1[++i])
			str[i] = s1[i];
		str[i++] = '\n';
	}
	free(s1);
	if (s2)
	{
		while (*s2)
			str[i++] = *s2++;
		str[i] = '\0';
		return (str);
	}
	return (0);
}

int		ft_open(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (0);
}
