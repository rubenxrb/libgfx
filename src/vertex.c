#include "libgfx.h"

t_2dp		*ft_2dpnew(float x, float y)
{
	t_2dp	*point;

	point = ft_memalloc(sizeof(t_3dp));
	point->x = x;
	point->y = y;
	return (point);
}

t_3dp		*ft_3dpnew(float x, float y, float z)
{
	t_3dp	*point;

	point = ft_memalloc(sizeof(t_3dp));
	point->x = x;
	point->y = y;
	point->z = z;
	return (point);
}

t_vtx		*ft_vtxnew(t_3dp local, t_color	*color)
{
	t_vtx	*new;

	new = ft_memalloc(sizeof(t_vtx));
	new->local = ft_3dpnew(local->x, local->y, local->z);
	new->world = ft_3dpnew(0, 0, 0);
	new->align = ft_3dpnew(0, 0, 0);
	new->rgb = color;
	return (new);
}
