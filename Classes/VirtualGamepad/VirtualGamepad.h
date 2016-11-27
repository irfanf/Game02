/*************************
	概要：バーチャルパッド
	制作者：タグチ　シンジ
*************************/
#pragma once

#include "cocos2d.h"

class VirtualGamepad : public cocos2d::Node
{
	private:
		// イベントリスナー
		bool onTouchBegan(cocos2d::Touch*, cocos2d::Event*);
		void onTouchMoved(cocos2d::Touch*, cocos2d::Event*);
		void onTouchEnded(cocos2d::Touch*, cocos2d::Event*);
		void onTouchCancelled(cocos2d::Touch*, cocos2d::Event*);

		// パッドのスプライト
		cocos2d::Sprite* m_padA;
		cocos2d::Sprite* m_padB;

		// 角度
		float m_angle;

		// 半径
		float m_range;

		// アクション
		bool m_action;

		// タッチ
		bool m_touch;

		// 最初のタッチ座標
		cocos2d::Vec2 m_startPos;

	public:
		// おまじない
		static VirtualGamepad* create(float r = 50.f);
		virtual bool init(float);

		// 角度の取得
		float getAngle()const;

		// アクションの取得
		bool action()const;

		// タッチの取得
		bool touch();
};

