#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer,1,1);

    // return the scene
    return scene;
}

void HelloWorld::onExit()
{

}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

	CCMenuItem *pInputItem = CCMenuItemFont::create("change text",this,menu_selector(HelloWorld::menuInputCallback));
	pInputItem->setPosition(ccp(origin.x + (visibleSize.width)/2,origin.y + (visibleSize.height)/2+100));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem,pInputItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0,2);
    
    CCSprite* pThings = CCSprite::create("things.png");
    pThings->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pThings, 0,4);

	CCTextFieldTTF* text = CCTextFieldTTF::textFieldWithPlaceHolder("Input Your Name...", "Arial", 20);
	text->setPosition(ccp(origin.x + (visibleSize.width)/2,origin.y + (visibleSize.height)/2+50));
	this->addChild(text,0,6);
	HelloWorldTextFieldDelegate* textDelegate = new HelloWorldTextFieldDelegate;
	textDelegate->m_pLayer = this;
	textDelegate->autorelease();
	this->addChild(textDelegate);
	text->setDelegate(textDelegate);
	//text->attachWithIME();
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

void HelloWorld::menuInputCallback(CCObject* pSender)
{
	CCTextFieldTTF* text = dynamic_cast<CCTextFieldTTF*>(this->getChildByTag(6));
	text->attachWithIME();
}

bool HelloWorldTextFieldDelegate::onTextFieldAttachWithIME(CCTextFieldTTF *sender)
{
	if(m_pLayer)
		m_pLayer->setPosition(ccp(0,100));
	return false;
}

bool HelloWorldTextFieldDelegate::onTextFieldDetachWithIME(CCTextFieldTTF *sender)
{
	if(m_pLayer)
		m_pLayer->setPosition(ccp(0,0));
	return false;
}