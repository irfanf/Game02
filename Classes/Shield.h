//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//!
//!	IRFAN FAHMI RAMADHAN
//!
//!	2016/11/17
//!	
//!	Shield.h
//!
//! Copyright ©2016 IrGame All Right Reserved
//!
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
#pragma once
//-------------------------------------------------
#include "cocos2d.h"
//-------------------------------------------------
class Shield : public cocos2d::Node
{
private:
	cocos2d::Sprite* _pShieldSpr2;		//スプライト2の宣言
	cocos2d::Sprite* _pShieldSpr1;		//スプライト1の宣言
	
	float _rad1;						//ラジアン1の宣言
	float _rad2;						//ラジアン2の宣言


public:
	static Shield* create();			
	virtual bool init();
	void update(float dt)override;		
	void rotate(float &rad,cocos2d::Sprite* target);
	cocos2d::Rect getShield1BoundingBox() { return _pShieldSpr1->getBoundingBox(); }	//Spirte1のboundingBoxを取得する
	cocos2d::Rect getShield2BoundingBox() { return _pShieldSpr2->getBoundingBox(); }	//Spirte2のboundingBoxを取得する
};

//-------------------------------------------------
