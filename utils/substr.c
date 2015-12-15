/*
** substr.c for Loader in /home/lejeun_m/Projets_Perso/PAWS
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Dec 15 02:21:16 2015 Matthew LEJEUNE
** Last update Tue Dec 15 02:29:30 2015 Matthew LEJEUNE
*/

#include "loader.h"

char		*substr(const char *str, int start, int end)
{
  int		cur_char = -1;
  char		*new_str = NULL;

  if ((new_str = malloc(sizeof(char) * (end - start + 1))) == NULL)
    return (NULL);
  memset(new_str, '\0', (end - start + 1));
  while (start < end && str[start] != '\0')
    {
      new_str[++cur_char] = str[start];
      start++;
    }
  return (new_str);
}
