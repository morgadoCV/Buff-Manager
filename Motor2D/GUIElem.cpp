#include "j1App.h"
#include "j1Input.h"
#include "j1Window.h"
#include "GUIElem.h"
#include "Log.h"
#include "j1Render.h"

GUIElem::GUIElem(fPoint localPos, j1Module* listener, SDL_Rect atlasRect, GUIElemType type, GUIElem* parent) : localPos(localPos), listener(listener), atlasRect(atlasRect), type(type), parent(parent)
{
	calculateScreenPos();
}

GUIElem::~GUIElem()
{
	DestroyChilds();
}

bool GUIElem::Update(float dt)
{
	return true;
}

bool GUIElem::MouseHover() const
{
	int x, y;
	App->input->GetMousePosition(x, y);
	uint scale = App->win->GetScale();

	bool result = false;

	//if collides
	if (!(x < screenPos.x ||
		x > screenPos.x + atlasRect.w ||
		y < screenPos.y ||
		y > screenPos.y + atlasRect.h))
	{
		result = true;
	}
	return result;
}

bool GUIElem::HandleInput()
{
	return true;
}

void GUIElem::DebugDraw() 
{

}

bool GUIElem::hasParent() const
{
	return parent != nullptr;
}

GUIElem* GUIElem::getParent() const
{
	return parent;
}

void GUIElem::addChild(GUIElem* child)
{
	childs.push_back(child);
}

bool GUIElem::UpdateChilds(float dt)
{
	bool result = true;

	if (childs.size() > 0)
	{
		std::list<GUIElem*>::iterator it;

		for (it = childs.begin(); it != childs.end() && result; ++it)
		{
			result = (*it)->Update(dt);
		}
	}

	return result;
}

bool GUIElem::DestroyChilds()
{
	if (childs.size() > 0)
	{
		std::list<GUIElem*>::iterator it;
		for (it = childs.begin(); it != childs.end(); ++it)
		{
			delete *it;
		}
		childs.clear();
	}
	return childs.size() <= 0;
}

fPoint GUIElem::calculateScreenPos()
{
	fPoint screenPos = { 0.0f, 0.0f };

	for (GUIElem* elem = this; elem != nullptr; elem = elem->parent)
	{
		screenPos += elem->localPos;
	}
	this->screenPos = screenPos;

	return screenPos;
}

void GUIElem::Move(fPoint dist)
{
	std::list<GUIElem*>::iterator it;
	for (it = childs.begin(); it != childs.end(); ++it)
	{
		(*it)->Move(dist);
	}
	this->localPos += dist;
	calculateScreenPos();
}