/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:49:05 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/14 14:22:21 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_env	*init_env(char **argv)
{
	t_env	*e;

	if ((e = (t_env *)ft_memalloc(sizeof(t_env))) == NULL)
		malloc_error();
	if ((e->mlx = mlx_init()) == NULL)
	{
		ft_memdel((void **)&e);
		malloc_error();
	}
	e->win1 = NULL;
	e->win2 = NULL;
	e->win3 = NULL;
	e->win4 = NULL;
	init_mlx_win(argv, e);
	return (e);
}

void	destroy_win(t_env *e)
{
	if (e->win1 != NULL)
	{
		if (e->win1->win != NULL)
			mlx_destroy_window(e->mlx, e->win1->win);
		ft_memdel((void **)&e->win1);
	}
	if (e->win2 != NULL)
	{
		if (e->win2->win != NULL)
			mlx_destroy_window(e->mlx, e->win2->win);
		ft_memdel((void **)&e->win2);
	}
	if (e->win3 != NULL)
	{
		if (e->win3->win != NULL)
			mlx_destroy_window(e->mlx, e->win3->win);
		ft_memdel((void **)&e->win3);
	}
	if (e->win4 != NULL)
	{
		if (e->win4->win != NULL)
			mlx_destroy_window(e->mlx, e->win4->win);
		ft_memdel((void **)&e->win4);
	}
}

void	init_mlx_win_bis(t_win **win, t_env *e, char *str, t_wd *wd)
{
	if ((*win = (t_win *)ft_memalloc(sizeof(t_win))) == NULL)
	{
		destroy_env(e);
		malloc_error();
	}
	if (((*win)->win = mlx_new_window(e->mlx, wd->w, wd->h, str)) == NULL)
	{
		destroy_env(e);
		malloc_error();
	}
	if (((*win)->img = mlx_new_image(e->mlx, wd->w, wd->h)) == NULL)
	{
		destroy_env(e);
		malloc_error();
	}
	if (((*win)->data = mlx_get_data_addr((*win)->img, &(*win)->bpp,
		&(*win)->sizeline, &(*win)->endian)) == NULL)
	{
		destroy_env(e);
		malloc_error();
	}
	(*win)->x_m = 0;
	(*win)->y_m = 0;
}

void	init_mlx_win(char **argv, t_env *e)
{
	int		i;
	t_wd	*wd;

	i = 1;
	if ((wd = (t_wd *)ft_memalloc(sizeof(t_wd))) == NULL)
		malloc_error();
	while (argv[i] != NULL)
	{
		if (ft_atoi(argv[i]) == 1)
		{
			wd->w = 780;
			wd->h = 720;
			init_mlx_win_bis(&e->win1, e, "Mandelbrot", wd);
			init_dim_mandel(e->win1, wd);
		}
		init_mlx_win_ter(argv, e, wd, i);
		i++;
	}
	ft_memdel((void **)&wd);
}

void	draw_fractal(char **argv, t_env *e)
{
	int		i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (ft_atoi(argv[i]) == 1)
		{
			mandelbrot(e);
			mlx_mouse_hook(e->win1->win, &scroll_mandel, e);
			mlx_hook(e->win1->win, 6, (1L << 6), &motion_hook_mandel, e);
			tips_mandel();
		}
		if (ft_atoi(argv[i]) == 2)
		{
			julia(e);
			mlx_mouse_hook(e->win2->win, &scroll_julia, e);
			mlx_hook(e->win2->win, 6, (1L << 6), &motion_hook_julia, e);
			tips_julia();
		}
		draw_fractal_bis(argv, e, i);
		i++;
	}
	mlx_event(e);
	mlx_loop(e->mlx);
}
