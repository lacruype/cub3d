/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:16:33 by lacruype          #+#    #+#             */
/*   Updated: 2020/01/15 10:53:52 by lacruype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "../LIBFT/libft.h"
# include "../GNL/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# define TEXTURE_NB 5

typedef struct	s_img
{
	char		*img;
	int			bpp;
	int			sizeline;
	int			endian;
	int			width;
	int			height;
	void		*img_ptr;
}				t_img;

typedef struct	s_sprite_u
{
	int			x;
	int			y;
	double		sprite_dist;
}				t_sprite_u;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			bpp;
	int			sizeline;
	int			endian;
	int			width;
	int			height;
	double		sprite_dist;
	double		transformx;
	double		transformy;
	int			screenx;
	int			starty;
	int			startx;
	int			endx;
	int			endy;
	int			sprite_posx;
	int			sprite_posy;
	int			stripe;
}				t_sprite;

typedef struct	s_rays
{
	t_img		img;
	t_img		*tex;
	t_sprite	*s;
	t_sprite_u	*sprite_utils;
	double		x_plane;
	double		y_plane;
	double		x_cam;
	double		x_raypos;
	double		y_raypos;
	double		x_deltadist;
	double		y_deltadist;
	double		x_raydir;
	double		y_raydir;
	double		x_sidedist;
	double		y_sidedist;
	double		walldist;
	int			x_map;
	int			y_map;
	int			hit;
	int			side;
	int			x;
	int			y;
	int			lineheight;
	int			start;
	int			end;
	int			color;
	int			x_text;
	int			y_text;
	int			id;
	double		x_wall;
	char		*line;
	int			map_line_len;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sprite_name;
	int			f;
	int			c;
	char		*map_to_split;
	char		**map;

	int			win_l;
	int			win_h;
	void		*mlx;
	void		*window;
	double		dx;
	double		dy;
	double		move_speed;
	double		rot_spd;
	int			forward;
	int			rotleft;
	int			rotright;
	int			mvleft;
	int			mvright;
	int			back;
	double		posx;
	double		posy;
	int			x_step;
	int			y_step;
	double		old_player_dx;
	double		old_player_dy;
	double		old_x_plane;
	int			fd;
	char		cardaxe;
	char		**file;
	int			nb_sprite_map;
	int			save;
	int			check_key_res;
	int			check_key_roof;
	int			check_key_floor;
	int			check_key_south;
	int			check_key_north;
	int			check_key_west;
	int			check_key_sprite;
	int			check_key_east;
	int			window_was_created;
	int			map_was_created;
	int			s_was_created;
	int			sprite_was_created;
	int			tex_was_created;
	int			file_was_created;
}				t_struct;

void			ft_error(int error, t_struct *r);
void			ft_parsing_cub3d(t_struct *r);
void			ft_too_much_lines(t_struct *r, int *i);
void			ft_path_north(char *line, t_struct *r);
void			ft_path_east(char *line, t_struct *r);
void			ft_path_west(char *line, t_struct *r);
void			ft_path_south(char *line, t_struct *r);
void			ft_parsing_map(char *line, t_struct *r);
int				check_line_map(char *line);
char			*ft_strjoin_cub3d(char *s1, char *s2);
void			ft_draw_map(t_struct *r);
void			ft_spawn(t_struct *r);
int				downhook(int keycode, t_struct *r);
int				uphook(int keycode, t_struct *r);
int				loop_hook(t_struct *r);
void			move(t_struct *r);
void			rotate_left(t_struct *r);
void			rotate_right(t_struct *r);
char			*ft_check_map_spaces(t_struct *r);
int				ft_check_map(t_struct *r);
void			dda_init(t_struct *r);
void			dda(t_struct *r);
void			ray_casting_init(t_struct *r, int x);
void			ray_casting(t_struct *r);
void			draw_wall(int x, int start, int end, t_struct *r);
void			floor_and_ceiling(t_struct *r, int x);
void			load_textures(t_struct *r);
int				parser(t_struct *r, char **av);
int				check_side(t_struct *r);
int				parser2(t_struct *r, char **av);
int				check_map(char *buff, t_struct *r);
int				ft_check_map_content2(t_struct *r);
int				ft_exit(t_struct *r);
void			ft_color_walls(t_struct *r);
void			init_parser(t_struct *r);
void			init_texture(t_struct *r);
void			put_pxl_to_img(t_struct *r, int x, int y);
void			put_pxl_to_img_sprite(t_struct *r, int x, int y);
void			draw_sprite(t_struct *r, int i, double *zbufer);
void			sprite_dist(t_struct *r);
void			sort_sprite(t_struct *r);
void			init_sprite(t_struct *r);
void			save_bmp_file(t_struct *r);
int				ft_open(char *file);
void			ft_arg(int ac, char **av, t_struct *r);
void			ft_sprite(t_struct *r, double *zbuffer, int i);
void			ft_f_space(char *line, int *i);
void			ft_c_space(char *line, int *i);

#endif
