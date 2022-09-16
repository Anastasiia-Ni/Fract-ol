/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:38:32 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/17 13:48:01 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	copy_buffer_to_image(t_fract *fractal)
{
	int	x;
	int	y;

	x = 0;
	while (x < fractal->width)
	{
		y = 0;
		while (y < fractal->height)
		{
			my_mlx_pixel_put(&fractal->display->img, x, y, \
			fractal->display->buffer[x][y]);
			y++;
		}
		x++;
	}
}

void	ft_screen(t_fract *fractal)
{
	copy_buffer_to_image(fractal);
	mlx_put_image_to_window(fractal->display->mlx, fractal->display->mlx_ptr,
		fractal->display->img.img, 0, 0);
	mlx_loop(fractal->display->mlx);
}
