//
// FloatVector.hpp for Loader in /home/lejeun_m/Projets_Perso/PAWS
// 
// Made by Matthew LEJEUNE
// Login   <lejeun_m@epitech.net>
// 
// Started on  Fri Dec 25 17:03:34 2015 Matthew LEJEUNE
// Last update Fri Jan  1 14:51:05 2016 Matthew LEJEUNE
//

#ifndef __FLOAT_VECTOR__
#define __FLOAT_VECTOR__

class FloatVector
{

public:
  FloatVector(float px=0,float py=0,float pz=0,float pa=0);

  ~FloatVector();

  FloatVector operator=(const FloatVector &fv);

  float x, y, z, a;
};

#endif
