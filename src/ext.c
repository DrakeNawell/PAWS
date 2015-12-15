/*
** ext.c for Loader in /home/lejeun_m/Projets_Perso/PAWS
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Dec 15 02:07:09 2015 Matthew LEJEUNE
** Last update Tue Dec 15 02:43:39 2015 Matthew LEJEUNE
*/

#include "loader.h"

static char    	*getExt()
{
  return (".obj");
}

int		ext(const char *filename)
{
  char		*ext = NULL;
  char		*cmp_ext = NULL;
  char		*tmp_ext = NULL;

  if ((cmp_ext = malloc(sizeof(char) * (strlen(getExt()) + 1))) == NULL)
    return (-1);
  strcpy(cmp_ext, getExt());
  if ((ext = substr(filename, lastIndexOf(filename, '.'), strlen(filename))) == NULL)
    return (-1);
  while ((tmp_ext = strtok_r(cmp_ext, ";", &cmp_ext)))
    {
      if (strcmp(ext, tmp_ext) == 0)
	{
	  free(ext);
	  return (0);
	}
    }
  free(ext);
  return (-1);
}
