/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vicalons <vicalons@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:40:45 by vicalons          #+#    #+#             */
/*   Updated: 2025/03/03 02:45:26 by vicalons         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int64_t	ft_atold(char *str)
{
	int	i;
	int	sgn;
	int64_t	nbr;

	if (!ft_isint(str))
		return (0);
	i = 0;
	sgn = 1;
	nbr = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	while (str[i])
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (sgn * nbr);
}

static void	free_char(char **arg)
{
	int	i;

	if (!arg)
		return ;
	i = 0;
	while (arg && arg[i])
	{
		if (arg[i] != NULL)
		{
			free(arg[i]);
			arg[i] = NULL;
		}
		i++;
	}
	free(arg);
	arg = NULL;
}

static void	ft_parse_argv(char **split_argv, int *nbrs)
{
	int	i;
	int64_t	tmp;

	i = 0;
	while (split_argv[i])
	{
		tmp = ft_atold(split_argv[i]);
		if (tmp > INT_MAX || tmp < INT_MIN || ft_strlen(split_argv[i]) > 11)
		{
			free_char(split_argv);
			free(nbrs);
			ft_error("Bad Numbers");
		}
		i++;
	}
}

static int	*ft_group_argv(int argc, char **argv, int len_stack)
{
	char	**split_argv;
	int	*nbrs;
	int	i;
	int	j;
	int	k;

	nbrs = (int *)malloc(sizeof(int) * len_stack);
	if (!nbrs)
		return (NULL);
	i = 0;
	k = 0;
	while (i++ < argc -1)
	{
		split_argv = ft_split(argv[i], ' ');
		if (!split_argv)
			ft_error("KO split");
		j = 0;
		ft_parse_argv(split_argv, nbrs);
		while (split_argv[j])
		{
			nbrs[k] = ft_atoi(split_argv[j]);
			k++;
			j++;
		}
		free_char(split_argv);
	}
	return (nbrs);
}

static int	ft_lenstack(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	len = 0;
	i = 0;
	while (i++ < argc -1)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' ' && ((argv[i][j] == '-' || \
							argv[i][j] == '+') && !ft_isdigit(argv[i][j + 1])))
				ft_error("KO not number, not espace or bad sign");
			if (ft_isdigit(argv[i][j])  && (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0'))
				len++;
			j++;
		}
	}
	return (len);
}

int	main(int argc, char **argv)
{
	int	len_stack;
	int	*list_nbrs;
	int	i;

	if (argc < 2)
		ft_error("KO length Arguments");
	ft_printf("OK?\n");
	len_stack = ft_lenstack(argc, argv);
	list_nbrs = ft_group_argv(argc, argv, len_stack);
	i = -1;
	while(++i < len_stack)
		printf("num -- %d\n", list_nbrs[i]);
	list_nbrs = list_nbrs;
	ft_printf("len stack: %d\n", len_stack);

	// Parseo
	//ft_checkargv(argc, argv);
	return (0);
}
