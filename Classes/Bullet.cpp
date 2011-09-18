//
//  Bullet.cpp
//  Asteroids
//
//  Created by Clawoo on 9/18/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include "Bullet.h"

USING_NS_CC;

Bullet* Bullet::spriteWithFile(const char *pszFileName)
{
    Bullet *pobSprite = new Bullet();
    if (pobSprite && pobSprite->initWithFile(pszFileName))
    {
        pobSprite->scheduleUpdate();
        pobSprite->autorelease();
        return pobSprite;
    }
    CC_SAFE_DELETE(pobSprite);
	return NULL;
}

void Bullet::update(cocos2d::ccTime dt)
{
    this->setPosition(ccp(this->getPosition().x + velocity_.x, this->getPosition().y + velocity_.y));
    
    CCSize windowSize = CCDirector::sharedDirector()->getWinSize();
    
    if (this->getPosition().x < 0)
    {
        this->setPosition(ccp(windowSize.width, this->getPosition().y));
    }
    else if (this->getPosition().x > windowSize.width)
    {
        this->setPosition(ccp(0, this->getPosition().y));
    }
    
    if (this->getPosition().y < 0)
    {
        this->setPosition(ccp(this->getPosition().x, windowSize.height));
    }
    else if (this->getPosition().y > windowSize.height)
    {
        this->setPosition(ccp(this->getPosition().x, 0));
    }
}