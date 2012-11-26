#ifndef TERRAIN_H
#define TERRAIN_H

#include "object.h"

struct Terrain:public Object{

	Terrain(string name, string type, string info):Object(name,type,info){}

};

#endif
