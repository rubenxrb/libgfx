#include "libgfx.h"

void	ft_mtx_translate(float mtx[4][4], t_3dp point)
{
	float	tmp[4][4];

	ft_mtxidmake(tmp);
	tmp[3][0] = point->x;
	tmp[3][1] = point->y;
	tmp[3][2] = point->z;
	ft_mtxmult(mtx, tmp, mtx);
}

void	ft_mtx_scale(float mtx[4][4], t_3dp point)
{
	float	tmp[4][4];

	i = 0;
	bzero_mtx(tmp);
	tmp[0][0] = point->x;
	tmp[1][1] = point->y;
	tmp[2][2] = point->z;
	tmp[3][3] = 1;
	ft_mtxmult(mtx, tmp, mtx);
}

void	ft_mtx_rotate(float mtx[4][4], t_3dp point)
{
	float	x_mtx[4][4];
	float	y_mtx[4][4];
	float	z_mtx[4][4];
	float	tmp1[4][4];
	float	tmp2[4][4];

	ft_mtxidmake(x_mtx);
	ft_mtxidmake(y_mtx);
	ft_mtxidmake(z_mtx);
	x_mtx[1][1] = cos(point->x);
	x_mtx[1][2] = sin(point->x);
	x_mtx[2][1] = -sin(point->x);
	x_mtx[2][2] = cos(point->x);
	y_mtx[0][0] = cos(point->y);
	y_mtx[0][2] = -sin(point->y);
	y_mtx[2][0] = sin(point->y);
	y_mtx[2][2] = cos(point->y);
	z_mtx[0][0] = cos(point->z);
	z_mtx[0][1] = sin(point->z);
	z_mtx[1][0] = -sin(point->z);
	z_mtx[1][1] = cos(point->z);
	ft_mtxmult(mtx, y_mtx, tmp1);
	ft_mtxmult(tmp1, x_mtx, tmp2);
	ft_mtxmult(tmp2, z_mtx, mtx);
}
