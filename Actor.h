#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp


class StudentWorld;

class Actor : public GraphObject
{
public:
	Actor(StudentWorld* sw, int imageID, double startX, double startY, Direction startDirection, double depth, bool m_canPass);
	virtual void doSomething() {
		return;
	};
	virtual ~Actor() {}
	StudentWorld* getWorld() { return m_map; }

	bool isAlive() const
	{
		return m_alive;
	}

	bool canBurn() const
	{
		return m_canBurn;
	}

	bool canInfected() const {
		return m_can_be_infected;
	}

	bool canPass() const {
		return m_canPass;
	}
	bool canBlock() const {
		return m_blocks;
	}

private:
	StudentWorld* m_map;
	
	bool m_alive;
	bool m_canBurn;
	bool m_can_be_infected;
	bool m_canPass;
	bool m_blocks;

};

class Moveable : public Actor
{
public:
	Moveable(StudentWorld* sw, int imageID, double startX, double startY, Direction startDirection, double depth);
	virtual ~Moveable() {}
private:
	bool m_alive;
};
//
//class Zombie : public Moveable
//{
//
//};
//
//class SmartZombie : public Zombie //smart zombie
//{
//
//};
//
//class DumbZombie : public Zombie //dumb zombie
//{
//
//};

class Human : public Moveable
{
public:
	Human(StudentWorld* sw, int imageID, double startX, double startY, Direction startDirection, double depth);
};

class Citizens : public Human  //citizens
{
public:
	Citizens(StudentWorld*sw, double startX, double startY);
	virtual ~Citizens() {}
	virtual void doSomething();
};

class Penelope : public Human //Penelope
{
public:
	Penelope(StudentWorld* sw, double startX, double startY);
	virtual ~Penelope() {}
	virtual void doSomething();

private:

	bool m_alive;

	int m_numLandmines;
	int m_numGas;
	int m_numVaccines;
	bool infected;
	int countInfection;

};





class Walls : public Actor  //walls
{
public:
	Walls(StudentWorld* sw, int startX, int startY);
	virtual ~Walls() {}


};

//class Pits : public Actor  //pits
//{
//
//};
//
//class Landmines : public Actor //landmines
//{
//
//};
//
//class Exits : public Actor	//exits
//{
//
//};
//
//
//
//
//
//
//class Goodie : public Actor
//{
//
//};
//
//class VaccineGoodie : public Goodie	//vaccine goodie
//{
//
//};
//
//class GasCanGoodie : public Goodie	//gas goodie
//{
//
//};
//
//class LandmineGoodie : public Goodie	//landmine goodie
//{
//
//};
//
//
//
//
//
//
//
//
//class Projectile : public Actor
//{
//public:
//
//};
//
//class Flames : public Projectile  //flames
//{
//
//};
//
//class Vomit : public Projectile  //vomit
//{
//
//};


#endif // ACTOR_H_