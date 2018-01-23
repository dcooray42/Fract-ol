/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:27:07 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/20 10:28:10 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_correct_param(char **argv)
{
	int	i;
	int	num;

	i = 1;
	while (argv[i] != NULL)
	{
		num = ft_atoi(argv[i]);
		if (num < 1 || num > 4)
		{
			ft_putendl("Enter a valid number:");
			write_parameters();
			exit(EXIT_SUCCESS);
		}
		else
			i++;
	}
}

int		main(int argc, char **argv)
{
	t_env	*e;

	if (argc >= 2 && argc <= 5)
	{
		check_numbers(argv);
		check_correct_param(argv);
		e = init_env(argv);
		draw_fractal(argv, e);
	}
	else
	{
		ft_putendl("Usage: <numbers ...> [4 windows max]");
		write_parameters();
	}
	return (0);
}

void	write_parameters(void)
{
	ft_putendl("\t1 - Mandelbrot set");
	ft_putendl("\t2 - Julia set");
	ft_putendl("\t3 - Multibrot set");
	ft_putendl("\t4 - Burning Ship fractal");
}

void	check_numbers(char **argv)
{
	int	*tab;
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		if (ft_atoi(argv[i++]) == 0)
			non_digit_error();
	}
	if ((tab = (int *)ft_memalloc(sizeof(int) * (i - 1))) == NULL)
	{
		ft_memdel((void **)&tab);
		malloc_error();
	}
	while (j < i - 1)
	{
		tab[j] = ft_atoi(argv[j + 1]);
		j++;
	}
	check_numbers_bis(tab, i - 1);
}

void	check_numbers_bis(int *tab, int index)
{
	int	i;
	int	j;

	i = 0;
	while (i < index)
	{
		j = 0;
		while (j < index)
		{
			if (j == i)
				j++;
			if (j < index)
			{
				if (tab[j] == tab[i])
				{
					ft_memdel((void **)&tab);
					same_number_error();
				}
			}
			j++;
		}
		i++;
	}
	ft_memdel((void **)&tab);
}
