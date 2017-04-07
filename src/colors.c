#include "libgfx.h"

t_rgb	*ft_colornew(const char *color)
{
	t_rgb	*new;

	new = ft_memalloc(sizeof(t_rgb));
	new->r =
	return (0);
}

t_rgb	ft_colormix(t_rgba color_a, t_rgba color_b)
{
	t_rgb	new;

	new.r = (color_a.r + color_b.r) / 2;
	new.g = (color_a.g + color_b.g) / 2;
	new.b = (color_a.b + color_b.b) / 2;
	return (new);
}

t_rgb	ft_(t_line, float z)
{
	t_rgb	new;

	if (!z_min || !z_max)
		return (0);

}
