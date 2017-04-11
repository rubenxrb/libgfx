#include "libgfx.h"

//color = 0xAABBCC or AABBCC
t_rgb	*ft_colornew(const char *color)
{
	t_rgb	*new;
	t_color	tmp;

	if(!(tmp = ft_hextoi(color)) || !ft_ishexstr(color))
		return (0);
	new = ft_memalloc(sizeof(t_rgb));
	new->r = tmp >> 16;
	new->g = tmp >> 8;
	new->b = tmp;
	new->a = 0;
	return (new);
}

t_rgb	ft_colormix(t_rgb color_a, t_rgb color_b)
{
	t_rgb	new;

	new.r = (color_a.r + color_b.r) / 2;
	new.g = (color_a.g + color_b.g) / 2;
	new.b = (color_a.b + color_b.b) / 2;
	return (new);
}

/*
t_rgb	ft_(t_line, float z)
{
	t_rgb	new;

	if (!z_min || !z_max)
		return (0);

}
*/
