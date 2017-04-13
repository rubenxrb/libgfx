#ifndef LIBGFX_H
# define LIBGFX_H

# include "libft.h"
# include <mlx.h>
# include <math.h>

# define ABS(x) ((x > 0) ? x : x * -1)
# define W_WIDTH 1600
# define W_HEIGHT 1200

typedef int		t_color;

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
	t_byte		a;
}				t_rgb;

typedef struct	s_line
{
	t_3dp		point_a;
	t_3dp		point_b;
	t_rgb		color_a;
	t_rgb		color_b;
}				t_line;

typedef struct	s_vtx
{
	t_3dp		*local;
	t_3dp		*world;
	t_3dp		*align;
	t_rgb		*color;
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
void	ft_mtxmultvec(t_3dp *src, float mtx[4][4], t_3dp *dst);
void	ft_mtx_translate(float mtx[4][4], t_3dp point);
void	ft_mtx_scale(float mtx[4][4], t_3dp point);
void	ft_mtx_rotate(float mtx[4][4], t_3dp point);
int		swap_vars(t_3dp *p0, t_3dp *p1);
t_rgb	*ft_colornew(const char *color);
t_2dp	*ft_2dpnew(float x, float y);
t_3dp	*ft_3dpnew(float x, float y, float z);
t_vtx	*ft_vtxnew(t_3dp *local, t_rgb *color);

#endif

/*
#ifndef LIBGFX_H
# define LIBGFX_H

# include "libft.h"
# include <math.h>

# define ABS(x) ((x > 0) ? x : x * -1)
# define W_WIDTH 1600
# define W_HEIGHT 1200

typedef int		t_color;

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
	t_byte		a;
}				t_rgb;

typedef struct	s_line
{
	t_3dp		*point_a;
	t_3dp		*point_b;
	t_rgb		*color_a;
	t_rgb		*color_b;
}				t_line;

typedef struct	s_vtx
{
	t_3dp		*local;
	t_3dp		*world;
	t_3dp		*align;
	t_rgb		*color;
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

t_mlx	*init_mlx();
t_rgb	*ft_colornew(const char *color);
t_2dp	*ft_2dpnew(float x, float y);
t_3dp	*ft_3dpnew(float x, float y, float z);
t_vtx	*ft_vtxnew(t_3dp *local, t_rgb *color);
t_rgb	ft_colormix(t_rgb color_a, t_rgb color_b);
void	bzero_mtx(float mtx[4][4]);
void	ft_mtxidmake(float mtx[4][4]);
void	ft_mtxcpy(float src[4][4], float dst[4][4]);
void	ft_mtxmult(float m1[4][4], float m2[4][4], float dst[4][4]);
void	ft_mtxmultvec(t_3dp *src, float mtx[4][4], t_3dp *dst);
void	ft_mtx_translate(float mtx[4][4], t_3dp *point);
void	ft_mtx_scale(float mtx[4][4], t_3dp *point);
void	ft_mtx_rotate(float mtx[4][4], t_3dp *point);
int		swap_vars(t_3dp *p0, t_3dp *p1);

#endif
*/
