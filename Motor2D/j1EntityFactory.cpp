#include "j1EntityFactory.h"
#include "j1Render.h"
#include "p2Log.h"


j1EntityFactory::j1EntityFactory() : j1Module()
{
	name.create("entity");
}

j1EntityFactory::~j1EntityFactory()
{
}

bool j1EntityFactory::Awake()
{

	return true;
}

bool j1EntityFactory::Start()
{

	return true;
}

bool j1EntityFactory::PreUpdate() 
{
	return true;
}


bool j1EntityFactory::Update(float dt)
{
	std::list<Entity*>::iterator iterator = entities.begin();

	for (iterator; iterator != entities.end(); iterator++)
	{

	}



	return true;
}

bool j1EntityFactory::CleanUp()
{
	for (std::list<Entity*>::iterator iterator = entities.begin(); iterator == entities.end(); iterator++)
	{
		delete *iterator;
	}
	entities.clear();
	return true;
}

Entity* j1EntityFactory::AddEntity(int pos_x, int pos_y, ENTITY_TYPES type)
{
	Entity* ent = nullptr;

	ent = new Entity(pos_x, pos_y, type);

	ent->type = type;
	ent->pos = { pos_x, pos_y };

	ent->rect = { pos_x, pos_y, 20, 32 };

	entities.push_back(ent);

	return ent;
}


