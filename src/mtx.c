#include "libgfx.h"

void	bzero_mtx(float mtx[4][4])
{
	size_t	i;

	i = 0;
	while (i < 4)
		ft_bzero(mtx[i++], sizeof(float) * 4);
}

void	ft_mtxidmake(float mtx[4][4])
{
	bzero_mtx(mtx);
	mtx[0][0] = 1;
	mtx[1][1] = 1;
	mtx[2][2] = 1;
	mtx[3][3] = 1;
}

void	ft_mtxcpy(float src[4][4], float dst[4][4])
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			dst[x][y] = src[x][y];
			y++;
		}
		x++;
	}
}

void	ft_mtxmult(float m1[4][4], float m2[4][4], float dst[4][4])
{
	size_t	x;
	size_t	y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			dst[x][y] = m1[x][0] * m2[0][y] + m1[x][1] * m2[1][y] +
				m1[x][2] * m2[2][y] + m1[x][3] * m2[3][y];
			y++;
		}
		x++;
	}
}

void	ft_mtxmultvec(t_3dp *src, float mtx[4][4], t_3dp *dst)
{
	double	x;
	double	y;
	double	z;

	x = (double)(src->x * mtx[0][0]) + (double)(src->y * mtx[1][0]) +
		(double)(src->z * mtx[2][0]) + mtx[3][0];
	if (x > 3.402823E38 || x < -3.402823E38)
		dst->x = (x < 0.0) ? -3.402823E38 : 3.402823E38;
	else
		dst->x = x;
	y = (double)(src->x * mtx[0][1]) + (double)(src->y * mtx[1][1]) +
		(double)(src->z * mtx[2][1]) + mtx[3][1];
	if (y > 3.402823E38 || y < -3.402823E38)
		dst->y = (y < 0.0) ? -3.402823E38 : 3.402823E38;
	else
		dst->y = y;
	z = (double)(src->x * mtx[0][2]) + (double)(src->y * mtx[1][2]) +
		(double)(src->z * mtx[2][2]) + mtx[3][2];
	if (z > 3.402823E38 || z < -3.402823E38)
		dst->z = (z < 0.0) ? -3.402823E38 : 3.402823E38;
	else
		dst->z = z;
}
