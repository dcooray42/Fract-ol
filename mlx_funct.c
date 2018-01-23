/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_funct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:23:42 by dcooray           #+#    #+#             */
/*   Updated: 2017/01/30 08:28:57 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_put_pixel_to_image(t_win *win, int x, int y, int color)
{
	char	r;
	char	g;
	char	b;
	int		i;

	r = ((color & 0xFF0000) >> 16);
	g = ((color & 0xFF00) >> 8);
	b = (color & 0xFF);
	i = (x * win->bpp / 8) + y * win->sizeline;
	win->data[i] = b;
	win->data[i + 1] = g;
	win->data[i + 2] = r;
}
