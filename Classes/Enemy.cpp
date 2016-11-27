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
#include "Enemy.h"

USING_NS_CC;

//------------------------------------
//@! 作成
//------------------------------------
Enemy * Enemy::create()
{
	auto enemy = new (std::nothrow) Enemy();
	if (enemy && enemy->init())
	{
		enemy->_contentSize = enemy->getBoundingBox().size;
		enemy->autorelease();
		return enemy;
	}
	CC_SAFE_DELETE(enemy);
	return nullptr;
}
//------------------------------------
//@! 初期化
//------------------------------------
bool Enemy::init()
{
	if(!Node::init()) return false;

	//初期化
	_speed = 0;
	_shootDelay = 0;

	//ターゲットのノード
	_pTargetNode = Node::create();
	_pTargetNode->setPosition(rand()%960,rand()%640);
	addChild(_pTargetNode);

	//スプライトの作成
	_pEnemySpr = Sprite::create("enemy.png");
	addChild(_pEnemySpr);

	//弾の初期化
	for (int i = 0; i < MAX_SHOT; i++)
	{
		_pBullets[i] = nullptr;
	}

	//方向の初期化
	_dir = Vec2(5344, 9321).getNormalized();

	//更新
	scheduleUpdate();
	return true;
}
//------------------------------------
//@! 更新
//@! 時間
//------------------------------------
void Enemy::update(float dt)
{
	_shootDelay++;
	log("%d,%d", (int)_pTargetNode->getPosition().x, (int)_pTargetNode->getPosition().y);
	
	//敵の移動
	move(5.f);
	
	//敵とノードの当たり判定
	Vec2 target = _pTargetNode->getPosition();
	Rect enemySpr = _pEnemySpr->getBoundingBox();

	bool hit = enemySpr.containsPoint(target);
	if(hit)
	{
		log("hit");
		_pTargetNode->setPosition(rand() % 960, rand() % 640);
	}

	//弾の設定
	for (int i = 0; i < MAX_SHOT; i++)
	{
		if (_pBullets[i] == nullptr && i < MAX_SHOT && _shootDelay >= 30)
		{
			_pBullets[i] = Bullet::create();
			_pBullets[i]->setPosition(_pEnemySpr->getPosition());
			_pBullets[i]->setTarget(_pPlayerTarget);
			addChild(_pBullets[i]);
			_shootDelay = 0;
		}
	}

	
}
//------------------------------------
//@! 敵の動き
//------------------------------------
void Enemy::move(float speed)
{

	//誘導係数
	float coef = 0.05f;

	//座標を取得
	Vec2 pos = _pEnemySpr->getPosition();
	//距離を計算する
	Vec2 dir = _pTargetNode->getPosition() - pos;
	//方向を決める(正規化）
	dir.normalize();
	// 旋回角度を制限する
	_dir = _dir * (1.0f - coef) + dir * coef;
	//正規化する
	_dir.normalize();

	//移動を方向とスピードを計算する
	auto mover = _dir*speed;
	//座標をずらす
	pos += mover;

	//動かす
	_pEnemySpr->setPosition(pos);

}

Bullet * Enemy::getBullet()
{
	for (int i = 0; i < MAX_SHOT;i++)
	{
		if(_pBullets[i] != nullptr)
		return _pBullets[i];
	}

}


