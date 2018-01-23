/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multibrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:11:15 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/10 23:11:16 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	draw_multibrot(t_win *win, t_coord *c, void (*f)(t_coord *, t_win *))
{
	while (c->x < win->w)
	{
		c->y = 0;
		while (c->y < win->h)
		{
			f(c, win);
			while (c->z_r * c->z_r + c->z_i * c->z_i < 4 && c->i < win->ite_max)
			{
				draw_multibrot_bis(win, c);
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

void	init_dim_multi(t_win *win, t_wd *wd, int n)
{
	if (wd)
	{
		win->w = wd->w;
		win->h = wd->h;
	}
	win->x1 = -2.0;
	win->x2 = 2.0;
	win->y1 = -2.0;
	win->y2 = 2.0;
	win->index = 0;
	win->input = 0;
	win->ite_max = 50;
	win->zoom_x = win->w / (win->x2 - win->x1);
	win->zoom_y = win->h / (win->y2 - win->y1);
	win->tmp = 0;
	win->color = 50;
	win->n = n;
}

void	draw_multibrot_bis(t_win *win, t_coord *c)
{
	c->tmp = c->z_r;
	c->r = c->z_r * c->z_r + c->z_i * c->z_i;
	c->theta = atan2(c->z_i, c->z_r);
	c->z_r = pow(c->r, (win->n / 2)) * cos(c->theta * win->n) + c->c_r;
	c->z_i = pow(c->r, (win->n / 2)) * sin(c->theta * win->n) + c->c_i;
}

void	multibrot(t_env *e)
{
	t_win	*win;
	t_coord	*c;

	win = e->win3;
	if ((c = (t_coord *)ft_memalloc(sizeof(t_coord))) == NULL)
	{
		destroy_env(e);
		malloc_error();
	}
	c->x = 0;
	if (win->input)
		draw_multibrot(win, c, &init_coord_move_mandel);
	else
		draw_multibrot(win, c, &init_coord_mandel);
	mlx_put_image_to_window(e->mlx, e->win3->win, e->win3->img, 0, 0);
	ft_memdel((void **)&c);
}
