#include "libgfx.h"

void	ft_drawpoint(void *mlx, void *win, t_2dp *point, t_rgb *clr)
{
	if ((point->x > 0 && point->y > 0) && (point->x < W_WIDTH && point->y
		< W_HEIGHT))
		mlx_pixel_put(mlx, win, point->x, point->y, (t_color)&*clr);
}

int	swap_vars(t_3dp *p0, t_3dp *p1)
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


t_line	*ft_linenew(t_3dp a, t_3dp b, t_rgb color_a, t_rgb color_b)
{
	t_line	*new;

	new = ft_memalloc(sizeof(t_line));
	new->a = a;
	new->b = b;
	new->color_a = color_a;
	new->color_b = color_b;
	return (new);
}
