//
// Material.hpp for Loader in /home/lejeun_m/Projets_Perso/PAWS
// 
// Made by Matthew LEJEUNE
// Login   <lejeun_m@epitech.net>
// 
// Started on  Fri Dec 25 17:04:32 2015 Matthew LEJEUNE
// Last update Sun Jan  3 22:50:31 2016 Matthew LEJEUNE
//

#ifndef __MATERIAL__
#define __MATERIAL__

#include "FloatVector.hpp"
#include <string>
#include <GL/gl.h>

class Material
{
public:
  Material(std::string n);

  Material(float r,float g,float b,std::string n);

  Material(Material *mat);

  ~Material();

  Material operator=(const Material &m);

  FloatVector diffuse, specular, ambient;
  GLuint illum;
  std::string name;
  GLuint texture;
};

#endif
