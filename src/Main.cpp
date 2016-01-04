//
// Main.cpp for Loader in /home/lejeun_m/Projets_Perso/PAWS
// 
// Made by Matthew LEJEUNE
// Login   <lejeun_m@epitech.net>
// 
// Started on  Fri Dec 25 17:21:31 2015 Matthew LEJEUNE
// Last update Mon Jan  4 02:44:32 2016 Matthew LEJEUNE
//

#include <SDL/SDL.h>

#include <GL/gl.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include "../include/MeshObj.hpp"
#include "../include/Loader.hpp"


int main(int argc,char *argv[])
{
  SDL_Event event;
  bool continuer=true;
  GLuint drawingMode = GL_QUADS;

  SDL_Init(SDL_INIT_VIDEO);

  SDL_SetVideoMode(1280,720,32,SDL_OPENGL);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70,(double)1280/720,.1,4000);
  glEnable(GL_TEXTURE_2D);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);

  MeshObj *cube=new MeshObj(argv[1]);

  int angle=0;

  while(continuer)
    {
      while (SDL_PollEvent(&event))
	{
	  switch (event.type)
	    {
	    case SDL_QUIT:
	      continuer = false;
	      break;
	    case SDL_KEYDOWN:
	      if (event.key.keysym.sym == SDLK_F1)
		{
		  if (drawingMode == GL_QUADS)
		    drawingMode = GL_LINES;
		  else if (drawingMode == GL_LINES)
		    drawingMode = GL_POINTS;
		  else if (drawingMode == GL_POINTS)
		    drawingMode = GL_QUADS;
		}
	      break;
	    }
	}
      glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

      glMatrixMode(GL_MODELVIEW);

      glLoadIdentity();

      gluLookAt(0,-10,0,0,0,0,0,0,1);

      glRotatef(90,1,0,0);
      glRotatef(angle, 0, 1, 0);
      glScalef(3, 3, 3);
      glTranslatef(0, 0, 0);
      cube->draw_model(drawingMode);

      glFlush();
      SDL_GL_SwapBuffers();
      SDL_Delay(20);

      angle++;
      angle%=360;
    }

  delete cube;

  return EXIT_SUCCESS;
}
