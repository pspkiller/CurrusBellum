/*
 * Char.h
 *
 *  Created on: 1 nov. 2010
 *      Author: PsPKiller
 */

#ifndef CHAR_H_
#define CHAR_H_

#include <irrlicht.h>

using namespace irr;

class Char
{
public :
	Char(scene::ISceneManager*, video::IVideoDriver*, core::vector3df);
	scene::ISceneNode* getBody();
	scene::ISceneNode* getTour();
	bool collision();
	void setCollision(scene::ISceneNode*);
	void move(char);
	void turn(char);
	void turnTour(char);
	void turnTour(core::vector3df);
	void update();
private :
	scene::ISceneNode* Body;
	scene::ISceneNode* Tour;
	core::vector3df moving;
	scene::ISceneNode* Collision;
	bool collide;
	int lastSens;
	float speed;
};


#endif /* CHAR_H_ */
