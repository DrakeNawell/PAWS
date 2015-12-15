/*
** main.c for Loader OBJ in /home/lejeun_m/Projets_Perso/PAWS
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Dec 15 01:43:55 2015 Matthew LEJEUNE
** Last update Tue Dec 15 02:43:13 2015 Matthew LEJEUNE
*/

#include "loader.h"

int		main(int argc, char *argv[])
{
  char		*buffer;

  if (argc > 1)
    {
      if ((buffer = reader(argv[1])) == NULL)
	return (-1);
    }
  else
    dprintf(1, "usage:\n\t./test file [-options]\n");
  free(buffer);
  return (0);
}
