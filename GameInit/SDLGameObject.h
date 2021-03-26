 //6   // SDLGameObject.h

#ifndef __SDLGameObject__
#define __SDLGameObject__
#include "LoaderParams.h"
#include "GameObject.h"
#include "Vector2D.h"


class SDLGameObject : public GameObject {
public:
    SDLGameObject();

    virtual void draw(std::string id="PLAY");
    virtual void update(){
        m_position += m_velocity;
        m_velocity += m_acceleration;
        //SDL_Delay(20);
    };
    virtual void clean(){}

    virtual Vector2D& getPositon() {return m_position;}
    int getWidth() {return m_w;}
    int getHeight() {return m_h;}

	virtual void load(const LoaderParams* pParams);

protected:
    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;
    int m_w;
    int m_h;
    int m_currentRow;
    int m_currentFrame;
    std::string m_textureID;
	int m_numFrames;
	int m_callbackID;



};
#endif // __SDLGameObject__
