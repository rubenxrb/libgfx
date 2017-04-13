#include "libgfx.h"

t_mlx	*init_mlx(size_t w_width, size_t w_height, const char *name)
{
	t_data	*frame_data;
	t_mlx	*ret;
	void	*id;
	void	*win;
	void	*img;

	frame_data = ft_memalloc(sizeof(t_data));
	ret = ft_memalloc(sizeof(t_mlx));
	id = mlx_id();
	win = mlx_win(w_width, w_height, name);
	img = mlx_frame();
	if (!id || !win || !img)
	{
		ft_memdel(&frame_data);
		ft_memdel(&ret);
		return (0);
	}
	ret->id = id;
	ret->win = win;
	ret->img = img;
}
