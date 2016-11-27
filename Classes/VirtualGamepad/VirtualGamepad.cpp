/*************************
	概要：バーチャルパッド
	制作者：タグチ　シンジ
*************************/
#include "VirtualGamepad.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

using namespace cocostudio::timeline;

VirtualGamepad* VirtualGamepad::create(float range)
{
	VirtualGamepad* pRet = new VirtualGamepad();

	if (pRet && pRet->init(range))
	{
		pRet->autorelease();
		return pRet;
	}
}


// on "init" you need to initialize your instance
bool VirtualGamepad::init(float range)
{
	//////////////////////////////
	// 1. super init first
	if (!Node::init())
	{
		return false;
	}

	// イベントリスナーの作成
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(VirtualGamepad::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(VirtualGamepad::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(VirtualGamepad::onTouchEnded, this);
	listener->onTouchCancelled = CC_CALLBACK_2(VirtualGamepad::onTouchCancelled, this);
	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

	// カメラの設定
	//Camera* camera = Camera::create();
	//camera->setCameraFlag(CameraFlag::USER1);
	//this->addChild(camera);
	
	// パッドのスプライト(外側)
	m_padA = Sprite::create("VrtualGamepad/outside.png");
	//m_padA->setPosition(200, 100);
	this->addChild(m_padA);
	//m_padA->setVisible(false);
	//m_padA->setCameraMask((unsigned short)CameraFlag::USER1);
	// パッドのスプライト(内側)
	m_padB = Sprite::create("VrtualGamepad/inside.png");
	m_padA->addChild(m_padB);
	m_padB->setPosition(m_padA->getContentSize().width / 2, m_padA->getContentSize().height / 2);
	//m_padB->setCameraMask((unsigned short)CameraFlag::USER1);

	// 半径を設定
	m_range = range;

	// アクションの初期化
	m_action = false;

	// タッチの初期化
	m_touch = false;

	return true;
}
/*--------------------------------------------------------------------------------------------------------------------------------------*/
// イベントリスナー
bool VirtualGamepad::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// 画像の移動
	Vec2 touchPos = touch->getLocation();

	Rect padBoundingBox = m_padA->getBoundingBox();

	bool hit = padBoundingBox.containsPoint(touchPos);

	if (hit)
	{
		log("hit");
		return true;
	}
	//m_padA->setPosition(touchPos);

	// 表示する
	//m_padA->setVisible(true);

	// 最初のタッチ座標を設定
	//m_startPos = touchPos;

	return false;
}
void VirtualGamepad::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// 画像の移動
	Vec2 touchPos = touch->getLocation();

	// 斜めの距離を取得
	float a = touchPos.x - m_padA->getPosition().x;
	float b = touchPos.y - m_padA->getPosition().y;
	float c = sqrt((a*a) + (b*b));

	// 設定した半径を超えていない
	if (c < m_range)
	{
		// 座標の変更
		m_padB->setPosition(touchPos - m_padA->getPosition() + m_padA->getContentSize() / 2);

		// アクション
		m_action = false;
	}
	else
	{
		// 二点間の距離を求める
		Vec2 distance = m_padA->getPosition() - touchPos;

		// 正規化
		distance.normalize();
		m_padB->setPosition(-distance*m_range + m_padA->getContentSize() / 2);

		// アクション
		m_action = true;
	}


	// 角度を求める
	m_angle = atan2f(b, a);
	//m_angle = atan2f(b, a) * 180.0f / 3.14;
}
void VirtualGamepad::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	//// 非表示にする
	//m_padA->setVisible(false);

	//// 座標の変更
	m_padB->setPosition(m_padA->getContentSize().width / 2, m_padA->getContentSize().height / 2);

	// アクション
	m_action = false;

	//// 画像の移動
	//Vec2 touchPos = touch->getLocation();


	//if (m_startPos == touchPos)	m_touch = true;
}
void VirtualGamepad::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// 非表示にする
	m_padA->setVisible(false);

	// 座標の変更
	m_padB->setPosition(m_padA->getContentSize().width / 2, m_padA->getContentSize().height / 2);

	// アクション
	m_action = false;
}
/*--------------------------------------------------------------------------------------------------------------------------------------*/
// 角度を返す
float VirtualGamepad::getAngle()const
{
	// 角度
	return m_angle;
}
/*--------------------------------------------------------------------------------------------------------------------------------------*/
// アクションを返す
bool VirtualGamepad::action()const
{
	// アクション
	return m_action;
}
/*--------------------------------------------------------------------------------------------------------------------------------------*/
// タッチの取得
bool VirtualGamepad::touch()
{
	if (m_touch)
	{
		m_touch = false;
		return true;
	}

	else
	{
		return false;
	}
}
/*--------------------------------------------------------------------------------------------------------------------------------------*/