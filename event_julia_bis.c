/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_julia_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 23:10:38 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/10 23:11:06 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	motion_hook_julia_bis(t_env *e)
{
	if (e->win2->input && e->win2->tmp)
	{
		e->win2->tmp = 0;
		julia(e);
	}
}
