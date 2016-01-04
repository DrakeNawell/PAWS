//
// MeshObj.cpp for Loader in /home/lejeun_m/Projets_Perso/PAWS
// 
// Made by Matthew LEJEUNE
// Login   <lejeun_m@epitech.net>
// 
// Started on  Fri Dec 25 16:18:33 2015 Matthew LEJEUNE
// Last update Mon Jan  4 03:48:14 2016 Matthew LEJEUNE
//

#include "sdlglutils.h"
#include "MeshObj.hpp"
#include "MeshObjGroup.hpp"

using namespace std;

vector<string> splitSpace(string s)
{
  vector<string> ret;
  string s1="";
  for(unsigned int i=0;i<s.size();i++)
    {
      if(s[i]==' '||i==s.size()-1)
        {
	  if(i==s.size()-1)
	    s1+=s[i];
	  ret.push_back(s1);
	  s1="";
        }
      else
	s1+=s[i];
    }
  return ret;
}

int	nbOccur(const char *s, char c)
{
  int	cur_char = 0;
  int	count = 0;
  
  while (s[cur_char] != '\0')
    {
      if (s[cur_char] == c)
	count++;
      cur_char++;
    }
  return (count);
}

string doubleSlash(string s)
{
  string s1 = "";
  vector<string> split = splitSpace(s.substr(2));

  for(unsigned int i = 0; i < s.size(); i++)
    {
      if(i < s.size() - 1 && s[i] == '/' && s[i + 1] == '/')
        {
	  s1 += "/1/";
	  i++;
        }
      else
	s1 += s[i];
    }
  return s1;
}

string remplacerSlash(string s)
{
  string ret="";
  for(unsigned int i=0;i<s.size();i++)
    {
      if(s[i]=='/')
	ret+=' ';
      else
	ret+=s[i];
    }
  return ret;
}

string get_directory(string s)
{
  string s1="",s2="";
  for(unsigned int i=0;i<s.size();i++)
    {
      if(s[i]=='/'||s[i]=='\\')
        {
	  s1+=s2+"/";
	  s2="";
        }
      else
	s2+=s[i];
    }
  return s1;
}

float* vector2float(vector<float>& tableau)
{
  float* t=NULL;
  t=(float*)malloc(tableau.size()*sizeof(float));
  if(t==NULL||tableau.empty())
    {
      float *t1=(float*)malloc(sizeof(float)*3);
      for(int i=0;i<3;i++)
	t1[i]=0.;
      return t1;
    }

  for(unsigned int i=0;i<tableau.size();i++)
    t[i]=tableau[i];
  return t;
}

Material	*MeshObj::GetMaterialByName(string name)
{
  for (unsigned int i = 0; i < materiaux.size(); i++)
    {
      if (name.compare(materiaux[i]->name) == 0)
	return (materiaux[i]);
    }
  return (NULL);
}

MeshObj::MeshObj(string s)
{
  charger_obj(s);
}
MeshObj::~MeshObj()
{
  for (unsigned int i = 0; i < groups.size(); i++)
    {
      free(groups[i].vertice);
      if (isNormal)
	free(groups[i].normals);
      if (isTexture)
	free(groups[i].textures);
      free(groups[i].colours);
    }

  if (!materiaux.empty())
    {
      for(unsigned int i = 0;i < (materiaux.size() - 1); i++)
	delete materiaux[i];
      materiaux.clear();
    }
}

