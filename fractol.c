/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 04:48:42 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/06 11:05:44 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./mlx/include/MLX42/MLX42.h"

int	main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init(900,900, "SailAway", 0);
	if (!mlx_ptr)
		return (1);
	mlx_loop(mlx_ptr);
	free(mlx_ptr);
}
