/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:09:56 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/17 13:44:35 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_init_fractal(t_fract *fractal)
{
	fractal->zoom = 0.8L;
	fractal->max_iter = 200;
	fractal->set_x = 0;
	fractal->set_y = 0;
	fractal->width = WIDHT;
	fractal->height = HEIGHT;
	fractal->palette = NULL;
	fractal->f_range = 1;
	fractal->display = init_display(WIDHT, HEIGHT);
	if (!fractal->display)
	{
		free(fractal->palette);
		free(fractal);
		return ;
	}
	if (!ft_update_palette(fractal))
	{
		free(fractal->palette);
		free(fractal);
		return ;
	}
}

void	put_pixel(int dot, int x, int y, t_fract *fractal)
{
	if (dot < 0)
		fractal->display->buffer[x][y] = 0;
	else
		fractal->display->buffer[x][y] = fractal->palette[dot];
}

void	ft_define_fractal(t_fract *fractal)
{
	int	dot;

	fractal->x = 0;
	while (fractal->x < fractal->width)
	{
		fractal->y = 0;
		while (fractal->y < fractal->height)
		{
			if (fractal->name == mandelbrot)
				dot = ft_mandelbrot(fractal->x, fractal->y, fractal);
			else if (fractal->name == mandelbar)
				dot = ft_tricorn(fractal->x, fractal->y, fractal);
			else
				dot = ft_julia(fractal->x, fractal->y, fractal);
			put_pixel(dot, fractal->x, fractal->y, fractal);
			fractal->y += 1;
		}
		fractal->x += 1;
	}
	ft_screen(fractal);
}

int	main(int argc, char **argv)
{
	t_fract	*fractal;

	fractal = (t_fract *)malloc(sizeof(t_fract));
	if (!fractal)
		return (1);
	if (!ft_check_input(argc, argv, fractal))
	{
		free (fractal);
		exit (1);
	}
	ft_init_fractal(fractal);
	mlx_mouse_hook(fractal->display->mlx_ptr, ft_mouse, fractal);
	mlx_hook(fractal->display->mlx_ptr, 17, 0, exit_hook, fractal);
	mlx_key_hook(fractal->display->mlx_ptr, ft_key, fractal);
	ft_define_fractal(fractal);
	if (fractal->name == julia)
		mlx_hook(fractal->display->mlx_ptr, 6, 0, ft_julia_motion, fractal);
	mlx_loop(fractal->display->mlx);
	ft_free_fractol(fractal);
	return (0);
}
