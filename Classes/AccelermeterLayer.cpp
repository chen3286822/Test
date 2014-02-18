#include "AccelermeterLayer.h"
#include "Unity.h"
#include "HelloWorldScene.h"

#define FIX_POS(_pos, _min, _max) \
	if (_pos < _min)        \
	_pos = _min;        \
else if (_pos > _max)   \
	_pos = _max;        \

void AccelermeterLayer::onEnter()
{
	CCLayer::onEnter();

	this->setAccelerometerEnabled(true);
}

void AccelermeterLayer::onExit()
{
	this->setAccelerometerEnabled(false);
}

void AccelermeterLayer::didAccelerate(CCAcceleration* pAccelerationValue)
{
	CCDirector* dir = CCDirector::sharedDirector();
	CCLayer* layer = dynamic_cast<CCLayer*>(this->getParent()->getChildByTag(1));
	CCSprite* spr = dynamic_cast<CCSprite*>(layer->getChildByTag(2));
	CCSize ballSize  = spr->getContentSize();

	CCPoint ptNow  = spr->getPosition();
	CCPoint ptTemp = dir->convertToUI(ptNow);

	ptTemp.x += pAccelerationValue->x * 9.81f;
	ptTemp.y -= pAccelerationValue->y * 9.81f;

	CCPoint ptNext = dir->convertToGL(ptTemp);
	CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
	CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	FIX_POS(ptNext.x, (origin.x+ballSize.width / 2.0), (origin.x + visibleSize.width - ballSize.width / 2.0));
	FIX_POS(ptNext.y, (origin.y+ballSize.height / 2.0), (origin.y + visibleSize.height - ballSize.height / 2.0));
	spr->setPosition(ptNext);

} 