/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 14:08:44 by atodesco          #+#    #+#             */
/*   Updated: 2020/01/13 16:27:41 by lacruype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_parser(t_struct *r)
{
	r->file[0] = r->so;
	r->file[1] = r->no;
	r->file[2] = r->ea;
	r->file[3] = r->we;
	r->file[4] = r->sprite_name;
}

void	init_texture(t_struct *r)
{
	int i;

	if (!(r->tex = malloc(sizeof(t_img) * TEXTURE_NB)))
		ft_error(9, r);
	r->tex_was_created = 1;
	if (!(r->file = malloc(sizeof(char *) * TEXTURE_NB)))
		ft_error(9, r);
	r->file_was_created = 1;
	init_parser(r);
	i = 0;
	while (i < TEXTURE_NB)
	{
		if (ft_open(r->file[i]) == -1)
			ft_error(6, r);
		r->tex[i].img_ptr = mlx_xpm_file_to_image(r->mlx,
			r->file[i], &r->tex[i].width, &r->tex[i].height);
		r->tex[i].img = mlx_get_data_addr(r->tex[i].img_ptr,
			&r->tex[i].bpp, &r->tex[i].sizeline,
				&r->tex[i].endian);
		if (r->tex[i].img == NULL)
			ft_error(1, r);
		i++;
	}
}
