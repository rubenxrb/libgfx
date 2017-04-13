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
	mtx_funct.c mtx.c vertex.c				\

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

	#
	#
	# NAME = libgfx.a
	#
	# CC = gcc -Wall -Werror -Wextra
	# RM = /bin/rm
	#
	# SDIR = ./src/
	# ODIR = ./obj/
	# LFTD = ../libft/
	# LFT = ../libft/libft.a
	# ILFT = -I../libft/inc
	# IDIR = -Iinc
	# INC = $(IDIR) $(ILFT)
	# LNK = -L$(LFTD) -lft
	#
	# SRCN = colors.c	\
	# 	drawing.c	\
	# 	image.c		\
	# 	keys.c		\
	# 	mtx_funct.c	\
	# 	mtx.c		\
	# 	vertex.c	\
	# 	init.c
	#
	# SRC = $(addprefix $(SDIR),$(SRCN))
	# OBJN = $(SRCN:.c=.o)
	# OBJ = $(addprefix $(ODIR),$(OBJN))
	#
	# all: $(NAME)
	# 	ar rc $(NAME) $(OBJ)
	#
	# $(NAME):mkobjd $(OBJ)
	# $(ODIR)%.o:$(SDIR)%.c
	# 	@$(CC) $(IDIR) $(ILFT) -o $@ -c $^
	#
	# $(LFT):
	# 	make -s -C $(LFTD)
	#
	# mkobjd:
	# 	mkdir -p $(ODIR)
	#
	# clean:
	# 	$(RM) -rf $(ODIR)
	# 	make -s -C $(LFTD) clean
	#
	# fclean: clean
	# 	$(RM) -rf $(NAME)
	#
	# re: fclean all
