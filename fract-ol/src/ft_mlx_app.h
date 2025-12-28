/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_app.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 21:26:08 by bayam             #+#    #+#             */
/*   Updated: 2025/12/26 15:01:26 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_APP_H
# define FT_MLX_APP_H

# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 600

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	char	*name;
	double	julia_x;
	double	julia_y;
	double	zoom;
}	t_data;

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

double		ft_atof(char *s);
void		pixel_to_image(t_data *data, int x, int y, int color);
void		adjust_zoom(t_data *data, double factor);
int			render_fractal(t_data *data);
int			close_window(t_data *data);
int			ft_strcmp(char *s1, char *s2);
t_complex	complex_square(t_complex z);
void		handle_pixel(int x, int y, t_data *data);
int			is_valid_num(char *s);

#endif