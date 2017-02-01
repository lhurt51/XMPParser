/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhurt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:40:17 by lhurt             #+#    #+#             */
/*   Updated: 2017/01/23 18:40:20 by lhurt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XPM_H
# define XPM_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include "libft/libft.h"

#include <stdio.h>

# define M_HEIGHT 24
# define M_WIDTH 24
# define W_HEIGHT 720
# define W_WIDTH 1280
# define T_SIZE 64
# define Y_ORIGIN (W_HEIGHT / 2)
# define X_ORIGIN (W_WIDTH / 2)
# define CAMERA_X(x) (2 * x / (double)(W_WIDTH) - 1) //x-coordinate in camera space
# define DELTADIST(primary, secondary) (sqrt(1 + (secondary * secondary) / (primary * primary)))

typedef struct		s_point
{
	double			x;
	double			y;
}					t_point;

typedef struct		s_intpoint
{
	int				x;
	int				y;
}					t_intpoint;

typedef struct		s_line
{
	int				inc;
	float			yans;
	float			xans;
}					t_line;

typedef struct		s_env
{
	void			*ptr[6];
}					t_env;

typedef struct		s_tex
{
	char			*name;
	int				pnts[T_SIZE][T_SIZE];
}					t_tex;

typedef struct		s_mlx
{
	t_env			tex[6];
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	void			*ptr[6];
	int				bits;
	int				size_line;
	int				endian;
}					t_mlx;

#endif
