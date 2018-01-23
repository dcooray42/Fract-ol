/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_mandel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 08:55:02 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/20 10:53:04 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		scroll_up_mandel(int x, int y, t_env *e)
{
	t_win	*win;
	t_vect	*v_true;
	t_vect	*v_rlt;
	t_c		*c;

	win = e->win1;
	init_c(&c, x, y, e);
	zoom_in(win, &v_true, &v_rlt, c);
	mandelbrot(e);
	ft_memdel((void **)&c);
	ft_memdel((void **)&v_true);
	ft_memdel((void **)&v_rlt);
	return (0);
}

int		scroll_down_mandel(int x, int y, t_env *e)
{
	t_win	*win;
	t_vect	*v_true;
	t_vect	*v_rlt;
	t_c		*c;

	win = e->win1;
	init_c(&c, x, y, e);
	zoom_out(win, &v_true, &v_rlt, c);
	mandelbrot(e);
	ft_memdel((void **)&c);
	ft_memdel((void **)&v_true);
	ft_memdel((void **)&v_rlt);
	return (0);
}

int		scroll_mandel(int button, int x, int y, t_env *e)
{
	if (e->win1->input == 0)
	{
		if (button == 4)
			scroll_up_mandel(x, y, e);
		if (button == 5)
			scroll_down_mandel(x, y, e);
	}
	return (0);
}

int		motion_hook_mandel(int x, int y, t_env *e)
{
	if (e->win1->input == 1)
	{
		e->win1->tmp = 1;
		if (x >= 0 && x < e->win1->w && y >= 0 && y < e->win1->h)
		{
			e->win1->x_m = x;
			e->win1->y_m = y;
		}
		else
		{
			e->win1->x_m = 0;
			e->win1->y_m = 0;
		}
		mandelbrot(e);
	}
	if (!e->win1->input && e->win1->tmp)
	{
		e->win1->tmp = 0;
		mandelbrot(e);
	}
	return (0);
}

void	key_hook_mandel_bis(int keycode, t_env *e)
{
	if (keycode == 8)
	{
		if (e->win1->input == 0)
			e->win1->input = 1;
		else if (e->win1->input == 1)
			e->win1->input = 0;
	}
	if (keycode == 15)
	{
		init_dim_mandel(e->win1, 0);
		mandelbrot(e);
	}
	if (keycode == 86 && e->win1->color < 150)
	{
		e->win1->color++;
		mandelbrot(e);
	}
	if (keycode == 83 && e->win1->color > 50)
	{
		e->win1->color--;
		mandelbrot(e);
	}
	key_hook_mandel_ter(keycode, e);
}
