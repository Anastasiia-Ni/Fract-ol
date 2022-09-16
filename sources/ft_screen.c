/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_screen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:39:02 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/17 13:48:07 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	init_window(t_disp	*display)
{
	display->mlx = mlx_init();
	if (!display->mlx)
	{
		ft_putendl_fd("Error init window", 2);
		free(display);
		return (0);
	}
	display->mlx_ptr = mlx_new_window(display->mlx, WIDHT, HEIGHT, "FRACT-OL");
	if (!display->mlx_ptr)
	{
		ft_putendl_fd("Error init window", 2);
		free(display);
		return (0);
	}
	return (1);
}

static int	init_buffer(t_disp	*display)
{
	int	i;

	display->buffer = ft_calloc(WIDHT, sizeof(unsigned int *));
	if (display->buffer)
	{
		i = 0;
		while (i < WIDHT)
		{
			display->buffer[i] = ft_calloc(HEIGHT, sizeof(unsigned int));
			if (!display->buffer[i])
			{
				ft_putendl_fd("Error memory allocation", 2);
				ft_free_display(display, i);
				return (0);
			}
			i++;
		}
		return (1);
	}
	else
	{
		ft_putendl_fd("Error memory allocation", 2);
		ft_free_display(display, 0);
		return (0);
	}
}

static int	init_screen(t_disp	*display)
{
	display->img.img = mlx_new_image(display->mlx, WIDHT, HEIGHT);
	if (display->img.img)
	{
		display->img.addr = mlx_get_data_addr(display->img.img,
				&display->img.bits_per_pixel,
				&display->img.line_length,
				&display->img.endian);
		return (1);
	}
	else
	{
		ft_putendl_fd("Error init screen", 2);
		ft_free_display(display, 0);
		return (0);
	}
}

t_disp	*init_display(int width, int height)
{
	t_disp	*display;

	display = (t_disp *)malloc(sizeof(t_disp));
	if (display && height)
	{
		if (!init_window(display))
			return (NULL);
		if (!init_buffer(display))
			return (NULL);
		display->img.img = NULL;
		if (!init_screen(display))
			return (NULL);
	}
	display->width = width;
	return (display);
}
