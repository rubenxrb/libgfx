#include "libgfx.h"

void	ft_drawpoint(void *mlx, void *win, t_2dp point, t_color clr)
{
	if ((point->x > 0 && point->y > 0) && (x < W_WIDTH && y < W_HEIGHT))
		mlx_pixel_put(mlx, win, point->x, point->y, (unsigned int)clr);
}

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

void	ft_drawline(void *mlx, void *win, t_line line)
{
	float	delta[3];
	float	error;
	float	slope;
	int		dir;


}
