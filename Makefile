##
## Makefile for Loader in /home/lejeun_m/Projets_Perso/PAWS
## 
## Made by Matthew LEJEUNE
## Login   <lejeun_m@epitech.net>
## 
## Started on  Sun Jan  3 21:38:50 2016 Matthew LEJEUNE
## Last update Mon Jan  4 03:40:30 2016 Matthew LEJEUNE
##

SRCDIR		=	src/
SRC_LOADER_DIR	=	$(SRCDIR)loader/
SRC_OBJ_DIR	=	$(SRC_LOADER_DIR)obj/

SRC		=	$(SRCDIR)Main.cpp \
				$(SRC_LOADER_DIR)FloatVector.cpp \
				$(SRC_LOADER_DIR)Material.cpp \
				$(SRC_LOADER_DIR)sdlglutils.cpp \
					$(SRC_OBJ_DIR)MeshObj.cpp \
					$(SRC_OBJ_DIR)MeshObjGroup.cpp \

OBJ		=	$(SRC:.cpp=.o)

CXXFLAGS	=	-Wall -Wextra
CXXFLAGS	+=	-g3
CXXFLAGS	+=	-I include/

LDLIBS		= 	-lSDL -lSDLmain -lSDL_image -lGL -lGLU

CC		=	g++

NAME		=	loader

all:			$(NAME)

$(NAME): 		$(OBJ)
				$(CC) -o $(NAME) $(OBJ) $(LDLIBS)

clean:
				rm -rf $(OBJ)

fclean: 		clean
				rm -rf $(NAME)

re: 			fclean all
