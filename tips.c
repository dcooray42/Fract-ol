/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tips.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:11:38 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/20 14:32:26 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	tips_mandel(void)
{
	ft_putendl("");
	ft_putendl("");
	ft_putendl("------------------Mandelbrot set------------------");
	ft_putendl("Mouse3 - Up = Zoom in");
	ft_putendl("Mouse3 - Down = Zoom out");
	ft_putendl("C = Change the parameters of the Mandelbrot set");
	ft_putendl("\twith mouse motion");
	ft_putendl("R = Reset the parameters (zoom, color, ...) to");
	ft_putendl("\tthe original ones");
	ft_putendl("Numpad 4 = Increase color integer");
	ft_putendl("Numpad 1 = Decrease color integer");
	ft_putendl("--------------------------------------------------");
	ft_putendl("");
	ft_putendl("");
}

void	tips_julia(void)
{
	ft_putendl("");
	ft_putendl("");
	ft_putendl("---------------------Julia set--------------------");
	ft_putendl("Mouse3 - Up = Zoom in");
	ft_putendl("Mouse3 - Down = Zoom out");
	ft_putendl("C = Change the parameters of the Julia set");
	ft_putendl("\twith mouse motion");
	ft_putendl("R = Reset the parameters (zoom, color, ...) to");
	ft_putendl("\tthe original ones");
	ft_putendl("Numpad 4 = Increase color integer");
	ft_putendl("Numpad 1 = Decrease color integer");
	ft_putendl("--------------------------------------------------");
	ft_putendl("");
	ft_putendl("");
}

void	tips_multi(void)
{
	ft_putendl("");
	ft_putendl("");
	ft_putendl("-------------------Multibrot set------------------");
	ft_putendl("Mouse3 - Up = Zoom in");
	ft_putendl("Mouse3 - Down = Zoom out");
	ft_putendl("C = Change the parameters of the Multibrot set");
	ft_putendl("\twith mouse motion");
	ft_putendl("R = Reset the parameters (zoom, color, ...) to");
	ft_putendl("\tthe original ones");
	ft_putendl("Numpad 4 = Increase color integer");
	ft_putendl("Numpad 1 = Decrease color integer");
	ft_putendl("Numpad + = Increase Multibrot set power");
	ft_putendl("Numpad - = Decrease Multibrot set power");
	ft_putendl("--------------------------------------------------");
	ft_putendl("");
	ft_putendl("");
}

void	tips_burn(void)
{
	ft_putendl("");
	ft_putendl("");
	ft_putendl("---------------Burning Ship fractal---------------");
	ft_putendl("Mouse3 - Up = Zoom in");
	ft_putendl("Mouse3 - Down = Zoom out");
	ft_putendl("C = Change the parameters of the Julia set");
	ft_putendl("\twith mouse motion");
	ft_putendl("R = Reset the parameters (zoom, color, ...) to");
	ft_putendl("\tthe original ones");
	ft_putendl("Numpad 4 = Increase color integer");
	ft_putendl("Numpad 1 = Decrease color integer");
	ft_putendl("--------------------------------------------------");
	ft_putendl("");
	ft_putendl("");
}
