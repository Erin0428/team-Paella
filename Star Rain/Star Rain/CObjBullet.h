#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：弾丸
class CObjBullet : public CObj
{
public:
		CObjBullet(float x,float y) ;//コンストラクタ
		~CObjBullet() {};
		void Init();
		void Action();
		void Draw();
private:
	float g_px;
	float g_py;
	float m_vx;
};