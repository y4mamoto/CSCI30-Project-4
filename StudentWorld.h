#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "GameController.h"
#include <string>
#include "Actor.h"
#include <vector>
#include <cmath>

using namespace std;

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
	// Generate the level
	StudentWorld(std::string assetDir) : GameWorld(assetDir) {}

	virtual ~StudentWorld() {}
	virtual int init();

	virtual int move();

	virtual void cleanUp();

	virtual void removeIce(int x, int y);

	virtual bool nearIcemanCheck(int x, int y, int radius);

	virtual void deleteDeadActor();

	virtual void addActor(Actor *a);

	virtual bool spawnRangeCheck(int x, int y, int radius);

	virtual void setDisplayText();

	virtual void pickupBarrel();

	virtual int barrelLeft();

	virtual void goldDrop(int x, int y);

	virtual void revealAllNearbyObjects(int x, int y, int radius);

	virtual void giveIcemanGold();

	virtual void giveIceManSonar();

	virtual void giveIceManWater();

	virtual bool noIceCheck(int x, int y);

	virtual bool boulderCheck(int x, int y, GraphObject::Direction dir);

	virtual bool IceCheck(int x, int y, GraphObject::Direction dir);

	virtual bool inRangeCheck(int value, int target, int range);

	virtual void generateSquirt(int x, int y, GraphObject::Direction dir);

	virtual void decrementSpawnTicks();

	virtual void boulderDamage(int x, int y);

	virtual GraphObject::Direction newDirection(int x, int y);

	virtual string statsFormat(int Level, int lives, int health, int water, int gold, int BarrelisLeft, int Sonar, int Score);

private:
	Ice *iceObject[64][64];
	Iceman *iceManObject;
	vector<Actor *> Actors;
	int num_barrel;
	int barrelPickedUp;
	BarrelOfOil *barrelObject[21];
	int num_gold;
	Gold *goldObject[5];
	int num_boulders;
	Boulder *boulderObject[9];
	Squirt *squirtObject;
	int num_protester;
	int max_protester;
	int protester_ticks;
	Protester *protesterObject[15];
};

#endif // STUDENTWORLD_H_
