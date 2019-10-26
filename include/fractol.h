/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbatz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 01:31:50 by kbatz             #+#    #+#             */
/*   Updated: 2019/10/26 09:01:06 by kbatz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

typedef struct s_complex	t_complex;
typedef struct s_params		t_params;
typedef struct s_vector		t_vector;
typedef struct s_point		t_point;
typedef struct s_fractal	t_fractal;
typedef enum e_fractal_nbr	t_fractal_nbr;
typedef struct s_rgb_color	t_rgb_color;
typedef struct s_color		t_color;
typedef	unsigned char		t_byte;

struct						s_color
{
	t_byte					b;
	t_byte					g;
	t_byte					r;
	t_byte					o;
};

struct						s_complex
{
	double					i;
	double					r;
};

struct						s_vector
{
	double					y;
	double					x;
};

struct						s_point
{
	int						y;
	int						x;
};

struct						s_params
{
	void					*mlx;
	void					*win;
	int						n;
	int						m;
	void					*img_ptr;
	t_color					*img;
	t_vector				shift;
	double					scale;
	t_point					mouse_p;
	t_byte					lmb : 1;
	t_byte					rmb : 1;
	t_byte					boost_mode : 1;
	double					iter;
};

struct						s_fractal
{
	const char				*name;
	int						len;
	double					(*f)(int x, int y);
};

enum						e_fractal_nbr
{
	MANDELBROT,
	JULIA,
	FRACTALS_LEN
};

extern t_fractal			g_fractals[];

void	ft_draw(t_params *prms);

#endif
