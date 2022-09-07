/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacruype <lacruype@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 11:00:09 by rledrin           #+#    #+#             */
/*   Updated: 2020/01/13 18:11:38 by lacruype         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void			write_rgb(t_struct *r, int height, int width, int fd)
{
	unsigned char	abc[3];
	int				i_j[2];
	int				*img_ptr;

	img_ptr = (void*)r->img.img;
	i_j[0] = 0;
	while (i_j[0] < height)
	{
		i_j[1] = 0;
		while (i_j[1] < width)
		{
			abc[0] = (240 & (img_ptr[(height - i_j[0]) *
							width + i_j[1]]) >> 16);
			abc[1] = (240 & (img_ptr[(height - i_j[0]) *
							width + i_j[1]]) >> 8);
			abc[2] = (240 & img_ptr[(height - i_j[0]) *
							width + i_j[1]]);
			write(fd, abc + 2, 1);
			write(fd, abc + 1, 1);
			write(fd, abc, 1);
			i_j[1]++;
		}
		i_j[0]++;
	}
}

unsigned char	*create_bitmap_file_header(int height,
											int width, int padding_size)
{
	int						file_size;
	static unsigned char	file_header[] = {
		0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
		0, 0, 0, 0,
	};

	file_size = 14 + 40 +
		(3 * width + padding_size) * height;
	file_header[0] = (unsigned char)('B');
	file_header[1] = (unsigned char)('M');
	file_header[2] = (unsigned char)(file_size);
	file_header[3] = (unsigned char)(file_size >> 8);
	file_header[4] = (unsigned char)(file_size >> 16);
	file_header[5] = (unsigned char)(file_size >> 24);
	file_header[10] = (unsigned char)(14 + 40);
	return (file_header);
}

unsigned char	*create_bitmap_info_header(int height, int width)
{
	static unsigned char info_header[] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
	};

	info_header[0] = (unsigned char)(40);
	info_header[4] = (unsigned char)(width);
	info_header[5] = (unsigned char)(width >> 8);
	info_header[6] = (unsigned char)(width >> 16);
	info_header[7] = (unsigned char)(width >> 24);
	info_header[8] = (unsigned char)(height);
	info_header[9] = (unsigned char)(height >> 8);
	info_header[10] = (unsigned char)(height >> 16);
	info_header[11] = (unsigned char)(height >> 24);
	info_header[12] = (unsigned char)(1);
	info_header[14] = (unsigned char)(3 * 8);
	return (info_header);
}

void			generate_bitmap_image(t_struct *r, int height, int width)
{
	int					fd;
	unsigned char		*file_header;
	unsigned char		*info_header;

	file_header = create_bitmap_file_header(height, width,
							(4 - (width * 3) % 4) % 4);
	info_header = create_bitmap_info_header(height, width);
	fd = open("save.bmp", O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 00700);
	if (fd < 0)
	{
		ft_putstr_fd("Error\n", 1);
		ft_putstr_fd("Create save.bmp file.", 1);
		ft_exit(r);
	}
	write(fd, file_header, 14);
	write(fd, info_header, 40);
	write_rgb(r, height, width, fd);
	close(fd);
}

void			save_bmp_file(t_struct *r)
{
	int		height;
	int		width;

	height = r->win_h;
	if (height % 2 == 1)
		height -= 1;
	width = r->win_l;
	if (width % 2 == 1)
		width -= 1;
	generate_bitmap_image(r, height, width);
	ft_exit(r);
}
