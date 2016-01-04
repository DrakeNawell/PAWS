//
// MeshObjGroup.cpp for Loader in /home/lejeun_m/Projets_Perso/PAWS
// 
// Made by Matthew LEJEUNE
// Login   <lejeun_m@epitech.net>
// 
// Started on  Thu Dec 31 23:01:15 2015 Matthew LEJEUNE
// Last update Mon Jan  4 03:46:30 2016 Matthew LEJEUNE
//

#include "../../../include/MeshObjGroup.hpp"

MeshObjGroup::MeshObjGroup()
{

}

MeshObjGroup::~MeshObjGroup()
{

}

MeshObjGroup MeshObjGroup::operator=(MeshObjGroup *group)
{
  n_data = group->n_data;
  mat = group->mat;
  iv = group->iv;
  it = group->it;
  in = group->in;
  vertice = group->vertice;
  normals = group->normals;
  textures = group->textures;
  colours = group->colours;
  return (*this);
}
