/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 12:32:42 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/20 10:30:05 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	destroy_env(t_env *e)
{
	destroy_img(e);
	destroy_win(e);
	ft_memdel((void **)&e);
}

void	destroy_img(t_env *e)
{
	if (e->win1 != NULL)
		if (e->win1->img != NULL)
			mlx_destroy_image(e->mlx, e->win1->img);
	if (e->win2 != NULL)
		if (e->win2->img != NULL)
			mlx_destroy_image(e->mlx, e->win2->img);
	if (e->win3 != NULL)
		if (e->win3->img != NULL)
			mlx_destroy_image(e->mlx, e->win3->img);
	if (e->win4 != NULL)
		if (e->win4->img != NULL)
			mlx_destroy_image(e->mlx, e->win4->img);
}

void	init_mlx_win_ter(char **argv, t_env *e, t_wd *wd, int i)
{
	if (ft_atoi(argv[i]) == 2)
	{
		wd->w = 600;
		wd->h = 720;
		init_mlx_win_bis(&e->win2, e, "Julia", wd);
		init_dim_julia(e->win2, wd);
	}
	if (ft_atoi(argv[i]) == 3)
	{
		wd->w = 600;
		wd->h = 600;
		init_mlx_win_bis(&e->win3, e, "Multibrot", wd);
		init_dim_multi(e->win3, wd, 2);
	}
	if (ft_atoi(argv[i]) == 4)
	{
		wd->w = 1200;
		wd->h = 750;
		init_mlx_win_bis(&e->win4, e, "Burning Ship", wd);
		init_dim_burn(e->win4, wd);
	}
}

void	draw_fractal_bis(char **argv, t_env *e, int i)
{
	if (ft_atoi(argv[i]) == 3)
	{
		multibrot(e);
		mlx_mouse_hook(e->win3->win, &scroll_multi, e);
		mlx_hook(e->win3->win, 6, (1L << 6), &motion_hook_multi, e);
		tips_multi();
	}
	if (ft_atoi(argv[i]) == 4)
	{
		burning_ship(e);
		mlx_mouse_hook(e->win4->win, &scroll_burn, e);
		mlx_hook(e->win4->win, 6, (1L << 6), &motion_hook_burn, e);
		tips_burn();
	}
}

void	init_c(t_c **c, int x, int y, t_env *e)
{
	if ((*c = (t_c *)ft_memalloc(sizeof(t_c))) == NULL)
	{
		destroy_env(e);
		malloc_error();
	}
	(*c)->x = (double)x;
	(*c)->y = (double)y;
	(*c)->e = e;
}
