/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhayoun <nhayoun@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 12:41:27 by nhayoun           #+#    #+#             */
/*   Updated: 2024/04/23 17:08:23 by nhayoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol_bonus.h"

void	ft_putstr_err(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	write(2, s, i);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if ((unsigned char)s1[i] - (unsigned char)s2[i] > 0)
			return (1);
		else if ((unsigned char)s1[i] - (unsigned char)s2[i] < 0)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_double(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] <= 32)
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] == '.')
		i++;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (i == ft_strlen(str))
		return (1);
	else
		return (0);
}

void	ft_tolower(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}
