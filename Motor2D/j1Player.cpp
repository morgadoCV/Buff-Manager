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
	position.x = 100;
	position.y = 100;
	player_rect.h = 32;
	player_rect.w = 20;

	speed.x = 2;
	speed.y = 2;


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
	//TODO 4 Remember to delete the new Tasks
	return true;
}


bool j1Player::Movement()
{
	//TODO 4 Add the task to the queque 
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_DOWN)
	{

	}
	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_DOWN)
	{

	}
	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_DOWN)
	{

	}
	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
	{

	}

	if (App->input->GetKey(SDL_SCANCODE_E) == KEY_DOWN)
	{
		//TODO 5 Exchange task so when you press A it goes to the right an so  
		

	}

	if (App->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN)
	{
		//TODO 6 Change the actor of the action
		
	}
	return true;
}
