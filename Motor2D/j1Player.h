#ifndef _J1PLAYER_H__
#define _J1PLAYER_H__

#include "j1Module.h"
#include "p2Point.h"
#include "SDL/include/SDL.h"

#include <queue>

class Task;
class Entity;

class j1Player : public j1Module
{
public:
	j1Player();
	virtual ~j1Player();

	bool Awake();

	bool Start();

	bool PreUpdate();

	bool Update(float dt);

	bool Movement();

	bool CleanUp();

public:
	int Armor;
	int Health;
	int Attack;
	Entity* Player = nullptr;
	Entity* Enemy = nullptr;
	Entity* Actor = nullptr;

private:

};



#endif // !_J1PLAYER_H__

