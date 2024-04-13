/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 04:38:23 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/13 15:40:31 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

	#include "./MLX42/include/MLX42/MLX42.h"
	#include "./libr/libr.h"
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

typedef struct s_fractal
{
	void	*mlx_ptr;
	char	*name;
	mlx_image_t	*img;
	double	escape_value;
	int		iterations;
}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

void	fractal_init(t_fractal *fractal);

void	fractal_render(t_fractal *fractal);

double scaling_value(double ival, double omin, double omax, double imin, double imax);

t_complex sum_complex(t_complex z1, t_complex z2);

t_complex sqrt_complex(t_complex z);

#endif