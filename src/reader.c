/*
** reader.c for Loader in /home/lejeun_m/Projets_Perso/PAWS
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Dec 15 01:46:28 2015 Matthew LEJEUNE
** Last update Tue Dec 15 02:27:42 2015 Matthew LEJEUNE
*/

#include "loader.h"

char		*reader(const char *filename)
{
  struct stat	st;
  int		fd;
  char		*buffer;

  if (ext(filename) == -1)
    {
      dprintf(2, "Wrong file extension.\n");
      return (NULL);
    }
  if (stat(filename, &st) == -1)
    {
      dprintf(2, "Error reading file stat.\nDoes the file exist ?\n");
      return (NULL);
    }
  if ((fd = open(filename, O_RDONLY)) == -1)
    return (NULL);
  if ((buffer = malloc(sizeof(char) * (st.st_size + 1))) == NULL)
    {
      dprintf(2, "Error allocating buffer memory.\n");
      return (NULL);
    }
  memset(buffer, '\0', (st.st_size + 1));
  if (read(fd, buffer, st.st_size) != st.st_size)
    {
      dprintf(2, "File size mismatch while reading.\n");
      free(buffer);
      return (NULL);
    }
  printf("%s", buffer);
  return (buffer);
}
