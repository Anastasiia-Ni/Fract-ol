/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:01:25 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/17 13:23:33 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	ft_is_double(char *str)
{
	if (!ft_isdigit(*str) && *str != '-')
		return (0);
	if (str[0] == '-' && !ft_isdigit(str[1]))
		return (0);
	if (!ft_strchr(str, '.') || ft_strchr(str, '.') != ft_strrchr(str, '.'))
		return (0);
	if (ft_strlen(str) > 10)
		return (0);
	return (1);
}

static	int	ft_check_double(t_complex *julia, char *double1, char *double2)
{
	if (!ft_is_double(double1))
	{
		ft_putendl_fd("Input Error\n./fractol \
Mandelbrot\n./fractol Mandelbar\n./fractol Julia x.x y.y", 2);
		return (0);
	}
	if (!ft_is_double(double2))
	{
		ft_putendl_fd("Input Error\n./fractol \
Mandelbrot\n./fractol Mandelbar\n./fractol Julia x.x y.y", 2);
		return (0);
	}
	julia->re = ft_atod(double1);
	julia->im = ft_atod(double2);
	return (1);
}

int	ft_check_input(int argc, char **argv, t_fract *fractal)
{
	if (argc == 2 && ((ft_strcmp(argv[1], "Mandelbrot") == 0) || \
		(ft_strcmp(argv[1], "Mandelbar") == 0)))
	{
		if (argv[1][7] == 'r')
			fractal->name = mandelbrot;
		else
			fractal->name = mandelbar;
		return (1);
	}
	else if (argc == 4 && (ft_strcmp(argv[1], "Julia") == 0))
	{
		fractal->julia = ft_init_complex(-0.4, 0.6);
		fractal->name = julia;
		if (!ft_check_double(&fractal->julia, argv[2], argv[3]))
		{
			return (0);
		}
		return (1);
	}
	else
		ft_putendl_fd("Input Error\n./fractol \
Mandelbrot\n./fractol Mandelbar\n./fractol Julia x.x y.y", 2);
	return (0);
}
