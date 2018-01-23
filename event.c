/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 11:37:53 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/20 12:07:10 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_event(t_env *e)
{
	if (e->win1)
		mlx_key_hook(e->win1->win, &key_hook_mandel, e);
	if (e->win2)
		mlx_key_hook(e->win2->win, &key_hook_julia, e);
	if (e->win3)
		mlx_key_hook(e->win3->win, &key_hook_multi, e);
	if (e->win4)
		mlx_key_hook(e->win4->win, &key_hook_burn, e);
}

void	key_hook_multi_ter(int keycode, t_env *e)
{
	if (keycode == 86 && e->win3->color < 150)
	{
		e->win3->color++;
		multibrot(e);
	}
	if (keycode == 83 && e->win3->color > 50)
	{
		e->win3->color--;
		multibrot(e);
	}
	key_hook_multi_quater(keycode, e);
}
