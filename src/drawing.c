#include "libgfx.h"
#include <stdlib.h>

static int	swap_vars(t_3dp *p0, t_3dp *p1)
{
	float temp;

	if (fabs(p1->x - p0->x) > fabs(p1->y - p0->y))
		return (0);
	temp = p0->y;
	p0->y = p0->x;
	p0->x = temp;
	temp = p1->y;
	p1->y = p1->x;
	p1->x = temp;
	return (1);
}

static int	check_deltas(t_3dp *p0, t_3dp *p1, float delta[3], int dir)
{
	t_3dp	temp;

	if (p0->x == 4.2E7 || p1->x == 4.2E7)
		return (0);
	if ((p0->x > p1->x && p0->x > (dir ? W_HEIGHT : W_WIDTH) / 2) ||
		(p0->x < p1->x && p0->x < (dir ? W_HEIGHT : W_WIDTH) / 2))
	{
		temp = *p0;
		*p0 = *p1;
		*p1 = temp;
	}
	delta[0] = p1->x - p0->x;
	if (p0->y == 4.2E7 || p1->y == 4.2E7)
		return (0);
	delta[1] = p1->y - p0->y;
	delta[2] = p1->z - p0->z;
	return (1);
}

int			ft_drawpixel(t_mlx *mlx, t_3dp point)
{
	t_data		*frame;
	float		which;
	float		dist;
	int			i;

	i = 0;
	frame = mlx->frame;
	if (point.x > 0 && point.y > 0 && point.x < W_WIDTH && point.y < W_HEIGHT)
	{
		i = ((int)point.x * 4) + ((int)point.y * (mlx->frame->line_size));
		dist = ((point.z) - frame->z_min) / ((frame->z_max) - frame->z_min);
		which = (dist * (RGB_STEPS));
		ft_memcpy(&(frame->pixels[i]), &(frame->tab[abs((int)which - 1)]), 4);
		return (1);
	}
	return (0);
}

void		ft_drawline(t_mlx *mlx, t_line line)
{
	float	delta[3];
	float	error;
	float	slope;
	int		dir;

	dir = swap_vars(&(line.point_a), &(line.point_b));
	if (!check_deltas(&(line.point_a), &(line.point_b), delta, dir))
		return ;
	slope = fabs(delta[1] / delta[0]);
	error = -1.0;
	while ((int)line.point_a.x != (int)line.point_b.x)
	{
		if (!ft_drawpixel(mlx, init_3dp(dir ? line.point_a.y : line.point_a.x,
				dir ? line.point_a.x : line.point_a.y, line.point_a.z)))
			return ;
		error += slope;
		if (error >= 0.0)
		{
			line.point_a.y += (line.point_a.y > line.point_b.y) ? -1.0 : 1.0;
			error -= 1.0;
		}
		line.point_a.z += delta[2] / fabs(delta[0]);
		line.point_a.x += (line.point_a.x > line.point_b.x) ? -1.0 : 1.0;
	}
}
