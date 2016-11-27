//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//!
//!	IRFAN FAHMI RAMADHAN
//!
//!	2016/11/21
//!	
//!	GameManager.h
//!
//! Copyright ©2016 IrGame All Right Reserved
//!
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
#pragma once
#include "cocos2d.h"
#include "Player.h"
#include "Bullet.h"
#include "GameSystem.h"
#include "Enemy.h"

const int MAX_FIRE = 5;
class GameManager : public cocos2d::Node
{
private:
	Player* _pPlayer;
	//Bullet* _pFire[MAX_FIRE];
	Enemy* _pEnemy;
	GameSystem* _pGameSystem;
	cocos2d::Camera* _pCamera;
	cocos2d::Size _visibleSize;

public:
	//static cocos2d::Scene* createScene();
	static GameManager* create();
	virtual bool init();
	void update(float dt)override;


};

