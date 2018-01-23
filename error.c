/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 09:06:07 by dcooray           #+#    #+#             */
/*   Updated: 2017/01/25 09:06:08 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	non_digit_error(void)
{
	char	*str1;
	char	*str2;

	str1 = ft_strdup("Error: Parameter(s) contain(s) a string,");
	str2 = ft_strdup(" a non-digit character or a 0\n");
	str1 = ft_strdeljoin(str1, str2);
	write(2, str1, ft_strlen(str1));
	ft_strdel(&str1);
	exit(EXIT_SUCCESS);
}

void	malloc_error(void)
{
	char	*str;

	str = ft_strdup("Error: Malloc failled\n");
	write(2, str, ft_strlen(str));
	ft_strdel(&str);
	exit(EXIT_SUCCESS);
}

void	same_number_error(void)
{
	char	*str;

	str = ft_strdup("Error: Same number put in the parameters\n");
	write(2, str, ft_strlen(str));
	ft_strdel(&str);
	exit(EXIT_SUCCESS);
}
