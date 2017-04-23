#ifndef GFX_KEYS_H
# define GFX_KEYS_H

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

# define KEY_Q 12
# define KEY_E 14

# define KEY_PLUS 69
# define KEY_MIN 78

# define KEY_UP 126
# define KEY_DOWN 125
# define KEY_LEFT 123
# define KEY_RIGHT 124

# define KEY_ESC 53

typedef struct	s_keys
{
	int			w:1;
	int			a:1;
	int			s:1;
	int			d:1;
	int			q:1;
	int			e:1;
	int			min:1;
	int			plus:1;
	int			up:1;
	int			down:1;
	int			left:1;
	int			right:1;
}				t_keys;

#endif
