#include "j1GUI.h"
#include "j1App.h"
#include "Fonts.h"
#include "j1Textures.h"

#include "GUIElem.h"
#include "GUILabel.h"


j1GUI::j1GUI() : j1Module()
{
	name = "GUI";
}

j1GUI::~j1GUI() {}

bool j1GUI::Awake(pugi::xml_node& guiNode)
{
	return true;
}

bool j1GUI::Start()
{
	atlas = App->tex->Load("GUI/atlas.png");
	return true;
}

bool j1GUI::PreUpdate()
{
	if (elementsToSpawn.size() > 0)
	{
		std::list<GUIElem*>::iterator it;
		for (it = elementsToSpawn.begin(); it != elementsToSpawn.end(); ++it)
		{
			if ((*it)->hasParent())
				(*it)->getParent()->addChild(*it);
			else
				GUIElemList.push_back(*it);
		}
		elementsToSpawn.clear();
	}
	return elementsToSpawn.size() <= 0;
}

bool j1GUI::Update(float dt)
{
	bool result = true;

	std::list<GUIElem*>::iterator it;
	for (it = GUIElemList.begin(); it != GUIElemList.end() && result; ++it)
	{
		result = (*it)->Update(dt);
	}

	return result;
}

bool j1GUI::PostUpdate()
{
	if (elementsToKill.size() > 0)
	{
		std::list<GUIElem*>::iterator it;
		for (it = elementsToKill.begin(); it != elementsToKill.end(); ++it)
		{
			GUIElemList.remove(*it);
		}
		elementsToKill.clear();
	}
	return elementsToKill.size() <= 0;
}

bool j1GUI::CleanUp()
{
	std::list<GUIElem*>::reverse_iterator it;
	for (it = GUIElemList.rbegin(); it != GUIElemList.rend(); ++it)
	{
		delete (*it);
	}
	GUIElemList.clear();

	return GUIElemList.size() <= 0;
}

//----------------------------------------------------------------------------------------------------//

bool j1GUI::DestroyElem(GUIElem* element)
{
	elementsToKill.push_back(element);
	return true;
}

GUIElem* j1GUI::CreateLabel(fPoint position, LabelInfo& info, GUIElem* parent, j1Module* listener)
{
	Label* label = new Label(position, info, parent, listener);

	elementsToSpawn.push_back((GUIElem*)label);

	return label;
}


SDL_Texture* j1GUI::getAtlas() const
{
	return atlas;
}