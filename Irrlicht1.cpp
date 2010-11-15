/** Example 007 Collision

We will describe 2 methods: Automatic collision detection for moving through
3d worlds with stair climbing and sliding, and manual scene node and triangle
picking using a ray.  In this case, we will use a ray coming out from the
camera, but you can use any ray.

To start, we take the program from tutorial 2, which loads and displays a
quake 3 level. We will use the level to walk in it and to pick triangles from.
In addition we'll place 3 animated models into it for triangle picking. The
following code starts up the engine and loads the level, as per tutorial 2.
*/
#include <irrlicht.h>
#include "driverChoice.h"

#include "Char.h"
#include "Arene.h"
#include "EventManager.h"
#include "CollisionManager.h"
#include "Missile.h"
#include "Timer.h"

using namespace irr;

#ifdef _MSC_VER
#pragma comment(lib, "Irrlicht.lib")
#endif
/*
enum
{
	// I use this ISceneNode ID to indicate a scene node that is
	// not pickable by getSceneNodeAndCollisionPointFromRay()
	ID_IsNotPickable = 0,

	// I use this flag in ISceneNode IDs to indicate that the
	// scene node can be picked by ray selection.
	IDFlag_IsPickable = 1 << 0,

	// I use this flag in ISceneNode IDs to indicate that the
	// scene node can be highlighted.  In this example, the
	// homonids can be highlighted, but the level mesh can't.
	IDFlag_IsHighlightable = 1 << 1
};*/

int main()
{
	// ask user for driver
	video::E_DRIVER_TYPE driverType=driverChoiceConsole();
	if (driverType==video::EDT_COUNT)
		return 1;

	EventManager events;

	// create device
	IrrlichtDevice *device = createDevice(driverType, core::dimension2d<u32>(1024, 768), 32, false, false, false, &events);
	if (device == 0)
		return 1; // could not create selected driver.

	video::IVideoDriver* driver = device->getVideoDriver();
	scene::ISceneManager* smgr = device->getSceneManager();
	scene::ICameraSceneNode* camera = smgr->addCameraSceneNode(0, core::vector3df(40,100,-35), core::vector3df(40,30,10), 0, true);

	//scene::ICameraSceneNode* camera = smgr->addCameraSceneNodeFPS(0, 100.0f, .3f, ID_IsNotPickable, 0, 0, true, 3.f);
	//camera->setPosition(core::vector3df(50,70,-20));
	//camera->setTarget(core::vector3df(50,30,0));
	//device->getCursorControl()->setVisible(true);

	Char panzer(smgr, driver, core::vector3df(5,5,5));
	Arene arena(smgr, driver);

	//std::cout<<"init collision"<<std::endl;
	CollisionManager collisionManager(smgr, camera, &arena);
	MissileManager missileManager(smgr);

	int lastFPS = -1;
	f32 timeloop;
	f32 timeStack = 0;
	f32 last = device->getTimer()->getRealTime();
	while(device->run())
	{
		//std::cout<<"boucle"<<std::endl;
		f32 now = device->getTimer()->getRealTime();
		timeloop = now - last;
		timeStack += timeloop;
		last = now;
		if(timeStack >= 10)
		{
			timeStack = 0;
			panzer.turnTour(collisionManager.getMousetoGroundCollision(events.getMouseX(), events.getMouseY()));
			panzer.setCollision(collisionManager.setCollisionTankFromWalls(&panzer));
			if(events.IsKeyDown(KEY_KEY_Q))
				panzer.turn('l');
			else if(events.IsKeyDown(KEY_KEY_D))
				panzer.turn('r');

			if(events.IsKeyDown(KEY_KEY_Z))
				panzer.move('u');
			else if(events.IsKeyDown(KEY_KEY_S))
				panzer.move('d');
			else
				panzer.move('s');

			if(events.IsKeyDown(KEY_KEY_A))
				panzer.turnTour('l');
			else if(events.IsKeyDown(KEY_KEY_E))
				panzer.turnTour('r');

			if(events.IsKeyDown(KEY_SPACE))
				missileManager.addMissile(panzer.getTour()->getPosition(), panzer.getTour()->getRotation());

			panzer.update();
			missileManager.updateMissiles();
			collisionManager.setCollisionMissileFromWalls(&missileManager);
			missileManager.deleteMissiles(collisionManager.getCollidedMissile());
		}

		if (device->isWindowActive())
		{
			driver->beginScene(true, true, 0);
			smgr->drawAll();

			// We're all done drawing, so end the scene.
			driver->endScene();

			int fps = driver->getFPS();

			if (lastFPS != fps)
			{
				core::stringw str = L"TANKS - Irrlicht Engine [";
				str += driver->getName();
				str += "] FPS : ";
				str += fps;
				str += " TimeLoop : ";
				str += (double)timeloop;
				device->setWindowCaption(str.c_str());
				lastFPS = fps;
			}
			//std::cout<<"fin boucle"<<std::endl;
		}
	}
	std::cout<<"stop";
	device->drop();

	return 0;
}

/*
**/
