/*
 * Missile.cpp
 *
 *  Created on: 9 nov. 2010
 *      Author: PsPKiller
 */

#include "Missile.h"

/*
 * Missile
 */

Missile::Missile(scene::ISceneManager* smgr, core::vector3df pos, core::vector3df rot)
{
	Body = smgr->addSphereSceneNode();
	if(Body)
	{
		Body->setPosition(pos);
		Body->setScale(core::vector3df(0.1f,0.1f,0.1f));
		Body->setRotation(rot);
	}
}

Missile::~Missile()
{
	Body->remove();
	//delete(Body);
}

scene::ISceneNode* Missile::getBody()
{
	return Body;
}

void Missile::update()
{
	Body->setPosition(Body->getPosition() - Body->getRotation().rotationToDirection());
}

/*
 * MissileManager
 */

MissileManager::MissileManager(scene::ISceneManager* sm)
{
	smgr = sm;
}

std::multiset<Missile*>::iterator MissileManager::getMissilesBegin()
{
	return missiles.begin();
}

std::multiset<Missile*>::iterator MissileManager::getMissilesEnd()
{
	return missiles.end();
}

void MissileManager::addMissile(core::vector3df pos, core::vector3df rot)
{
	Missile* missile = new Missile(smgr, pos, rot);
	missiles.insert(missile);
}

void MissileManager::deleteMissiles(std::multiset<Missile*>* collidedMissile)
{
	std::multiset<Missile*>::iterator it;
	for(it = collidedMissile->begin(); it != collidedMissile->end(); it++)
	{
		missiles.erase((*it));
		collidedMissile->erase(it);
		delete((*it));
	}
	collidedMissile->clear();
}

void MissileManager::updateMissiles()
{
	std::multiset<Missile*>::iterator it;
	for(it = missiles.begin(); it != missiles.end(); it++)
		(*it)->update();
}
