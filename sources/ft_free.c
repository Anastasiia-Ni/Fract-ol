/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:31:54 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/17 10:28:30 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_free_display(t_disp	*display, int i)
{
	int	xy;
	int	j;

	xy = 0;
	if (display)
	{
		if (i == 0)
			xy = display->width;
		if (display->img.img)
			mlx_destroy_image(display->mlx, display->img.img);
		if (display->mlx_ptr)
			mlx_destroy_window(display->mlx, display->mlx_ptr);
		if (display->mlx)
			free(display->mlx);
		if (display->buffer)
		{
			j = 0;
			while (j < xy)
				free(display->buffer[j++]);
			free(display->buffer);
		}
		free(display);
	}
}

void	ft_free_fractol(t_fract *fractal)
{
	if (fractal->display)
		ft_free_display(fractal->display, 0);
	if (fractal->palette)
		free(fractal->palette);
	free(fractal);
}

int	exit_hook(t_fract *fractal)
{
	if (fractal)
		ft_free_fractol(fractal);
	exit(1);
}
