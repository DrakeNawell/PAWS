//
// Material.cpp for Loader in /home/lejeun_m/Projets_Perso/PAWS
// 
// Made by Matthew LEJEUNE
// Login   <lejeun_m@epitech.net>
// 
// Started on  Sun Jan  3 21:54:20 2016 Matthew LEJEUNE
// Last update Mon Jan  4 03:47:25 2016 Matthew LEJEUNE
//

#include "Material.hpp"

using namespace std;

Material::Material(string n):name(n)
{
  texture = 0;
}

Material::Material(float r,float g,float b,string n):name(n)
{
  diffuse.x=r;
  diffuse.y=g;
  diffuse.z=b;
  texture = 0;
}

Material::Material(Material *mat)
{
  diffuse=mat->diffuse;
  name=mat->name;
  texture = 0;
}

Material::~Material()
{
}
