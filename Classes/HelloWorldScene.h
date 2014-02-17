#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorldTextFieldDelegate : public cocos2d::CCLayer,public cocos2d::CCTextFieldDelegate
{
public:
	bool onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF *sender);
	bool onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF *sender);
	cocos2d::CCLayer* m_pLayer;
};

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	virtual void onExit();

    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
	void menuInputCallback(CCObject* pSender);
    
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
