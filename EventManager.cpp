/*
 * EventManager.cpp
 *
 *  Created on: 1 nov. 2010
 *      Author: PsPKiller
 */

#include "EventManager.h"

EventManager::EventManager()
{
	for (u32 i=0; i<KEY_KEY_CODES_COUNT; ++i)
		KeyIsDown[i] = false;
}

bool EventManager::IsKeyDown(EKEY_CODE keyCode) const
{
	return KeyIsDown[keyCode];
}

bool EventManager::OnEvent(const SEvent& event)
{
	// Remember whether each key is down or up
	if (event.EventType == EET_KEY_INPUT_EVENT)
		KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
	else if(event.EventType == EET_MOUSE_INPUT_EVENT)
	{
		mouseX = event.MouseInput.X;
		mouseY = event.MouseInput.Y;
	}
	return false;
}

int EventManager::getMouseX()
{
	return mouseX;
}

int EventManager::getMouseY()
{
	return mouseY;
}
