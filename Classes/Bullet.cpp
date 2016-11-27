//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//!
//!	IRFAN FAHMI RAMADHAN
//!
//!	2016/11/15
//!	
//!	Bullet.cpp
//!
//! Copyright ©2016 IrGame All Right Reserved
//!
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
#include "Bullet.h"
//--------------------------
USING_NS_CC;
//------------------------------------
//@! 作成
//------------------------------------
Bullet * Bullet::create()
{

	auto bullet = new (std::nothrow) Bullet();
	if (bullet && bullet->init())
	{
		bullet->_contentSize = bullet->getBoundingBox().size;
		bullet->autorelease();
		return bullet;
	}
	CC_SAFE_DELETE(bullet);
	return nullptr;
}
//------------------------------------
//@! 初期化
//------------------------------------
bool Bullet::init()
{
	if (!Node::init())
	{
		return false;
	}
	
	//パーティクルの設定
	_pFirePar = ParticleSystemQuad::create("fire_particle.plist");
	_pFirePar->resetSystem();
	_pFirePar->setAutoRemoveOnFinish(true);
	_pFirePar->setPosition(Vec2::ZERO);
	this->addChild(_pFirePar);

	//_bulletSpr = Sprite::create("bullet.png");
	//_bulletSpr->setPosition(Vec2::ZERO);
	//this->addChild(_bulletSpr);

	//方向の初期化
	_dir = Vec2(5344, 9321).getNormalized();

	this->scheduleUpdate();
	return true;

}
//------------------------------------
//@! 更新
//@! 時間
//------------------------------------
void Bullet::update(float dt)
{
	if (_player != nullptr)
	{
		//スピード
		float speed = 5.0f;
		float coef = 0.05f;

		//座標を取得
		Vec2 pos = getPosition();
		//距離を計算する
		Vec2 dir = _player->getPosition() - pos;
		//方向を決める(正規化）
		dir.normalize();

		_dir = _dir * (1.0f - coef) + dir * coef;
		//正規化する
		_dir.normalize();

		//移動を方向とスピードを計算する
		auto mover = _dir*speed;
		//座標をずらす
		pos += mover;

		//動かす
		this->setPosition(pos);


	}
}




