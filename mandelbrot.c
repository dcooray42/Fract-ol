/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:45:17 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/20 11:14:52 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_f(t_win *win, t_coord *c, void (*f)(t_coord *, t_win *))
{
	while (c->x < win->w)
	{
		c->y = 0;
		while (c->y < win->h)
		{
			f(c, win);
			while (c->z_r * c->z_r + c->z_i * c->z_i < 4 && c->i < win->ite_max)
			{
				c->tmp = c->z_r;
				c->z_r = c->z_r * c->z_r - c->z_i * c->z_i + c->c_r;
				c->z_i = 2 * c->z_i * c->tmp + c->c_i;
				c->i = c->i + 1;
			}
			if (c->i == win->ite_max)
				mlx_put_pixel_to_image(win, c->x, c->y, 0);
			else
				mlx_put_pixel_to_image(win, c->x, c->y, 0xFFFFFF *
						((double)c->i / (double)win->color));
			c->y++;
		}
		c->x++;
	}
}

void	init_dim_mandel(t_win *win, t_wd *wd)
{
	if (wd)
	{
		win->w = wd->w;
		win->h = wd->h;
	}
	win->x1 = -2.0;
	win->x2 = 0.6;
	win->y1 = -1.2;
	win->y2 = 1.2;
	win->index = 0;
	win->input = 0;
	win->ite_max = 50;
	win->zoom_x = win->w / (win->x2 - win->x1);
	win->zoom_y = win->h / (win->y2 - win->y1);
	win->tmp = 0;
	win->color = 50;
}

void	init_coord_mandel(t_coord *c, t_win *win)
{
	c->c_r = c->x / win->zoom_x + win->x1;
	c->c_i = c->y / win->zoom_y + win->y1;
	c->z_r = 0;
	c->z_i = 0;
	c->i = 0;
}

void	init_coord_move_mandel(t_coord *c, t_win *win)
{
	c->c_r = c->x / win->zoom_x + win->x1;
	c->c_i = c->y / win->zoom_y + win->y1;
	c->z_r = (double)win->x_m / win->zoom_x + win->x1;
	c->z_i = (double)win->y_m / win->zoom_y + win->y1;
	c->i = 0;
}

void	mandelbrot(t_env *e)
{
	t_win	*win;
	t_coord	*c;

	win = e->win1;
	if ((c = (t_coord *)ft_memalloc(sizeof(t_coord))) == NULL)
	{
		destroy_env(e);
		malloc_error();
	}
	c->x = 0;
	if (win->input)
		draw_f(win, c, &init_coord_move_mandel);
	else
		draw_f(win, c, &init_coord_mandel);
	mlx_put_image_to_window(e->mlx, e->win1->win, e->win1->img, 0, 0);
	ft_memdel((void **)&c);
}