void MeshObj::charger_obj(string nom)
{
  MeshObjGroup *group;
  ifstream fichier(nom.c_str(), ios::in);
  vector<FloatVector> ver,nor,tex,col;

  string ligne,curname="";

  if(fichier)
    {
      while(getline(fichier,ligne))
        {
	  if(ligne[0]=='v')
            {
	      if(ligne[1]==' ') //Vertex
                {
		  if (!isVertice)
		    isVertice = true;
		  char x[255],y[255],z[255];
		  sscanf(ligne.c_str(),"v %s %s %s",x,y,z);
		  ver.push_back(FloatVector(strtod(x,NULL),strtod(y,NULL),strtod(z,NULL)));
                }
	      else if(ligne[1]=='t') //Texture
                {
		  if (!isTexture)
		    isTexture = true;
		  char x[255],y[255];
		  sscanf(ligne.c_str(),"vt %s %s",x,y);
		  tex.push_back(FloatVector(strtod(x,NULL),strtod(y,NULL)));
                }
	      else if(ligne[1]=='n') //Normale
                {
		  if (!isNormal)
		    isNormal = true;
		  char x[255],y[255],z[255];
		  sscanf(ligne.c_str(),"vn %s %s %s",x,y,z);
		  nor.push_back(FloatVector(strtod(x,NULL),strtod(y,NULL),strtod(z,NULL)));
                }
            }
	  else if (ligne[0] == 'g')
	    {
	      if (group)
		groups.push_back(*group);
	      group = new MeshObjGroup();
	    }
	  else if(ligne[0]=='f') //Indice faces
            {
	      if (!group)
		group = new MeshObjGroup();
	      int ndata = nbOccur(splitSpace(ligne.substr(2))[0].c_str(), '/') + 1;
	      ligne=doubleSlash(ligne);
	      ligne=remplacerSlash(ligne);

	      vector<string> termes=splitSpace(ligne.substr(2));
	      
	      int ndonnees;
	      if (!isNormal || !isTexture)
		ndonnees = (int)termes.size() / 2;
	      else
		ndonnees = (int)termes.size() / 3;
	      for(int i = 0; i < (ndonnees==3?3:4); i++)
                {
		  group->iv.push_back(strtol(termes[i*ndata].c_str(),NULL,10)-1);
		  if (isTexture)
		    group->it.push_back(strtol(termes[i*ndata+1].c_str(),NULL,10)-1);
		  if (isNormal)
		    group->in.push_back(strtol(termes[i*ndata+2].c_str(),NULL,10)-1);
                }
	      if(ndonnees==3)
                {
		  group->iv.push_back(strtol(termes[0].c_str(),NULL,10)-1);
		  if (isTexture)
		    group->it.push_back(strtol(termes[1].c_str(),NULL,10)-1);
		  if (isNormal)
		    group->in.push_back(strtol(termes[2].c_str(),NULL,10)-1);
                }
	      for(unsigned int i=0;i<materiaux.size();i++)
		{
		  if(materiaux[i]->name==curname)
		    {
		      for(int j=0;j<4;j++)
			col.push_back(materiaux[i]->diffuse);
		      break;
		    }
		}
            }
	  else if(ligne[0]=='m')
	    {
	      charger_mtl(get_directory(nom)+ligne.substr(7));
	      printf("MTL loaded\n");
	    }
	  else if(ligne[0]=='u')
	    {
	      if (group)
		{
		  groups.push_back(*group);
		  group = NULL;
		}
	      if (!group)
		group = new MeshObjGroup();
	      curname=ligne.substr(7);
	      group->mat = curname;
	    }
        }
      fichier.close();
      groups.push_back(*group);

      for (int index = 0; index < (int)groups.size(); index++)
	{
	  vector<float> tc(0), tv(0), tn(0), tt(0);
	  for(unsigned int i = 0; i < groups[index].iv.size(); i++)
	    if(groups[index].iv[i] < ver.size())
	      {
		tv.push_back(ver[groups[index].iv[i]].x);
		tv.push_back(ver[groups[index].iv[i]].y);
		tv.push_back(ver[groups[index].iv[i]].z);
		
		if (col.size() > 0)
		  {
		    tc.push_back(col[i].x);
		    tc.push_back(col[i].y);
		    tc.push_back(col[i].z);
		    tc.push_back(col[i].a);
		  }
		else
		  {
		    tc.push_back(.8);
		    tc.push_back(.8);
		    tc.push_back(.8);
		    tc.push_back(1);
		  }
	      }
	  
	  if (isNormal)
	    for(unsigned int i = 0; i < groups[index].in.size(); i++)
	      if(groups[index].in[i]<nor.size())
		{
		  tn.push_back(nor[groups[index].in[i]].x);
		  tn.push_back(nor[groups[index].in[i]].y);
		  tn.push_back(nor[groups[index].in[i]].z);
		}
	  
	  if (isTexture)
	    for(unsigned int i = 0; i < groups[index].it.size(); i++)
	      if(groups[index].it[i] < tex.size())
		{
		  tt.push_back(tex[groups[index].it[i]].x);
		  tt.push_back(tex[groups[index].it[i]].y);
		}
	  
	  groups[index].vertice = vector2float(tv);
	  if (isNormal)
	    groups[index].normals = vector2float(tn);
	  if (isTexture)
	    groups[index].textures = vector2float(tt);
	  groups[index].colours = vector2float(tc);
	  groups[index].n_data = groups[index].iv.size();
	  groups[index].iv.clear();
	  groups[index].it.clear();
	  groups[index].in.clear();
	}
    }
  ver.clear();
  nor.clear();
  tex.clear();
  col.clear();
}

