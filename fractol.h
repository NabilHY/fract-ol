/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 04:38:23 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/21 21:40:12 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

	#include "./MLX42/include/MLX42/MLX42.h"
	# include <stdlib.h>
	# include <unistd.h>
	#define WIDTH 800
	#define HEIGHT 800
	/*colors*/
	#define ERR_MSG "Invalid Input Try:\n->./fractol mandelbrot\n->./fractol julia <real(double)> <imag(double)\n>"

typedef struct s_fractal
{
	void	*mlx_ptr;
	char	*name;
	mlx_image_t	*img;
	double	escape_value;
	int		iterations;
	double		x_shift;
	double		y_shift;
	double		zoom;
	double		x_julia;
	double		y_julia;
	double		cursor_x;
	double		cursor_y;
	double		x_min;
	double		x_max;
	double		y_min;
	double		y_max;
}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

typedef	struct s_coor
{
	int		x;
	int		y;
}	t_coor;

void		fractal_init(t_fractal *fractal);

void		fractal_render(t_fractal *fractal);

double	scaling_value(double ival, double omin, double omax, double imax);

t_complex 	sum_complex(t_complex z1, t_complex z2);

t_complex 	sqrt_complex(t_complex z);

void		ft_putstr_err(char *s);

int			ft_double(char *str);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

void		ft_tolower(char *str);

double		ft_atod(char *str);

int			ft_strlen(char *str);

void		apply_zoom(t_fractal *fractal, double zoom);

void	cursor_coor(double xpos, double ypos, void *param);

void	scrollhook(double xdelta, double ydelta, void *param);

void	keyhook(mlx_key_data_t keydata, void *param);

#endif