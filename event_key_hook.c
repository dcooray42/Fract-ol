/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_key_hook.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 10:29:03 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/20 10:29:04 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook_mandel(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		destroy_env(e);
		exit(EXIT_SUCCESS);
	}
	key_hook_mandel_bis(keycode, e);
	return (0);
}

int		key_hook_julia(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		destroy_env(e);
		exit(EXIT_SUCCESS);
	}
	key_hook_julia_bis(keycode, e);
	return (0);
}

int		key_hook_multi(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		destroy_env(e);
		exit(EXIT_SUCCESS);
	}
	key_hook_multi_bis(keycode, e);
	return (0);
}

int		key_hook_burn(int keycode, t_env *e)
{
	if (keycode == 53)
	{
		destroy_env(e);
		exit(EXIT_SUCCESS);
	}
	key_hook_burn_bis(keycode, e);
	return (0);
}
