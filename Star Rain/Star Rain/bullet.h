#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class Bullet : public CObj
{
	public:
		Bullet() {};
		~Bullet() {};
		void Init();
		void Action();
		void Draw();
	private:
};