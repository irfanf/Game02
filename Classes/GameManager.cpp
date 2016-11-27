//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
//!
//!	IRFAN FAHMI RAMADHAN
//!
//!	2016/11/21
//!	
//!	GameManager.cpp
//!
//! Copyright ©2016 IrGame All Right Reserved
//!
//_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/_/
#include "GameManager.h"
#include "GameOverScene.h"


USING_NS_CC;

/*
Scene* GameManager::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameManager::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
*/

GameManager * GameManager::create()
{
	//メモリ
	auto gm = new (std::nothrow) GameManager();
	if (gm && gm->init())
	{
		//gm->_contentSize = gm->getBoundingBox().size;
		gm->autorelease();
		return gm;
	}
	CC_SAFE_DELETE(gm);
	return nullptr;
}

bool GameManager::init()
{
	if (!Node::init())
	{
		return false;
	}

	_visibleSize = Director::getInstance()->getVisibleSize();

	_pPlayer = Player::create();
	_pPlayer->setPosition(_visibleSize.width / 2, _visibleSize.height / 2);
	_pPlayer->setHP(MAX_HP);
	this->addChild(_pPlayer);

	/*for (int i = 0; i < MAX_FIRE; i++)
	{
		_pFire[i] = Bullet::create();
		_pFire[i]->setPosition((rand() % 1500) + 700, (rand() % 1500) + 700);
		_pFire[i]->setTarget(_pPlayer);
		this->addChild(_pFire[i]);
	}*/

	_pCamera = Camera::create();
	_pCamera->setCameraFlag(CameraFlag::USER1);
	this->addChild(_pCamera);

	_pGameSystem = GameSystem::create();
	_pGameSystem->setCameraMask((unsigned short)CameraFlag::USER1);
	this->addChild(_pGameSystem);

	_pEnemy = Enemy::create();
	_pEnemy->setBulletTarget(_pPlayer);
	//_pEnemy->setPosition(_visibleSize.width / 2, _visibleSize.height / 2);
	addChild(_pEnemy);

	//タッチを有効する
//	this->setTouchEnabled(true);
//	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);

	this->scheduleUpdate();
	return true;
}

void GameManager::update(float dt)
{

	//_pCamera = getScene()->getDefaultCamera();
	Vec2 cameraPos = _pPlayer->getPosition();
	//_pCamera->setPosition(cameraPos);

	auto camera = getScene()->getDefaultCamera();
	camera->setPosition(cameraPos);

	//_pGameSystem->setCameraMask((unsigned short)CameraFlag::USER1, true);
	//this->setCameraMask((unsigned short)CameraFlag::USER1);

	//convert to world vector
	Rect playerBoundingBox = RectApplyAffineTransform(_pPlayer->getPlayerBoundingBox(), _pPlayer->getNodeToWorldAffineTransform());
	Rect shield1BoundingBox1 = RectApplyAffineTransform(_pPlayer->getShield()->getShield1BoundingBox(), _pPlayer->getNodeToWorldAffineTransform());
	Rect shield1BoundingBox2 = RectApplyAffineTransform(_pPlayer->getShield()->getShield2BoundingBox(), _pPlayer->getNodeToWorldAffineTransform());
	
	float hp = _pPlayer->getHP();

	if (hp <= 0)
	{
		auto scene = GameOverScene::createScene();
		auto transition = TransitionFade::create(1.0f, scene);
		Director::getInstance()->replaceScene(transition);

		this->unscheduleAllSelectors();
	}

	/*for (int i = 0; i < MAX_FIRE; i++)
	{
		if (_pFire[i] != nullptr)
		{
			bool hit = playerBoundingBox.containsPoint(_pFire[i]->getPosition());
			bool hitShield1 = shield1BoundingBox1.containsPoint(_pFire[i]->getPosition());
			bool hitShield2 = shield1BoundingBox2.containsPoint(_pFire[i]->getPosition());

			if (hit)
			{

				hp -= 5;
				_pFire[i]->removeFromParent();
				_pFire[i] = nullptr;

				_pFire[i] = Bullet::create();
				_pFire[i]->setPosition((rand() % 1500) - 500, (rand() % 1500) - 500);
				_pFire[i]->setTarget(_pPlayer);
				this->addChild(_pFire[i]);
			}

		
			if (hitShield1 || hitShield2)
			{
				
				_pFire[i]->removeFromParent();
				_pFire[i] = nullptr;
			
				_pFire[i] = Bullet::create();
				_pFire[i]->setPosition((rand() % 1500) - 500, (rand() % 1500) - 500);
				_pFire[i]->setTarget(_pPlayer);
				this->addChild(_pFire[i]);
			}
		}
	}*/
	
	float hpScale = _pGameSystem->getHPBarScale();
	hpScale = hp / MAX_HP;

	_pPlayer->setHP(hp);
	_pGameSystem->setHPBarScale(hpScale);
}