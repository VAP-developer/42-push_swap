/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:36:57 by vicalons          #+#    #+#             */
/*   Updated: 2025/02/27 16:13:47 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_sgn(char c)
{
	if (c == '-')
		return (-1);
	return (0);
}

double	ft_atof(char *str)
{
	long	integer;
	double	decimal;
	double	power;
	int		sgn;

	integer = 0;
	decimal = 0;
	sgn = 1;
	power = 1;
	if (ft_isfloat(str) == 0)
		return (0);
	if (*str == '-' || *str == '+')
		sgn = ft_sgn(*str++);
	while (*str && *str != '.')
		integer = integer * 10 + (*str++ - '0');
	if (*str == '.')
		str++;
	while (*str)
	{
		power /= 10;
		decimal += (*str++ - '0') * power;
	}
	return ((integer + decimal) * sgn);
}
