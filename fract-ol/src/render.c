/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bayam <bayam@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:43:35 by bayam             #+#    #+#             */
/*   Updated: 2025/12/26 15:05:34 by bayam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mlx_app.h"

double		map(double unscaled_num, double new_min,
				double new_max, double old_max);
void		pixel_to_image(t_data *data, int x, int y, int color);
void		handle_pixel(int x, int y, t_data *data);
int			render_fractal(t_data *data);
static void	calculate_fractal(int x, int y, t_data *data, t_complex c);

double	map(double unscaled_num, double new_min, double new_max, double old_max)
{
	return (new_min + (new_max - new_min) * unscaled_num / old_max);
}

void	pixel_to_image(t_data *data, int x, int y, int color)
{
	int	offset;

	if (x < 0 || x >= WIDTH || y < 0 || y > HEIGHT)
		return ;
	offset = (y * data->size_line) + (x * (data->bits_per_pixel / 8));
	*(unsigned int *)(data->img_data + offset) = color;
}

static void	calculate_fractal(int x, int y, t_data *data, t_complex c)
{
	t_complex	z;
	double		tmp;
	int			i;

	i = 0;
	if (ft_strcmp(data->name, "mandelbrot") == 0)
		z = (t_complex){0.0, 0.0};
	else
	{
		z = c;
		c = (t_complex){data->julia_x, data->julia_y};
	}
	while ((z.x * z.x + z.y * z.y) < 4.0 && i < 100)
	{
		tmp = z.x * z.x - z.y * z.y + c.x;
		z.y = 2 * z.x * z.y + c.y;
		z.x = tmp;
		i++;
	}
	if (i == 100)
		pixel_to_image(data, x, y, 0x000000);
	else
		pixel_to_image(data, x, y, (i * 2 << 16) | (i * 3 << 8) | (i * 10));
}

void	handle_pixel(int x, int y, t_data *data)
{
	t_complex	c;

	c.x = map(x, -2.0 * data->zoom, 2.0 * data->zoom, (double)WIDTH);
	c.y = map(y, 2.0 * data->zoom, -2.0 * data->zoom, (double)HEIGHT);
	calculate_fractal(x, y, data, c);
}

int	render_fractal(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}
