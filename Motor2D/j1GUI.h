#ifndef __MODULEGUI_H__
#define __MODULEGUI_H__

#include "j1Module.h"
#include <list>
#include <map>
#include "p2Point.h"
#include "SDL/include/SDL.h"
#include "Fonts.h"

class LabelInfo;
class GUIElem;
enum class BType;


class j1GUI : public j1Module
{
public:

	j1GUI();
	virtual ~j1GUI();

	bool Awake(pugi::xml_node&);
	bool Start();
	bool PreUpdate();
	bool Update(float dt);
	bool PostUpdate();
	bool CleanUp();

public:
	GUIElem * CreateLabel(fPoint position, LabelInfo& info, GUIElem* parent = nullptr, j1Module* listener = nullptr);

	bool DestroyElem(GUIElem* element);
	SDL_Texture* getAtlas() const;

public:
	std::list<GUIElem*> GUIElemList;
	std::list<GUIElem*> elementsToSpawn;
	std::list<GUIElem*> elementsToKill;

private:
	SDL_Texture * atlas = nullptr;
};




#endif