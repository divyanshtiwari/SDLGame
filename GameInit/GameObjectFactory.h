#ifndef __GameObjectFactory__
#define __GameObjectFactory__

#include <string>
#include <map>
#include "GameObject.h"
#include <iostream>

class BaseCreator
{
public:
	virtual GameObject* createGameObject() const = 0;
	virtual ~BaseCreator() {}
};

class GameObjectFactory
{
	std::map<std::string, BaseCreator*> m_creators;

	GameObjectFactory(){}
	~GameObjectFactory(){}

	static GameObjectFactory* s_pInstance;

public:

	static GameObjectFactory* Instance()
	{
		if (s_pInstance == nullptr)
		{
			s_pInstance = new GameObjectFactory();
			return s_pInstance;
		}
		return s_pInstance;
	}

	bool registerType(std::string typeID, BaseCreator* pCreator);

	GameObject* create(std::string typeID);
};

typedef GameObjectFactory TheGameObjectFactory;

#endif //defined!(__GameObjectFactory__)
