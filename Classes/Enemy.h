//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//!
//!	IRFAN FAHMI RAMADHAN
//!
//!	2016/11/23
//!	
//!	Enemy.h
//!
//! Copyright ©2016 IrGame All Right Reserved
//!
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
#pragma once
//--------------------------
#include "cocos2d.h"
#include "Bullet.h"
#include "Player.h"
#include <iostream>

const int MAX_SHOT = 3;
//---------------------------------------
class Enemy : public cocos2d::Node
{
private:
	cocos2d::Sprite* _pEnemySpr;		//敵のスプライト
	cocos2d::Node* _pTargetNode;		//ターゲット
	cocos2d::Vec2 _dir;
	Bullet* _pBullets[MAX_SHOT];		//弾
	//std::vector<Bullet*>_pBullets;
	Player* _pPlayerTarget;
	float _speed;

	float _shootDelay;

public:
	static Enemy* create();
	virtual bool init();
	void update(float dt)override;
	cocos2d::Rect getEnemyBoundingBox() { return _pEnemySpr->getBoundingBox(); }
	Node* getNode() { return _pTargetNode; }
	void move(float speed);
	void setBulletTarget(Player* player) { _pPlayerTarget = player; }
	Bullet* getBullet();
	//Sprite* getEnemySpr() { return _pEnemySpr; }
	//void movement(float &speed);
};
//---------------------------------------

