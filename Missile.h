/*
 * Missile.h
 *
 *  Created on: 9 nov. 2010
 *      Author: PsPKiller
 */

#ifndef MISSILE_H_
#define MISSILE_H_

#include <irrlicht.h>
#include <set>

using namespace irr;

class Missile
{
public :
	Missile(scene::ISceneManager*, core::vector3df, core::vector3df);
	~Missile();
	scene::ISceneNode* getBody();
	void update();
private :
	scene::ISceneNode* Body;
};

class MissileManager
{
public :
	MissileManager(scene::ISceneManager*);
	void addMissile(core::vector3df, core::vector3df);
	void deleteMissiles(std::multiset<Missile*>*);
	void updateMissiles();
	std::multiset<Missile*>::iterator getMissilesBegin();
	std::multiset<Missile*>::iterator getMissilesEnd();
private :
	scene::ISceneManager* smgr;
	std::multiset<Missile*> missiles;
};

#endif /* MISSILE_H_ */
