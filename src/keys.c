#include "libgfx.h"
#include <stdlib.h>

int		exit_hook(void)
{
	exit(0);
}

int		press_hook(int key, t_mlx *mlx)
{
	if (key == KEY_ESC)
		exit_hook();
	if (key == KEY_W)
		mlx->events->w = 1;
	else if (key == KEY_A)
		mlx->events->a = 1;
	else if (key == KEY_S)
		mlx->events->s = 1;
	else if (key == KEY_D)
		mlx->events->d = 1;
	else if (key == KEY_Q)
		mlx->events->q = 1;
	else if (key == KEY_E)
		mlx->events->e = 1;
	else if (key == KEY_UP)
		mlx->events->up = 1;
	else if (key == KEY_DOWN)
		mlx->events->down = 1;
	else if (key == KEY_LEFT)
		mlx->events->left = 1;
	else if (key == KEY_RIGHT)
		mlx->events->right = 1;
	return (0);
}

int		release_hook(int key, t_mlx *mlx)
{
	if (key == KEY_W)
		mlx->events->w = 0;
	else if (key == KEY_A)
		mlx->events->a = 0;
	else if (key == KEY_S)
		mlx->events->s = 0;
	else if (key == KEY_D)
		mlx->events->d = 0;
	else if (key == KEY_Q)
		mlx->events->q = 0;
	else if (key == KEY_E)
		mlx->events->e = 0;
	else if (key == KEY_UP)
		mlx->events->up = 0;
	else if (key == KEY_DOWN)
		mlx->events->down = 0;
	else if (key == KEY_LEFT)
		mlx->events->left = 0;
	else if (key == KEY_RIGHT)
		mlx->events->right = 0;
	return (0);
}
