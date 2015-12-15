/*
** loader.h for Loader in /home/lejeun_m/Projets_Perso/PAWS
** 
** Made by Matthew LEJEUNE
** Login   <lejeun_m@epitech.net>
** 
** Started on  Tue Dec 15 01:45:25 2015 Matthew LEJEUNE
** Last update Tue Dec 15 02:29:06 2015 Matthew LEJEUNE
*/

#ifndef __LOADER_H__
#define __LOADER_H__

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

char		*reader(const char *);
int		ext(const char *);

char		*substr(const char *, int, int);
int		lastIndexOf(const char *, char);

#endif
