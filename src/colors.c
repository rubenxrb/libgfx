#include "libgfx.h"

t_rgb			*ft_colornew(const char *color)
{
	t_rgb	*new;
	t_color	tmp;

	if (!(tmp = ft_hextoi(color)) || !ft_ishexstr(color))
		return (0);
	new = ft_memalloc(sizeof(t_rgb));
	new->r = tmp >> 16;
	new->g = tmp >> 8;
	new->b = tmp;
	new->a = 0;
	return (new);
}

t_rgb			ft_colormix(t_rgb color_a, t_rgb color_b)
{
	t_rgb	new;

	new.r = (color_a.r + color_b.r) / 2;
	new.g = (color_a.g + color_b.g) / 2;
	new.b = (color_a.b + color_b.b) / 2;
	return (new);
}

t_color			ft_rgbtoint(t_rgb col)
{
	return (((int)col.r << 16) + ((int)col.g << 8) + (int)col.b);
}

static t_color	gen_color(t_rgb col_a, t_rgb col_b, size_t step, int col_n)
{
	t_rgb	ret;

	ret.r = (col_b.r - col_a.r) * step / col_n + col_a.r;
	ret.g = (col_b.g - col_a.g) * step / col_n + col_a.g;
	ret.b = (col_b.b - col_a.b) * step / col_n + col_a.b;
	return (ft_rgbtoint(ret));
}

t_color			*new_colortab(t_rgb *scheme, int num)
{
	t_color		*tab;
	int			i;

	i = 0;
	tab = ft_memalloc(sizeof(t_color) * num);
	while (i < num)
	{
		tab[i] = gen_color(*scheme, *(scheme + 1), i, num);
		i++;
	}
	return (tab);
}
