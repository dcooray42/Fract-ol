/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 13:18:26 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/07 10:52:16 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_coord_move_julia(t_coord *c, t_win *win)
{
	c->c_r = (double)win->x_m / win->zoom_x + win->x1;
	c->c_i = (double)win->y_m / win->zoom_y + win->y1;
	c->z_r = c->x / win->zoom_x + win->x1;
	c->z_i = c->y / win->zoom_y + win->y1;
	c->i = 0;
}

void	init_coord_julia(t_coord *c, t_win *win)
{
	c->c_r = win->stat_x;
	c->c_i = win->stat_y;
	c->z_r = c->x / win->zoom_x + win->x1;
	c->z_i = c->y / win->zoom_y + win->y1;
	c->i = 0;
}

void	init_dim_julia(t_win *win, t_wd *wd)
{
	if (wd)
	{
		win->w = wd->w;
		win->h = wd->h;
	}
	win->x1 = -1;
	win->x2 = 1;
	win->y1 = -1.2;
	win->y2 = 1.2;
	win->index = 0;
	win->stat_x = 0;
	win->stat_y = 0;
	win->input = 0;
	win->ite_max = 50;
	win->zoom_x = win->w / (win->x2 - win->x1);
	win->zoom_y = win->h / (win->y2 - win->y1);
	win->tmp = 0;
	win->color = 50;
}

void	julia(t_env *e)
{
	t_win	*win;
	t_coord	*c;

	win = (t_win *)e->win2;
	if ((c = (t_coord *)ft_memalloc(sizeof(t_coord))) == NULL)
	{
		destroy_env(e);
		malloc_error();
	}
	c->x = 0;
	if (!win->input)
		draw_f(win, c, &init_coord_move_julia);
	else
		draw_f(win, c, &init_coord_julia);
	mlx_put_image_to_window(e->mlx, e->win2->win, e->win2->img, 0, 0);
	ft_memdel((void **)&c);
}
