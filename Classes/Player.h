//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//!
//!	IRFAN FAHMI RAMADHAN
//!
//!	2016/11/15
//!	
//!	Player.h
//!
//! Copyright ©2016 IrGame All Right Reserved
//!
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
#pragma once
//--------------------------
#include "cocos2d.h"
#include "Shield.h"
#include "VirtualGamepad\VirtualGamepad.h"
//--------------------------

enum MY_KEY_CODE
{
	W,
	A,
	S,
	D
};
const int MAX_HP = 100;
//---------------------------------------
class Player : public cocos2d::Node
{
private:
	VirtualGamepad* _padPlayer;
	VirtualGamepad* _padShield;
	cocos2d::Sprite* _playerSpr;
	//cocos2d::ParticleSystemQuad* _shieldPar;
	//cocos2d::Sprite* _shieldSpr;
	//cocos2d::Rect _sprBoundingBox;

	Shield* _pShield;
	//Shield* _pShield2;
	//cocos2d::Camera* _pCamera;

	float _rad;
	bool _isMove;
	int _key;
	bool _isKeyOn;
	int _hp;

public:
	static Player* create();
	virtual bool init();
	void setHP(int hp) { _hp = hp; }
	int getHP() { return _hp; }
	void move(float x,float y);
	void update(float dt)override;
	void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);
	cocos2d::Rect getPlayerBoundingBox() { return _playerSpr->getBoundingBox(); }
	//cocos2d::Rect getShieldBoundingBox() { return _pShield1->getBoundingBox(); }
	Shield* getShield() { return _pShield; }
	//cocos2d::Sprite* getPlayerSpr() { return _playerSpr; }
	void rotate(cocos2d::Ref* pSender);
};
//---------------------------------------

