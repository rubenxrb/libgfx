#ifndef LIBGFX_H
# define LIBGFX_H

# include "libft.h"
# include <mlx.h>
# include <math.h>

# define ABS(x) ((x > 0) ? x : x * -1)
# define W_WIDTH 1600
# define W_HEIGHT 1200

typedef struct	s_xy
{
	float		x;
	float		y;
}				t_2dp;

typedef struct	s_xyz
{
	float		x;
	float		y;
	float		z;
}				t_3dp;

typedef struct	s_rgb
{
	t_byte		r;
	t_byte		g;
	t_byte		b;
}				t_rgb;

typedef struct	s_line
{
	t_3dp		point_a;
	t_3dp		point_b;
	t_rgba		color_a;
	t_rgba		color_b;
}				t_line;

typedef struct	s_vtx
{
	t_3dp		*local;
	t_3dp		*world;
	t_3dp		*align;
	t_rgba		*color;
}				t_vtx;

typedef struct	s_data
{
	char		*pixels;
	int			bpp;
	int			line_size;
	int			endian;
}				t_data;

typedef struct	s_mlx
{
	void		*id;
	void		*win;
	void		*img;
	t_data		*frame;
}				t_mlx;

void	bzero_mtx(float mtx[4][4]);
void	ft_mtxidmake(float mtx[4][4]);
void	ft_mtxcpy(float src[4][4], float dst[4][4]);
void	ft_mtxmult(float m1[4][4], float m2[4][4], float dst[4][4]);
void	ft_mtxmultvec(t_3d *src, float mtx[4][4], t_3d *dst);
void	ft_mtx_translate(float mtx[4][4], t_3dp point);
void	ft_mtx_scale(float mtx[4][4], t_3dp point);
void	ft_mtx_rotate(float mtx[4][4], t_3dp point);
t_3dp	*ft_3dpnew(float x, float y, float z);
t_vtx	*ft_vtxnew(t_3dp local, t_3dp world, t_3dp align);

#endif
