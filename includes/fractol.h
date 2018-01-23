/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcooray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 13:26:57 by dcooray           #+#    #+#             */
/*   Updated: 2017/02/20 14:26:02 by dcooray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/includes/libft.h"
# include <math.h>
# include <mlx.h>

typedef struct	s_wd
{
	int	h;
	int	w;
}				t_wd;

typedef struct	s_vect
{
	double	x;
	double	y;
}				t_vect;

typedef struct	s_coord
{
	int		x;
	int		y;
	double	tmp;
	int		i;
	double	c_r;
	double	c_i;
	double	c_z;
	double	z_r;
	double	z_i;
	double	z_z;
	double	r;
	double	theta;
}				t_coord;

typedef struct	s_win
{
	void	*win;
	void	*img;
	char	*data;
	int		bpp;
	int		sizeline;
	int		endian;
	int		x_m;
	int		y_m;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	h_x;
	double	h_y;
	double	zoom_x;
	double	zoom_y;
	int		index;
	int		input;
	int		color;
	int		ite_max;
	int		h;
	int		w;
	int		tmp;
	double	stat_x;
	double	stat_y;
	double	n;
}				t_win;

typedef struct	s_env
{
	void	*mlx;
	t_win	*win1;
	t_win	*win2;
	t_win	*win3;
	t_win	*win4;
}				t_env;

typedef struct	s_c
{
	double	x;
	double	y;
	t_env	*e;
}				t_c;

void			draw_fractal(char **argv, t_env *e);
void			draw_fractal_bis(char **argv, t_env *e, int i);
void			draw_f(t_win *win, t_coord *c,
				void (*f)(t_coord *, t_win *));
void			init_dim_mandel(t_win *win, t_wd *wd);
void			init_coord_mandel(t_coord *c, t_win *win);
void			init_coord_move_mandel(t_coord *c, t_win *win);
void			mandelbrot(t_env *e);
void			init_coord_julia(t_coord *c, t_win *win);
void			init_coord_move_julia(t_coord *c, t_win *win);
void			init_dim_julia(t_win *win, t_wd *wd);
void			julia(t_env *e);
void			draw_multibrot(t_win *win, t_coord *c,
				void (*f)(t_coord *, t_win *));
void			draw_multibrot_bis(t_win *win, t_coord *c);
void			init_dim_multi(t_win *win, t_wd *wd, int n);
void			multibrot(t_env *e);
void			draw_burn(t_win *win, t_coord *c,
				void (*f)(t_coord *, t_win *));
void			init_dim_burn(t_win *win, t_wd *wd);
void			burning_ship(t_env *e);
void			malloc_error(void);
t_env			*init_env(char **argv);
void			init_mlx_win(char **argv, t_env *e);
void			init_mlx_win_bis(t_win **win, t_env *e, char *str, t_wd *wd);
void			init_mlx_win_ter(char **argv, t_env *e, t_wd *wd, int i);
void			destroy_img(t_env *e);
void			destroy_win(t_env *e);
void			destroy_env(t_env *e);
void			write_parameters(void);
void			check_numbers(char **argv);
void			check_numbers_bis(int *tab, int index);
void			check_correct_param(char **argv);
void			non_digit_error(void);
void			same_number_error(void);
void			mlx_event(t_env *e);
void			zoom_scale(t_win *win);
void			init_c(t_c **c, int x, int y, t_env *e);
void			zoom_in(t_win *win, t_vect **v_true, t_vect **v_rlt, t_c *c);
void			zoom_out(t_win *win, t_vect **v_true, t_vect **v_rlt, t_c *c);
int				key_hook_mandel(int keycode, t_env *e);
void			key_hook_mandel_bis(int keycode, t_env *e);
void			key_hook_mandel_ter(int keycode, t_env *e);
int				key_hook_julia(int keycode, t_env *e);
void			key_hook_julia_bis(int keycode, t_env *e);
void			key_hook_julia_ter(int keycode, t_env *e);
int				key_hook_multi(int keycode, t_env *e);
void			key_hook_multi_bis(int keycode, t_env *e);
void			key_hook_multi_ter(int keycode, t_env *e);
void			key_hook_multi_quater(int keycode, t_env *e);
int				key_hook_burn(int keycode, t_env *e);
void			key_hook_burn_bis(int keycode, t_env *e);
void			key_hook_burn_ter(int keycode, t_env *e);
int				motion_hook_mandel(int x, int y, t_env *e);
int				motion_hook_julia(int x, int y, t_env *e);
void			motion_hook_julia_bis(t_env *e);
int				motion_hook_multi(int x, int y, t_env *e);
int				motion_hook_burn(int x, int y, t_env *e);
int				scroll_mandel(int button, int x, int y, t_env *e);
int				scroll_julia(int button, int x, int y, t_env *e);
int				scroll_multi(int button, int x, int y, t_env *e);
int				scroll_burn(int button, int x, int y, t_env *e);
int				scroll_up_mandel(int x, int y, t_env *e);
int				scroll_up_julia(int x, int y, t_env *e);
int				scroll_up_multi(int x, int y, t_env *e);
int				scroll_up_burn(int x, int y, t_env *e);
int				scroll_down_mandel(int x, int y, t_env *e);
int				scroll_down_julia(int x, int y, t_env *e);
int				scroll_down_multi(int x, int y, t_env *e);
int				scroll_down_burn(int x, int y, t_env *e);
void			mlx_put_pixel_to_image(t_win *win, int x, int y, int color);
void			tips_mandel(void);
void			tips_julia(void);
void			tips_multi(void);
void			tips_burn(void);

#endif
