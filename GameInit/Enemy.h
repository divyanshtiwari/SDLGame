 //14   // Enemy.h

#ifndef __Enemy__
#define __Enemy__
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "GameObjectFactory.h"

class Enemy : public SDLGameObject
{
public:

    Enemy();

    virtual void load(const LoaderParams *pParams);
    virtual void draw();
    virtual void update();

};

class EnemyCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Enemy();
	}
};
#endif // __Enemy__
