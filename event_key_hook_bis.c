/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key_hook_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 10:47:46 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/20 14:25:22 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	key_hook_mandel_ter(int keycode, t_env *e)
{
	if (keycode == 126 && !e->win1->input)
	{
		e->win1->y2 = (e->win1->h / e->win1->zoom_y) + e->win1->y1;
		e->win1->y1 -= (e->win1->y2 - e->win1->y1) * 0.01;
		mandelbrot(e);
	}
	if (keycode == 124 && !e->win1->input)
	{
		e->win1->x2 = (e->win1->w / e->win1->zoom_x) + e->win1->x1;
		e->win1->x1 += (e->win1->x2 - e->win1->x1) * 0.01;
		mandelbrot(e);
	}
	if (keycode == 125 && !e->win1->input)
	{
		e->win1->y2 = (e->win1->h / e->win1->zoom_y) + e->win1->y1;
		e->win1->y1 += (e->win1->y2 - e->win1->y1) * 0.01;
		mandelbrot(e);
	}
	if (keycode == 123 && !e->win1->input)
	{
		e->win1->x2 = (e->win1->w / e->win1->zoom_x) + e->win1->x1;
		e->win1->x1 -= (e->win1->x2 - e->win1->x1) * 0.01;
		mandelbrot(e);
	}
}

void	key_hook_julia_ter(int keycode, t_env *e)
{
	if (keycode == 126 && e->win2->input)
	{
		e->win2->y2 = (e->win2->h / e->win2->zoom_y) + e->win2->y1;
		e->win2->y1 -= (e->win2->y2 - e->win2->y1) * 0.01;
		julia(e);
	}
	if (keycode == 124 && e->win2->input)
	{
		e->win2->x2 = (e->win2->w / e->win2->zoom_x) + e->win2->x1;
		e->win2->x1 += (e->win2->x2 - e->win2->x1) * 0.01;
		julia(e);
	}
	if (keycode == 125 && e->win2->input)
	{
		e->win2->y2 = (e->win2->h / e->win2->zoom_y) + e->win2->y1;
		e->win2->y1 += (e->win2->y2 - e->win2->y1) * 0.01;
		julia(e);
	}
	if (keycode == 123 && e->win2->input)
	{
		e->win2->x2 = (e->win2->w / e->win2->zoom_x) + e->win2->x1;
		e->win2->x1 -= (e->win2->x2 - e->win2->x1) * 0.01;
		julia(e);
	}
}

void	key_hook_multi_quater(int keycode, t_env *e)
{
	if (keycode == 126 && !e->win3->input)
	{
		e->win3->y2 = (e->win3->h / e->win3->zoom_y) + e->win3->y1;
		e->win3->y1 -= (e->win3->y2 - e->win3->y1) * 0.01;
		multibrot(e);
	}
	if (keycode == 124 && !e->win3->input)
	{
		e->win3->x2 = (e->win3->w / e->win3->zoom_x) + e->win3->x1;
		e->win3->x1 += (e->win3->x2 - e->win3->x1) * 0.01;
		multibrot(e);
	}
	if (keycode == 125 && !e->win3->input)
	{
		e->win3->y2 = (e->win3->h / e->win3->zoom_y) + e->win3->y1;
		e->win3->y1 += (e->win3->y2 - e->win3->y1) * 0.01;
		multibrot(e);
	}
	if (keycode == 123 && !e->win3->input)
	{
		e->win3->x2 = (e->win3->w / e->win3->zoom_x) + e->win3->x1;
		e->win3->x1 -= (e->win3->x2 - e->win3->x1) * 0.01;
		multibrot(e);
	}
}

void	key_hook_burn_ter(int keycode, t_env *e)
{
	if (keycode == 126 && !e->win4->input)
	{
		e->win4->y2 = (e->win4->h / e->win4->zoom_y) + e->win4->y1;
		e->win4->y1 -= (e->win4->y2 - e->win4->y1) * 0.01;
		burning_ship(e);
	}
	if (keycode == 124 && !e->win4->input)
	{
		e->win4->x2 = (e->win4->w / e->win4->zoom_x) + e->win4->x1;
		e->win4->x1 += (e->win4->x2 - e->win4->x1) * 0.01;
		burning_ship(e);
	}
	if (keycode == 125 && !e->win4->input)
	{
		e->win4->y2 = (e->win4->h / e->win4->zoom_y) + e->win4->y1;
		e->win4->y1 += (e->win4->y2 - e->win4->y1) * 0.01;
		burning_ship(e);
	}
	if (keycode == 123 && !e->win4->input)
	{
		e->win4->x2 = (e->win4->w / e->win4->zoom_x) + e->win4->x1;
		e->win4->x1 -= (e->win4->x2 - e->win4->x1) * 0.01;
		burning_ship(e);
	}
}
