/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:08:53 by anifanto          #+#    #+#             */
/*   Updated: 2021/11/17 13:45:25 by anifanto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WIDHT 1200
# define HEIGHT 600

# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_display
{
	void			*mlx;
	void			*mlx_ptr;
	unsigned int	**buffer;
	t_img			img;
	int				width;
}					t_disp;

typedef struct s_complex
{
	double	re;
	double	im;
}			t_complex;

enum e_fractal {mandelbrot, mandelbar, julia};

typedef struct s_fractal
{
	enum e_fractal	name;
	int				x;
	int				y;
	double			set_x;
	double			set_y;
	long double		zoom;
	int				max_iter;
	int				width;
	int				height;
	int				f_range;
	unsigned int	*palette;
	t_disp			*display;
	t_complex		julia;
}					t_fract;

int			main(int argc, char **argv);
int			ft_check_input(int argc, char **argv, t_fract *fractal);
int			ft_mandelbrot(int x, int y, t_fract *fractal);
int			ft_julia(int x, int y, t_fract *fractal);
int			ft_tricorn(int x, int y, t_fract *fractal);
int			ft_update_palette(t_fract *fractal);
int			ft_mouse(int button, int x, int y, t_fract *fractal);
int			ft_key(int key, t_fract *fractal);
void		ft_define_fractal(t_fract *fractal);
void		ft_free_fractol(t_fract *fractal);
void		ft_free_display(t_disp	*display, int i);
void		ft_screen(t_fract *fractal);
t_disp		*init_display(int width, int height);
t_complex	ft_init_complex(double re, double im);
int			ft_julia_motion(int x, int y, t_fract *fractal);
int			exit_hook(t_fract *fractal);

#endif
