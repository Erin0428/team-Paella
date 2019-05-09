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
	float m_vy;


	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	bool m_hit;	//衝突判定

	int m_block_type;

	//ブロックの当たり判定
	void BlockHit(
		float*x, float*y, bool scroll_on,
		bool*up, bool*down, bool*left, bool*right,
		float*vx, float*vy, int*bt
	);

};