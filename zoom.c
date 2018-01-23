/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 10:27:22 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/14 10:56:38 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_scale(t_win *win)
{
	(void)win;
}

void	zoom_in(t_win *win, t_vect **v_true, t_vect **v_rlt, t_c *c)
{
	if ((*v_true = (t_vect *)ft_memalloc(sizeof(t_vect))) == NULL)
	{
		destroy_env(c->e);
		ft_memdel((void **)&c);
		malloc_error();
	}
	if ((*v_rlt = (t_vect *)ft_memalloc(sizeof(t_vect))) == NULL)
	{
		destroy_env(c->e);
		ft_memdel((void **)&c);
		ft_memdel((void **)v_true);
		malloc_error();
	}
	win->ite_max++;
	(*v_true)->x = c->x / win->zoom_x + win->x1;
	(*v_true)->y = c->y / win->zoom_y + win->y1;
	(*v_rlt)->x = win->w / c->x;
	(*v_rlt)->y = win->h / c->y;
	win->zoom_x *= 1.1;
	win->zoom_y *= 1.1;
	win->h_x = win->w / win->zoom_x;
	win->h_y = win->h / win->zoom_y;
	win->x1 = (*v_true)->x - win->h_x / (*v_rlt)->x;
	win->y1 = (*v_true)->y - win->h_y / (*v_rlt)->y;
}

void	zoom_out(t_win *win, t_vect **v_true, t_vect **v_rlt, t_c *c)
{
	if ((*v_true = (t_vect *)ft_memalloc(sizeof(t_vect))) == NULL)
	{
		destroy_env(c->e);
		ft_memdel((void **)&c);
		malloc_error();
	}
	if ((*v_rlt = (t_vect *)ft_memalloc(sizeof(t_vect))) == NULL)
	{
		destroy_env(c->e);
		ft_memdel((void **)&c);
		ft_memdel((void **)v_true);
		malloc_error();
	}
	win->ite_max--;
	(*v_true)->x = c->x / win->zoom_x + win->x1;
	(*v_true)->y = c->y / win->zoom_y + win->y1;
	(*v_rlt)->x = win->w / c->x;
	(*v_rlt)->y = win->h / c->y;
	win->zoom_x /= 1.1;
	win->zoom_y /= 1.1;
	win->h_x = win->w / win->zoom_x;
	win->h_y = win->h / win->zoom_y;
	win->x1 = (*v_true)->x - win->h_x / (*v_rlt)->x;
	win->y1 = (*v_true)->y - win->h_y / (*v_rlt)->y;
}
