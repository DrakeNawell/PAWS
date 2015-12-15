/*
** lastIndexOf.c for Loader in /home/lejeun_m/Projets_Perso/PAWS
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Dec 15 02:19:04 2015 Matthew LEJEUNE
** Last update Tue Dec 15 02:29:18 2015 Matthew LEJEUNE
*/

#include "loader.h"

int		lastIndexOf(const char *str, char cmp)
{
  int		cur_char = -1;
  int		index = -1;

  while (str[++cur_char] != '\0')
    if (str[cur_char] == cmp)
      index = cur_char;
  return (index);
}
