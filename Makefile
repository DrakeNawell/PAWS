SRC=		src/main.c \
		src/reader.c \
		src/ext.c \
		utils/lastIndexOf.c \
		utils/substr.c

OBJ=		$(SRC:.c=.o)

NAME=		test

CC=		gcc

CFLAGS=		-Wall -Wextra -g3
CFLAGS+=	-I ./include `pkg-config --cflags glfw3`

LDFLAGS=	`pkg-config --static --libs glfw3`

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
