 //30   // GameGraphics.h

#ifndef __GameGraphics__
#define __GameGraphics__
#include "SDLGameObject.h"
#include "GameObjectFactory.h"

class GameGraphics:public SDLGameObject{
public:
    GameGraphics();

    virtual void draw();
    virtual void update();
    virtual void clean() {}
    virtual void load(const LoaderParams * pParams);

};

class GameGraphicsCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new GameGraphics();
	}
};


#endif // __GameGraphics__
