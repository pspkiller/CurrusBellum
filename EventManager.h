/*
 * EventManager.h
 *
 *  Created on: 1 nov. 2010
 *      Author: PsPKiller
 */

#ifndef EVENTMANAGER_H_
#define EVENTMANAGER_H_

#include <irrlicht.h>

using namespace irr;

class EventManager : public IEventReceiver
{
public:
	EventManager();
	// This is used to check whether a key is being held down
	virtual bool IsKeyDown(EKEY_CODE) const;
	// This is the one method that we have to implement
	virtual bool OnEvent(const SEvent&);
	int getMouseX();
	int getMouseY();
private :
	// We use this array to store the current state of each key
	bool KeyIsDown[KEY_KEY_CODES_COUNT];
	int mouseX;
	int mouseY;
};

#endif /* EVENTMANAGER_H_ */
