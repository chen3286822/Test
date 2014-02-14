#ifndef __TOUCH_LAYER_H__
#define __TOUCH_LAYER_H__

#include "cocos2d.h"
USING_NS_CC;

class TouchLayer : public cocos2d::CCLayer
{
public:
	virtual bool init();
	virtual void onExit();

	virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
	virtual void ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent);

	CREATE_FUNC(TouchLayer);
};

#endif