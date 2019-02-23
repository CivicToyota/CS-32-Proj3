#include "StudentWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <iostream>

#include "Level.h"
using namespace std;

GameWorld* createStudentWorld(string assetPath)
{
	return new StudentWorld(assetPath);
}

// Students:  Add code to this file, StudentWorld.h, Actor.h and Actor.cpp

StudentWorld::StudentWorld(string assetPath)
	: GameWorld(assetPath),m_level(1)
{
}

int StudentWorld::init()
{
	Level lev(assetPath());
	int numLevel = getLevel();
	ostringstream oss;
	oss.fill('0');
	oss << setw(2) << numLevel;
	string s = oss.str();

	string levelFile = "level" + s + ".txt";
	Level::LoadResult result = lev.loadLevel(levelFile);
	if (result == Level::load_fail_file_not_found)
		cerr << "Cannot find " << levelFile << "data file" << endl;
	else if (result == Level::load_fail_bad_format)
		cerr << "Your level was improperly formatted" << endl;
	else if (result == Level::load_success)
	{
		//cerr << "Successfully loaded level" << endl;

		for (int x = 0; x < VIEW_WIDTH; x++) {
			for (int y = 0; y < VIEW_HEIGHT; y++)
			{
				Level::MazeEntry ge = lev.getContentsOf(x, y); // level_x=5, level_y=10
				switch (ge) // so x=80 and y=160
				{
				case Level::empty:
					break;
				case Level::smart_zombie:
					//cout << "Location 80,160 starts with a smart zombie" << endl;
					break;
				case Level::dumb_zombie:
					//cout << "Location 80,160 starts with a dumb zombie" << endl;
					break;
				case Level::player:
					actor.push_back(new Penelope(this, x, y));
					break;
				case Level::exit:
					//cout << "Location 80,160 is where an exit is" << endl;
					break;
				case Level::wall:
					actor.push_back(new Walls(this, x, y));
					break;
				case Level::pit:
					//cout << "Location 80,160 has a pit in the ground" << endl;
					break;
				default:;
				}
			}
		}

	}

	return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
	for (std::vector<Actor*>::iterator it = actor.begin(); it != actor.end();it++)
	{
		(*it)->doSomething();
	}
	return GWSTATUS_CONTINUE_GAME;
}

void StudentWorld::cleanUp()
{
	for (std::vector<Actor*>::iterator it = actor.begin(); it != actor.end();it++)
	{
		delete *it;
	}
	actor.clear();
}


bool StudentWorld::ableToMoveHere(int x, int y, Actor* actPTR) {
	if (x < 0 || x >= VIEW_WIDTH || y < 0 || y >= VIEW_HEIGHT)
		return false;

	for (auto it = actor.begin(); it != actor.end(); it++)
	{
		if (actPTR != *it)
		{
			if (abs((*it)->getX() - x) < 16 && abs((*it)->getY() - y) < 16)
			{
				return false;
			}
		}
	}
	
	return true;
}