/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 04:38:23 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/16 19:07:01 by nhayoun          ###   ########.fr       */
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
	#define WHITE       0xFFFFFF
	#define BLACK       0x000000
	#define RED         0xFF0000
	#define GREEN       0x00FF00
	#define BLUE        0x0000FF
	#define YELLOW      0xFFFF00
	#define MAGENTA     0xFF00FF
	#define CYAN        0x00FFFF
	#define ORANGE      0xFFA500
	#define PURPLE      0x800080
	#define PINK        0xFFC0CB
	#define GRAY        0x808080
	
	#define MAJESTIC_1  0x5A175D
	#define MAJESTIC_2  0x67074E
	#define MAJESTIC_3  0xDD9933
	#define MAJESTIC_4  0xBBBBBB
	#define MAJESTIC_5  0xAAAAAA

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
}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

void		fractal_init(t_fractal *fractal);

void		fractal_render(t_fractal *fractal);

double 		scaling_value(double ival, double omin, double omax, double imin, double imax);

t_complex 	sum_complex(t_complex z1, t_complex z2);

t_complex 	sqrt_complex(t_complex z);

void		ft_putstr(char *s);

int			ft_strncmp(const char *s1, const char *s2, size_t n);

void		ft_tolower(char *str);

double		ft_atod(char *str);

#endif