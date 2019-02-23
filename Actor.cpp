#include "Actor.h"
#include "StudentWorld.h"
#include "GraphObject.h"
#include "GameConstants.h"

#include <list>
using namespace std;
// Students:  Add code to this file, Actor.h, StudentWorld.h, and StudentWorld.cpp



Actor::Actor(StudentWorld* sw, int imageID, double startX, double startY, Direction startDirection, double depth, bool canPass)
	:GraphObject(imageID, startX * SPRITE_WIDTH, startY * SPRITE_HEIGHT, startDirection, depth, 1), m_map(sw), m_alive(true), m_canPass(canPass)
{
}

Moveable::Moveable(StudentWorld* sw, int imageID, double startX, double startY, Direction startDirection, double depth)
	: Actor(sw, imageID, startX, startY, startDirection, depth, false), m_alive(true)
{}

Human::Human(StudentWorld* sw, int imageID, double startX, double startY, Direction startDirection, double depth)
	: Moveable(sw, imageID, startX, startY, startDirection, depth)
{}

////////////////////////////////////////////////////////////////////////////
// CITIZENS
////////////////////////////////////////////////////////////////////////////

Citizens::Citizens(StudentWorld* sw, double startX, double startY)
	:Human(sw, IID_CITIZEN, startX, startY, right, 0)
{

}

void Citizens::doSomething() //incomplete
{
	return;
}

////////////////////////////////////////////////////////////////////////////
// PENELOPE
////////////////////////////////////////////////////////////////////////////

Penelope::Penelope(StudentWorld* sw, double startX, double startY)
	:Human(sw, IID_PLAYER, startX, startY, right, 0),m_alive(true)
{




	m_numLandmines = 0;
	m_numGas = 0;
	m_numVaccines = 0;
	infected = false;
	countInfection = 0;
}



void Penelope::doSomething()
{
	int ch;
	if (getWorld()->getKey(ch))
	{
		// user hit a key during this tick!
		switch (ch)
		{
		case KEY_PRESS_LEFT:
			setDirection(left);
			if (getWorld()->ableToMoveHere(getX() - 4, getY(),this))
			{
				moveTo(getX() - 4, getY());
			}
			break;
		case KEY_PRESS_RIGHT:
			setDirection(right);
			if (getWorld()->ableToMoveHere(getX() + 4, getY(),this))
			{
				moveTo(getX() + 4, getY());
			}
			break;
		case KEY_PRESS_UP:
			setDirection(up);
			if (getWorld()->ableToMoveHere(getX(), getY() + 4,this))
				moveTo(getX(), getY() + 4);
			break;
		case KEY_PRESS_DOWN:
			setDirection(down);
			if (getWorld()->ableToMoveHere(getX(), getY() - 4, this))
				moveTo(getX(), getY() - 4);
			break;
		case KEY_PRESS_SPACE:
			//add flames in front of Penelope...;
			break;
			// etc…
		}
	}
}



/////////////////////////////////////////////////////////////////
// WALLS
////////////////////////////////////////////////////////////////

Walls::Walls(StudentWorld* sw, int startX, int startY)
	: Actor(sw, IID_WALL, startX, startY, right, 0, false)
{}

