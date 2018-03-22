#include "j1Player.h"
#include "j1Render.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Scene.h"
#include "j1Map.h"
#include "j1EntityFactory.h"

j1Player::j1Player() : j1Module()
{
	name.create("player");
}

j1Player::~j1Player()
{
}

bool j1Player::Awake()
{
	
	return true;
}

bool j1Player::Start()
{
	Attack = 5;
	Armor = 5;
	Health = 100;
	return true;
}

bool j1Player::PreUpdate()
{
	return true;
}

bool j1Player::Update(float dt)
{

	Movement();

	return true;
}


bool j1Player::CleanUp()
{
	
	return true;
}


bool j1Player::Movement()
{
	
	return true;
}
