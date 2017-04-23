#include "libgfx.h"

t_mlx	*init_mlx(size_t w_width, size_t w_height, const char *name)
{
	t_mlx	*ret;

	if (!(ret = ft_memalloc(sizeof(t_mlx))))
		return (0);
	ret->id = mlx_init();
	ret->win = mlx_new_window(ret->id, w_width, w_height, (char *)name);
	ret->img = mlx_new_image(ret->id, w_width, w_height);
	if (!ret->id || !ret->win || !ret->img)
	{
		ft_memdel((void **)ret);
		return (0);
	}
	ret->frame = ft_memalloc(sizeof(t_data));
	ret->trans = ft_memalloc(sizeof(t_mods));
	ret->events = ft_memalloc(sizeof(t_keys));
	if (!ret->frame || !ret->trans || !ret->events)
	{
		ft_memdel((void **)ret);
		return (0);
	}
	return (ret);
}

t_3dp	init_3dp(float x, float y, float z)
{
	t_3dp	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_2dp	init_2dp(float x, float y)
{
	t_2dp	point;

	point.x = x;
	point.y = y;
	return (point);
}

t_line	init_line(t_3dp *a, t_3dp *b)
{
	t_line	line;

	line.point_a = *a;
	line.point_b = *b;
	return (line);
}

t_rgb	init_rgb(t_color col)
{
	t_rgb	new;

	new.r = col >> 16;
	new.g = col >> 8;
	new.b = col;
	new.a = 0;
	return (new);
}
