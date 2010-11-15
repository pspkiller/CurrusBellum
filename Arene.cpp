/*
 * Arene.cpp
 *
 *  Created on: 1 nov. 2010
 *      Author: PsPKiller
 */

#include "Arene.h"

Arene::Arene(scene::ISceneManager* smgr, video::IVideoDriver* driver)
{
	Ground = smgr->addCubeSceneNode();
	if(Ground)
	{
		Ground->setPosition(core::vector3df(40,0,50));
		Ground->setScale(core::vector3df(40,0.2f,40));
		Ground->setMaterialTexture(0, driver->getTexture("D:/Travail/Programmation/media/Textures/terrain_ruinedgrass.jpeg"));
		Ground->setMaterialFlag(video::EMF_LIGHTING, false);
	}
	scene::ISceneNode* wall = smgr->addCubeSceneNode();
	if(wall)
	{
		wall->setPosition(core::vector3df(40,5,-50));
		wall->setScale(core::vector3df(20,1,2));
		wall->setMaterialFlag(video::EMF_LIGHTING, false);
		Walls.insert(std::pair<int, scene::ISceneNode*>(0,wall));
	}
	wall = smgr->addCubeSceneNode();
	if(wall)
	{
		wall->setPosition(core::vector3df(40,5,150));
		wall->setScale(core::vector3df(20,1,2));
		wall->setMaterialFlag(video::EMF_LIGHTING, false);
		Walls.insert(std::pair<int, scene::ISceneNode*>(1,wall));
	}
	wall = smgr->addCubeSceneNode();
	if(wall)
	{
		wall->setPosition(core::vector3df(-50,5,40));
		wall->setScale(core::vector3df(2,1,20));
		wall->setMaterialFlag(video::EMF_LIGHTING, false);
		Walls.insert(std::pair<int, scene::ISceneNode*>(2,wall));
	}
	wall = smgr->addCubeSceneNode();
	if(wall)
	{
		wall->setPosition(core::vector3df(150,5,40));
		wall->setScale(core::vector3df(2,1,20));
		wall->setMaterialFlag(video::EMF_LIGHTING, false);
		Walls.insert(std::pair<int, scene::ISceneNode*>(3,wall));
	}

	GroundTriSelector = smgr->createTriangleSelectorFromBoundingBox(Ground);
	Ground->setTriangleSelector(GroundTriSelector);

	light1 = smgr->addLightSceneNode(0, core::vector3df(40,50,50), video::SColorf(1.0f,1.0f,1.0f,1.0f), 100.0f);;
}

scene::ISceneNode* Arene::getGround()
{
	return Ground;
}

scene::ITriangleSelector* Arene::getGroundTriSelector()
{
	return GroundTriSelector;
}

std::map<int, scene::ISceneNode*>::iterator Arene::getWallsBegin()
{
	return Walls.begin();
}

std::map<int, scene::ISceneNode*>::iterator Arene::getWallsEnd()
{
	return Walls.end();
}
