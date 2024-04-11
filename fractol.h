/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 04:38:23 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/11 22:23:25 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H

	#include "./MLX42/include/MLX42/MLX42.h"
	#include "./libr/libr.h"
	#define WIDTH 1920
	#define HEIGHT 1080

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fractal
{
	void	*mlx_ptr;
	char	*name;
	t_img	img;
}	t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

void	fractal_init(t_fractal *fractal);

double	scaling_value(double omax, double imax, double imin, double ivalue);

#endif