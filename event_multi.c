/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_multi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:02:31 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/20 10:35:19 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		scroll_up_multi(int x, int y, t_env *e)
{
	t_win	*win;
	t_vect	*v_true;
	t_vect	*v_rlt;
	t_c		*c;

	win = e->win3;
	init_c(&c, x, y, e);
	zoom_in(win, &v_true, &v_rlt, c);
	multibrot(e);
	ft_memdel((void **)&c);
	ft_memdel((void **)&v_true);
	ft_memdel((void **)&v_rlt);
	return (0);
}

int		scroll_down_multi(int x, int y, t_env *e)
{
	t_win	*win;
	t_vect	*v_true;
	t_vect	*v_rlt;
	t_c		*c;

	win = e->win3;
	init_c(&c, x, y, e);
	zoom_out(win, &v_true, &v_rlt, c);
	multibrot(e);
	ft_memdel((void **)&c);
	ft_memdel((void **)&v_true);
	ft_memdel((void **)&v_rlt);
	return (0);
}

int		scroll_multi(int button, int x, int y, t_env *e)
{
	if (e->win3->input == 0)
	{
		if (button == 4)
			scroll_up_multi(x, y, e);
		if (button == 5)
			scroll_down_multi(x, y, e);
	}
	return (0);
}

int		motion_hook_multi(int x, int y, t_env *e)
{
	if (e->win3->input == 1)
	{
		e->win3->tmp = 1;
		if (x >= 0 && x < e->win3->w && y >= 0 && y < e->win3->h)
		{
			e->win3->x_m = x;
			e->win3->y_m = y;
		}
		else
		{
			e->win3->x_m = 0;
			e->win3->y_m = 0;
		}
		multibrot(e);
	}
	if (!e->win3->input && e->win3->tmp)
	{
		e->win3->tmp = 0;
		multibrot(e);
	}
	return (0);
}

void	key_hook_multi_bis(int keycode, t_env *e)
{
	if (keycode == 8)
	{
		if (e->win3->input == 0)
			e->win3->input = 1;
		else if (e->win3->input == 1)
			e->win3->input = 0;
	}
	if (keycode == 69 && !e->win3->input)
	{
		init_dim_multi(e->win3, 0, e->win3->n + 1);
		multibrot(e);
	}
	if (keycode == 78 && e->win3->n > 2 && !e->win3->input)
	{
		init_dim_multi(e->win3, 0, e->win3->n - 1);
		multibrot(e);
	}
	if (keycode == 15)
	{
		init_dim_multi(e->win3, 0, 2);
		multibrot(e);
	}
	key_hook_multi_ter(keycode, e);
}
