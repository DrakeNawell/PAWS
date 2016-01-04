//
// MeshObjGroup.hpp for Loader in /home/lejeun_m/Projets_Perso/PAWS
// 
// Made by Matthew LEJEUNE
// Login   <lejeun_m@epitech.net>
// 
// Started on  Thu Dec 31 23:01:22 2015 Matthew LEJEUNE
// Last update Mon Jan  4 03:42:17 2016 Matthew LEJEUNE
//

#ifndef __OBJ_GROUP__
#define __OBJ_GROUP__

#include <vector>
#include <stdlib.h>
#include <GL/gl.h>
#include "Material.hpp"

using namespace std;

class MeshObjGroup
{
public:
  MeshObjGroup();
  ~MeshObjGroup();

  MeshObjGroup operator=(MeshObjGroup *group);
  int n_data;
  string mat;
  vector<unsigned int> iv, in, it;
  float *vertice, *normals, *textures, *colours;
};

#endif
