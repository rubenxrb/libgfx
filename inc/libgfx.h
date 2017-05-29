#ifndef LIBGFX_H
# define LIBGFX_H

# include <libft.h>
# include <gfx_keys.h>
# include <mlx.h>
# include <math.h>

# define W_WIDTH 1200
# define W_HEIGHT 900
# define RGB_STEPS 150
# define ABS(x) ((x > 0) ? x : x * -1)

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

typedef struct	s_vtx
{
	t_3dp		*local;
	t_3dp		*world;
	t_3dp		*align;
	t_3dp		*proj;
}				t_vtx;

typedef struct	s_line
{
	t_3dp		point_a;
	t_3dp		point_b;
}				t_line;

typedef struct	s_mods
{
	t_3dp		rot;
	t_3dp		shift;
	float		scale;
	int			per;
}				t_mods;

typedef struct	s_data
{
	char		*pixels;
	t_color		*tab;
	int			bpp;
	int			line_size;
	int			endian;
	float		z_min;
	float		z_max;
}				t_data;

typedef struct	s_mlx
{
	void		*id;
	void		*win;
	void		*img;
	t_data		*frame;
	t_mods		*trans;
	t_keys		*events;
}				t_mlx;

t_mlx			*init_mlx(size_t w_width, size_t w_height, const char *name);
t_3dp			init_3dp(float x, float y, float z);
t_2dp			init_2dp(float x, float y);
t_line			init_line(t_3dp *a, t_3dp *b);
t_rgb			init_rgb(t_color col);
t_rgb			*ft_colornew(const char *color);
t_rgb			ft_colormix(t_rgb color_a, t_rgb color_b);
t_color			ft_rgbtoint(t_rgb col);
t_color			*new_colortab(t_rgb *scheme, int num);
void			ft_renderframe(t_mlx *mlx);
t_2dp			*ft_2dpnew(float x, float y);
t_3dp			*ft_3dpnew(float x, float y, float z);
t_vtx			*ft_vtxnew(t_3dp *local);
int				ft_drawpixel(t_mlx *mlx, t_3dp point);
void			ft_drawline(t_mlx *mlx, t_line line);
void			bzero_mtx(float mtx[4][4]);
void			ft_mtxidmake(float mtx[4][4]);
void			ft_mtxcpy(float src[4][4], float dst[4][4]);
void			ft_mtxmult(float m1[4][4], float m2[4][4], float dst[4][4]);
void			ft_mtxmultvec(t_3dp *src, float mtx[4][4], t_3dp *dst);
void			ft_mtx_translate(float mtx[4][4], t_3dp *point);
void			ft_mtx_scale(float mtx[4][4], t_3dp *point);
void			ft_mtx_rotate(float mtx[4][4], t_3dp *point);
int				press_hook(int key, t_mlx *mlx);
int				release_hook(int key, t_mlx *mlx);
int				exit_hook();

#endif
