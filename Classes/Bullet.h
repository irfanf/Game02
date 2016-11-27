//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//!
//!	IRFAN FAHMI RAMADHAN
//!
//!	2016/11/15
//!	
//!	Bullet.h
//!
//! Copyright ©2016 IrGame All Right Reserved
//!
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
#pragma once
//---------------------
#include "cocos2d.h"
#include "Player.h"
//---------------------

class Bullet : public cocos2d::Node
{
private:

	cocos2d::Vec2 _dir;							//方向
	cocos2d::ParticleSystemQuad* _pFirePar;		//パーティクル（火）
	Player* _player;

public:
	static Bullet* create();
	void setTarget(Player* player) { _player = player; }
	void update(float dt)override;
	virtual bool init();
};

