/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 12:30:21 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/17 12:30:21 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	ft_init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

int	ft_mandelbrot(int x, int y, t_fract *fractal)
{
	t_complex	c;
	t_complex	z;
	t_complex	z_tmp;
	int			i;

	z = ft_init_complex(0.0, 0.0);
	c.re = 2 * (x - fractal->width / 2.0 + fractal->set_x) * \
	(long double)(4.0 / fractal->width * fractal->zoom);
	c.im = (fractal->height / 2.0 - y + fractal->set_y) * \
	(long double)(4.0 / fractal->height * fractal->zoom);
	i = 0;
	while (i < fractal->max_iter)
	{
		if (pow(z.re, 2) + pow(z.im, 2) > 4)
			return (i);
		z_tmp = z;
		z.re = pow(z.re, 2) - pow(z.im, 2) + c.re;
		z.im = 2 * z_tmp.re * z_tmp.im + c.im;
		i++;
	}
	return (-1);
}

int	ft_julia(int x, int y, t_fract *fractal)
{
	t_complex	z;
	t_complex	z_tmp;
	int			i;

	z.re = 2 * (x - fractal->width / 2.0 + fractal->set_x) * \
	(long double)(4.0 / fractal->width * fractal->zoom);
	z.im = (fractal->height / 2.0 - y + fractal->set_y) * \
	(long double)(4.0 / fractal->height * fractal->zoom);
	i = 0;
	while (i < fractal->max_iter)
	{
		if (pow(z.re, 2) + pow(z.im, 2) > 4)
			return (i);
		z_tmp = z;
		z.re = (z.re * z.re) - (z.im * z.im) + fractal->julia.re;
		z.im = 2 * z_tmp.re * z_tmp.im + fractal->julia.im;
		i++;
	}
	return (-1);
}

int	ft_tricorn(int x, int y, t_fract *fractal)
{
	t_complex	z;
	t_complex	z_tmp;
	t_complex	c;
	int			i;

	z = ft_init_complex(0.0, 0.0);
	c.re = 2 * (x - fractal->width / 2.0 + fractal->set_x) * \
	(long double)(4.0 / fractal->width * fractal->zoom);
	c.im = (fractal->height / 2.0 - y + fractal->set_y) * \
	(long double)(4.0 / fractal->height * fractal->zoom);
	i = 0;
	while (i < fractal->max_iter)
	{
		if (pow(z.re, 2) + pow(z.im, 2) > 4)
			return (i);
		z_tmp = z;
		z.re = (z.re * z.re) - (z.im * z.im) + c.re;
		z.im = -2 * z_tmp.re * z_tmp.im + c.im;
		i++;
	}
	return (-1);
}
