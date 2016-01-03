##
## Makefile for Loader in /home/lejeun_m/Projets_Perso/PAWS
## 
## Made by Matthew LEJEUNE
## Login   <lejeun_m@epitech.net>
## 
## Started on  Sun Jan  3 21:38:50 2016 Matthew LEJEUNE
## Last update Sun Jan  3 22:20:42 2016 Matthew LEJEUNE
##

SRC=	src/Main.cpp \
	src/loader/FloatVector.cpp \
	src/loader/Material.cpp \
	src/loader/obj/MeshObj.cpp \
	src/loader/obj/MeshObjGroup.cpp \
	src/loader/sdlglutils.cpp

OBJ=	$(SRC:.cpp=.o)

CFLAGS=	-Wall -Wextra -g3 -I include/

LDFLAGS= -lSDL -lSDLmain -lSDL_image -lGL -lGLU

CXX=	g++

NAME=	loader

all:	$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: 	fclean all
