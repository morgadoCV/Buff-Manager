#ifndef __J1ENTITYFACTORY_H__
#define __J1ENTITYFACTORY_H__

#include "j1App.h"
#include "j1Module.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "SDL/include/SDL.h"

#include <list>
#include <queue>

#define MAX_ENEMIES 5

class Entity;

enum ENTITY_TYPES
{
	NO_TYPE,
	PLAYER,
	ENEMY
};

class j1EntityFactory : public j1Module {
private:

	std::list<Entity*> entities;

public:
	j1EntityFactory();
	virtual ~j1EntityFactory();

public:
	bool Awake();
	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool CleanUp();
	

	Entity* AddEntity(int x, int y, ENTITY_TYPES type);

};

class Entity {
public:

	Entity(int x, int y, ENTITY_TYPES type) {}
	virtual void Move(float dt) {};

public:
	iPoint pos;
	ENTITY_TYPES type;
	SDL_Rect rect;

};

#endif // !__ENTITIES_H__