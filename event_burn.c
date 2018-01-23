/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_burn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 11:19:12 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/20 14:26:30 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		scroll_up_burn(int x, int y, t_env *e)
{
	t_win	*win;
	t_vect	*v_true;
	t_vect	*v_rlt;
	t_c		*c;

	win = e->win4;
	init_c(&c, x, y, e);
	zoom_in(win, &v_true, &v_rlt, c);
	burning_ship(e);
	ft_memdel((void **)&c);
	ft_memdel((void **)&v_true);
	ft_memdel((void **)&v_rlt);
	return (0);
}

int		scroll_down_burn(int x, int y, t_env *e)
{
	t_win	*win;
	t_vect	*v_true;
	t_vect	*v_rlt;
	t_c		*c;

	win = e->win4;
	init_c(&c, x, y, e);
	zoom_out(win, &v_true, &v_rlt, c);
	burning_ship(e);
	ft_memdel((void **)&c);
	ft_memdel((void **)&v_true);
	ft_memdel((void **)&v_rlt);
	return (0);
}

int		scroll_burn(int button, int x, int y, t_env *e)
{
	if (e->win4->input == 0)
	{
		if (button == 4)
			scroll_up_burn(x, y, e);
		if (button == 5)
			scroll_down_burn(x, y, e);
	}
	return (0);
}

int		motion_hook_burn(int x, int y, t_env *e)
{
	if (e->win4->input == 1)
	{
		e->win4->tmp = 1;
		if (x >= 0 && x < e->win4->w && y >= 0 && y < e->win4->h)
		{
			e->win4->x_m = x;
			e->win4->y_m = y;
		}
		else
		{
			e->win4->x_m = 0;
			e->win4->y_m = 0;
		}
		burning_ship(e);
	}
	if (!e->win4->input && e->win4->tmp)
	{
		e->win4->tmp = 0;
		burning_ship(e);
	}
	return (0);
}

void	key_hook_burn_bis(int keycode, t_env *e)
{
	if (keycode == 8)
	{
		if (e->win4->input == 0)
			e->win4->input = 1;
		else if (e->win4->input == 1)
			e->win4->input = 0;
	}
	if (keycode == 15)
	{
		init_dim_burn(e->win4, 0);
		burning_ship(e);
	}
	if (keycode == 86 && e->win4->color < 150)
	{
		e->win4->color++;
		burning_ship(e);
	}
	if (keycode == 83 && e->win4->color > 50)
	{
		e->win4->color--;
		burning_ship(e);
	}
	key_hook_burn_ter(keycode, e);
}
