#include "TitleScene.h"
#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
//-------------------------------------------
USING_NS_CC;
using namespace cocostudio::timeline;
//-------------------------------------------
const float BG_SPEED = 10.0f;
const float TIME_CONVERTER = 60.0f;
const int MAX_OPACITY = 200;
//------------------------------------
//@! クラス作成
//------------------------------------
Scene* TitleScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = TitleScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
//------------------------------------
//@! クラスの初期化
//------------------------------------
bool TitleScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//画面サイズ
	Size visibleSize = Director::getInstance()->getVisibleSize();

	//初期化
	_time = 0;
	_opacity = 0;
	_startOpacity = 0;

	//タッチしたら移動
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(TitleScene::onTouchBegan, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	//ゲームタイトル
	_titleName = Sprite::create("titleName.png");
	//_titleName->setAnchorPoint(Vec2::ZERO);
	_titleName->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 50);
	_titleName->setOpacity(_opacity);
	this->addChild(_titleName);

	//ゲームスタート
	_start = Sprite::create("gameStart.png");
	_start->setPosition(visibleSize.width / 2, visibleSize.height / 2 - 150);
	_start->setOpacity(_startOpacity);
	this->addChild(_start);

	//パーティクルエフェクト
	CCParticleSystemQuad* par = CCParticleSystemQuad::create("title_par.plist");
	par->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(par);

	//更新
	this->scheduleUpdate();

	return true;
}
//------------------------------------
//@! 更新
//@! 時間
//------------------------------------
void TitleScene::update(float dt)
{
	//時間カウント
	_time++;

	if (_time >= (3.0f * TIME_CONVERTER))
	{
		//タイトルの透明
		if (_opacity <= MAX_OPACITY)_opacity++;
		_titleName->setOpacity(_opacity);
	}

	if (_time >= (4.0f * TIME_CONVERTER))
	{
		//Blink
		_startOpacity += 4.0f;
		_start->setOpacity(_startOpacity);
	}
}

//------------------------------------
//@! クリックしたら移動
//@! タッチ、イベント
//------------------------------------
bool TitleScene::onTouchBegan(Touch* touch, Event* unused_event)
{

	//移動先シーンの作成
	auto scene = HelloWorld::createScene();
	auto transition = TransitionTurnOffTiles::create(1.0f, scene);
	Director::getInstance()->replaceScene(transition);

	this->unscheduleAllSelectors();

	return false;
}