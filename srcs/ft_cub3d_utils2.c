/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 10:47:37 by lacruype          #+#    #+#             */
/*   Updated: 2020/01/15 10:55:23 by lacruype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_f_space(char *line, int *i)
{
	while (line[*i] != 'F' && line[*i])
		(*i)++;
	(*i)++;
	while (line[(*i)] == ' ' && line[*i])
		(*i)++;
}

void	ft_c_space(char *line, int *i)
{
	while (line[*i] != 'C' && line[*i])
		(*i)++;
	(*i)++;
	while (line[(*i)] == ' ' && line[*i])
		(*i)++;
}
