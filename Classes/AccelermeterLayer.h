#ifndef __ACCELERMETER_H__
#define __ACCELERMETER_H__

#include "cocos2d.h"
USING_NS_CC;


class AccelermeterLayer : public CCLayer
{
public:
	virtual void onEnter();
	virtual void onExit();

	virtual void didAccelerate(CCAcceleration* pAccelerationValue);

	CREATE_FUNC(AccelermeterLayer);
};

#endif