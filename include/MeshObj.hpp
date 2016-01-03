//
// MeshObj.hpp for Loader in /home/lejeun_m/Projets_Perso/PAWS
// 
// Made by Matthew LEJEUNE
// Login   <lejeun_m@epitech.net>
// 
// Started on  Fri Dec 25 17:07:29 2015 Matthew LEJEUNE
// Last update Sun Jan  3 18:53:13 2016 Matthew LEJEUNE
//

#include "Material.hpp"
#include "MeshObjGroup.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <GL/gl.h>

class MeshObj
{
public:
  MeshObj(std::string n);

  ~MeshObj();

  void charger_obj(std::string n);

  void charger_mtl(MeshObjGroup *g, std::string n);

  void draw_model(GLuint drawingMode);

  void setMaterialsAndTex(std::vector<Material*> mats, GLuint tex);

  void giveMaterialsAndTex(MeshObj *target);

  Material *GetMaterialByName(std::string name);

private:
  GLuint texture;
  GLuint tex[4];
  GLuint n_data;
  bool isVertice, isNormal, isTexture;
  std::vector<MeshObjGroup> groups;
  float *vertice, *normals, *textures, *colours;
  std::vector<Material*> materiaux;
};
