/*
 * CollisionManager.h
 *
 *  Created on: 4 nov. 2010
 *      Author: PsPKiller
 */

#ifndef COLLISIONMANAGER_H_
#define COLLISIONMANAGER_H_

#include <irrlicht.h>
#include "Arene.h"
#include "Char.h"
#include "Missile.h"

using namespace irr;

class CollisionManager
{
public :
	CollisionManager(scene::ISceneManager*, scene::ICameraSceneNode*, Arene*);
	core::vector3df getMousetoGroundCollision(int, int);
	scene::ISceneNode* setCollisionTankFromWalls(Char*);
	void setCollisionMissileFromWalls(MissileManager*);
	std::multiset<Missile*>* getCollidedMissile();
private :
	std::multiset<Missile*> collidedMissile;
	scene::ISceneCollisionManager* collisionManager;
	scene::ISceneManager* smgr;
	scene::ICameraSceneNode* camera;
	Arene* arena;
};

#endif /* COLLISIONMANAGER_H_ */
