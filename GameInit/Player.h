 //11   // Player.h

#ifndef __Player__
#define __Player__
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "GameObjectFactory.h"

class Player: public SDLGameObject{
public:
    Player();

    virtual void draw();
    virtual void update();
    virtual void clean() { }
    virtual void load(const LoaderParams * pParams);

private:
    void handleInput();

};

class PlayerCreator : public BaseCreator
{
	GameObject* createGameObject() const
	{
		return new Player();
	}
};

#endif // __Player__
