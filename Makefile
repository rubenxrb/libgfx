NAME = libgfx.a

CC = gcc -Wall -Werror -Wextra
RM = /bin/rm

SDIR = ./src/
ODIR = ./obj/
LFTD = ../libft/
LFT = ../libft/libft.a
IDIR = -Iinc -I$(LFTD)inc -I$(LFTD)src/get_next_line/inc -I../minilibx
INC = $(IDIR) $(ILFT)
LNK = -L$(LFTD) -lft

SRCN = colors.c	\
  drawing.c		\
  frame.c		\
  keys.c		\
  mtx_funct.c	\
  mtx.c			\
  vertex.c		\
  init.c

SRC = $(addprefix $(SDIR),$(SRCN))
OBJN = $(SRCN:.c=.o)
OBJ = $(addprefix $(ODIR),$(OBJN))

all: $(NAME)
	ar rc $(NAME) $(OBJ)

$(NAME):mkobjd $(OBJ)
$(ODIR)%.o:$(SDIR)%.c
	@$(CC) $(IDIR) -o $@ -c $^

$(LFT):
	make -s -C $(LFTD)

mkobjd:
	mkdir -p $(ODIR)

clean:
	$(RM) -rf $(ODIR)
	make -s -C $(LFTD) clean

fclean: clean
	$(RM) -rf $(NAME)

re: fclean all
