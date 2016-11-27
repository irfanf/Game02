//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//!
//!	IRFAN FAHMI RAMADHAN
//!
//!	2016/11/15
//!	
//!	Player.cpp
//!
//! Copyright ©2016 IrGame All Right Reserved
//!
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//---------------------------------------
#include "Player.h"
#include "VirtualGamepad\VirtualGamepad.h"
//---------------------------------------
USING_NS_CC;
//---------------------------------------
const float RADIUS = 10.0f;

//---------------------------------------
Player * Player::create()
{
	//メモリ
	auto player = new (std::nothrow) Player();
	if (player && player->init())
	{
		player->_contentSize = player->getBoundingBox().size;
		player->autorelease();
		return player;
	}
	CC_SAFE_DELETE(player);
	return nullptr;

}


bool Player::init()
{
	if (!Node::init())
	{
		return false;
	}
	_isMove = false;
	_isKeyOn = false;
	_rad = 0.f;
	_hp = MAX_HP;

	//スプライトの生成
	_playerSpr = Sprite::create("player.png");
	_playerSpr->setPosition(Vec2::ZERO);
	this->addChild(_playerSpr);

	_pShield = Shield::create();
	addChild(_pShield);

	////盾の作成1
	//_pShield1 = Shield::create();
	//_pShield1->setPosition(0, 100);
	//_pShield1->setCenter(this->getPosition());
	//addChild(_pShield1);


	////盾の作成2
	//_pShield2 = Shield::create();
	//_pShield2->setPosition(0, -100);
	//_pShield2->setCenter(this->getPosition());
	//addChild(_pShield2);


	////盾の生成
	//_shieldSpr = Sprite::create("1.png");
	//_shieldSpr->setPosition(0,-100);
	//this->addChild(_shieldSpr);
	//
	//_shieldPar = ParticleSystemQuad::create("shieldPar.plist");
	//_shieldPar->resetSystem();
	//_shieldPar->setScale(0.7f);
	//_shieldPar->setPosition(32.f,16.f);
	//_shieldSpr->addChild(_shieldPar);

	EventListenerKeyboard* listener = EventListenerKeyboard::create();
	listener->onKeyPressed = CC_CALLBACK_2(Player::onKeyPressed, this);
	listener->onKeyReleased = CC_CALLBACK_2(Player::onKeyReleased, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	this->scheduleUpdate();
	return true;

}

void Player::move(float x, float y)
{
	Vec2 currentPos = this->getPosition();

	this->setPosition(currentPos.x + x, currentPos.y + y);
}

void Player::update(float dt)
{

	if (_isMove)
	{
		_rad += 0.1f;

		//Vec2 shieldPos = _shieldSpr->getPosition();

		float x = cosf(_rad) * RADIUS;
		float y = sinf(_rad) * RADIUS;

		//x += shieldPos.x;
		//y += shieldPos.y;
		//
		//_shieldSpr->setPosition(x, y);
		//_shieldSpr->setRotation(-x);
	}

	if (_isKeyOn)
	{
		switch (_key)
		{
		case W:
			move(0.0f, 5.0f);
			break;
		case A:
			move(-5.0f, 0.0f);
			break;
		case S:
			move(0.0f, -5.0f);
			break;
		case D:
			move(5.0f, 0.0f);
			break;

		}
	}


}

void Player::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		_key = W;
		_isKeyOn = true;
		break;
	case EventKeyboard::KeyCode::KEY_A:
		_key = A;
		_isKeyOn = true;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		_key = S;
		_isKeyOn = true;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		_key = D;
		_isKeyOn = true;
		break;
	case EventKeyboard::KeyCode::KEY_R:
		_isMove = true;
		break;
	}
}

void Player::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event * event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_W:
		_isKeyOn = false;
		break;
	case EventKeyboard::KeyCode::KEY_A:
		_isKeyOn = false;
		break;
	case EventKeyboard::KeyCode::KEY_S:
		_isKeyOn = false;
		break;
	case EventKeyboard::KeyCode::KEY_D:
		_isKeyOn = false;
		break;
	case EventKeyboard::KeyCode::KEY_R:
		_isMove = false;
		break;
	}
}

void Player::rotate(cocos2d::Ref * pSender)
{
	_rad += 0.1f;

	//Vec2 shieldPos = _shieldSpr->getPosition();

	float x = cosf(_rad) * RADIUS;
	float y = sinf(_rad) * RADIUS;

	//x += shieldPos.x;
	//y += shieldPos.y;
	//
	//_shieldSpr->setPosition(x, y);
	//_shieldSpr->setRotation(-x);
}




