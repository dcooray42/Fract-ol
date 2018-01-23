/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 16:23:13 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/20 11:56:49 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		scroll_up_julia(int x, int y, t_env *e)
{
	t_win	*win;
	t_vect	*v_true;
	t_vect	*v_rlt;
	t_c		*c;

	win = e->win2;
	init_c(&c, x, y, e);
	zoom_in(win, &v_true, &v_rlt, c);
	julia(e);
	ft_memdel((void **)&c);
	ft_memdel((void **)&v_true);
	ft_memdel((void **)&v_rlt);
	return (0);
}

int		scroll_down_julia(int x, int y, t_env *e)
{
	t_win	*win;
	t_vect	*v_true;
	t_vect	*v_rlt;
	t_c		*c;

	win = e->win2;
	init_c(&c, x, y, e);
	zoom_out(win, &v_true, &v_rlt, c);
	julia(e);
	ft_memdel((void **)&c);
	ft_memdel((void **)&v_true);
	ft_memdel((void **)&v_rlt);
	return (0);
}

int		scroll_julia(int button, int x, int y, t_env *e)
{
	if (e->win2->input == 1)
	{
		if (button == 4)
			scroll_up_julia(x, y, e);
		if (button == 5)
			scroll_down_julia(x, y, e);
	}
	return (0);
}

int		motion_hook_julia(int x, int y, t_env *e)
{
	if (e->win2->input == 0)
	{
		e->win2->tmp = 1;
		if (x >= 0 && x < e->win2->w && y >= 0 && y < e->win2->h)
		{
			e->win2->x_m = x;
			e->win2->y_m = y;
		}
		else
		{
			e->win2->x_m = 0;
			e->win2->y_m = 0;
		}
		julia(e);
	}
	if (e->win2->input && e->win2->tmp && !e->win2->stat_x && !e->win2->stat_y)
	{
		e->win2->tmp = 0;
		e->win2->stat_x = (double)x / e->win2->zoom_x + e->win2->x1;
		e->win2->stat_y = (double)y / e->win2->zoom_y + e->win2->y1;
		julia(e);
	}
	motion_hook_julia_bis(e);
	return (0);
}

void	key_hook_julia_bis(int keycode, t_env *e)
{
	if (keycode == 8)
	{
		if (e->win2->input == 0)
			e->win2->input = 1;
		else if (e->win2->input == 1)
			e->win2->input = 0;
	}
	if (keycode == 15)
	{
		init_dim_julia(e->win2, 0);
		julia(e);
	}
	if (keycode == 86 && e->win2->color < 150)
	{
		e->win2->color++;
		julia(e);
	}
	if (keycode == 83 && e->win2->color > 50)
	{
		e->win2->color--;
		julia(e);
	}
	key_hook_julia_ter(keycode, e);
}
