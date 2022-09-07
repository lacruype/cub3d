/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 13:09:26 by lacruype          #+#    #+#             */
/*   Updated: 2020/01/15 10:30:16 by lacruype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_init_player(t_struct *r)
{
	r->move_speed = 0.25;
	r->rot_spd = 0.08;
	r->forward = 0;
	r->mvleft = 0;
	r->mvright = 0;
	r->rotleft = 0;
	r->rotright = 0;
	r->back = 0;
}

void		ft_init(t_struct *r)
{
	if (r->cardaxe == 'n' || r->cardaxe == 's')
	{
		r->y_plane = 0.0;
		r->x_plane = 0.66;
	}
	else
	{
		r->y_plane = 0.66;
		r->x_plane = 0.0;
	}
	r->x_text = 0;
	r->y_text = 0;
	ft_init_player(r);
}

void		ft_arg(int ac, char **av, t_struct *r)
{
	int i;

	if (ac < 2 || ac > 3)
		ft_error(7, r);
	i = ft_strlen_gnl(av[1]);
	if (av[1][i - 1] != 'b' || av[1][i - 2] != 'u'
		|| av[1][i - 3] != 'c' || av[1][i - 4] != '.')
		ft_error(1, r);
	if (ac == 3)
	{
		if (ft_strncmp(av[2], "-save", ft_strlen_gnl(av[2])) == 0)
			r->save = 1;
		else
			ft_error(1, r);
	}
}

void		ft_init_cub(t_struct *r, int ac, char **av)
{
	int i;

	i = 0;
	r->map_was_created = 0;
	r->check_key_roof = 0;
	ft_arg(ac, av, r);
	if ((r->fd = open(av[1], O_RDONLY)) != 3)
		ft_error(1, r);
	r->map_to_split = ft_strnew(0);
	while (get_next_line(r->fd, &r->line) == 1)
	{
		ft_parsing_cub3d(r);
		free(r->line);
	}
	ft_parsing_cub3d(r);
	free(r->line);
	r->map_to_split = ft_check_map_spaces(r);
	if (!(r->map = ft_split(r->map_to_split, '\n')))
		ft_error(10, r);
	r->map_was_created = 1;
	free(r->map_to_split);
	close(r->fd);
	if (ft_check_map(r) != 0)
		return ;
}

int			main(int ac, char **av)
{
	t_struct	r;

	ft_init_cub(&r, ac, av);
	r.mlx = mlx_init();
	r.window = mlx_new_window(r.mlx, r.win_l, r.win_h, "Cub3D");
	r.window_was_created = 1;
	ft_spawn(&r);
	ft_init(&r);
	init_texture(&r);
	mlx_hook(r.window, 2, 1L << 0, downhook, &r);
	mlx_hook(r.window, 3, 1L << 1, uphook, &r);
	mlx_hook(r.window, 17, 1L << 17, ft_exit, &r);
	if (!(r.s = malloc(sizeof(t_sprite) * (2))))
		ft_error(9, &r);
	r.s_was_created = 1;
	if (!(r.sprite_utils = malloc(sizeof(t_sprite_u) * r.nb_sprite_map)))
		ft_error(9, &r);
	r.sprite_was_created = 1;
	ray_casting(&r);
	if (r.save == 1)
		save_bmp_file(&r);
	mlx_loop_hook(r.mlx, loop_hook, &r);
	mlx_loop(r.mlx);
	return (0);
}
