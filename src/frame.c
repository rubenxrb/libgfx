#include "libgfx.h"

void	ft_renderframe(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->id, mlx->win, mlx->img, 0, 0);
	mlx_destroy_image(mlx->id, mlx->img);
}
