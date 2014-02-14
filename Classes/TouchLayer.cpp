#include "TouchLayer.h"
#include "HelloWorldScene.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <android/log.h>

#define  LOG_TAG    "main"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,LOG_TAG,__VA_ARGS__)
#else
#define  LOGD(...)
#endif

bool TouchLayer::init()
{
	bool bRet = false;
	do 
	{        
		CC_BREAK_IF(!CCLayer::init());
		LOGD("content width:%f height:%f",this->getContentSize().width,this->getContentSize().height);

		CCDirector* pDirector = CCDirector::sharedDirector();
		LOGD("win size width:%f height:%f",pDirector->getWinSize().width,pDirector->getWinSize().height);

		this->setTouchMode(kCCTouchesAllAtOnce);
		this->setTouchEnabled(true);
		// success
		bRet = true;
	} while(0);
	return bRet;
}

void TouchLayer::onExit()
{
	this->setTouchEnabled(false);
}

bool TouchLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLayer* layer = dynamic_cast<CCLayer*>(this->getParent()->getChildByTag(1));
	CCSprite* spr = dynamic_cast<CCSprite*>(layer->getChildByTag(2));

	CCPoint locationInNode = spr->convertToNodeSpace(pTouch->getLocation());
	CCSize s = spr->getContentSize();
	CCRect rect = CCRect(0, 0, s.width, s.height);

	if (rect.containsPoint(locationInNode))
	{
		spr->setOpacity(180);
		return true;
	}
	return false;
}

void TouchLayer::ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLayer* layer = dynamic_cast<CCLayer*>(this->getParent()->getChildByTag(1));
	CCSprite* spr = dynamic_cast<CCSprite*>(layer->getChildByTag(4));

	spr->setPosition(spr->getPosition()+pTouch->getDelta());
}

void TouchLayer::ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent)
{
	CCLayer* layer = dynamic_cast<CCLayer*>(this->getParent()->getChildByTag(1));
	CCSprite* spr = dynamic_cast<CCSprite*>(layer->getChildByTag(2));

	CCPoint locationInNode = spr->convertToNodeSpace(pTouch->getLocation());
	CCSize s = spr->getContentSize();
	CCRect rect = CCRect(0, 0, s.width, s.height);

	if (rect.containsPoint(locationInNode))
	{
		spr->setOpacity(255);
	}
}

void TouchLayer::ccTouchCancelled(CCTouch *pTouch, CCEvent *pEvent)
{

}


void TouchLayer::ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent)
{
	if (pTouches->count() == 1)
	{
		CCTouch* touch = dynamic_cast<CCTouch*>(pTouches->anyObject());
		CCLayer* layer = dynamic_cast<CCLayer*>(this->getParent()->getChildByTag(1));
		CCSprite* spr = dynamic_cast<CCSprite*>(layer->getChildByTag(2));

		CCPoint locationInNode = spr->convertToNodeSpace(touch->getLocation());
		CCSize s = spr->getContentSize();
		CCRect rect = CCRect(0, 0, s.width, s.height);

		if (rect.containsPoint(locationInNode))
		{
			spr->setOpacity(180);
		}
	}	
}

void TouchLayer::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
	if (pTouches->count() == 1)
	{
		CCLayer* layer = dynamic_cast<CCLayer*>(this->getParent()->getChildByTag(1));
		CCSprite* spr = dynamic_cast<CCSprite*>(layer->getChildByTag(4));

		CCTouch* touch = dynamic_cast<CCTouch*>(pTouches->anyObject());
		spr->setPosition(spr->getPosition()+touch->getDelta());
	}
	else if (pTouches->count() == 2)
	{
		CCLayer* layer = dynamic_cast<CCLayer*>(this->getParent()->getChildByTag(1));
		CCSprite* spr = dynamic_cast<CCSprite*>(layer->getChildByTag(2));

		CCTouch* touch = dynamic_cast<CCTouch*>(pTouches->anyObject());
		spr->setPosition(spr->getPosition()+touch->getDelta());
	}
	
}

void TouchLayer::ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent)
{
	if (pTouches->count() == 1)
	{
		CCLayer* layer = dynamic_cast<CCLayer*>(this->getParent()->getChildByTag(1));
		CCSprite* spr = dynamic_cast<CCSprite*>(layer->getChildByTag(2));

		CCTouch* touch = dynamic_cast<CCTouch*>(pTouches->anyObject());
		CCPoint locationInNode = spr->convertToNodeSpace(touch->getLocation());
		CCSize s = spr->getContentSize();
		CCRect rect = CCRect(0, 0, s.width, s.height);

		if (rect.containsPoint(locationInNode))
		{
			spr->setOpacity(255);
		}
	}
	
}

void TouchLayer::ccTouchesCancelled(CCSet *pTouches, CCEvent *pEvent)
{

}