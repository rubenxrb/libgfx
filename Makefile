NAME = libgfx.a

CC = gcc -Wall -Werror -Wextra
RM = /bin/rm

SDIR = ./src/
ODIR = ./obj/
LFTD = ../libft/
ILFT = -I../libft/inc
IDIR = -Iinc
INC = $(IDIR) $(ILFT)
LNK = -L$(LFTD) -lft

SRCN = colors.c drawing.c image.c keys.c	\
	mtx_funct.c mtx.c vertex.c
SRC = $(addprefix $(SDIR),$(SRCN))
OBJ = $(addprefix $(ODIR),$(SRC:.c=.o))

all: $(NAME)
	ar rc $(NAME) $(OBJ)

$(NAME):lib $(OBJ)
$(OBJ):$(SRC)
	$(CC) -o $@ -c $< $(INC)

lib:
	make -s -C $(LFTD)

clean:
	$(RM) -rf $(ODIR)
	make -s -C $(LFTD) clean

fclean: clean
	$(RM) -rf $(NAME)

re: fclean all
