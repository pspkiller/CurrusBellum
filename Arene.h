/*
 * Arene.h
 *
 *  Created on: 1 nov. 2010
 *      Author: PsPKiller
 */

#ifndef ARENE_H_
#define ARENE_H_

#include <irrlicht.h>
#include <map>

using namespace irr;

class Arene
{
public :
	Arene(scene::ISceneManager*, video::IVideoDriver*);
	scene::ISceneNode* getGround();
	scene::ITriangleSelector* getGroundTriSelector();
	std::map<int, scene::ISceneNode*>::iterator getWallsBegin();
	std::map<int, scene::ISceneNode*>::iterator getWallsEnd();

private :
	scene::ISceneNode* Ground;
	std::map<int, scene::ISceneNode*> Walls;
	scene::ITriangleSelector* GroundTriSelector;
	scene::ILightSceneNode* light1;
	scene::ILightSceneNode* light2;
	scene::ILightSceneNode* light3;
	scene::ILightSceneNode* light4;
};

#endif /* ARENE_H_ */
