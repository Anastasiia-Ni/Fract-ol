/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:29:57 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/17 12:30:02 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "./mlx/mlx.h"

int	ft_mouse(int button, int x, int y, t_fract *fractal)
{
	if (button == 1)
	{
		fractal->set_x -= (fractal->width / 2 - x) * 0.00004;
		fractal->set_y += (fractal->height / 2 - y) * 0.00004;
	}
	else if (button == 4 && fractal->zoom > 0.000001L)
	{
		fractal->set_x -= fractal->width / 2 - x;
		fractal->set_y += fractal->height / 2 - y;
		fractal->zoom *= 1.1L;
		fractal->set_x /= 1.1L;
		fractal->set_y /= 1.1L;
	}
	else if (button == 5)
	{
		fractal->set_x -= fractal->width / 2 - x;
		fractal->set_y += fractal->height / 2 - y;
		fractal->zoom /= 1.1L;
		fractal->set_x *= 1.1L;
		fractal->set_y *= 1.1L;
	}
	ft_define_fractal(fractal);
	return (0);
}

static int	ft_key_cont(int key, t_fract *fractal)
{
	if (key == 53)
	{
		ft_free_fractol(fractal);
		exit(1);
	}
	else if (key == 24)
	{
		if ((long)fractal->max_iter + 50 < 2000)
			fractal->max_iter += 50;
		ft_update_palette(fractal);
	}
	else if (key == 123)
		fractal->set_x += 10.1;
	else if (key == 124)
		fractal->set_x -= 10.1;
	else if (key == 126)
		fractal->set_y -= 10.1;
	else if (key == 125)
		fractal->set_y += 10.1;
	else if (key == 29)
	{
		fractal->f_range += 1;
		ft_update_palette(fractal);
	}
	return (0);
}

int	ft_key(int key, t_fract *fractal)
{
	if (key == 31)
	{
		fractal->zoom /= 1.1L;
		fractal->set_x *= 1.1L;
		fractal->set_y *= 1.1L;
	}
	else if (key == 35)
	{
		fractal->zoom *= 1.1L;
		fractal->set_x /= 1.1L;
		fractal->set_y /= 1.1L;
	}
	else if (key == 27)
	{
		if ((long)fractal->max_iter - 50 > 0)
			fractal->max_iter -= 50;
		ft_update_palette(fractal);
	}
	ft_key_cont(key, fractal);
	ft_define_fractal(fractal);
	return (0);
}

int	ft_julia_motion(int x, int y, t_fract *fractal)
{
	if (fractal->name == julia)
	{
		fractal->julia = ft_init_complex(4 * ((double)x / WIDHT \
		- 0.9), 4 * ((double)(HEIGHT - y) / HEIGHT - 0.9));
		ft_define_fractal(fractal);
	}
	return (0);
}
