 //16   // LoaderParams.h

#ifndef __LoaderParams__
#define __LoaderParams__
#include <string>
class LoaderParams{
public:
//    LoaderParams(int x, int y, int w, int h,std::string textureID){
//        m_x=x;
//        m_y=y;
//        m_w = w;
//        m_h = h;
//        m_textureID = textureID;
//    }
//
	LoaderParams(int x, int y, int w, int h, std::string textureID, int numFrames, int callbackID = 0, int animSpeed = 0) :
		m_x(x),
		m_y(y),
		m_w(w),
		m_h(h),
		m_numFrames(numFrames),
		m_textureID(textureID),
		m_callbackID(callbackID),
		m_animSpeed(animSpeed){

		}

    int getX() const {return m_x;}
    int getY() const { return m_y; }
    int getWidth() const { return m_w; }
    int getHeight() const { return m_h; }
    std::string getTextureID() const { return m_textureID; }
    int getNumFrames() const { return m_numFrames; }
	int getCallbackID() const { return m_callbackID; }

private:
    int m_x;
    int m_y;
    int m_w;
    int m_h;
    int m_numFrames;
	int m_callbackID;
	int m_animSpeed;
    std::string m_textureID;
};

#endif // __LoaderParams__
