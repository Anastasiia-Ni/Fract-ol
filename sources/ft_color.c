/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:29:58 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/17 11:33:58 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

unsigned int	ft_get_rgb(int r, int g, int b, int a)
{
	unsigned int	x;

	x = a << 24 | r << 16 | g << 8 | b ;
	return (x);
}

unsigned int	ft_update_color(t_fract *fractal, int dot)
{
	int		r;
	int		g;
	int		b;
	double	rate;

	rate = 5.0L * dot / fractal->max_iter;
	b = 255 * (1 - rate);
	r = 255 * (rate - 1);
	if (b < 0)
		b = 0;
	if (r < 0)
		r = 0;
	g = 255 - b - r;
	if (fractal->f_range % 5 == 1)
		return (ft_get_rgb(r, g, b, 0) * 1.001);
	else if (fractal->f_range % 5 == 2)
		return (0x00FFFFFF - ft_get_rgb(r, g, b, 0));
	else if (fractal->f_range % 5 == 3)
		return (0x0000FFFF - ft_get_rgb(r, g, b, 0));
	else if (fractal->f_range % 5 == 4)
		return (0x00424242 - ft_get_rgb(r, g, b, 0));
	else
		return (0x00123456 - ft_get_rgb(r, g, b, 0));
}

int	ft_update_palette(t_fract *fractal)
{
	int	i;

	i = 0;
	if (fractal->palette)
		free(fractal->palette);
	fractal->palette = ft_calloc(fractal->max_iter, sizeof(unsigned int));
	if (!fractal->palette)
	{
		ft_putendl_fd("Error memory allocation", 2);
		return (0);
	}
	while (i < fractal->max_iter)
	{
		fractal->palette[i] = ft_update_color(fractal, i);
		i++;
	}
	return (1);
}
