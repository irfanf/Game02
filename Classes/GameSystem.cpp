//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//!
//!	IRFAN FAHMI RAMADHAN
//!
//!	2016/11/19
//!	
//!	GameSystem.cpp
//!
//! Copyright ©2016 IrGame All Right Reserved
//!
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
#include "GameSystem.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameOverScene.h"

USING_NS_CC;

using namespace cocostudio::timeline;

/*
Scene* GameSystem::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameSystem::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
*/

// on "init" you need to initialize your instance
bool GameSystem::init()
{
	if (!Node::init())
	{
		return false;
	}
	_gameDuration = 60;
	_timer = 0;
	_hpBarScale = 1.f;

	Size visibleSize = Director::getInstance()->getVisibleSize();

	//プレイヤーHPバー
	Sprite* emptyHpBarSpr = Sprite::create("emptyHP.png");
	emptyHpBarSpr->setPosition(visibleSize.width / 2, 600);
	addChild(emptyHpBarSpr);


	_hpBarSpr = Sprite::create("fullHP.png");
	_hpBarSpr->setAnchorPoint(Vec2::ZERO);
	_hpBarSpr->setPosition(230, 575);
	this->addChild(_hpBarSpr);

	_timeText = Label::create("", "Jokerman", 50);
	_timeText->setPosition(960 / 2, 550);
	//_timeText->setCameraMask((unsigned short)CameraFlag::USER1);
	this->addChild(_timeText);

	//Node::setCameraMask((unsigned short)CameraFlag::USER1);

	this->scheduleUpdate();
	return true;
}
void GameSystem::update(float dt)
{
	_timer++;

	setHPBarScale(_hpBarScale);
	
	if (_timer >= 60)
	{
		_gameDuration--;
		String* str = String::createWithFormat("%d", _gameDuration);
		_timeText->setString(str->getCString());
		_timer = 0;
	}

	if (_gameDuration <= 0)
	{
		//移動先シーンの作成
		auto scene = GameOverScene::createScene();
		auto transition = TransitionFade::create(1.0f, scene);
		Director::getInstance()->replaceScene(transition);

		this->unscheduleAllSelectors();
		log("Game End");
	}
}

