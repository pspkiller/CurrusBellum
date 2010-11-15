/*
 * Char.cpp
 *
 *  Created on: 1 nov. 2010
 *      Author: PsPKiller
 */

#include "Char.h"

Char::Char(scene::ISceneManager* smgr, video::IVideoDriver* driver, core::vector3df posBody)
{
	speed = 0;
	lastSens = 1;
	moving = core::vector3df(0,0,0);
	Collision = 0;

	Body = smgr->addMeshSceneNode(smgr->getMesh("D:/Travail/Programmation/media/Meshs/tank_body.3ds"));
	if (Body)
	{
		Body->setPosition(posBody);
		//Body->setScale(core::vector3df(0.7,0.3f,1.5f));
		//Body->setMaterialTexture(0, driver->getTexture("D:/Travail/Programmation/media/Textures/char_body.png"));
		Body->setMaterialFlag(video::EMF_WIREFRAME, false);
	}

	Tour = smgr->addMeshSceneNode(smgr->getMesh("D:/Travail/Programmation/media/Meshs/tank_tour.3ds"));
	if (Tour)
	{
		Tour->setPosition(Body->getPosition()+core::vector3df(0,3,0));
		//Tour->setScale(core::vector3df(0.4f,0.2f,0.8f));
		Tour->setMaterialTexture(0, driver->getTexture("D:/Travail/Programmation/media/Textures/char_tour.png"));
		Tour->setMaterialFlag(video::EMF_WIREFRAME, false);
	}
}

scene::ISceneNode* Char::getBody()
{
	return Body;
}

scene::ISceneNode* Char::getTour()
{
	return Tour;
}

bool Char::collision()
{
	if(Collision)
		return true;
	else
		return false;
}

void Char::setCollision(scene::ISceneNode* anim)
{
	Collision = anim;
}

void Char::move(char sens)
{
	if(!collide)
	{
		switch(sens)
		{
		case 'u' :
			lastSens = 1;
			if(speed < 0.4)
				speed += 0.04;
			// direction à prendre en fonction de l'angle du tank
			moving = Body->getRotation().rotationToDirection();
			moving.Z *= speed;
			moving.X *= speed;
			break;
		case 'd' :
			lastSens = -1;
			if(speed < 0.4)
				speed += 0.04;
			moving = Body->getRotation().rotationToDirection();
			moving.Z *= speed;
			moving.X *= speed;
			break;
		case 's' :
			if(speed > 0)
				speed -= 0.01;
			break;
		default : break;
		}
	}
}

void Char::turn(char sens)
{
	if(!collide)
	{
		switch(sens)
		{
		case 'r' :
			Body->setRotation(Body->getRotation()+core::vector3df(0,2,0));
			break;
		case 'l' :
			Body->setRotation(Body->getRotation()-core::vector3df(0,2,0));
			break;
		default : break;
		}
	}
}

void Char::turnTour(char sens)
{
	switch(sens)
	{
	case 'r' :
		Tour->setRotation(Tour->getRotation()+core::vector3df(0,2,0));
		break;
	case 'l' :
		Tour->setRotation(Tour->getRotation()-core::vector3df(0,2,0));
		break;
	default : break;
	}
}

void Char::turnTour(core::vector3df target)
{
	if(target.X != 0 && target.Z != 0)
	{
		float x=target.X;
		float z=target.Z;
		float xdiff=Tour->getPosition().X-x;
		float zdiff=Tour->getPosition().Z-z;
		float yaw=atan2(xdiff,zdiff);
		Tour->setRotation(core::vector3df(0,(yaw*180/3.14f),0));
	}
}

void Char::update()
{
	if(Collision)
	{
		collide = true;
		moving = Body->getPosition() - Collision->getPosition();
		moving = moving.normalize();
		speed = 1;
		lastSens = 1;
	}
	else if(collide)
	{
		if(speed <= 0.2)
			collide = false;
		else
			speed -= 0.05;
	}
	else if(speed >= 0)
	{
		moving = Body->getRotation().rotationToDirection();
	}
	moving.X *= speed;
	moving.Y = 0;
	moving.Z *= speed;
	Body->setPosition(Body->getPosition() + lastSens*moving);
	Tour->setPosition(Body->getPosition()+core::vector3df(0,3,0));
}
