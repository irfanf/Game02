#include "GameOverScene.h"
#include "TitleScene.h"
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
//@! �N���X�쐬
//------------------------------------
Scene* GameOverScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameOverScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
//------------------------------------
//@! �N���X�̏�����
//------------------------------------
bool GameOverScene::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//��ʃT�C�Y
	Size visibleSize = Director::getInstance()->getVisibleSize();


	Sprite* go = Sprite::create("gameOver.png");
	go->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	this->addChild(go);

	//�^�b�`��L������
	this->setTouchEnabled(true);
	this->setTouchMode(Touch::DispatchMode::ONE_BY_ONE);
	//�X�V
	this->scheduleUpdate();

	return true;
}

//------------------------------------
//@! ���Ԃ�������,�V�[���ړ�����
//@! ����
//@! �߂�l�@bool
//------------------------------------
bool GameOverScene::onTouchBegan(Touch* touch, Event* unused_event)
{
	//�ړ���V�[���̍쐬
	auto scene = TitleScene::createScene();
	auto transition = TransitionFade::create(1.0f, scene);
	Director::getInstance()->replaceScene(transition);

	this->unscheduleAllSelectors();

	return false;
}