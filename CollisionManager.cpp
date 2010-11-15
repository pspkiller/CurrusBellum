/*
 * CollisionManager.cpp
 *
 *  Created on: 4 nov. 2010
 *      Author: PsPKiller
 */

#include "CollisionManager.h"

CollisionManager::CollisionManager(scene::ISceneManager* sm, scene::ICameraSceneNode* cam, Arene* ar)
{
	collisionManager = sm->getSceneCollisionManager();
	smgr = sm;
	camera = cam;
	arena = ar;
}

core::vector3df CollisionManager::getMousetoGroundCollision(int x,  int y)
{
	core::line3df ray = collisionManager->getRayFromScreenCoordinates(core::vector2di(x,y), camera);
	core::vector3df collision;
	core::triangle3df outTri;
	const scene::ISceneNode* outNode;
	collisionManager->getCollisionPoint(ray, arena->getGroundTriSelector(), collision, outTri, outNode);
	return collision;
}

scene::ISceneNode* CollisionManager::setCollisionTankFromWalls(Char* tank)
{
	std::map<int, scene::ISceneNode*>::iterator it;
	for(it = arena->getWallsBegin(); it != arena->getWallsEnd(); it++)
	{
		if(tank->getBody()->getTransformedBoundingBox().intersectsWithBox((*it).second->getTransformedBoundingBox()))
		{
			return (*it).second;
		}
	}
	return 0;
}

void CollisionManager::setCollisionMissileFromWalls(MissileManager* missM)
{
	std::map<int, scene::ISceneNode*>::iterator itW;
	std::multiset<Missile*>::iterator itM;
	for(itM = missM->getMissilesBegin(); itM != missM->getMissilesEnd(); itM++)
	{
		for(itW = arena->getWallsBegin(); itW != arena->getWallsEnd(); itW++)
		{
			if((*itM)->getBody()->getTransformedBoundingBox().intersectsWithBox((*itW).second->getTransformedBoundingBox()))
			{
				collidedMissile.insert((*itM));
			}
		}
	}
}

std::multiset<Missile*>* CollisionManager::getCollidedMissile()
{
	return &collidedMissile;
}

