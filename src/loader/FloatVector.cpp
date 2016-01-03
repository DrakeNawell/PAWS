//
// FloatVector.cpp for Loader in /home/lejeun_m/Projets_Perso/PAWS
// 
// Made by Matthew LEJEUNE
// Login   <lejeun_m@epitech.net>
// 
// Started on  Sun Jan  3 21:53:40 2016 Matthew LEJEUNE
// Last update Sun Jan  3 22:43:40 2016 Matthew LEJEUNE
//

#include "../../include/FloatVector.hpp"

FloatVector::FloatVector(float px,float py,float pz,float pa):x(px),y(py),z(pz),a(pa)
{
}
FloatVector::~FloatVector()
{
}
FloatVector FloatVector::operator=(const FloatVector &fv)
{
  x=fv.x;
  y=fv.y;
  z=fv.z;
  a=fv.a;

  return *this;
}
