﻿//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//!
//!	IRFAN FAHMI RAMADHAN
//!
//!	2016/11/19
//!	
//!	GameSystem.h
//!
//! Copyright ©2016 IrGame All Right Reserved
//!
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
#pragma once

#include "cocos2d.h"

class GameSystem : public cocos2d::Node
{
private:
	float _timer;
	float _hpBarScale;

	int _gameDuration;
	cocos2d::Label* _timeText;
	cocos2d::Sprite* _hpBarSpr;

public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	//static cocos2d::Scene* createScene();
	CREATE_FUNC(GameSystem);


	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	void setHPBarScale(float scale) { _hpBarSpr->setScaleX(scale); }
	float getHPBarScale() { return _hpBarScale; }

	void update(float dt)override;
};