void MeshObj::charger_mtl(string nom)
{
  ifstream fichier(nom.c_str(), ios::in);
  string curname="";
  Material *mat = NULL;

  if(fichier)
    {
      string ligne="";
      while(getline(fichier,ligne))
        {
	  if(ligne[0]=='n')
	    {
	      if (mat)
	        materiaux.push_back(mat);
	      curname=ligne.substr(7);
	      mat = new Material(curname);
	    }
	  else if(ligne[0]=='K'&&ligne[1]=='d')
            {
	      printf("Diffuse light material for %s\n", curname.c_str());
	      vector<string> termes=splitSpace(ligne.substr(3));
	      mat->diffuse.x = (float)strtod(termes[0].c_str(),NULL);
	      mat->diffuse.y = (float)strtod(termes[1].c_str(),NULL);
	      mat->diffuse.z = (float)strtod(termes[2].c_str(),NULL);
            }
	  else if (ligne[0] == 'K' && ligne[1] == 'a')
	    {
	      printf("Ambient light material for %s\n", curname.c_str());
	      vector<string> t = splitSpace(ligne.substr(3));
	      mat->ambient.x = (float)strtod(t[0].c_str(), NULL);
	      mat->ambient.y = (float)strtod(t[1].c_str(), NULL);
	      mat->ambient.z = (float)strtod(t[2].c_str(), NULL);
	    }
	  else if (ligne[0] == 'K' && ligne[1] == 's')
	    {
	      printf("Spec light material for %s\n", curname.c_str());
	      vector<string> t = splitSpace(ligne.substr(3));
	      mat->specular.x = (float)strtod(t[0].c_str(), NULL);
	      mat->specular.y = (float)strtod(t[1].c_str(), NULL);
	      mat->specular.z = (float)strtod(t[2].c_str(), NULL);
	    }
	  else if(ligne[0]=='m'&&ligne[5]=='d')
            {
	      string f=get_directory(nom)+ligne.substr(7);
	      mat->texture = loadTexture(f.c_str());
	      printf("Texture loaded : %s\nGL_BIND_NUM : %u\n", f.c_str(), mat->texture);
	    }
	  else if(ligne[0]=='d')
            {
	      string n=ligne.substr(2);
	      mat->diffuse.a=strtod(n.c_str(),NULL);
            }
        }
      fichier.close();
      materiaux.push_back(mat);
    }
  else
    {
      fprintf(stderr,"Erreur lors de la lecture de %s...",nom.c_str());
    }
}

void MeshObj::draw_model(GLuint drawingMode)
{
  Material *mater = NULL;

  glEnableClientState(GL_VERTEX_ARRAY);
  if (isTexture && drawingMode == GL_QUADS)
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
  if(isNormal)
    glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  for (int i = 0; i < (int)groups.size(); i++)
    {
      mater = GetMaterialByName(groups[i].mat);
      if (mater)
	{
	  if (isTexture && drawingMode == GL_QUADS)
	    glBindTexture(GL_TEXTURE_2D, mater->texture);
	}
      glVertexPointer(3,GL_FLOAT,0,groups[i].vertice);
      if(isTexture)
	glTexCoordPointer(2,GL_FLOAT,0,groups[i].textures);
      if(isNormal)
	glNormalPointer(GL_FLOAT,0,groups[i].normals);
      glColorPointer(4,GL_FLOAT,0,groups[i].colours);
      glDrawArrays(drawingMode,0,groups[i].n_data);
    }
  glDisableClientState(GL_COLOR_ARRAY);
  if (isTexture)
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
  if (isNormal)
    glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void MeshObj::setMaterialsAndTex(std::vector<Material*> mats,GLuint tex)
{
  materiaux.clear();
  for(unsigned int i=0;i<mats.size();i++)
    materiaux.push_back(new Material(mats[i]));
  texture=tex;
}

void MeshObj::giveMaterialsAndTex(MeshObj *target)
{
  target->setMaterialsAndTex(materiaux,texture);
}
