/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 04:48:42 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/05 05:25:50 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>

int	main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
} 