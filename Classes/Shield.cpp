//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//!
//!	IRFAN FAHMI RAMADHAN
//!
//!	2016/11/17
//!	
//!	Shield.cpp
//!
//! Copyright ©2016 IrGame All Right Reserved
//!
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/

//----------------------------
#include "Shield.h"
//----------------------------
USING_NS_CC;
//----------------------------
const float RADIUS = 10.0f;
//------------------------------------
//@! 作成
//------------------------------------
Shield* Shield::create()
{
	//メモリ
	auto shield = new (std::nothrow) Shield();
	if (shield && shield->init())
	{
		shield->_contentSize = shield->getBoundingBox().size;
		shield->autorelease();
		return shield;
	}
	CC_SAFE_DELETE(shield);
	return nullptr;

}
//------------------------------------
//@! 初期化
//------------------------------------
bool Shield::init()
{
	if (!Node::init())
	{
		return false;
	}
	
	//初期値を代入
	_rad1 = 0.f;
	_rad2 = 3.1415f;
	
	//スプライト１の作成
	_pShieldSpr1 = Sprite::create("1.png");
	_pShieldSpr1->setPosition(0, 100);
	addChild(_pShieldSpr1);

	//スプライト２の作成
	_pShieldSpr2 = Sprite::create("1.png");
	_pShieldSpr2->setPosition(0, -100);
	addChild(_pShieldSpr2);

	//パーティクルエフェクトの作成
	ParticleSystemQuad*_shieldPar1 = ParticleSystemQuad::create("shieldPar.plist");
	_shieldPar1->resetSystem();
	_shieldPar1->setPosition(32, 16);//_shieldPar->getContentSize().width / 2, 
								   	 //_shieldPar->getContentSize().height / 2);
	_shieldPar1->setScale(0.7f);
	_pShieldSpr1->addChild(_shieldPar1);

	//パーティクルエフェクトの作成
	ParticleSystemQuad*_shieldPar = ParticleSystemQuad::create("shieldPar.plist");
	_shieldPar->resetSystem();
	_shieldPar->setPosition(32, 16);//_shieldPar->getContentSize().width / 2, 
									//_shieldPar->getContentSize().height / 2);
	_shieldPar->setScale(0.7f);
	_pShieldSpr2->addChild(_shieldPar);

	//更新を呼び出す
	this->scheduleUpdate();
	return true;

}
//------------------------------------
//@! 更新
//@! 時間
//------------------------------------
void Shield::update(float dt)
{
	rotate(_rad1,_pShieldSpr1);
	rotate(_rad2, _pShieldSpr2);
}
//------------------------------------
//@! 回す
//@! ラジアンとスプライトターゲット
//------------------------------------
void Shield::rotate(float &rad, cocos2d::Sprite * target)
{
	//ラジアンのIncrement
	rad += 0.1f;

	//○の動きをする（曲げる）
	float x1 = cosf(rad) * 100;
	float y1 = sinf(rad) * 100;

	//ターゲットにattachする
	target->setPosition(x1, y1);
	target->setRotation(-x1);
}

