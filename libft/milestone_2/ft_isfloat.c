/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfloat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:42:45 by vicalons          #+#    #+#             */
/*   Updated: 2025/02/27 14:21:50 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_isfloat(char *str)
{
	int	i;
	int	point;

	i = 0;
	point = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
		{
			if (str[i] == '.')
				point += 1;
			if (point > 1)
				return (0);
			i++;
		}
		else
			return (0);
	}
	return (1);
}
